#pragma once

#include "krnl/krnl.h"
#include "rtl/rtl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define KiB(x) ((x) *    1024 ) // = 0x00000400
#define MiB(x) ((x) * KiB(1024)) // = 0x00100000
#define X64K   (KiB(64)) // = 0x00010000

#define PAGE_SHIFT                          12 // 2^12 = 4 KiB
#define PAGE_SIZE                           (1 << PAGE_SHIFT) // = 0x00001000 = KiB(4)
#define PAGE_MASK                           (PAGE_SIZE - 1)
#define PAGE_LARGE_SHIFT                    22 // 2^22 = 4 MiB
#define PAGE_LARGE_SIZE                     (1 << PAGE_LARGE_SHIFT) // = 0x00400000 = 4 MiB
#define PAGE_LARGE_MASK                     (PAGE_LARGE_SIZE - 1)
#define PTE_PER_PAGE                        1024

// Page masks
#define PAGE_NOACCESS          0x01
#define PAGE_READONLY          0x02
#define PAGE_READWRITE         0x04
#define PAGE_EXECUTE           0x10
#define PAGE_EXECUTE_READ      0x20
#define PAGE_EXECUTE_READWRITE 0x40
#define PAGE_EXECUTE_WRITECOPY 0x80
#define PAGE_GUARD             0x100
#define PAGE_NOCACHE           0x200
#define PAGE_WRITECOMBINE      0x400

// Memory Masks
#define MEM_COMMIT             0x1000
#define MEM_RESERVE            0x2000
#define MEM_DECOMMIT           0x4000
#define MEM_RELEASE            0x8000
#define MEM_FREE               0x10000
#define MEM_PRIVATE            0x20000
#define MEM_RESET              0x80000
#define MEM_TOP_DOWN           0x100000
#define MEM_NOZERO             0x800000

#define MAXIMUM_ZERO_BITS                   21
#define NV2A_INSTANCE_PAGE_COUNT            16
#define PAGE_DIRECTORY_PHYSICAL_ADDRESS     0x0F000
#define MAX_VIRTUAL_ADDRESS                 0xFFFFFFFF

// Common page calculations
#define ROUND_UP_4K(size)                   (((size) + PAGE_MASK) & (~PAGE_MASK))
#define ROUND_UP(size, alignment)           (((size) + (alignment - 1)) & (~(alignment - 1)))
#define ROUND_DOWN_4K(size)                 ((size) & (~PAGE_MASK))
#define ROUND_DOWN(size, alignment)         ((size) & (~(alignment - 1)))
#define PAGES_SPANNED(Va, Size)             ((ULONG)((((ULONG_PTR)(Va) & (PAGE_SIZE - 1)) + (Size) + (PAGE_SIZE - 1)) >> PAGE_SHIFT))
#define PAGES_SPANNED_LARGE(Va, Size)       ((ULONG)((((ULONG_PTR)(Va) & (PAGE_LARGE_SIZE - 1)) + (Size) + (PAGE_LARGE_SIZE - 1)) >> PAGE_LARGE_SHIFT))
#define CHECK_ALIGNMENT(size, alignment)    (((ULONG_PTR)(size) % (alignment)) == 0)
#define BYTE_OFFSET(Va)                     ((ULONG)((ULONG_PTR)(Va) & (PAGE_SIZE - 1)))
#define BYTE_LARGE_OFFSET(Va)               ((ULONG)((ULONG_PTR)(Va) & (PAGE_LARGE_SIZE - 1)))
#define BYTES_TO_PAGES(size)                (ROUND_UP_4K(size) >> PAGE_SHIFT)

// Memory ranges
#define X64M_PHYSICAL_PAGE                  0x04000

#define LOWEST_USER_ADDRESS                 0x00010000
#define HIGHEST_USER_ADDRESS                0x7FFEFFFF
#define HIGHEST_VAD_ADDRESS                 (HIGHEST_USER_ADDRESS - X64K) // for NtAllocateVirtualMemory
#define USER_MEMORY_SIZE                    (HIGHEST_USER_ADDRESS - LOWEST_USER_ADDRESS + 1) // 0x7FFE0000 = 2 GiB - 128 KiB

#define PHYSICAL_MAP_BASE                   0x80000000
#define PHYSICAL_MAP_SIZE                   (MiB(256)) // = 0x10000000
#define PHYSICAL_MAP_END                    (PHYSICAL_MAP_BASE + PHYSICAL_MAP_SIZE - 1) // 0x8FFFFFFF

#define CONTIGUOUS_MEMORY_BASE              PHYSICAL_MAP_BASE

