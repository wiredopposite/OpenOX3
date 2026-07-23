#pragma once

#include "krnl/krnl.h"
#include "ke/bugcodes.h"

#ifdef __cplusplus
extern "C" {
#endif

#define KE_SYSTEM_TYPE 0x0201
#define KE_ABORT 0x202
#define KE_CLOCK_INCREMENT_LOW 0x203
#define KE_CLOCK_INCREMENT_HIGH 0x204
#define KE_TIME_MS 0x205
#define KE_ACPI_TIME_LOW 0x20F
#define KE_ACPI_TIME_HIGH 0x210

#define THREAD_QUANTUM 60 // ms that a thread is allowed to run before being preempted, in multiples of CLOCK_QUANTUM_DECREMENT
#define CLOCK_QUANTUM_DECREMENT 3 // subtracts 1 ms after every clock interrupt, in multiples of CLOCK_QUANTUM_DECREMENT
#define WAIT_QUANTUM_DECREMENT 10 // disassembly uses add -0xA when accounting wait completion
#define NORMAL_BASE_PRIORITY 8
#define TIME_CRITICAL_BASE_PRIORITY 14
#define LOW_PRIORITY 0
#define LOW_REALTIME_PRIORITY 16
#define HIGH_PRIORITY 31
#define MAX_SUSPEND_COUNT 0x7f

#define PRIORITY_BOOST_EVENT 1
#define PRIORITY_BOOST_MUTANT 1
#define PRIORITY_BOOST_SEMAPHORE PRIORITY_BOOST_EVENT
#define PRIORITY_BOOST_IO 0
#define PRIORITY_BOOST_TIMER 0

#define HIGH_LEVEL 31
#define CLOCK_LEVEL 28
#define SYNC_LEVEL CLOCK_LEVEL
#define PROFILE_LEVEL 26
#define SCI_LEVEL 27
#define SMBUS_LEVEL 15
#define DISPATCH_LEVEL 2
#define APC_LEVEL 1
#define PASSIVE_LEVEL 0

#define IRQL_OFFSET_FOR_IRQ 4
#define DISPATCH_LENGTH 22

#define IDT_SERVICE_VECTOR_BASE 0x20
#define IDT_INT_VECTOR_BASE 0x30
#define MAX_BUS_INTERRUPT_LEVEL 26

#define SYNCHRONIZATION_OBJECT_TYPE_MASK 7

#define MUTANT_LIMIT 0x80000000

#define MAX_TIMER_DPCS 16

#define INITIALIZE_GLOBAL_KEVENT(Event, Type, State) \
    KEVENT Event = {                                 \
        Type,                                        \
        FALSE,                                       \
        sizeof(KEVENT) / sizeof(LONG),               \
        FALSE,                                       \
        State,                                       \
        &Event.Header.WaitListHead,                  \
        &Event.Header.WaitListHead                   \
    }

typedef UCHAR KIRQL;
typedef KIRQL *PKIRQL;
typedef CCHAR KPROCESSOR_MODE;

typedef enum _MODE {
	KernelMode,
	UserMode,
	MaximumMode
} MODE;

typedef enum _KOBJECTS {
	EventNotificationObject = 0,
	EventSynchronizationObject = 1,
	MutantObject = 2,
	ProcessObject = 3,
	QueueObject = 4,
	SemaphoreObject = 5,
	ThreadObject = 6,
	Spare1Object = 7,
	TimerNotificationObject = 8,
	TimerSynchronizationObject = 9,
	Spare2Object = 10,
	Spare3Object = 11,
	Spare4Object = 12,
	Spare5Object = 13,
	Spare6Object = 14,
	Spare7Object = 15,
	Spare8Object = 16,
	Spare9Object = 17,
	ApcObject,
	DpcObject,
	DeviceQueueObject,
	EventPairObject,
	InterruptObject,
	ProfileObject
} KOBJECTS;

typedef enum _TIMER_TYPE {
	NotificationTimer,
	SynchronizationTimer
} TIMER_TYPE;

typedef enum _WAIT_TYPE {
	WaitAll,
	WaitAny
} WAIT_TYPE;

typedef enum _KTHREAD_STATE {
	Initialized,
	Ready,
	Running,
	Standby,
	Terminated,
	Waiting,
	Transition
} KTHREAD_STATE;

typedef enum _KINTERRUPT_MODE {
	LevelSensitive,
	Edge
} KINTERRUPT_MODE;

typedef enum _KWAIT_REASON {
	Executive = 0,
	FreePage = 1,
	PageIn = 2,
	PoolAllocation = 3,
	DelayExecution = 4,
	Suspended = 5,
	UserRequest = 6,
	WrExecutive = 7,
	WrFreePage = 8,
	WrPageIn = 9,
	WrPoolAllocation = 10,
	WrDelayExecution = 11,
	WrSuspended = 12,
	WrUserRequest = 13,
	WrEventPair = 14,
	WrQueue = 15,
	WrLpcReceive = 16,
	WrLpcReply = 17,
	WrVirtualMemory = 18,
	WrPageOut = 19,
	WrRendezvous = 20,
	WrFsCacheIn = 21,
	WrFsCacheOut = 22,
	Spare4 = 23,
	Spare5 = 24,
	Spare6 = 25,
	WrKernel = 26,
	MaximumWaitReason = 27
} KWAIT_REASON;

typedef enum _EVENT_TYPE {
	NotificationEvent = 0,
	SynchronizationEvent
} EVENT_TYPE;

typedef struct _KAPC_STATE {
	LIST_ENTRY ApcListHead[MaximumMode];
	struct _KPROCESS *Process;
	BOOLEAN KernelApcInProgress;
	BOOLEAN KernelApcPending;
	BOOLEAN UserApcPending;
	BOOLEAN ApcQueueable;
} KAPC_STATE, *PKAPC_STATE;

typedef struct _KWAIT_BLOCK {
	LIST_ENTRY WaitListEntry;
	struct _KTHREAD *Thread;
	PVOID Object;
	struct _KWAIT_BLOCK *NextWaitBlock;
	USHORT WaitKey;
	USHORT WaitType;
} KWAIT_BLOCK, *PKWAIT_BLOCK;

typedef struct _KQUEUE {
	DISPATCHER_HEADER Header;
	LIST_ENTRY EntryListHead;
	ULONG CurrentCount;
	ULONG MaximumCount;
	LIST_ENTRY ThreadListHead;
} KQUEUE, *PKQUEUE;

typedef struct _KTIMER {
	DISPATCHER_HEADER Header;
	ULARGE_INTEGER DueTime;
	LIST_ENTRY TimerListEntry;
	struct _KDPC *Dpc;
	LONG Period;
} KTIMER, *PKTIMER;

typedef VOID(XBOXAPI *PKNORMAL_ROUTINE)(
	PVOID NormalContext,
	PVOID SystemArgument1,
	PVOID SystemArgument2
	);

typedef VOID(XBOXAPI *PKKERNEL_ROUTINE)(
	struct _KAPC *Apc,
	PKNORMAL_ROUTINE *NormalRoutine,
	PVOID *NormalContext,
	PVOID *SystemArgument1,
	PVOID *SystemArgument2
	);

typedef VOID(XBOXAPI *PKRUNDOWN_ROUTINE)(
	struct _KAPC *Apc
	);

typedef VOID(XBOXAPI *PKSTART_ROUTINE)(
	VOID *StartContext
	);

typedef VOID(XBOXAPI *PKSYSTEM_ROUTINE)(
	PKSTART_ROUTINE StartRoutine,
	VOID *StartContext
	);

typedef struct _KAPC {
	USHORT Type;
	UCHAR ApcMode;
	BOOLEAN Inserted;
	struct _KTHREAD *Thread;
	LIST_ENTRY ApcListEntry;
	PKKERNEL_ROUTINE KernelRoutine;
	PKRUNDOWN_ROUTINE RundownRoutine;
	PKNORMAL_ROUTINE NormalRoutine;
	PVOID NormalContext;
	PVOID SystemArgument1;
	PVOID SystemArgument2;
} KAPC, *PKAPC;

typedef struct _KSEMAPHORE {
	DISPATCHER_HEADER Header;
	LONG Limit;
} KSEMAPHORE, *PKSEMAPHORE;

typedef struct _KEVENT {
	DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT;

typedef struct _KDEVICE_QUEUE {
	CSHORT Type;
	UCHAR Size;
	BOOLEAN Busy;
	LIST_ENTRY DeviceListHead;
} KDEVICE_QUEUE, *PKDEVICE_QUEUE;

typedef struct _KDEVICE_QUEUE_ENTRY {
	LIST_ENTRY DeviceListEntry;
	ULONG SortKey;
	BOOLEAN Inserted;
} KDEVICE_QUEUE_ENTRY, *PKDEVICE_QUEUE_ENTRY;

typedef struct _KMUTANT {
	DISPATCHER_HEADER Header;
	LIST_ENTRY MutantListEntry;
	struct _KTHREAD *OwnerThread;
	BOOLEAN Abandoned;
} KMUTANT, *PKMUTANT;

typedef struct _KSTART_FRAME {
	PKSYSTEM_ROUTINE SystemRoutine;
	PKSTART_ROUTINE StartRoutine;
	PVOID StartContext;
} KSTART_FRAME, *PKSTART_FRAME;

typedef struct _KSWITCHFRAME {
	PVOID ExceptionList;
	DWORD Eflags;
	PVOID RetAddr;
} KSWITCHFRAME, *PKSWITCHFRAME;

typedef struct _KTHREAD {
	DISPATCHER_HEADER Header;
	LIST_ENTRY MutantListHead;
	ULONG KernelTime;
	PVOID StackBase; // not subtracted by sizeof(FX_SAVE_AREA) -> it points to the top of the stack
	PVOID StackLimit;
	PVOID KernelStack;
	PVOID TlsData;
	UCHAR State;
	BOOLEAN Alerted[MaximumMode];
	BOOLEAN Alertable;
	UCHAR NpxState;
	CHAR Saturation;
	SCHAR Priority;
	UCHAR Padding;
	KAPC_STATE ApcState;
	ULONG ContextSwitches;
	LONG_PTR WaitStatus;
	KIRQL WaitIrql;
	KPROCESSOR_MODE WaitMode;
	BOOLEAN WaitNext;
	UCHAR WaitReason;
	PKWAIT_BLOCK WaitBlockList;
	LIST_ENTRY WaitListEntry;
	ULONG WaitTime;
	ULONG KernelApcDisable;
	LONG Quantum;
	SCHAR BasePriority;
	UCHAR DecrementCount;
	SCHAR PriorityDecrement;
	BOOLEAN DisableBoost;
	UCHAR NpxIrql;
	CCHAR SuspendCount;
	BOOLEAN Preempted;
	BOOLEAN HasTerminated;
	PKQUEUE Queue;
	LIST_ENTRY QueueListEntry;
	KTIMER Timer;
	KWAIT_BLOCK TimerWaitBlock;
	KAPC SuspendApc;
	KSEMAPHORE SuspendSemaphore;
	LIST_ENTRY ThreadListEntry;
} KTHREAD, *PKTHREAD;

typedef struct _ETHREAD {
	KTHREAD Tcb;
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER ExitTime;
	NTSTATUS ExitStatus;
	union {
		LIST_ENTRY TimerList; // list of active timers to this thread
		LIST_ENTRY ReaperLink; // only used by PsTerminateSystemThread
	};
	HANDLE UniqueThread;
	PVOID StartAddress;
	LIST_ENTRY IrpList;
	PVOID DebugData;
} ETHREAD, *PETHREAD;
STATIC_ASSERT(sizeof(ETHREAD) == 0x140);

typedef struct _KPROCESS {
	LIST_ENTRY ReadyListHead;
	LIST_ENTRY ThreadListHead;
	ULONG StackCount;
	LONG ThreadQuantum;
	SCHAR BasePriority;
	BOOLEAN DisableBoost;
	BOOLEAN DisableQuantum;
} KPROCESS, *PKPROCESS;

typedef struct _KFLOATING_SAVE {
	UCHAR    Flags;
	UCHAR    CurrentIrql;
	UCHAR    OldNpxIrql;
	UCHAR    Reserved;
	ULONG    Reserved2;
	union {
		PVOID    NpxBuffer;
		USHORT   ControlWord;
	};
	ULONG    MXCsr;
	ULONG    Cr0NpxState;
	PKTHREAD Thread;
} KFLOATING_SAVE, *PKFLOATING_SAVE;

typedef VOID(XBOXAPI *PKDEFERRED_ROUTINE)(
	struct _KDPC *Dpc,
	PVOID DeferredContext,
	PVOID SystemArgument1,
	PVOID SystemArgument2
	);

typedef struct _KDPC {
	CSHORT Type;
	BOOLEAN Inserted;
	UCHAR Padding;
	LIST_ENTRY DpcListEntry;
	PKDEFERRED_ROUTINE DeferredRoutine;
	PVOID DeferredContext;
	PVOID SystemArgument1;
	PVOID SystemArgument2;
	// PULONG_PTR Lock;
} KDPC, *PKDPC;

typedef struct _KSYSTEM_TIME {
	ULONG LowTime;
	LONG HighTime;
	LONG High2Time;
} KSYSTEM_TIME, *PKSYSTEM_TIME;

typedef struct _DPC_QUEUE_ENTRY {
	PKDPC Dpc;
	PKDEFERRED_ROUTINE Routine;
	PVOID Context;
} DPC_QUEUE_ENTRY, *PDPC_QUEUE_ENTRY;

typedef BOOLEAN(XBOXAPI *PKSERVICE_ROUTINE)(
	struct _KINTERRUPT *Interrupt,
	PVOID ServiceContext
	);

typedef struct _KINTERRUPT {
	PKSERVICE_ROUTINE ServiceRoutine;
	PVOID ServiceContext;
	ULONG BusInterruptLevel;
	ULONG Irql;
	BOOLEAN Connected;
	BOOLEAN ShareVector;
	UCHAR Mode;
	ULONG ServiceCount;
	ULONG DispatchCode[DISPATCH_LENGTH];
} KINTERRUPT, *PKINTERRUPT;

typedef BOOLEAN(XBOXAPI *PKSYNCHRONIZE_ROUTINE)(
    PVOID SynchronizeContext
	);

STATIC_ASSERT(sizeof(KAPC) == 0x28);
STATIC_ASSERT(offsetof(KTHREAD, Timer) == 0x88);
STATIC_ASSERT(sizeof(KDPC) == 0x1c);
STATIC_ASSERT(sizeof(KFLOATING_SAVE) == 0x18);
STATIC_ASSERT(sizeof(KINTERRUPT) == 0x70);

#define SIZE_OF_FPU_REGISTERS 128

#pragma pack(1)
typedef struct _FLOATING_SAVE_AREA {
	USHORT  ControlWord;
	USHORT  StatusWord;
	USHORT  TagWord;
	USHORT  ErrorOpcode;
	ULONG   ErrorOffset;
	ULONG   ErrorSelector;
	ULONG   DataOffset;
	ULONG   DataSelector;
	ULONG   MXCsr;
	ULONG   Reserved1;
	UCHAR   RegisterArea[SIZE_OF_FPU_REGISTERS];
	UCHAR   XmmRegisterArea[SIZE_OF_FPU_REGISTERS];
	UCHAR   Reserved2[224];
	ULONG   Cr0NpxState;
} FLOATING_SAVE_AREA, *PFLOATING_SAVE_AREA;
#pragma pack()

/**
 * NOTE: if this is used with a fxsave instruction to save the 
 * float state, then this buffer must be 16-byte aligned.
 */
typedef struct _FX_SAVE_AREA {
	FLOATING_SAVE_AREA FloatSave;
	ULONG Align16Byte[3];
} FX_SAVE_AREA, *PFX_SAVE_AREA;

STATIC_ASSERT(offsetof(FLOATING_SAVE_AREA, ControlWord) == 0x00);
STATIC_ASSERT(offsetof(FLOATING_SAVE_AREA, StatusWord) == 0x02);
STATIC_ASSERT(offsetof(FLOATING_SAVE_AREA, MXCsr) == 0x18);
STATIC_ASSERT(offsetof(FLOATING_SAVE_AREA, Cr0NpxState) == 0x200);
STATIC_ASSERT(sizeof(FLOATING_SAVE_AREA) == 0x204);
STATIC_ASSERT(sizeof(FX_SAVE_AREA) == 0x210);

typedef struct _CONTEXT {
	DWORD ContextFlags;
	FLOATING_SAVE_AREA FloatSave;
	DWORD Edi;
	DWORD Esi;
	DWORD Ebx;
	DWORD Edx;
	DWORD Ecx;
	DWORD Eax;
	DWORD Ebp;
	DWORD Eip;
	DWORD SegCs;
	DWORD EFlags;
	DWORD Esp;
	DWORD SegSs;
} CONTEXT, *PCONTEXT;
STATIC_ASSERT(sizeof(CONTEXT) == 0x238);

typedef struct _KPRCB {
	struct _KTHREAD *CurrentThread;
	struct _KTHREAD *NextThread;
	struct _KTHREAD *IdleThread;
	struct _KTHREAD *NpxThread;
	ULONG InterruptCount;
	ULONG DpcTime;
	ULONG InterruptTime;
	ULONG DebugDpcTime;
	ULONG KeContextSwitches;
	ULONG DpcInterruptRequested;
	LIST_ENTRY DpcListHead;
	ULONG DpcRoutineActive;
	PVOID DpcStack;
	ULONG QuantumEnd;
	FX_SAVE_AREA NpxSaveArea;
	VOID *DmEnetFunc;
	VOID *DebugMonitorData;
	PVOID DebugHaltThread;
	PVOID DebugDoubleFault;
} KPRCB, *PKPRCB;
STATIC_ASSERT(sizeof(KPRCB) == 0x25c);

typedef struct _NT_TIB {
	struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
	PVOID StackBase; // already subtracted by sizeof(FX_SAVE_AREA)
	PVOID StackLimit;
	PVOID SubSystemTib;
	DWORD Version;
	PVOID ArbitraryUserPointer;
	struct _NT_TIB *Self;
} NT_TIB, *PNT_TIB;
STATIC_ASSERT(sizeof(NT_TIB) == 0x1c);

typedef struct _KPCR {
	NT_TIB NtTib;
	struct _KPCR *SelfPcr;
	KPRCB *Prcb;
	KIRQL Irql;
	KPRCB PrcbData;
} KPCR, *PKPCR;
STATIC_ASSERT(offsetof(KPCR, NtTib) == 0x00);
STATIC_ASSERT(offsetof(KPCR, SelfPcr) == 0x1C);
STATIC_ASSERT(offsetof(KPCR, Prcb) == 0x20);
STATIC_ASSERT(offsetof(KPCR, Irql) == 0x24);
STATIC_ASSERT(offsetof(KPCR, PrcbData) == 0x28);
STATIC_ASSERT(offsetof(KPCR, NtTib.ExceptionList) == 0x00);
STATIC_ASSERT(offsetof(KPCR, NtTib.StackBase) == 0x04);
STATIC_ASSERT(offsetof(KPCR, NtTib.StackLimit) == 0x08);
STATIC_ASSERT(offsetof(KPCR, NtTib.SubSystemTib) == 0x0C);
STATIC_ASSERT(offsetof(KPCR, NtTib.Version) == 0x10);
STATIC_ASSERT(offsetof(KPCR, NtTib.ArbitraryUserPointer) == 0x14);
STATIC_ASSERT(offsetof(KPCR, NtTib.Self) == 0x18);
STATIC_ASSERT(offsetof(KPCR, PrcbData.CurrentThread) == 0x28);
STATIC_ASSERT(offsetof(KPCR, PrcbData.NextThread) == 0x2C);
STATIC_ASSERT(offsetof(KPCR, PrcbData.IdleThread) == 0x30);
STATIC_ASSERT(offsetof(KPCR, PrcbData.NpxThread) == 0x34);
STATIC_ASSERT(offsetof(KPCR, PrcbData.DpcListHead) == 0x50);
STATIC_ASSERT(offsetof(KPCR, PrcbData.DpcRoutineActive) == 0x58);
STATIC_ASSERT(offsetof(KPCR, PrcbData.DebugHaltThread) == 0x27C);
STATIC_ASSERT(offsetof(KPCR, PrcbData.DebugDoubleFault) == 0x280);

typedef VOID(FASTCALL *PKDPC_DISPATCH_NOTIFY)(
    PKDEFERRED_ROUTINE DeferredRoutine, 
    ULONG Phase);

EXPORTNUM(92) DLLEXPORT ULONG XBOXAPI KeAlertResumeThread
(
    PKTHREAD Thread
);

EXPORTNUM(93) DLLEXPORT BOOLEAN XBOXAPI KeAlertThread
(
    PKTHREAD Thread,
    KPROCESSOR_MODE ProcessorMode
);

EXPORTNUM(94) DLLEXPORT VOID XBOXAPI KeBoostPriorityThread
(
    PKTHREAD Thread,
    KPRIORITY Increment
);

[[noreturn]] EXPORTNUM(95) DLLEXPORT VOID XBOXAPI KeBugCheck
(
	ULONG BugCheckCode
);

[[noreturn]] EXPORTNUM(96) DLLEXPORT VOID XBOXAPI KeBugCheckEx
(
	ULONG BugCheckCode,
	ULONG_PTR BugCheckParameter1,
	ULONG_PTR BugCheckParameter2,
	ULONG_PTR BugCheckParameter3,
	ULONG_PTR BugCheckParameter4
);

EXPORTNUM(97) DLLEXPORT BOOLEAN XBOXAPI KeCancelTimer
(
    PKTIMER Timer
);

EXPORTNUM(98) DLLEXPORT BOOLEAN XBOXAPI KeConnectInterrupt
(
	PKINTERRUPT  InterruptObject
);

EXPORTNUM(99) DLLEXPORT NTSTATUS XBOXAPI KeDelayExecutionThread
(
	KPROCESSOR_MODE WaitMode,
	BOOLEAN Alertable,
	PLARGE_INTEGER Interval
);

EXPORTNUM(100) DLLEXPORT BOOLEAN XBOXAPI KeDisconnectInterrupt
(
    PKINTERRUPT Interrupt
);

EXPORTNUM(101) DLLEXPORT VOID XBOXAPI KeEnterCriticalRegion();

EXPORTNUM(103) DLLEXPORT KIRQL XBOXAPI KeGetCurrentIrql();

EXPORTNUM(104) DLLEXPORT PKTHREAD XBOXAPI KeGetCurrentThread();

EXPORTNUM(105) DLLEXPORT VOID XBOXAPI KeInitializeApc
(
	PKAPC Apc,
	PKTHREAD Thread,
	PKKERNEL_ROUTINE KernelRoutine,
	PKRUNDOWN_ROUTINE RundownRoutine,
	PKNORMAL_ROUTINE NormalRoutine,
	KPROCESSOR_MODE ApcMode,
	PVOID NormalContext
);

EXPORTNUM(106) DLLEXPORT VOID XBOXAPI KeInitializeDeviceQueue
(
	PKDEVICE_QUEUE DeviceQueue
);

EXPORTNUM(107) DLLEXPORT VOID XBOXAPI KeInitializeDpc
(
	PKDPC Dpc,
	PKDEFERRED_ROUTINE DeferredRoutine,
	PVOID DeferredContext
);

EXPORTNUM(108) DLLEXPORT VOID XBOXAPI KeInitializeEvent
(
	PKEVENT Event,
	EVENT_TYPE Type,
	BOOLEAN SignalState
);

EXPORTNUM(109) DLLEXPORT VOID XBOXAPI KeInitializeInterrupt
(
	PKINTERRUPT Interrupt,
	PKSERVICE_ROUTINE ServiceRoutine,
	PVOID ServiceContext,
	ULONG Vector,
	KIRQL Irql,
	KINTERRUPT_MODE InterruptMode,
	BOOLEAN ShareVector
);

EXPORTNUM(110) DLLEXPORT VOID XBOXAPI KeInitializeMutant
(
	PKMUTANT Mutant,
	BOOLEAN InitialOwner
);

EXPORTNUM(111) DLLEXPORT VOID XBOXAPI KeInitializeQueue
(
    PKQUEUE Queue,
    ULONG Count
);

EXPORTNUM(112) DLLEXPORT VOID XBOXAPI KeInitializeSemaphore
(
	PKSEMAPHORE Semaphore,
	LONG Count,
	LONG Limit
);

EXPORTNUM(113) DLLEXPORT VOID XBOXAPI KeInitializeTimerEx
(
	PKTIMER Timer,
	TIMER_TYPE Type
);

EXPORTNUM(114) DLLEXPORT BOOLEAN XBOXAPI KeInsertByKeyDeviceQueue
(
    PKDEVICE_QUEUE DeviceQueue,
    PKDEVICE_QUEUE_ENTRY DeviceQueueEntry,
    ULONG SortKey
);

EXPORTNUM(115) DLLEXPORT BOOLEAN XBOXAPI KeInsertDeviceQueue
(
    PKDEVICE_QUEUE DeviceQueue,
    PKDEVICE_QUEUE_ENTRY DeviceQueueEntry
);

EXPORTNUM(116) DLLEXPORT LONG XBOXAPI KeInsertHeadQueue
(
    PKQUEUE Queue,
    PLIST_ENTRY Entry
);

EXPORTNUM(117) DLLEXPORT LONG XBOXAPI KeInsertQueue
(
    PKQUEUE Queue,
    PLIST_ENTRY Entry
);

EXPORTNUM(118) DLLEXPORT BOOLEAN XBOXAPI KeInsertQueueApc
(
	PKAPC Apc,
	PVOID SystemArgument1,
	PVOID SystemArgument2,
	KPRIORITY Increment
);

EXPORTNUM(119) DLLEXPORT BOOLEAN XBOXAPI KeInsertQueueDpc
(
	PKDPC Dpc,
	PVOID SystemArgument1,
	PVOID SystemArgument2
);

EXPORTNUM(120) DLLEXPORT extern volatile KSYSTEM_TIME KeInterruptTime;

EXPORTNUM(121) DLLEXPORT BOOLEAN XBOXAPI KeIsExecutingDpc();

EXPORTNUM(122) DLLEXPORT VOID XBOXAPI KeLeaveCriticalRegion();

EXPORTNUM(123) DLLEXPORT LONG XBOXAPI KePulseEvent
(
    PKEVENT Event,
    KPRIORITY Increment,
    BOOLEAN Wait
);

EXPORTNUM(124) DLLEXPORT LONG XBOXAPI KeQueryBasePriorityThread
(
    PKTHREAD Thread
);

EXPORTNUM(125) DLLEXPORT ULONGLONG XBOXAPI KeQueryInterruptTime();

EXPORTNUM(126) DLLEXPORT ULONGLONG XBOXAPI KeQueryPerformanceCounter();

EXPORTNUM(127) DLLEXPORT ULONGLONG XBOXAPI KeQueryPerformanceFrequency();

EXPORTNUM(128) DLLEXPORT VOID XBOXAPI KeQuerySystemTime
(
	PLARGE_INTEGER CurrentTime
);

EXPORTNUM(129) DLLEXPORT KIRQL XBOXAPI KeRaiseIrqlToDpcLevel();

EXPORTNUM(130) DLLEXPORT KIRQL XBOXAPI KeRaiseIrqlToSynchLevel();

EXPORTNUM(131) DLLEXPORT LONG XBOXAPI KeReleaseMutant
(
	PKMUTANT Mutant,
	KPRIORITY Increment,
	BOOLEAN Abandoned,
	BOOLEAN Wait
);

EXPORTNUM(132) DLLEXPORT LONG XBOXAPI KeReleaseSemaphore
(
	PKSEMAPHORE Semaphore,
	KPRIORITY Increment,
	LONG Adjustment,
	BOOLEAN Wait
);

EXPORTNUM(133) DLLEXPORT PKDEVICE_QUEUE_ENTRY XBOXAPI KeRemoveByKeyDeviceQueue
(
    PKDEVICE_QUEUE DeviceQueue,
    ULONG SortKey
);

EXPORTNUM(134) DLLEXPORT PKDEVICE_QUEUE_ENTRY XBOXAPI KeRemoveDeviceQueue
(
    PKDEVICE_QUEUE DeviceQueue
);

EXPORTNUM(135) DLLEXPORT BOOLEAN XBOXAPI KeRemoveEntryDeviceQueue
(
    PKDEVICE_QUEUE DeviceQueue,
    PKDEVICE_QUEUE_ENTRY DeviceQueueEntry
);

EXPORTNUM(136) DLLEXPORT PLIST_ENTRY XBOXAPI KeRemoveQueue
(
    PKQUEUE Queue,
    KPROCESSOR_MODE WaitMode,
    PLARGE_INTEGER Timeout
);

EXPORTNUM(137) DLLEXPORT BOOLEAN XBOXAPI KeRemoveQueueDpc
(
    PKDPC Dpc
);

EXPORTNUM(138) DLLEXPORT LONG XBOXAPI KeResetEvent
(
    PKEVENT Event
);

EXPORTNUM(139) DLLEXPORT NTSTATUS XBOXAPI KeRestoreFloatingPointState
(
	PKFLOATING_SAVE FloatSave
);

EXPORTNUM(140) DLLEXPORT ULONG XBOXAPI KeResumeThread
(
	PKTHREAD Thread
);

EXPORTNUM(141) DLLEXPORT PLIST_ENTRY XBOXAPI KeRundownQueue
(
    PKQUEUE Queue
);

EXPORTNUM(142) DLLEXPORT NTSTATUS XBOXAPI KeSaveFloatingPointState
(
	PKFLOATING_SAVE FloatSave
);

EXPORTNUM(143) DLLEXPORT LONG XBOXAPI KeSetBasePriorityThread
(
	PKTHREAD Thread,
	LONG Increment
);

EXPORTNUM(144) DLLEXPORT LOGICAL XBOXAPI KeSetDisableBoostThread
(
    PKTHREAD Thread,
    LOGICAL Disable
);

EXPORTNUM(145) DLLEXPORT LONG XBOXAPI KeSetEvent
(
	PKEVENT Event,
	KPRIORITY Increment,
	BOOLEAN	Wait
);

EXPORTNUM(146) DLLEXPORT VOID XBOXAPI KeSetEventBoostPriority
(
    PKEVENT Event,
    PKTHREAD *Thread
);

EXPORTNUM(147) DLLEXPORT LONG XBOXAPI KeSetPriorityProcess
(
	PKPROCESS Process,
	LONG NewBasePriority
);

EXPORTNUM(148) DLLEXPORT KPRIORITY XBOXAPI KeSetPriorityThread
(
	PKTHREAD Thread,
	LONG Priority
);

EXPORTNUM(149) DLLEXPORT BOOLEAN XBOXAPI KeSetTimer
(
	PKTIMER Timer,
	LARGE_INTEGER DueTime,
	PKDPC Dpc
);

EXPORTNUM(150) DLLEXPORT BOOLEAN XBOXAPI KeSetTimerEx
(
	PKTIMER Timer,
	LARGE_INTEGER DueTime,
	LONG Period,
	PKDPC Dpc
);

EXPORTNUM(151) DLLEXPORT VOID XBOXAPI KeStallExecutionProcessor
(
	ULONG MicroSeconds
);

EXPORTNUM(152) DLLEXPORT ULONG XBOXAPI KeSuspendThread
(
	PKTHREAD Thread
);

EXPORTNUM(153) DLLEXPORT BOOLEAN XBOXAPI KeSynchronizeExecution
(
    PKINTERRUPT Interrupt,
    PKSYNCHRONIZE_ROUTINE SynchronizeRoutine,
    PVOID SynchronizeContext
);

EXPORTNUM(154) DLLEXPORT extern volatile KSYSTEM_TIME KeSystemTime;

EXPORTNUM(155) DLLEXPORT BOOLEAN XBOXAPI KeTestAlertThread
(
	KPROCESSOR_MODE AlertMode
);

EXPORTNUM(156) DLLEXPORT extern volatile DWORD KeTickCount;

EXPORTNUM(157) DLLEXPORT extern ULONG KeTimeIncrement;

EXPORTNUM(158) DLLEXPORT NTSTATUS XBOXAPI KeWaitForMultipleObjects
(
    ULONG Count,
    PVOID Object[],
    WAIT_TYPE WaitType,
    KWAIT_REASON WaitReason,
    KPROCESSOR_MODE WaitMode,
    BOOLEAN Alertable,
    PLARGE_INTEGER Timeout,
    PKWAIT_BLOCK WaitBlockArray
);

EXPORTNUM(159) DLLEXPORT NTSTATUS XBOXAPI KeWaitForSingleObject
(
	PVOID Object,
	KWAIT_REASON WaitReason,
	KPROCESSOR_MODE WaitMode,
	BOOLEAN Alertable,
	PLARGE_INTEGER Timeout
);

EXPORTNUM(160) DLLEXPORT KIRQL FASTCALL KfRaiseIrql
(
	KIRQL NewIrql
);

EXPORTNUM(161) DLLEXPORT VOID FASTCALL KfLowerIrql
(
	KIRQL NewIrql
);

EXPORTNUM(162) DLLEXPORT extern ULONG_PTR KiBugCheckData[5];

EXPORTNUM(163) DLLEXPORT VOID FASTCALL KiUnlockDispatcherDatabase
(
	KIRQL NewIrql
);

#ifdef __cplusplus
}
#endif
