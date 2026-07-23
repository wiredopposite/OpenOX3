#ifndef __NEWLIB_H__
#define __NEWLIB_H__

/*
 * Hand-written stand-in for the header newlib's `configure` normally
 * generates from --enable/--disable flags. Values below mirror a
 * reasonably standard newlib configuration (C99 printf/scanf formats,
 * long long support), single-threaded (no _RETARGETABLE_LOCKING, so
 * sys/lock.h stays no-op), no multibyte/locale support.
 */

#define _WANT_IO_C99_FORMATS
#define _WANT_IO_POSIX_EXTENSIONS
#define _WANT_IO_LONG_LONG

#define __NEWLIB__      4
#define __NEWLIB_MINOR__ 5
#define __NEWLIB_PATCHLEVEL__ 0

#endif /* __NEWLIB_H__ */