#define DEVKIT_MEMORY_BASE                  0xB0000000
#define DEVKIT_MEMORY_SIZE                  (MiB(256)) // = 0x10000000
#define DEVKIT_MEMORY_END                   (DEVKIT_MEMORY_BASE + DEVKIT_MEMORY_SIZE - 1) // 0xBFFFFFFF

#define PAGE_TABLES_BASE                    0xC0000000
#define PAGE_TABLES_SIZE                    (MiB(4)) // = 0x00400000
#define PAGE_TABLES_END                     (PAGE_TABLES_BASE + PAGE_TABLES_SIZE - 1) // 0xC03FFFFF

#define PAGE_DIRECTORY_BASE                 0xC0300000

#define SYSTEM_MEMORY_BASE                  0xD0000000
#define SYSTEM_MEMORY_SIZE                  (MiB(512)) // = 0x20000000
#define SYSTEM_MEMORY_END                   (SYSTEM_MEMORY_BASE + SYSTEM_MEMORY_SIZE - 1) // 0xEFFFFFFF

#define WRITE_COMBINED_BASE                 0xF0000000 // WC (The WC memory is another name of the tiled memory)
#define WRITE_COMBINED_SIZE                 (MiB(128)) // = 0x08000000
#define WRITE_COMBINED_END                  (WRITE_COMBINED_BASE + WRITE_COMBINED_SIZE - 1) // 0xF7FFFFFF

#define UNCACHED_BASE                       0xF8000000 // UC
#define UNCACHED_SIZE                       (MiB(128)) // = 0x08000000
#define UNCACHED_END                        (UNCACHED_BASE + UNCACHED_SIZE - 1) // 0xFFFFFFFF

// These macros check if the supplied address is inside a known range
#define IS_PHYSICAL_ADDRESS(Va) (((ULONG)(Va) - PHYSICAL_MAP_BASE) <= (PHYSICAL_MAP_END - PHYSICAL_MAP_BASE))
#define IS_SYSTEM_ADDRESS(Va) (((ULONG)(Va) - SYSTEM_MEMORY_BASE) <= (SYSTEM_MEMORY_END - SYSTEM_MEMORY_BASE))
#define IS_DEVKIT_ADDRESS(Va) (((ULONG)(Va) - DEVKIT_MEMORY_BASE) <= (DEVKIT_MEMORY_END - DEVKIT_MEMORY_BASE))
#define IS_USER_ADDRESS(Va) (((ULONG)(Va) - LOWEST_USER_ADDRESS) <= (HIGHEST_USER_ADDRESS - LOWEST_USER_ADDRESS))

 // Pte protection masks
#define PTE_VALID_MASK              0x00000001
#define PTE_WRITE_MASK              0x00000002
#define PTE_OWNER_MASK              0x00000004
#define PTE_WRITE_THROUGH_MASK      0x00000008
#define PTE_CACHE_DISABLE_MASK      0x00000010
#define PTE_ACCESS_MASK             0x00000020
#define PTE_DIRTY_MASK              0x00000040
#define PTE_PAGE_LARGE_MASK         0x00000080
#define PTE_GLOBAL_MASK             0x00000100
#define PTE_GUARD_END_MASK          0x00000200
#define PTE_PERSIST_MASK            0x00000400
#define PTE_NOACCESS                0x00000000
#define PTE_READONLY                0x00000000 // confirmed with a kernel dump
#define PTE_READWRITE               PTE_WRITE_MASK
#define PTE_NOCACHE                 PTE_CACHE_DISABLE_MASK
#define PTE_GUARD                   PTE_GUARD_END_MASK
#define PTE_VALID_PROTECTION_MASK   0x0000021B // valid, write, write-through, no cache, guard/end
#define PTE_SYSTEM_PROTECTION_MASK  0x0000001B // valid, write, write-through, no cache

// Indicates that the system pte entry is not linked to other entries
#define PTE_LIST_END (ULONG)0x3FFFFFFF

// Indicates that the pfn entry is not linked to other entries
// Retail: 0xFFFE (bit 0 must be 0 — bit 0 of Blink overlaps the Busy flag at bit 16 of the ULONG)
#define PFN_LIST_END (USHORT)0xFFFE
// Define how many free lists a pfn region has
// Retail: ListIdx = PFN & 0x1F (5 bits, 32 free lists)
// Retail: MiEncodeFreePfn = (PFN >> 4) & 0xFFFE; DecodeFreePfn = (encoded << 4) | listIdx
#define PFN_LIST_SHIFT 5
#define PFN_NUM_LISTS (1 << PFN_LIST_SHIFT)
#define PFN_LIST_MASK (PFN_NUM_LISTS - 1)

