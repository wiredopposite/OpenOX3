#include <wchar.h>

wchar_t *wmemmove(wchar_t * _PDCLIB_restrict dst, const wchar_t * _PDCLIB_restrict s, size_t n)
{
    wchar_t *d = dst;

    if (d == s || n == 0) {
        return dst;
    }
    if (d < s) {
        while (n--) {
            *d++ = *s++;
        }
    }
    else {
        d += n;
        s += n;
        while (n--) {
            *(--d) = *(--s);
        }
    }
    return dst;
}