#include <wchar.h>

wchar_t *wcschr(const wchar_t * _PDCLIB_restrict ws, wchar_t wc) 
{
    while (*ws != L'\0') {
        if (*ws == wc) {
            return (wchar_t *)ws;
        }
        ws++;
    }
    return (wc == L'\0') ? (wchar_t *)ws : NULL;
}