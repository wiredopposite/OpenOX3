#pragma once

#include "krnl/krnl.h"
#include "xe/xbe.h"
#include "ob/ob.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _LAUNCH_DATA_HEADER {
	DWORD dwLaunchDataType;
	DWORD dwTitleId;
	CHAR szLaunchPath[520];
	DWORD dwFlags;
} LAUNCH_DATA_HEADER, *PLAUNCH_DATA_HEADER;

typedef struct _LAUNCH_DATA_PAGE {
	LAUNCH_DATA_HEADER Header;
	UCHAR Pad[492];
	UCHAR LaunchData[3072];
} LAUNCH_DATA_PAGE, *PLAUNCH_DATA_PAGE;

// Disassembly: _LDR_DATA_TABLE_ENTRY, 0x800514e0 (XepDataTableEntry layout)
typedef struct _LDR_DATA_TABLE_ENTRY {
	LIST_ENTRY InLoadOrderLinks;          // +0x00
	LIST_ENTRY InMemoryOrderLinks;        // +0x08
	LIST_ENTRY InInitializationOrderLinks; // +0x10
	PVOID DllBase;                        // +0x18
	PVOID EntryPoint;                     // +0x1C
	ULONG SizeOfImage;                    // +0x20
	UNICODE_STRING FullDllName;           // +0x24
	UNICODE_STRING BaseDllName;           // +0x2C
	ULONG Flags;                          // +0x34
	USHORT LoadCount;                     // +0x38
	USHORT TlsIndex;                      // +0x3A
	PVOID SectionPointer;                 // +0x3C
	ULONG CheckSum;                       // +0x40
	PVOID LoadedImports;                  // +0x44
} LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;
STATIC_ASSERT(sizeof(LDR_DATA_TABLE_ENTRY) == 0x48);

EXPORTNUM(164) DLLEXPORT extern PLAUNCH_DATA_PAGE LaunchDataPage;

EXPORTNUM(326) DLLEXPORT extern OBJECT_STRING XeImageFileName;

EXPORTNUM(327) DLLEXPORT NTSTATUS XBOXAPI XeLoadSection
(
	PXBE_SECTION Section
);

EXPORTNUM(328) DLLEXPORT NTSTATUS XBOXAPI XeUnloadSection
(
	PXBE_SECTION Section
);

// Disassembly: XePublicKeyData, Ordinal_355 — DVD-X2 RSA public key blob (null placeholder)
EXPORTNUM(355) DLLEXPORT extern UCHAR XePublicKeyData[1];

#ifdef __cplusplus
}
#endif