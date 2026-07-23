#pragma once

#include "win32types/types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define FASTCALL __fastcall
#define CDECL    __cdecl
#define NTAPI    __stdcall

#define MAXLONG 0x7fffffff

#define ANSI_NULL ((CHAR)0)
#define UNICODE_NULL ((WCHAR)0)

#define CONTAINING_RECORD(address, type, field) ((type *)((PCHAR)(address) - (ULONG_PTR)offsetof(type, field)))

#define LOWORD(l) ((WORD)((DWORD_PTR)(l)))
#define HIWORD(l) ((WORD)(((DWORD_PTR)(l) >> 16) & 0xFFFF))

#define MAXULONG_PTR (~((ULONG_PTR)0))
#define MAXLONG_PTR  ((LONG_PTR)(MAXULONG_PTR >> 1))
#define MINLONG_PTR  (~MAXLONG_PTR)

typedef struct _LIST_ENTRY {
	struct _LIST_ENTRY *Flink;
	struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY;

typedef struct _SINGLE_LIST_ENTRY {
	struct _SINGLE_LIST_ENTRY *Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY;
typedef SINGLE_LIST_ENTRY SLIST_ENTRY;
typedef PSINGLE_LIST_ENTRY PSLIST_ENTRY;

typedef union _SLIST_HEADER {
	ULONGLONG Alignment;
	struct {
		SINGLE_LIST_ENTRY Next;
		USHORT Depth;
		USHORT Sequence;
	};
} SLIST_HEADER, *PSLIST_HEADER;

typedef struct _STRING {
	USHORT Length;
	USHORT MaximumLength;
	PCHAR Buffer;
} STRING, *PSTRING;
typedef STRING ANSI_STRING;
typedef PSTRING PANSI_STRING;

typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
	PWCHAR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;
typedef const UNICODE_STRING *PCUNICODE_STRING;

typedef struct _DISPATCHER_HEADER {
	UCHAR Type;
	UCHAR Absolute;
	UCHAR Size;
	UCHAR Inserted;
	LONG SignalState;
	LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER;

typedef union _ULARGE_INTEGER {
	struct {
		DWORD LowPart;
		DWORD HighPart;
	};

	struct {
		DWORD LowPart;
		DWORD HighPart;
	} u;

	DWORDLONG QuadPart;
} ULARGE_INTEGER, *PULARGE_INTEGER;

typedef union _LARGE_INTEGER {
	struct {
		DWORD LowPart;
		LONG HighPart;
	};

	struct {
		DWORD LowPart;
		LONG HighPart;
	} u;

	LONGLONG QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

typedef struct _TIME_FIELDS {
	USHORT Year;
	USHORT Month;
	USHORT Day;
	USHORT Hour;
	USHORT Minute;
	USHORT Second;
	USHORT Millisecond;
	USHORT Weekday;
} TIME_FIELDS, *PTIME_FIELDS;

#ifdef __cplusplus
}
#endif
