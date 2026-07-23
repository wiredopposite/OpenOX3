/*
 * Minimal newlib syscall layer for OpenOX. No I/O, no processes, no
 * threads yet -- these are the stubs newlib's libc/reent glue calls
 * into (_read_r -> _read, etc). Replace as real kernel facilities
 * (console, VFS, page allocator) come online.
 */
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <stdint.h>

#define OPENOX_HEAP_SIZE (16u * 1024u * 1024u)
static uint8_t s_heap[OPENOX_HEAP_SIZE];
static uint8_t *s_heap_ptr = s_heap;

void *_sbrk(ptrdiff_t incr)
{
    uint8_t *prev = s_heap_ptr;

    if (incr < 0 || (uintptr_t)(s_heap + OPENOX_HEAP_SIZE - s_heap_ptr) < (uintptr_t)incr) {
        errno = ENOMEM;
        return (void *)-1;
    }

    s_heap_ptr += incr;
    return prev;
}

void _exit(int status)
{
    (void)status;
    for (;;) { }
}

int _kill(int pid, int sig)
{
    (void)pid;
    (void)sig;
    errno = EINVAL;
    return -1;
}

int _getpid(void)
{
    return 1;
}

int _close(int file)
{
    (void)file;
    errno = EBADF;
    return -1;
}

int _fstat(int file, struct stat *st)
{
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file)
{
    (void)file;
    return 0;
}

off_t _lseek(int file, off_t ptr, int dir)
{
    (void)file;
    (void)ptr;
    (void)dir;
    errno = EBADF;
    return -1;
}

int _open(const char *name, int flags, ...)
{
    (void)name;
    (void)flags;
    errno = ENOENT;
    return -1;
}

int _read(int file, void *ptr, size_t len)
{
    (void)file;
    (void)ptr;
    (void)len;
    errno = EBADF;
    return -1;
}

int _write(int file, const void *ptr, size_t len)
{
    (void)file;
    (void)ptr;
    (void)len;
    errno = EBADF;
    return -1;
}

int _gettimeofday(struct timeval *tv, void *tz)
{
    (void)tz;
    if (tv) {
        tv->tv_sec = 0;
        tv->tv_usec = 0;
    }
    return 0;
}

clock_t _times(struct tms *buf)
{
    if (buf) {
        buf->tms_utime = 0;
        buf->tms_stime = 0;
        buf->tms_cutime = 0;
        buf->tms_cstime = 0;
    }
    return 0;
}
