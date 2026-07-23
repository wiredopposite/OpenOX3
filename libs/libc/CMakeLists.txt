set(NEWLIB_DIR "${OPENOX_THIRDPARTY_DIR}/newlib")
set(NEWLIB_LIBC_DIR "${NEWLIB_DIR}/newlib/libc")

# Built directly as CMake sources rather than through newlib's own
# autotools build -- newlib has no CMake build of its own, and driving
# its configure/make through a clang-cl/lld-link cross setup is more
# trouble than it's worth. libc/machine (arch-tuned asm, ELF/GAS-flavored)
# and libc/sys/* (other targets' syscall ports) are deliberately excluded;
# port/syscalls.c is our port instead. Portable C fallbacks in libc/string
# etc. cover what the asm would have provided.
file(GLOB _libc_srcs
    "${NEWLIB_LIBC_DIR}/string/*.c"
    "${NEWLIB_LIBC_DIR}/stdlib/*.c"
    "${NEWLIB_LIBC_DIR}/stdio/*.c"
    "${NEWLIB_LIBC_DIR}/ctype/*.c"
    "${NEWLIB_LIBC_DIR}/errno/*.c"
    "${NEWLIB_LIBC_DIR}/signal/*.c"
    "${NEWLIB_LIBC_DIR}/time/*.c"
    "${NEWLIB_LIBC_DIR}/misc/*.c"
    "${NEWLIB_LIBC_DIR}/search/*.c"
)

# __dprintf.c uses obsolete K&R varargs.h instead of stdarg.h; it's a
# nonstandard debug helper, not part of any standard surface.
list(FILTER _libc_srcs EXCLUDE REGEX "__dprintf\\.c$")

# These pull in an alternate (GNU/BSD/locale-suffixed) declaration of a
# function that the first, differently-visibility-gated declaration
# already brought in earlier in the same translation unit, since we
# don't set _GNU_SOURCE/_BSD_SOURCE consistently -- a real fix means
# sorting out newlib's feature-visibility macros project-wide, not
# worth it for functionality we don't need yet (locale-suffixed
# strtol/wcstod variants, glibc fopencookie, wide unlocked stdio,
# GNU/BSD qsort_r and strerror_r variants).
list(FILTER _libc_srcs EXCLUDE REGEX
    "time/strptime\\.c$|string/wmempcpy\\.c$|string/strerror_r\\.c$|stdlib/wcstold\\.c$|stdio/putwchar_u\\.c$|stdio/putwc_u\\.c$|stdio/getwchar_u\\.c$|stdio/getwc_u\\.c$|stdio/fopencookie\\.c$"
)
list(FILTER _libc_srcs EXCLUDE REGEX "search/qsort_r\\.c$|search/bsd_qsort_r\\.c$")

# libc/reent and libc/syscalls are picked file-by-file rather than
# globbed: the rest of those dirs is fork/exec/mkdir/link/dirent glue
# for a process- and filesystem-having OS, which we don't have. Only
# pull in the reentrant wrappers that correspond to what port/syscalls.c
# actually implements. libc/posix is skipped entirely for the same
# reason (exec*, popen, wordexp, opendir/readdir, regex...).
set(_libc_reent_srcs
    "${NEWLIB_LIBC_DIR}/reent/closer.c"
    "${NEWLIB_LIBC_DIR}/reent/fstatr.c"
    "${NEWLIB_LIBC_DIR}/reent/getreent.c"
    "${NEWLIB_LIBC_DIR}/reent/gettimeofdayr.c"
    "${NEWLIB_LIBC_DIR}/reent/impure.c"
    "${NEWLIB_LIBC_DIR}/reent/isattyr.c"
    "${NEWLIB_LIBC_DIR}/reent/lseekr.c"
    "${NEWLIB_LIBC_DIR}/reent/openr.c"
    "${NEWLIB_LIBC_DIR}/reent/readr.c"
    "${NEWLIB_LIBC_DIR}/reent/reent.c"
    "${NEWLIB_LIBC_DIR}/reent/sbrkr.c"
    "${NEWLIB_LIBC_DIR}/reent/signalr.c"
    "${NEWLIB_LIBC_DIR}/reent/timesr.c"
    "${NEWLIB_LIBC_DIR}/reent/writer.c"
)

set(_libc_syscalls_srcs
    "${NEWLIB_LIBC_DIR}/syscalls/sysclose.c"
    "${NEWLIB_LIBC_DIR}/syscalls/sysfstat.c"
    "${NEWLIB_LIBC_DIR}/syscalls/sysgetpid.c"
    "${NEWLIB_LIBC_DIR}/syscalls/sysgettod.c"
    "${NEWLIB_LIBC_DIR}/syscalls/sysisatty.c"
    "${NEWLIB_LIBC_DIR}/syscalls/syskill.c"
    "${NEWLIB_LIBC_DIR}/syscalls/syslseek.c"
    "${NEWLIB_LIBC_DIR}/syscalls/sysopen.c"
    "${NEWLIB_LIBC_DIR}/syscalls/sysread.c"
    "${NEWLIB_LIBC_DIR}/syscalls/syssbrk.c"
    "${NEWLIB_LIBC_DIR}/syscalls/systimes.c"
    "${NEWLIB_LIBC_DIR}/syscalls/syswrite.c"
)

# clang lowers long long / unsigned long long multiply, divide, remainder
# and shift on this target to calls to fixed MSVC-named helpers (_alldiv
# etc) instead of its own portable compiler-rt builtins -- that's what
# "MSVC ABI compatible" means. They'd normally come from MSVC's libcmt.lib,
# which we don't link (/NODEFAULTLIB, no CRT), so we supply our own.
add_library(libc STATIC
    ${_libc_srcs}
    ${_libc_reent_srcs}
    ${_libc_syscalls_srcs}
    "${CMAKE_CURRENT_LIST_DIR}/port/syscalls.c"
    "${CMAKE_CURRENT_LIST_DIR}/port/arch/i386_msvc_helpers.asm"
)

target_include_directories(libc PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/port/include"
    "${NEWLIB_LIBC_DIR}/include"
)

# libc/reent and libc/syscalls call the bare _open/_read/_write/etc.
# names with no prototype in scope (upstream newlib expects each
# target's own sys/<port> headers to supply these); force-include ours.
# COMPILE_LANGUAGE-gated so it doesn't get handed to NASM.
target_compile_options(libc PRIVATE
    "$<$<COMPILE_LANGUAGE:C>:/FI${CMAKE_CURRENT_LIST_DIR}/port/include/openox_syscalls.h>"
    "$<$<COMPILE_LANGUAGE:C>:/FI${CMAKE_CURRENT_LIST_DIR}/port/types/default_types.h>"
)