typedef ULONG PFN;
typedef ULONG PFN_NUMBER;
typedef ULONG PFN_COUNT;
typedef ULONG PHYSICAL_ADDRESS;

typedef enum _MMPFN_BUSY_TYPE {
	MmUnknownUsage = 0,
	MmStackUsage = 1,
	MmVirtualPageTableUsage = 2,
	MmSystemPageTableUsage = 3,
	MmPoolUsage = 4,
	MmVirtualMemoryUsage = 5,
	MmSystemMemoryUsage = 6,
	MmImageUsage = 7,
	MmFsCacheUsage = 8,
	MmContiguousUsage = 9,
	MmDebuggerUsage = 10,
	MmMaximumUsage = 11
} MMPFN_BUSY_TYPE;

typedef union _MMPTE {
	ULONG ul;
	struct {
		ULONG Valid : 1;
		ULONG Write : 1;
		ULONG Owner : 1;
		ULONG WriteThrough : 1;
		ULONG CacheDisable : 1;
		ULONG Access : 1;
		ULONG Dirty : 1;
		ULONG PageLarge : 1;
		ULONG Global : 1;
		ULONG GuardEnd : 1;
		ULONG Persist : 1;
		ULONG : 1;
		ULONG Pfn : 20;
	} Hw;
	struct {
		ULONG Preset : 1;
		ULONG OnePte : 1;
		ULONG NextEntry : 30;
	} List;
} MMPTE, *PMMPTE;
STATIC_ASSERT(sizeof(MMPTE) == 4, "MMPTE size mismatch");

typedef struct _MMPFNFREE {
	USHORT PackedPfnFlink;
	USHORT PackedPfnBlink;
} MMPFNFREE, *PMMPFNFREE;
STATIC_ASSERT(sizeof(MMPFNFREE) == 4, "MMPFNFREE size mismatch");

typedef struct _MMPFNREGION {
	MMPFNFREE FreeListHead[PFN_NUM_LISTS];
	PFN_COUNT PagesAvailable;
} MMPFNREGION, *PMMPFNREGION;
STATIC_ASSERT(sizeof(MMPFNREGION) == 0x84, "MMPFNREGION size mismatch");

typedef struct _MMPTERANGE {
	MMPTE HeadPte;
	PMMPTE FirstCommittedPte;
	PMMPTE LastCommittedPte;
	PMMPTE LastReservedPte;
	PFN_COUNT *AvailablePages;
	PFN_NUMBER(FASTCALL *RemovePageRoutine)(MMPFN_BUSY_TYPE BusyType, PMMPTE Pte);
} MMPTERANGE, *PMMPTERANGE;
STATIC_ASSERT(sizeof(MMPTERANGE) == 24, "MMPTERANGE size mismatch");

typedef struct _MMADDRESS_NODE {
	ULONG StartingVpn;
	ULONG EndingVpn;
	struct _MMADDRESS_NODE *Parent;    
	struct _MMADDRESS_NODE *LeftChild; 
	struct _MMADDRESS_NODE *RightChild;
} MMADDRESS_NODE, *PMMADDRESS_NODE;
STATIC_ASSERT(sizeof(MMADDRESS_NODE) == 20, "MMADDRESS_NODE size mismatch");

typedef struct _MMGLOBALDATA {
	PMMPFNREGION RetailPfnRegion;
	PMMPTERANGE SystemPteRange;
	PULONG AvailablePages;
	PFN_COUNT *AllocatedPagesByUsage;
	PRTL_CRITICAL_SECTION AddressSpaceLock;
	PMMADDRESS_NODE *VadRoot;
	PMMADDRESS_NODE *VadHint;
	PMMADDRESS_NODE *VadFreeHint;
} MMGLOBALDATA, *PMMGLOBALDATA;
STATIC_ASSERT(sizeof(MMGLOBALDATA) == 0x20, "MMGLOBALDATA size mismatch");

typedef struct _MM_STATISTICS {
	ULONG Length;
	ULONG TotalPhysicalPages;
	ULONG AvailablePages;
	ULONG VirtualMemoryBytesCommitted;
	ULONG VirtualMemoryBytesReserved;
	ULONG CachePagesCommitted;
	ULONG PoolPagesCommitted;
	ULONG StackPagesCommitted;
	ULONG ImagePagesCommitted;
} MM_STATISTICS, *PMM_STATISTICS;
STATIC_ASSERT(sizeof(MM_STATISTICS) == 0x24, "MM_STATISTICS size mismatch");

