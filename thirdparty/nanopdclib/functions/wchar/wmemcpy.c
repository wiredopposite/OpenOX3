#include <wchar.h>

wchar_t *wmemcpy(wchar_t * _PDCLIB_restrict s1, const wchar_t * _PDCLIB_restrict s2, size_t n )
{
    wchar_t * dest = (wchar_t *)s1;

    while (n--) {
        *s1++ = *s2++;
    }

    return dest;
}