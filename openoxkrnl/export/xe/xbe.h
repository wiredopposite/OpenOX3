/*
 * ergo720                Copyright (c) 2023
 */

#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define XBEIMAGE_MAGIC 'HEBX'
#define XBEIMAGE_BASE 0x10000

#define XBEIMAGE_MEDIA_TYPE_HARD_DISK            0x00000001
#define XBEIMAGE_MEDIA_TYPE_DVD_X2               0x00000002
#define XBEIMAGE_MEDIA_TYPE_DVD_CD               0x00000004
#define XBEIMAGE_MEDIA_TYPE_CD                   0x00000008
#define XBEIMAGE_MEDIA_TYPE_DVD_5_RO             0x00000010
#define XBEIMAGE_MEDIA_TYPE_DVD_9_RO             0x00000020
#define XBEIMAGE_MEDIA_TYPE_DVD_5_RW             0x00000040
#define XBEIMAGE_MEDIA_TYPE_DVD_9_RW             0x00000080
#define XBEIMAGE_MEDIA_TYPE_DONGLE               0x00000100
#define XBEIMAGE_MEDIA_TYPE_MEDIA_BOARD          0x00000200
#define XBEIMAGE_MEDIA_TYPE_NONSECURE_HARD_DISK  0x40000000
#define XBEIMAGE_MEDIA_TYPE_NONSECURE_MODE       0x80000000
#define XBEIMAGE_MEDIA_TYPE_MEDIA_MASK           0x00FFFFFF

#define XBEIMAGE_SECTION_WRITEABLE               0x00000001
#define XBEIMAGE_SECTION_PRELOAD                 0x00000002
#define XBEIMAGE_SECTION_EXECUTABLE              0x00000004
#define XBEIMAGE_SECTION_INSERTFILE              0x00000008
#define XBEIMAGE_SECTION_HEAD_PAGE_READONLY      0x00000010
#define XBEIMAGE_SECTION_TAIL_PAGE_READONLY      0x00000020

#define XBEIMAGE_REGION_NA					0x00000001
#define XBEIMAGE_REGION_JAPAN				0x00000002
#define XBEIMAGE_REGION_RESTOFWORLD			0x00000004
#define XBEIMAGE_REGION_MANUFACTURING		0x80000000
#define XBEIMAGE_REGION_MASK				0x7FFFFFFF

#define XBEIMAGE_XOR_ENTRY_DEBUG 			0x94859D4B
#define XBEIMAGE_XOR_ENTRY_RETAIL 			0xA8FC57AB
#define XBEIMAGE_XOR_KERNEL_THUNK_DEBUG 	0xEFB1F152
#define XBEIMAGE_XOR_KERNEL_THUNK_RETAIL 	0x5B6D40B6

#pragma pack(1)
typedef struct _XBE_HEADER {
	DWORD dwMagic;                         // 0x0000 - magic number [should be "XBEH"]
	UCHAR pbDigitalSignature[256];         // 0x0004 - digital signature
	DWORD dwBaseAddr;                      // 0x0104 - base address
	DWORD dwSizeofHeaders;                 // 0x0108 - size of headers
	DWORD dwSizeofImage;                   // 0x010C - size of image
	DWORD dwSizeofImageHeader;             // 0x0110 - size of image header
	DWORD dwTimeDate;                      // 0x0114 - timedate stamp
	DWORD dwCertificateAddr;               // 0x0118 - certificate address
	DWORD dwSections;                      // 0x011C - number of sections
	DWORD dwSectionHeadersAddr;            // 0x0120 - section headers address

	typedef struct _INIT_FLAGS {
		DWORD bMountUtilityDrive : 1;    // mount utility drive flag
		DWORD bFormatUtilityDrive : 1;    // format utility drive flag
		DWORD bLimit64MB : 1;    // limit development kit run time memory to 64mb flag
		DWORD bDontSetupHarddisk : 1;    // don't setup hard disk flag
		DWORD Unused : 4;    // unused (or unknown)
		DWORD Unused_b1 : 8;    // unused (or unknown)
		DWORD Unused_b2 : 8;    // unused (or unknown)
		DWORD Unused_b3 : 8;    // unused (or unknown)
	} INIT_FLAGS;

	union {                                // 0x0124 - initialization flags
		INIT_FLAGS dwInitFlags;
		DWORD dwInitFlags_value;
	};

	DWORD dwEntryAddr;                     // 0x0128 - entry point address
	DWORD dwTLSAddr;                       // 0x012C - thread local storage directory address
	DWORD dwPeStackCommit;                 // 0x0130 - size of stack commit
	DWORD dwPeHeapReserve;                 // 0x0134 - size of heap reserve
	DWORD dwPeHeapCommit;                  // 0x0138 - size of heap commit
	DWORD dwPeBaseAddr;                    // 0x013C - original base address
	DWORD dwPeSizeofImage;                 // 0x0140 - size of original image
	DWORD dwPeChecksum;                    // 0x0144 - original checksum
	DWORD dwPeTimeDate;                    // 0x0148 - original timedate stamp
	DWORD dwDebugPathnameAddr;             // 0x014C - debug pathname address
	DWORD dwDebugFilenameAddr;             // 0x0150 - debug filename address
	DWORD dwDebugUnicodeFilenameAddr;      // 0x0154 - debug unicode filename address
	DWORD dwKernelImageThunkAddr;          // 0x0158 - kernel image thunk address
	DWORD dwNonKernelImportDirAddr;        // 0x015C - non kernel import directory address
	DWORD dwLibraryVersions;               // 0x0160 - number of library versions
	DWORD dwLibraryVersionsAddr;           // 0x0164 - library versions address
	DWORD dwKernelLibraryVersionAddr;      // 0x0168 - kernel library version address
	DWORD dwXAPILibraryVersionAddr;        // 0x016C - xapi library version address
	DWORD dwLogoBitmapAddr;                // 0x0170 - logo bitmap address
	DWORD dwSizeofLogoBitmap;              // 0x0174 - logo bitmap size
} XBE_HEADER, *PXBE_HEADER;