EXPORTNUM(102) DLLEXPORT extern MMGLOBALDATA MmGlobalData;

EXPORTNUM(165) DLLEXPORT PVOID XBOXAPI MmAllocateContiguousMemory
(
	ULONG NumberOfBytes
);

EXPORTNUM(166) DLLEXPORT PVOID XBOXAPI MmAllocateContiguousMemoryEx
(
	ULONG NumberOfBytes,
	PHYSICAL_ADDRESS LowestAcceptableAddress,
	PHYSICAL_ADDRESS HighestAcceptableAddress,
	ULONG Alignment,
	ULONG ProtectionType
);

EXPORTNUM(167) DLLEXPORT PVOID XBOXAPI MmAllocateSystemMemory
(
	ULONG NumberOfBytes,
	ULONG Protect
);

EXPORTNUM(168) DLLEXPORT PVOID XBOXAPI MmClaimGpuInstanceMemory
(
	SIZE_T NumberOfBytes,
	SIZE_T *NumberOfPaddingBytes
);

EXPORTNUM(169) DLLEXPORT PVOID XBOXAPI MmCreateKernelStack
(
	ULONG NumberOfBytes,
	BOOLEAN DebuggerThread
);

EXPORTNUM(170) DLLEXPORT VOID XBOXAPI MmDeleteKernelStack
(
	PVOID StackBase,
	PVOID StackLimit
);

EXPORTNUM(171) DLLEXPORT VOID XBOXAPI MmFreeContiguousMemory
(
	PVOID BaseAddress
);

EXPORTNUM(172) DLLEXPORT ULONG XBOXAPI MmFreeSystemMemory
(
	PVOID BaseAddress,
	ULONG NumberOfBytes
);

EXPORTNUM(173) DLLEXPORT PHYSICAL_ADDRESS XBOXAPI MmGetPhysicalAddress
(
	PVOID BaseAddress
);

EXPORTNUM(174) DLLEXPORT BOOLEAN XBOXAPI MmIsAddressValid
(
	PVOID VirtualAddress
);

EXPORTNUM(175) DLLEXPORT VOID XBOXAPI MmLockUnlockBufferPages
(
	PVOID BaseAddress,
	SIZE_T NumberOfBytes,
	BOOLEAN UnlockPages
);

EXPORTNUM(176) DLLEXPORT VOID XBOXAPI MmLockUnlockPhysicalPage
(
	ULONG PhysicalAddress,
	UCHAR Unlock
);

EXPORTNUM(177) DLLEXPORT PVOID XBOXAPI MmMapIoSpace
(
	ULONG PhysicalAddress,
	ULONG NumberOfBytes,
	ULONG Protect
);

EXPORTNUM(178) DLLEXPORT VOID XBOXAPI MmPersistContiguousMemory
(
	PVOID BaseAddress,
	ULONG NumberOfBytes,
	BOOLEAN Persist
);

EXPORTNUM(179) DLLEXPORT ULONG XBOXAPI MmQueryAddressProtect
(
	PVOID VirtualAddress
);

EXPORTNUM(180) DLLEXPORT SIZE_T XBOXAPI MmQueryAllocationSize
(
	PVOID BaseAddress
);

EXPORTNUM(182) DLLEXPORT VOID XBOXAPI MmSetAddressProtect
(
	PVOID BaseAddress,
	ULONG NumberOfBytes,
	ULONG NewProtect
);

EXPORTNUM(181) DLLEXPORT NTSTATUS XBOXAPI MmQueryStatistics
(
	PMM_STATISTICS MemoryStatistics
);

EXPORTNUM(183) DLLEXPORT VOID XBOXAPI MmUnmapIoSpace
(
	PVOID BaseAddress,
	ULONG NumberOfBytes
);

EXPORTNUM(374) DLLEXPORT PVOID XBOXAPI MmDbgAllocateMemory
(
	ULONG NumberOfBytes,
	ULONG Alignment
);

EXPORTNUM(375) DLLEXPORT ULONG XBOXAPI MmDbgFreeMemory
(
	PVOID BaseAddress,
	ULONG NumberOfBytes
);

EXPORTNUM(376) DLLEXPORT PFN_COUNT XBOXAPI MmDbgQueryAvailablePages();

EXPORTNUM(377) DLLEXPORT VOID XBOXAPI MmDbgReleaseAddress
(
	PVOID VirtualAddress,
	PULONG OldPte
);

EXPORTNUM(378) DLLEXPORT PVOID XBOXAPI MmDbgWriteCheck
(
	PVOID VirtualAddress,
	PULONG OldPte
);

#ifdef __cplusplus
}
#endif
