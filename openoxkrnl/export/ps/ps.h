#pragma once

#include "krnl/krnl.h"
#include "ke/ke.h"
#include "ob/ob.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef VOID(XBOXAPI *PCREATE_THREAD_NOTIFY_ROUTINE)(
	PETHREAD eThread,
	HANDLE ThreadId,
	BOOLEAN Create
);

typedef struct _PS_STATISTICS {
	ULONG Length;
	ULONG ThreadCount;
	ULONG HandleCount;
} PS_STATISTICS, *PPS_STATISTICS;

EXPORTNUM(254) DLLEXPORT NTSTATUS XBOXAPI PsCreateSystemThread
(
	PHANDLE ThreadHandle,
	PHANDLE ThreadId,
	PKSTART_ROUTINE StartRoutine,
	PVOID StartContext,
	BOOLEAN DebuggerThread
);

EXPORTNUM(255) DLLEXPORT NTSTATUS XBOXAPI PsCreateSystemThreadEx
(
	PHANDLE ThreadHandle,
	SIZE_T ThreadExtensionSize,
	SIZE_T KernelStackSize,
	SIZE_T TlsDataSize,
	PHANDLE ThreadId,
	PKSTART_ROUTINE StartRoutine,
	PVOID StartContext,
	BOOLEAN CreateSuspended,
	BOOLEAN DebuggerThread,
	PKSYSTEM_ROUTINE SystemRoutine
);

// Disassembly: _PsQueryStatistics@4, 0x8002e7af
EXPORTNUM(256) DLLEXPORT NTSTATUS XBOXAPI PsQueryStatistics
(
	PPS_STATISTICS Statistics
);

// Disassembly: _PsSetCreateThreadNotifyRoutine@4, 0x8002e501
EXPORTNUM(257) DLLEXPORT NTSTATUS XBOXAPI PsSetCreateThreadNotifyRoutine
(
	PCREATE_THREAD_NOTIFY_ROUTINE NotifyRoutine
);

EXPORTNUM(258) DLLEXPORT VOID XBOXAPI PsTerminateSystemThread
(
	NTSTATUS ExitStatus
);

EXPORTNUM(259) DLLEXPORT extern OBJECT_TYPE PsThreadObjectType;

#ifdef __cplusplus
}
#endif