typedef struct _XBE_CERTIFICATE {
	DWORD  dwSize;                               // 0x0000 - size of certificate
	DWORD  dwTimeDate;                           // 0x0004 - timedate stamp
	DWORD  dwTitleId;                            // 0x0008 - title id
	WCHAR  wsTitleName[40];                        // 0x000C - title name (unicode)
	DWORD  dwAlternateTitleId[0x10];             // 0x005C - alternate title ids
	DWORD  dwAllowedMedia;                       // 0x009C - allowed media types
	DWORD  dwGameRegion;                         // 0x00A0 - game region
	DWORD  dwGameRatings;                        // 0x00A4 - game ratings
	DWORD  dwDiscNumber;                         // 0x00A8 - disc number
	DWORD  dwVersion;                            // 0x00AC - version
	BYTE   bzLanKey[16];                          // 0x00B0 - lan key
	BYTE   bzSignatureKey[16];                    // 0x00C0 - signature key
	// NOT ALL XBEs have these fields!
	BYTE   bzTitleAlternateSignatureKey[16][16];  // 0x00D0 - alternate signature keys
	DWORD  dwOriginalCertificateSize;            // 0x01D0 - Original Certificate Size?
	DWORD  dwOnlineService;                      // 0x01D4 - Online Service ID
	DWORD  dwSecurityFlags;                      // 0x01D8 - Extra Security Flags
	BYTE   bzCodeEncKey[16];                      // 0x01DC - Code Encryption Key?
} XBE_CERTIFICATE, *PXBE_CERTIFICATE;

typedef struct _XBE_SECTION {
	DWORD 	Flags;
	PVOID 	VirtualAddress;
	DWORD 	VirtualSize;
	DWORD 	FileAddress;
	DWORD 	FileSize;
	PCSZ 	SectionName;
	DWORD 	SectionReferenceCount;
	PUSHORT HeadReferenceCount;
	PUSHORT TailReferenceCount;
	BYTE 	ShaHash[20];
} XBE_SECTION, *PXBE_SECTION;

typedef struct _XBE_LIBRARY_VERSION {
	BYTE szName[8];
	WORD wMajorVersion;
	WORD wMinorVersion;
	WORD wBuildVersion;
	union {
		struct {
			WORD QFEVersion : 13;
			WORD Approved : 2;
			WORD bDebugBuild : 1;
		};
		WORD wFlags;
	};
} XBE_LIBRARY_VERSION, *PXBE_LIBRARY_VERSION;
STATIC_ASSERT(sizeof(XBE_LIBRARY_VERSION) == 0x10);

typedef struct _XBE_TLS {
	DWORD dwDataStartAddr;
	DWORD dwDataEndAddr;
	DWORD dwTLSIndexAddr;
	DWORD dwTLSCallbackAddr;
	DWORD dwSizeofZeroFill;
	DWORD dwCharacteristics;
} XBE_TLS, *PXBE_TLS;

typedef struct _XBE_IMAGE_EXPORT_DIRECTORY {
	ULONG  Characteristics;
	ULONG  TimeDateStamp;
	USHORT MajorVersion;
	USHORT MinorVersion;
	ULONG  Name;
	ULONG  Base;
	ULONG  NumberOfFunctions;
	ULONG  NumberOfNames;
	ULONG  AddressOfFunctions;
	ULONG  AddressOfNames;
	ULONG  AddressOfNameOrdinals;
} XBE_IMAGE_EXPORT_DIRECTORY, *PXBE_IMAGE_EXPORT_DIRECTORY;

#pragma pack()

#ifdef __cplusplus
}
#endif
