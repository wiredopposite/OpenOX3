CRT bring-up checklist
1. Zero .bss — verify whether your loader (whatever put you at 0x80010000 and jumped to MainCrtStartup) zero-fills the gap between a section's raw size and virtual size the way a real PE loader would. If it's your own minimal loader and it just memcpys raw file bytes, uninitialized globals/statics won't actually be zero. You already manually zero 0x80100000-0x80400000 for the bootloader region — same concern applies to your own .bss.

2. Call C++ global/static constructors — I verified this empirically: a namespace-scope object with a non-trivial constructor lands its init-thunk pointer in a section literally named .CRT$XCU. The MSVC/lld-link convention is .CRT$XCA (start marker, empty) through .CRT$XCZ (end marker, empty), with the linker sorting .CRT$* sections alphabetically so all the XC* initializer-pointer arrays from every translation unit end up contiguous between them. You need something like:


typedef void (*InitFunc)(void);
extern "C" InitFunc __xc_a[], __xc_z[]; // placed via linker at .CRT$XCA / .CRT$XCZ
for (InitFunc* p = __xc_a; p != __xc_z; ++p)
    if (*p) (*p)();
with two 1-element arrays declared __declspec(allocate("CRT$XCA")) / __declspec(allocate("CRT$XCZ")) respectively to bracket it (same pattern you're already using for SECTION_INIT/SECTION_PERSIST in section.hpp). Skip this and any file-scope object with a constructor silently never runs its constructor.

3. FPU/SSE state — your toolchain passes -msse -mno-sse (net effect: SSE codegen disabled), so floating point goes through x87. Before any floating-point instruction executes (including incidentally, inside newlib's printf/strtod/dtoa machinery for %f/%e/%g formats, which you enabled via _WANT_IO_C99_FORMATS), you need FNINIT and CR0 configured (EM/MP/TS bits) so the first FP instruction doesn't fault into a #NM exception you have no handler for yet.

4. Stack commit size — check your /STACK: linker setting (I didn't see one in openoxkrnl's LINK_FLAGS, so it's defaulting to PE's standard 1MB reserve / 4KB commit). Normal Windows PE semantics assume the OS grows the stack on demand via guard-page faults — you don't have page-fault handling wired up yet (presumably), so you need reserve == commit (a single upfront-committed size) or you'll fault the instant the stack exceeds one page.

5. Heap backing — already flagged: _sbrk in port/syscalls.c is a placeholder static array. Anything that calls malloc/operator new (libc++ containers, etc.) depends on it. Swap it for a real allocator call when you have one.

6. Nothing needed for: stdio stream init (__sinit runs lazily on first use of stdin/stdout/stderr, not something you call), the reentrancy struct _impure_ptr (a normal statically-initialized global, comes up fine as long as .data loads correctly), atexit/global destructors (irrelevant unless you expect the kernel to ever "exit" cleanly).