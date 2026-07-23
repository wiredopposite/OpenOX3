# OpenOX3 — Agent Briefing

You're picking up work on **OpenOX3**, a from-scratch, standalone NT/Xbox-style kernel
(`openoxkrnl`) written in C/C++, targeting real x86 (i686) hardware. This doc exists so
you don't have to re-derive the architecture or re-discover the same bugs the hard way.
Read it fully before touching the build.

## What this project actually is

An NT-kernel-style OS (Xbox-derived conventions: `HAL`, `KE`, `MM`, `OB`, `PS`, `RTL`,
etc. namespaces under `openoxkrnl/export/`) built with a **modern LLVM toolchain**
(clang-cl + lld-link) instead of real MSVC, and using **real libc/libc++** (mlibc +
llvm-project's libcxx) instead of hand-rolling everything. It is genuinely freestanding —
there is no real Windows OS underneath, no Windows SDK, no CRT. The kernel is responsible
for its own GDT, IDT/exceptions, memory manager, timers, and threading — all written by
hand in C/C++/asm, bootstrapped before any of that infrastructure exists.

**Why an MSVC-flavored target at all, if there's no Windows?** The kernel needs to
produce genuine PE/COFF binaries with NT calling conventions (to match hardware/bootloader
expectations, Xbox-style). That constraint is the source of most of the weird issues
you'll find below — LLVM ties COFF object-file emission to the target triple's OS field
being literally `windows`, and that in turn makes clang predefine `_WIN32`, which every
dependency (libc++, mlibc) then uses to assume a *real* Windows environment exists. It
doesn't. Expect this tension to recur.

## Repo layout

- `cmake/toolchain.cmake` — the one toolchain file used for the outer project, the
  kernel, and libcxx's nested build. Sets up clang-cl as C/C++ compiler,
  `--target=i686-pc-windows-msvc`, `CMAKE_SYSTEM_NAME=Generic` (see gotchas below),
  freestanding flags, and a **custom `CMAKE_C/CXX_LINK_EXECUTABLE` rule** (needed because
  `Generic` disables CMake's normal MSVC linker-flag handling).
- `cmake/mlibc-cross.ini` — separate meson cross-file for building mlibc (mlibc is a
  meson project, not CMake).
- `libs/libc/` — CMake `ExternalProject_Add` wrapper that runs meson/ninja to build
  mlibc, producing the `libc` imported target.
- `libs/libcxx/` — CMake `ExternalProject_Add` wrapper that builds llvm-project's
  `runtimes` (libcxx) against mlibc's headers, producing the `libcxx` imported target.
- `libs/win32types/` — header-only NT-style type defs (`ULONG`, `PVOID`, `BYTE`,
  `NTSTATUS`, etc.) for the kernel's exported API surface.
- `thirdparty/llvm-project/` — submodule, **unforked**, points at real upstream. Only
  used for its `runtimes`/libcxx source; nothing here has been patched (yet — if you need
  to patch libc++ source itself, that's a bigger decision, see "Open architectural
  questions" below).
- `thirdparty/mlibc/` — submodule, but **forked** to `https://github.com/wiredopposite/mlibc.git`
  specifically so we could patch it (see "mlibc fork patches" below). This is a real,
  general-purpose libc (not a minimal freestanding one) — chosen over alternatives
  (newlib, picolibc, llvm-libc) because its `sysdeps` porting model matches this
  project's need for OS-specific hooks, and llvm-libc has no baremetal-x86/hosted-kernel
  config at all (only ARM/RISC-V baremetal + Linux/Windows/UEFI hosted).
- `thirdparty/mlibc/sysdeps/openox/` — our OS port for mlibc. `sysdeps.cpp` here is where
  the OS-specific "guts" behind mlibc's `Sysdeps<Tag>` mechanism live.
- `openoxkrnl/` — the kernel itself. `src/main.cpp` has a `MainCrtStartup` entry point
  (placeholder — the *real* entry/CRT design, including handling both a
  BIOS+bootloader launch and a direct-disk-executable launch, has not been designed
  yet). `export/` holds the NT-style public API headers.
- A **bootloader** does not exist yet. Decision already made: it will NOT go through
  mlibc's build machinery at all — just a handful of hand-written `string.h`-level
  functions directly in the bootloader project, since its C needs are minimal.

## mlibc fork patches (all in `thirdparty/mlibc`, all committed to the fork)

Every one of these was found by actually running the build and reading the real error —
not guessed. If you hit a new mlibc build error, use the same method: reproduce, read
the exact diagnostic, fix precisely, verify with `nm`/`objdump` if it's ABI-sensitive.

1. **`pic: true` → `pic: get_option('b_staticpic')`** (`options/ansi/meson.build`,
   `options/posix/meson.build`) — was hardcoded, breaking `-fPIC`-unsupported COFF
   targets. Now respects the normal meson option.
2. **ELF-only assembler directives guarded behind `__ELF__`**
   (`options/internal/include/mlibc-asm/helpers.h`, plus raw `.hidden`/`.type`/
   `.cfi_undefined` lines in `options/rtld/x86/{entry,runtime}.S` and
   `options/internal/x86/{fenv,setjmp}.S`) — COFF has no equivalent for `.type`, `.size`,
   `.cfi_*`, `.hidden`, or `.note.GNU-stack`; these are now no-ops when `__ELF__` isn't
   defined.
3. **GCC atomic lock-free macros + POSIX feature macros** added via
   `add_project_arguments()` in top-level `meson.build`, gated on
   `host_machine.system() == 'openox'`: clang never predefines
   `__GCC_ATOMIC_*_LOCK_FREE` for MSVC-flavored targets (only ELF ones), but
   `freestnd-cxx-hdrs`'s `<atomic>` assumes they exist. Also defines
   `_POSIX_C_SOURCE=202405L`, `_XOPEN_SOURCE=800`, `_GNU_SOURCE` project-wide so the
   various `__MLIBC_XOPEN`/`__MLIBC_POSIX2024`/`_GNU_SOURCE`-gated declarations
   (`MINSIGSTKSZ`, `cookie_io_functions_t`, etc.) are consistently available.
4. **`endian.h`**: `#ifdef __GNUC__` → also accepts `__clang__` (clang doesn't define
   `__GNUC__` for MSVC-flavored triples, but does define the `__BYTE_ORDER__` the file
   actually needs).
5. **`posix_string.cpp` / `collation.hpp`**: `wcsxfrm`/`strcoll<wchar_t>` assumed a
   32-bit `wchar_t`/`wint_t` (glibc convention). This target's `wchar_t` is 16-bit
   (real Windows convention). Fixed at the source in `CollationPolicy<wchar_t>` —
   `getWeight`/`getExtra` return an empty span of the correct type when
   `__SIZEOF_WCHAR_T__ != 4`, since there's no real locale data loaded anyway (`nrules`
   is always 0 currently).
6. **RTLD (dynamic linker) dropped entirely** from the static `libc` target
   (`link_with`/`link_whole` of `ld_static_lib` removed in the `libc_static =
   static_library('c', ...)` block, top-level `meson.build`). RTLD is inherently
   ELF-shaped (references `__ehdr_start`, `__init_array_start/end`,
   `_pltRelocateStub`, etc. — none of which exist for a static PE kernel), and nothing
   in a single statically-linked kernel image will ever call into it (no `dlopen`).
   Note this was a two-step fix: removing it from `link_whole` alone wasn't enough,
   because for a static-library-to-static-library relationship meson doesn't
   distinguish "weak dependency" the same way it does for executables — had to drop it
   from `link_with` too.
7. **New file `options/internal/x86/msvc_i64.c`**: implements `__alldiv`, `__allrem`,
   `__aulldiv`, `__aullrem` — MSVC CRT helper symbols clang emits calls to for 64-bit
   arithmetic on i386 (no native 64-bit divide instruction). These are **not** in LLVM's
   `compiler-rt` (which uses different names like `__divdi3`) — verified empirically,
   there is no prebuilt library to link. Implementation notes if you touch this file:
   - The actual math is a plain bit-by-bit `udivmod64` — deliberately avoids `/` and `%`
     on `unsigned long long` inside the helpers themselves, since using those operators
     would recursively call these same functions.
   - The real callee-cleans-stack ABI these need only comes from `__stdcall`, but
     `__stdcall` also mangles the name (`__alldiv` → `___alldiv_impl@16`), which doesn't
     match what the compiler's call sites reference (plain `__alldiv`). Solved with a
     second, tiny `__attribute__((naked))` function per symbol doing a single tail
     `jmp` to the decorated name — verified correct via `llvm-nm`/`llvm-objdump` on the
     actual compiled object, not assumed.
   - **Watch the underscore count** if you extend this pattern: a C source name with N
     leading underscores becomes an object-file symbol with N+1 (one added by normal
     cdecl decoration). Getting this off by one is exactly the bug that ate an entire
     debugging round here.
   - clangd/IntelliSense may show spurious parse errors on the
     `__attribute__((naked))` functions in this file (and in `setjmp.S`-adjacent work).
     This is an IDE/clangd limitation, not a real compiler error — verified by invoking
     the actual `clang` binary directly. Don't trust the squiggle here; trust the real
     build.
8. **`options/internal/x86/setjmp.S`**: added a real `__sigsetjmp` (was entirely
   undefined anywhere in mlibc — every OS port has to supply it). Current
   implementation just returns 0 immediately (same as the non-sigmask `setjmp` path),
   because there's no signal subsystem yet, so there's no mask to save. This is
   correct-for-now, not a permanent stub avoidance — see comment in the file for
   exactly what needs to change once real signal handling exists.

## Toolchain gotchas (already solved, know these before you re-derive them)

- **`CMAKE_SYSTEM_NAME=Generic`** disables CMake's `Platform/Windows-MSVC` module. Two
  concrete consequences already hit: (a) static libraries get Unix naming (`libc++.a`,
  not `c++.lib`) even on this MSVC-flavored toolchain — our CMake targets reference the
  real `libc++.a`/`libc.a` names, not MSVC ones; (b) CMake doesn't know to wrap
  MSVC-only linker flags (`/SUBSYSTEM:NATIVE`, `/BASE:`, etc.) with `/link` before
  passing them to clang-cl — fixed via the custom `CMAKE_C/CXX_LINK_EXECUTABLE` rule in
  `toolchain.cmake` (order matters: `/link` must come *after* `-o <target>` and the
  libraries, not before, or clang-cl's own `-o` parsing breaks).
- **Unquoted `-isystem` paths containing spaces** (`C:\Program Files\LLVM\...`) silently
  split into bogus tokens on the command line. Any new `-isystem`/similar flag added to
  `CMAKE_C_FLAGS_INIT` needs to be a single quoted string
  (`\"-isystem${path}\"`), not `-isystem ${path}`.
- **`-U_WIN32`** is in `CMAKE_C_FLAGS_INIT`/`CMAKE_CXX_FLAGS_INIT` deliberately. Verified
  empirically: it strips the `_WIN32` macro from what source code sees (so libc++ and
  friends stop assuming a real Windows OS/CRT exists) while the actual compiler output
  is still genuine COFF and still uses the MSVC ABI (`_MSC_VER` stays defined,
  calling convention/mangling unaffected) — there is no target triple that gives COFF
  output without implying `_WIN32` (tested: forcing `os=none` with an explicit `-coff`
  object-format suffix crashes LLVM's backend outright).
- **mlibc's meson build must use plain `clang`/`clang++`, not `clang-cl`**
  (`cmake/mlibc-cross.ini`). mlibc's own `meson.build` calls `-dumpmachine` directly
  (a GNU-driver-only flag) and assumes GNU-style `-std=c++23` rather than clang-cl's
  `/std:` naming — using the GNU driver (still targeting `i686-pc-windows-msvc`, so it
  still emits COFF) sidesteps both without needing to patch meson.build.
- **meson's `--prefix` rejects Windows-style paths** for any cross `host_machine.system`
  it doesn't recognize as literally `windows` (ours is `openox`) — regardless of
  slash direction. Fix: don't pass `--prefix` at meson-setup time at all; use
  `--destdir` at install time instead (see `libs/libc/CMakeLists.txt`).
- **`ExternalProject_Add`'s configure step doesn't re-run on source-file changes**
  inside `SOURCE_DIR` (only on `CMAKE_ARGS` changes) — if you edit `mlibc`'s
  `meson.build` or `toolchain.cmake` and a rebuild doesn't pick it up, you need to
  `rm -rf` the relevant `build/libs/<name>`, `libs/<name>/build`, `libs/<name>/install`
  directories to force a clean reconfigure. Editing an existing `.c`/`.cpp` file's
  *content* (not the meson.build) is fine — meson's own ninja graph tracks that
  correctly and just recompiles the one file.
- **Background build commands**: don't manually background with `(...) &`. Pass the
  command straight to the run_in_background flag — manual `&`-backgrounding inside an
  already-backgrounded shell call let the launcher return immediately while the real
  build got killed/orphaned, producing a false "completed" signal with a stale/partial
  log.

## Current status (as of this doc)

- mlibc builds clean end-to-end through the real CMake target (`mlibc_build`).
- libcxx builds clean end-to-end against mlibc's headers (`libcxx_build`).
- `openoxkrnl.exe` gets through compiling and most of linking. Actively being worked
  through symbol-by-symbol as real code starts calling into libc (this is expected and
  is going the way libc bring-up always goes — see method above).

### Resolved this round
`__alldiv`/`__allrem`/`__aulldiv`/`__aullrem` (msvc_i64.c), the whole family of
ELF-only-linker-symbol errors (`__ehdr_start`, `__init_array_start/end`,
`__fini_array_start/end`, `__preinit_array_start/end`, `_pltRelocateStub` — all gone
once RTLD was dropped), `__sigsetjmp`.

### Still outstanding — mechanical (small stub, no design decision needed)
- `__rtld_allocateTcb`, `mlibc::tcb_available_flag` — only reachable via
  `pthread_create` (real thread creation), nothing calls it yet. A single static `Tcb`
  instance would satisfy this for now.
- `__dlapi_exit` — called at process exit to clean up dynamically-loaded objects; we
  have none. Safe no-op.
- `mlibc::cLocaleCollSeqMb` — a locale collation data table, declared
  (`options/internal/generic/locale-defaults.cpp`) but never defined anywhere in our
  build config. Needs an empty/minimal definition.
- `__fltused`, `__purecall`, `___dso_handle` — classic CRT-glue symbols
  (`_fltused` = compiler marker for "floating point is used", `_purecall` = pure
  virtual call handler, `__dso_handle` = per-module handle for destructor
  registration). These belong in the kernel's own custom entry/CRT work (already
  agreed direction), not in mlibc — trivial definitions once that CRT exists.

### Still outstanding — genuinely architectural (need a decision, not just a stub)
- **`__tls_index`/`__tls_array`**: mlibc's `options/internal/include/mlibc/strtol.hpp`
  uses real C++ `thread_local`. On this Windows-flavored triple, the compiler lowers
  `thread_local` using the *native Windows TLS model* (loader-managed `.tls` PE
  section, `__tls_index`/`__tls_array` set up by a real OS loader) — completely
  separate from mlibc's own `TcbSet`-based per-thread-struct mechanism (the i386 SysV
  `%gs`-based convention, which itself needs a GDT that doesn't exist yet either). We
  have neither. Options considered but not yet decided: (a) `-femulated-tls` (makes the
  compiler lower `thread_local` through calls to `__emutls_get_address`, which we'd
  implement ourselves against mlibc's TCB — much smaller ask than real PE `.tls`
  section handling), (b) patch `strtol.hpp` to avoid `thread_local` entirely, (c)
  implement real minimal `.tls`-section support. (a) was the leading idea when this was
  last discussed but not committed to.
- **`operator delete(void*, unsigned int)`** (sized delete): checked via `llvm-nm` on
  the actual built `libc++.a` — it's marked *undefined* there too, not just missing
  from the final link. This is because `LIBCXX_CXX_ABI=none` means no ABI library
  provides the global `operator new`/`delete` overload set, and libc++'s own
  `new.cpp` doesn't cover the sized-delete overload on its own. Needs a decision on
  where the global new/delete implementations should live (a small shim library?
  directly in the kernel?).

## How this user likes to work (read this, it'll save you both time)

- **Verify empirically, don't assert from memory.** Repeatedly, the fast path was
  "run the actual compiler/linker, read the exact diagnostic, check with
  `nm`/`objdump`/`readobj`" rather than confidently stating how an ABI/toolchain detail
  works. Several early mistakes in this project came from asserting something
  (a triple's macro behavior, a calling convention, a build system default) that turned
  out to be wrong on inspection. When genuinely unsure about a low-level ABI/toolchain
  detail, check first.
- **Small, real fixes over big rewrites.** Every fix in the mlibc fork is the smallest
  change that addresses the actual root cause — no speculative refactors, no "while I'm
  here" cleanups.
- **No unsolicited code walls.** This user has explicitly pushed back on long
  unrequested explanations/jargon dumps and on being told "here's what you need to
  implement" without concrete action. Prefer: state the finding, propose the fix, do it
  (or ask a *specific* clarifying question if there's a real fork in the road) — don't
  narrate options at length.
- **Ask before big architectural swings.** Things like "should mlibc replace
  nanopdclib", "fork mlibc vs. patch file", "CMAKE_SYSTEM_NAME=Windows vs. custom link
  rule" were all explicit decision points raised to the user, not decided unilaterally.
  The two "genuinely architectural" items above are exactly this kind of decision —
  don't just pick one and implement it.
- Building happens with **capped parallelism** (`--parallel 6` in
  `libs/libcxx/CMakeLists.txt`) — a 16-core/32GB machine was hitting real memory
  thrashing (not a bug, just heavy C++ template compiles) at full `-j16`. Keep that in
  mind if you add more heavy parallel build steps.
- NT-style types (`ULONG`, `PVOID`, `BYTE`, etc. — see `libs/win32types/`) are meant for
  the kernel's **exported API surface only**. Internal implementation should use
  idiomatic modern C++/STL, since real effort went into getting libc++ working — don't
  push NT-style typedefs through internal code.

## Suggested next steps (not prescriptive — ask the user)

1. Resolve the two architectural items above (TLS model, operator delete/new) — these
   block finishing `openoxkrnl.exe`'s link.
2. Knock out the remaining mechanical stubs (`__rtld_allocateTcb`,
   `tcb_available_flag`, `__dlapi_exit`, `cLocaleCollSeqMb`).
3. Design the real kernel entry/CRT (handles BIOS+bootloader launch vs. direct-executable
   launch with argc/argv; owns `_fltused`/`_purecall`/`__dso_handle`).
4. GDT/IDT/memory-manager/timer/threading bring-up in the kernel — this is also what
   unblocks the still-`STUB()`'d mlibc sysdeps (`TcbSet` needs the GDT, `ClockGet` needs
   a timer, `VmMap`/`VmUnmap` need the memory manager, `FutexWait`/`FutexWake` need a
   scheduler).
5. Bootloader project (hand-written minimal C, no mlibc) — doesn't exist yet.
