#pragma once

#include "krnl/krnl.h"
#include "ob/ob.h"
#include "ke/ke.h"
#include "ki/seh.h"
#include "xbox/xbox.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ERWLOCK {
	LONG LockCount;
	ULONG WritersWaitingCount;
	ULONG ReadersWaitingCount;
	ULONG ReadersEntryCount;
	KEVENT WriterEvent;
	KSEMAPHORE ReaderSemaphore;
} ERWLOCK, *PERWLOCK;

#pragma pack(push, 4)
typedef struct _EX_TIMER {
	KTIMER Timer;
	KAPC TimerApc;
	KDPC TimerDpc;
	LIST_ENTRY ActiveTimerListEntry;
	LONG Period;
	BOOLEAN ApcAssociated;
	ULONG Reserved;
} EX_TIMER, *PEX_TIMER;
#pragma pack(pop)
STATIC_ASSERT(offsetof(EX_TIMER, TimerApc) == 0x28);
STATIC_ASSERT(offsetof(EX_TIMER, TimerDpc) == 0x50);
STATIC_ASSERT(offsetof(EX_TIMER, ActiveTimerListEntry) == 0x6C);
STATIC_ASSERT(offsetof(EX_TIMER, Period) == 0x74);
STATIC_ASSERT(offsetof(EX_TIMER, ApcAssociated) == 0x78);
STATIC_ASSERT(sizeof(EX_TIMER) == 0x80);

EXPORTNUM(12) DLLEXPORT VOID XBOXAPI ExAcquireReadWriteLockExclusive
(
	PERWLOCK ReadWriteLock
);

EXPORTNUM(13) DLLEXPORT VOID XBOXAPI ExAcquireReadWriteLockShared
(
	PERWLOCK ReadWriteLock
);

EXPORTNUM(14) DLLEXPORT PVOID XBOXAPI ExAllocatePool
(
	SIZE_T NumberOfBytes
);

EXPORTNUM(15) DLLEXPORT PVOID XBOXAPI ExAllocatePoolWithTag
(
	SIZE_T NumberOfBytes,
	ULONG Tag
);

EXPORTNUM(16) DLLEXPORT extern OBJECT_TYPE ExEventObjectType;

EXPORTNUM(17) DLLEXPORT VOID XBOXAPI ExFreePool
(
	PVOID P
);

EXPORTNUM(18) DLLEXPORT VOID XBOXAPI ExInitializeReadWriteLock
(
	PERWLOCK ReadWriteLock
);

EXPORTNUM(19) DLLEXPORT LARGE_INTEGER XBOXAPI ExInterlockedAddLargeInteger
(
	PLARGE_INTEGER Addend,
	LARGE_INTEGER Increment
);

EXPORTNUM(20) DLLEXPORT VOID FASTCALL ExInterlockedAddLargeStatistic
(
    PLARGE_INTEGER Addend,
    ULONG Increment
);

EXPORTNUM(21) DLLEXPORT LONGLONG FASTCALL ExInterlockedCompareExchange64
(
    LONGLONG volatile *Destination,
    PLONGLONG Exchange,
    PLONGLONG Comparand
);

EXPORTNUM(22) DLLEXPORT extern OBJECT_TYPE ExMutantObjectType;

EXPORTNUM(23) DLLEXPORT ULONG XBOXAPI ExQueryPoolBlockSize
(
	PVOID PoolBlock
);

EXPORTNUM(24) DLLEXPORT NTSTATUS XBOXAPI ExQueryNonVolatileSetting
(
	DWORD ValueIndex,
	DWORD *Type,
	PVOID Value,
	SIZE_T ValueLength,
	PSIZE_T ResultLength
);

EXPORTNUM(26) DLLEXPORT VOID XBOXAPI ExRaiseException
(
	PEXCEPTION_RECORD ExceptionRecord
);

EXPORTNUM(27) DLLEXPORT VOID XBOXAPI ExRaiseStatus
(
	NTSTATUS Status
);

EXPORTNUM(28) DLLEXPORT VOID XBOXAPI ExReleaseReadWriteLock
(
	PERWLOCK ReadWriteLock
);

EXPORTNUM(25) DLLEXPORT NTSTATUS XBOXAPI ExReadWriteRefurbInfo
(
	PXBOX_REFURB_INFO RefurbInfo,
	ULONG DataSize,
	BOOLEAN WriteOperation
);

EXPORTNUM(29) DLLEXPORT NTSTATUS XBOXAPI ExSaveNonVolatileSetting
(
	DWORD ValueIndex,
	DWORD Type,
	PVOID Value,
	SIZE_T ValueLength
);

EXPORTNUM(30) DLLEXPORT extern OBJECT_TYPE ExSemaphoreObjectType;

EXPORTNUM(31) DLLEXPORT extern OBJECT_TYPE ExTimerObjectType;

EXPORTNUM(32) DLLEXPORT PLIST_ENTRY FASTCALL ExfInterlockedInsertHeadList
(
    PLIST_ENTRY ListHead,
    PLIST_ENTRY ListEntry
);

EXPORTNUM(33) DLLEXPORT PLIST_ENTRY FASTCALL ExfInterlockedInsertTailList
(
    PLIST_ENTRY ListHead,
    PLIST_ENTRY ListEntry
);

EXPORTNUM(34) DLLEXPORT PLIST_ENTRY FASTCALL ExfInterlockedRemoveHeadList
(
    PLIST_ENTRY ListHead
);

EXPORTNUM(51) DLLEXPORT LONG FASTCALL InterlockedCompareExchange
(
	volatile PLONG Destination,
	LONG  Exchange,
	LONG  Comparand
);

EXPORTNUM(52) DLLEXPORT LONG FASTCALL InterlockedDecrement
(
	volatile PLONG Addend
);

EXPORTNUM(53) DLLEXPORT LONG FASTCALL InterlockedIncrement
(
	volatile PLONG Addend
);

EXPORTNUM(54) DLLEXPORT LONG FASTCALL InterlockedExchange
(
	volatile PLONG Destination,
	LONG Value
);

EXPORTNUM(55) DLLEXPORT LONG FASTCALL InterlockedExchangeAdd
(
	volatile PLONG Addend,
	LONG Increment
);

EXPORTNUM(56) DLLEXPORT PSINGLE_LIST_ENTRY FASTCALL InterlockedFlushSList
(
	PSLIST_HEADER ListHead
);

EXPORTNUM(57) DLLEXPORT PSINGLE_LIST_ENTRY FASTCALL InterlockedPopEntrySList
(
	PSLIST_HEADER ListHead
);

EXPORTNUM(58) DLLEXPORT PSINGLE_LIST_ENTRY FASTCALL InterlockedPushEntrySList
(
	PSLIST_HEADER ListHead,
	PSINGLE_LIST_ENTRY ListEntry
);

#ifdef __cplusplus
}
#endif
