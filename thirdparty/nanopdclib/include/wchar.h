#pragma once

#include "pdclib/_PDCLIB_lib_ext1.h"
#include "pdclib/_PDCLIB_internal.h"
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WCHAR_MAX  _PDCLIB_WCHAR_MAX
#define WCHAR_MIN  _PDCLIB_WCHAR_MIN

#ifndef WEOF
#define WEOF (0xffffffffu)
#endif

_PDCLIB_PUBLIC wchar_t *wcschr(const wchar_t * _PDCLIB_restrict ws, wchar_t wc);
_PDCLIB_PUBLIC wchar_t *wcsrchr(const wchar_t * _PDCLIB_restrict str, wchar_t ch);
_PDCLIB_PUBLIC wchar_t *wcsstr(const wchar_t * _PDCLIB_restrict dest, const wchar_t *src);
wchar_t *wcspbrk( const wchar_t *dest, const wchar_t *str );
size_t wcscspn( const wchar_t* dest, const wchar_t* src );
size_t wcsspn( const wchar_t* dest, const wchar_t* src );
size_t wcslen( const wchar_t *str );
size_t wcsnlen_s(const wchar_t *str, size_t strsz);
int wcscmp( const wchar_t* lhs, const wchar_t* rhs );
int wcscoll( const wchar_t *lhs, const wchar_t *rhs );
size_t wcsxfrm( wchar_t* restrict dest, const wchar_t* restrict src, size_t count );
wchar_t* wcscpy( wchar_t* restrict dest, const wchar_t* restrict src );

wchar_t* wcscpy( wchar_t* restrict dest, const wchar_t* restrict src );
wchar_t* wcsncpy( wchar_t* restrict dest, const wchar_t* restrict src, size_t count );
wchar_t* wcscat( wchar_t* restrict dest, const wchar_t* restrict src );
wchar_t* wcsncat( wchar_t* restrict dest, const wchar_t* restrict src, size_t count );
wchar_t* wcstok( wchar_t*  restrict str, const wchar_t* restrict delim, wchar_t** restrict ptr );

wchar_t *wmemchr( const wchar_t *ptr, wchar_t ch, size_t count );
_PDCLIB_PUBLIC int wmemcmp(const wchar_t * _PDCLIB_restrict s1, const wchar_t * _PDCLIB_restrict s2, size_t cnt);
_PDCLIB_PUBLIC wchar_t *wmemcpy(wchar_t * _PDCLIB_restrict dst, const wchar_t * _PDCLIB_restrict src, size_t cnt);
_PDCLIB_PUBLIC wchar_t *wmemmove(wchar_t * _PDCLIB_restrict dst, const wchar_t * _PDCLIB_restrict src, size_t cnt);
wchar_t* wmemset( wchar_t* dest, wchar_t ch, size_t count );

float wcstof( const wchar_t* restrict str, wchar_t** restrict str_end );
double wcstod( const wchar_t* restrict str, wchar_t** restrict str_end );
long double wcstold( const wchar_t* restrict str, wchar_t** restrict str_end );
long wcstol( const wchar_t * restrict str, wchar_t ** restrict str_end, int base );
long long wcstoll( const wchar_t * restrict str, wchar_t ** restrict str_end, int base );

#ifdef __clusplus
}
#endif