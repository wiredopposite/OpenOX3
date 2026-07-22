#include <wchar.h>

wchar_t *wcsrchr(const wchar_t * _PDCLIB_restrict str, wchar_t ch)
{
    const wchar_t *p = str;
    while (*p) p++;
    
    while (str <= p) {
        if (*p == ch) {
            return (wchar_t *) p;
        }
        p--;
    }
    return NULL;
}