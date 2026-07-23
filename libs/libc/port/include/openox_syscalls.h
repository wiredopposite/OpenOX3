#ifndef OPENOX_SYSCALLS_H
#define OPENOX_SYSCALLS_H

/*
 * Force-included (via -include) into every newlib/libc/reent and
 * libc/syscalls translation unit built for OpenOX. Upstream newlib
 * never ships prototypes for these -- targets are expected to supply
 * them via their own sys/<port> headers, which we don't have since
 * we build newlib's sources directly instead of through its own
 * configure/make. Must match port/syscalls.c exactly.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>

int _open(const char *name, int flags, ...);
int _close(int file);
int _read(int file, void *ptr, size_t len);
int _write(int file, const void *ptr, size_t len);
off_t _lseek(int file, off_t ptr, int dir);
int _fstat(int file, struct stat *st);
int _isatty(int file);
void *_sbrk(ptrdiff_t incr);
void _exit(int status) __attribute__((noreturn));
int _kill(int pid, int sig);
int _getpid(void);
int _gettimeofday(struct timeval *tv, void *tz);
clock_t _times(struct tms *buf);

#endif /* OPENOX_SYSCALLS_H */
