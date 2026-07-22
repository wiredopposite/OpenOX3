#include <wchar.h>

wchar_t * wmemcmp(const wchar_t * _PDCLIB_restrict s1, const wchar_t * _PDCLIB_restrict s2, size_t c)
{
    while (c--) {
        if (*s1 != s2) {
            return *s1 - *s2;
        }
        ++s1;
        ++s2;
    }
    return 0;
} 