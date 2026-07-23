#pragma once

#include "krnl/krnl.h"
#include "hal/pci.h"
#include "hal/pcicfg.h"
#include "ke/ke.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DISC_TRAY_STATE_CLOSED 	0
#define DISC_TRAY_STATE_ACTIVE 	(1u << 0)
#define DISC_TRAY_STATE_OPEN 	(1u << 4)
#define DISC_TRAY_STATE_UNK 	(1u << 5)
#define DISC_TRAY_STATE_OPENING	(3u << 4)
#define DISC_TRAY_STATE_EMPTY 	(1u << 6)
#define DISC_TRAY_STATE_CLOSING (5u << 4)
#define DISC_TRAY_STATE_UNK2 	(3u << 5)
#define DISC_TRAY_STATE_RESET 	(7u << 4)
#define DISC_TRAY_STATE_MASK 	(7u << 4)

typedef enum _FIRMWARE_REENTRY {
    HalHaltRoutine,
    HalRebootRoutine,
    HalQuickRebootRoutine,
    HalKdRebootRoutine,
    HalFatalErrorRebootRoutine,
    HalMaximumRoutine
} FIRMWARE_REENTRY;

typedef VOID(XBOXAPI *PHAL_SHUTDOWN_NOTIFICATION)(
	struct _HAL_SHUTDOWN_REGISTRATION *ShutdownRegistration
	);

typedef struct _HAL_SHUTDOWN_REGISTRATION {
	PHAL_SHUTDOWN_NOTIFICATION NotificationRoutine;
	LONG Priority;
	LIST_ENTRY ListEntry;
} HAL_SHUTDOWN_REGISTRATION, *PHAL_SHUTDOWN_REGISTRATION;

EXPORTNUM(9) DLLEXPORT NTSTATUS XBOXAPI HalReadSMCTrayState
(
    PULONG TrayState,
    PULONG TrayStateChangeCount
);

// Disassembly: _HalEnableTrayEjectRequiresReboot@4, called from XeLoadImage:0x8003f62a
BOOLEAN XBOXAPI HalEnableTrayEjectRequiresReboot(UCHAR Flags);

EXPORTNUM(38) DLLEXPORT VOID FASTCALL HalClearSoftwareInterrupt
(
    KIRQL RequestIrql
);

EXPORTNUM(39) DLLEXPORT VOID XBOXAPI HalDisableSystemInterrupt
(
    ULONG BusInterruptLevel
);

EXPORTNUM(40) DLLEXPORT extern ULONG HalDiskCachePartitionCount;

// Disassembly: _HalDiskModelNumber, 0x8005fc28, ordinal 41 — ANSI_STRING populated by IdexDiskCreate
EXPORTNUM(41) DLLEXPORT extern ANSI_STRING HalDiskModelNumber;

// Disassembly: _HalDiskSerialNumber, 0x8005fc08, ordinal 42 — ANSI_STRING populated by IdexDiskCreate
EXPORTNUM(42) DLLEXPORT extern ANSI_STRING HalDiskSerialNumber;

EXPORTNUM(43) DLLEXPORT VOID XBOXAPI HalEnableSystemInterrupt
(
	ULONG BusInterruptLevel,
	KINTERRUPT_MODE InterruptMode
);

EXPORTNUM(44) DLLEXPORT ULONG XBOXAPI HalGetInterruptVector
(
	ULONG BusInterruptLevel,
	PKIRQL Irql
);

EXPORTNUM(45) DLLEXPORT NTSTATUS XBOXAPI HalReadSMBusValue
(
	UCHAR SlaveAddress,
	UCHAR CommandCode,
	BOOLEAN ReadWordValue,
	ULONG *DataValue
);

EXPORTNUM(46) DLLEXPORT VOID XBOXAPI HalReadWritePCISpace
(
	ULONG BusNumber,
	ULONG SlotNumber,
	ULONG RegisterNumber,
	PVOID Buffer,
	ULONG Length,
	BOOLEAN WritePCISpace
);

EXPORTNUM(47) DLLEXPORT VOID XBOXAPI HalRegisterShutdownNotification
(
	PHAL_SHUTDOWN_REGISTRATION ShutdownRegistration,
	BOOLEAN Register
);

EXPORTNUM(48) DLLEXPORT VOID FASTCALL HalRequestSoftwareInterrupt
(
	KIRQL Request
);

[[noreturn]] EXPORTNUM(49) DLLEXPORT VOID XBOXAPI HalReturnToFirmware
(
    FIRMWARE_REENTRY Routine
);

EXPORTNUM(50) DLLEXPORT NTSTATUS XBOXAPI HalWriteSMBusValue
(
	UCHAR SlaveAddress,
	UCHAR CommandCode,
	BOOLEAN WriteWordValue,
	ULONG DataValue
);

EXPORTNUM(329) DLLEXPORT VOID XBOXAPI READ_PORT_BUFFER_UCHAR
(
    PUCHAR Port,
    PUCHAR Buffer,
    ULONG Count
);

EXPORTNUM(330) DLLEXPORT VOID XBOXAPI READ_PORT_BUFFER_USHORT
(
    PUSHORT Port,
    PUSHORT Buffer,
    ULONG Count
);

EXPORTNUM(331) DLLEXPORT VOID XBOXAPI READ_PORT_BUFFER_ULONG
(
    PULONG Port,
    PULONG Buffer,
    ULONG Count
);

EXPORTNUM(332) DLLEXPORT VOID XBOXAPI WRITE_PORT_BUFFER_UCHAR
(
    PUCHAR Port,
    PUCHAR Buffer,
    ULONG Count
);

EXPORTNUM(333) DLLEXPORT VOID XBOXAPI WRITE_PORT_BUFFER_USHORT
(
    PUSHORT Port,
    PUSHORT Buffer,
    ULONG Count
);

EXPORTNUM(334) DLLEXPORT VOID XBOXAPI WRITE_PORT_BUFFER_ULONG
(
    PULONG Port,
    PULONG Buffer,
    ULONG Count
);

EXPORTNUM(356) DLLEXPORT extern ULONG HalBootSMCVideoMode;

EXPORTNUM(358) DLLEXPORT BOOLEAN XBOXAPI HalIsResetOrShutdownPending();

EXPORTNUM(360) DLLEXPORT VOID XBOXAPI HalInitiateShutdown();

EXPORTNUM(365) DLLEXPORT VOID XBOXAPI HalEnableSecureTrayEject();

EXPORTNUM(366) DLLEXPORT NTSTATUS XBOXAPI HalWriteSMCScratchRegister
(
    ULONG ScratchRegister
);

#ifdef __cplusplus
}
#endif
