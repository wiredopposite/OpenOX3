#pragma once
#include <stddef.h>
#include <stdarg.h>
#include "nanoprintf.h"

typedef struct _FILE FILE;

static __inline int printf(const char *fmt, ...) { (void)fmt; return 0; }
static __inline int fprintf(FILE *fp, const char *fmt, ...) { (void)fp; (void)fmt; return 0; }

static __inline int snprintf(char *s, size_t n, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int r = npf_vsnprintf(s, n, fmt, ap);
    va_end(ap);
    return r;
}
static __inline int vsnprintf(char *s, size_t n, const char *fmt, va_list ap) {
    return npf_vsnprintf(s, n, fmt, ap);
}
static __inline int vsnprintf_s(char *s, size_t sz, size_t n, const char *fmt, va_list ap) {
    (void)sz;
    return npf_vsnprintf(s, n, fmt, ap);
}

static __inline int fscanf(FILE *fp, const char *fmt, ...) { (void)fp; (void)fmt; return -1; }
static __inline FILE *fopen(const char *path, const char *mode) { (void)path; (void)mode; return (FILE *)0; }
static __inline int fclose(FILE *fp) { (void)fp; return -1; }
static __inline size_t fread(void *buf, size_t sz, size_t n, FILE *fp) { (void)buf; (void)sz; (void)n; (void)fp; return 0; }
static __inline size_t fwrite(const void *buf, size_t sz, size_t n, FILE *fp) { (void)buf; (void)sz; (void)n; (void)fp; return 0; }
static __inline int feof(FILE *fp) { (void)fp; return 1; }
static __inline int ferror(FILE *fp) { (void)fp; return 1; }
static __inline int fflush(FILE *fp) { (void)fp; return -1; }
static __inline int fseek(FILE *fp, long offset, int whence) { (void)fp; (void)offset; (void)whence; return -1; }
static __inline long ftell(FILE *fp) { (void)fp; return -1L; }
static __inline void rewind(FILE *fp) { (void)fp; }
