#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TRUE 1
#define FALSE 0

typedef void VOID;
typedef int32_t BOOL;
typedef uint8_t BYTE;
typedef int8_t INT8;
typedef unsigned char UCHAR;
typedef char CHAR;
typedef wchar_t WCHAR;
typedef CHAR SCHAR;
typedef CHAR CCHAR;
typedef uint8_t BOOLEAN;
typedef uint16_t USHORT;
typedef int16_t CSHORT;
typedef int16_t SHORT;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef uint32_t ULONG;
typedef uint32_t UINT;
typedef int32_t LONG;
typedef int32_t INT;
typedef int64_t LONGLONG;
typedef uint64_t ULONGLONG;
typedef ULONGLONG QUAD;
typedef uint64_t DWORDLONG;
typedef LONG NTSTATUS;
typedef LONG KPRIORITY;
typedef LONG HRESULT;
typedef ULONG ACCESS_MASK;
typedef ULONG LOGICAL;

// using VOID = void;
// using BYTE = uint8_t;
// using INT8 = int8_t;
// using UCHAR = unsigned char;
// using CHAR = char;
// using WCHAR = wchar_t;
// using BOOL = bool;
// using SCHAR = CHAR;
// using CCHAR = CHAR;
// using BOOLEAN = uint8_t;
// using USHORT = uint16_t;
// using CSHORT = int16_t;
// using WORD = uint16_t;
// using DWORD = uint32_t;
// using ULONG = uint32_t;
// using UINT = uint32_t;
// using LONG = int32_t;
// using INT = int32_t;
// using LONGLONG = int64_t;
// using ULONGLONG = uint64_t;
// using QUAD = ULONGLONG;
// using DWORDLONG = uint64_t;
// using NTSTATUS = LONG;
// using KPRIORITY = LONG;
// using HRESULT = LONG;
// using ACCESS_MASK = ULONG;
// using LOGICAL = ULONG;

#if _WIN32

typedef void *PVOID;
typedef BOOLEAN *PBOOLEAN;
typedef uintptr_t ULONG_PTR;
typedef uintptr_t DWORD_PTR;
typedef intptr_t LONG_PTR;
typedef ULONG_PTR *PULONG_PTR;
typedef PVOID HANDLE;
typedef ACCESS_MASK *PACCESS_MASK;
typedef HANDLE *PHANDLE;
typedef ULONG_PTR SIZE_T;
typedef SIZE_T *PSIZE_T;
typedef const WCHAR *PCWSTR;
typedef USHORT *PUSHORT;
typedef ULONG *PULONG;
typedef LONGLONG *PLONGLONG;
typedef ULONGLONG *PULONGLONG;
typedef DWORD *LPDWORD;
typedef UCHAR *PUCHAR;
typedef LONG *PLONG;
typedef const CHAR *PCSZ;
typedef CHAR *PCHAR;
typedef BYTE *PBYTE;
typedef WCHAR *PWCHAR;
typedef PWCHAR PWSTR;

// using PVOID = void *;
// using ULONG_PTR = uintptr_t;
// using DWORD_PTR = uintptr_t;
// using LONG_PTR = intptr_t;
// using PULONG_PTR = ULONG_PTR *;
// using HANDLE = PVOID;
// using PACCESS_MASK = ACCESS_MASK *;
// using PHANDLE = HANDLE *;
// using SIZE_T = ULONG_PTR;
// using PSIZE_T = SIZE_T *;
// using PCWSTR = const WCHAR *;
// using PUSHORT = USHORT *;
// using PULONG = ULONG *;
// using PLONGLONG = LONGLONG *;
// using PULONGLONG = ULONGLONG *;
// using LPDWORD = DWORD *;
// using PUCHAR = UCHAR *;
// using PLONG = LONG *;
// using PCSZ = const CHAR *;
// using PCHAR = CHAR *;
// using PBYTE = BYTE *;
// using PWCHAR = WCHAR *;
// using PWSTR = PWCHAR;

#else

typedef LONG  BOOL;
typedef ULONG PBOOLEAN;
typedef ULONG PVOID;
typedef ULONG HANDLE;
typedef ULONG PACCESS_MASK;
typedef ULONG PHANDLE;
typedef ULONG SIZE_T;
typedef ULONG PSIZE_T;
typedef ULONG ULONG_PTR;
typedef ULONG DWORD_PTR;
typedef LONG  LONG_PTR;
typedef ULONG PULONG_PTR;
typedef ULONG PCWSTR;
typedef ULONG PUSHORT;
typedef ULONG PULONG;
typedef ULONG PLONGLONG;
typedef ULONG PULONGLONG;
typedef ULONG LPDWORD;
typedef ULONG PUCHAR;
typedef ULONG PLONG;
typedef ULONG PCSZ;
typedef ULONG PCHAR;
typedef ULONG PBYTE;
typedef ULONG PWCHAR;
typedef ULONG PWSTR;

// using PVOID = ULONG;
// using HANDLE = PVOID;
// using PACCESS_MASK = ULONG;
// using PHANDLE = ULONG;
// using SIZE_T = ULONG;
// using PSIZE_T = ULONG;
// using ULONG_PTR = ULONG;
// using DWORD_PTR = ULONG;
// using LONG_PTR = LONG;
// using PULONG_PTR = ULONG;
// using PCWSTR = ULONG;
// using PUSHORT = ULONG;
// using PULONG = ULONG;
// using PLONGLONG = ULONG;
// using PULONGLONG = ULONG;
// using LPDWORD = ULONG;
// using PUCHAR = ULONG;
// using PLONG = ULONG;
// using PCSZ = ULONG;
// using PCHAR = ULONG;
// using PBYTE = ULONG;
// using PWCHAR = ULONG;
// using PWSTR = PWCHAR;

#endif

#ifndef STATIC_ASSERT
    #define UNDEF_STATIC_ASSERT
    #ifdef __cplusplus
        #define STATIC_ASSERT static_assert
    #else
        #define STATIC_ASSERT _Static_assert
    #endif
#endif

STATIC_ASSERT(sizeof(BOOL) == 4, "BOOL must be 4 bytes");
STATIC_ASSERT(sizeof(LONG) == 4, "LONG must be 4 bytes");
STATIC_ASSERT(sizeof(ULONG) == 4, "ULONG must be 4 bytes");
STATIC_ASSERT(sizeof(WCHAR) == 2, "WCHAR must be 2 bytes");
STATIC_ASSERT(sizeof(CHAR) == 1, "CHAR must be 1 byte");
STATIC_ASSERT(sizeof(PVOID) == 4, "PVOID must be 4 bytes");

#ifdef UNDEF_STATIC_ASSERT
    #undef UNDEF_STATIC_ASSERT
    #undef STATIC_ASSERT
#endif

#ifdef __cplusplus
}
#endif
