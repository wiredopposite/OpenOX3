#pragma once
#include <stddef.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define EOF -1

extern void *calloc(size_t n, size_t size);
extern void  free(void *ptr);
extern void *malloc(size_t size);
extern void *realloc(void *ptr, size_t size);

static __inline void exit(int code) { (void)code; __debugbreak(); }
static __inline void abort(void) { __debugbreak(); }

#ifndef __cplusplus
typedef int (*_crt_atexit_fn)(void);
static __inline int atexit(_crt_atexit_fn fn) { (void)fn; return 0; }
#endif
