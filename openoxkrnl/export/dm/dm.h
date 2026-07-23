#pragma once

#include "krnl/krnl.h"
#include "ki/seh.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _DM_TELL_CODE {
    DmTellEnterDebugger = 1,
    DmTellPrepareReboot,
    DmTellMapDebugDrive,
    DmTellSetFrameCounter,
    DmTellSetPerfCounters,
    DmTellRegisterPerfCounter,
    DmTellUnregisterPerfCounter,
    DmTellSetDebugIp,
    DmTellGetDebugIp,
    DmTellInsertAllocEntry,
    DmTellRemoveAllocEntry,
    DmTellIsDebugging,
    DmTellAquireIp,
    DmTellSetStaticIpFlag,
    DmTellGetStaticIpFlag,
    DmTellSetStaticIpAddress,
    DmTellGetStaticIpAddress,
    DmTellSetStaticSubnet,
    DmTellGetStaticSubnet,
    DmTellSetStaticGateway,
    DmTellGetStaticGateway,
    DmTellGetActiveIp,
    DmTellGetActiveSubnet,
    DmTellGetActiveGateway,
    DmTellWipeConfig,
    DmTellGetModuleProcAddress,
    DmTellRequestHalt
} DM_TELL_CODE, *PDM_TELL_CODE;

typedef struct _XProfpGlobals {
    PULONG bufnext;
    PULONG bufend;
    PULONG bufnext_stopped;
    PULONG bufstart;
    ULONG start_type;
    ULONG start_param;
    LONG lock;
    LONG reserved;
} XProfpGlobals, *PXProfpGlobals;
STATIC_ASSERT(sizeof(XProfpGlobals) == 0x20, "XProfpGlobals size mismatch");

// #pragma pack(push, 1)
typedef struct _DMGD {
    PULONG FrameCounter;
    PULONG FlipCounter;
    struct _D3DSurface *Surface;
    PVOID *RegisterBase;
    PVOID PerfCounters;
    PULONG pdwOpcode;
    PUCHAR *ppSnapshotBuffer;
    PVOID D3DInternalsFunction;
    ULONG DMGDVersion;
} DMGD, *PDMGD;
STATIC_ASSERT(sizeof(DMGD) == 0x24);

typedef struct _DMXAPI {
    UCHAR XapiStarted;
    ULONG LastErrorTlsOff;
    ULONG CurrentFiberTlsOff;
} DMXAPI, *PDMXAPI;
STATIC_ASSERT(sizeof(DMXAPI) == 0xC);

typedef struct _DMDVD {
    ULARGE_INTEGER Timestamp;
    ULONG Parameters;
    ULONG ResponseTime;
} DMDVD, *PDMDVD;
STATIC_ASSERT(sizeof(DMDVD) == 0x10);

typedef struct _DMINIT {
    PKDEBUG_ROUTINE *DebugRoutine;
    PLIST_ENTRY LoaderModuleList;
    ULONG Flags;
    PVOID *ClockIntRoutine;
    PVOID *ProfIntRoutine;
    ULONG (*TellRoutine)(ULONG, PVOID);
    PVOID *CtxSwapRoutine;
    struct _XProfpGlobals *XProfpDataPtr;
    PDMGD D3DDriverData;
    PDMXAPI XapiData;
    PBOOLEAN DisallowXbdm;
    VOID (*HalStartProfileRoutine)(ULONG);
    VOID (*HalStopProfileRoutine)(ULONG);
    VOID (*HalProfileIntervalRoutine)(ULONG);
    PVOID *DpcDispatchNotifyRoutine;
    PDMDVD NextDVDSample;
} DMINIT, *PDMINIT;
STATIC_ASSERT(sizeof(DMINIT) == 0x40);
// #pragma pack(pop)

#ifdef __cplusplus
}
#endif
