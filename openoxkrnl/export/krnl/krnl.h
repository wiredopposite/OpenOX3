#pragma once

#include <stddef.h>
#include <stdarg.h>
#include <win32types/win32types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define XBOXAPI __stdcall

#ifndef EXPORTNUM
#define EXPORTNUM(n)
#endif

#ifndef DLLEXPORT
// #ifdef OPENOXKRNL
#define DLLEXPORT // __declspec(dllexport)
// #else
// #define DLLEXPORT __declspec(dllimport)
// #endif
#endif

#ifndef EXTERN
#define EXTERN extern
#endif

#ifdef __cplusplus
#define STATIC_ASSERT static_assert
#else
#define STATIC_ASSERT _Static_assert
#endif

// // #define ARRAYSIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// // We use i/o instructions to communicate with the host that's running us
// // The list of i/o ports used on the xbox is at https://xboxdevwiki.net/Memory, so avoid using one of those

// // Output debug strings to the host
// #define DBG_OUTPUT_STR_PORT 0x0200

// // Retail value is 0x3000 (12288) -- verified against xboxkrnl.exe (gap between
// // _KiIdleThreadStackLimit and _KiDoubleFaultStackLimit is exactly 0x3000).
// #define KERNEL_STACK_SIZE 12288
// #define KERNEL_BASE 0x80010000

// // Retail sets the idle thread's initial ESP to the literal true top of KiIdleThreadStack
// // (KernelEntry, retail 0x800f094a: MOV ESP, DAT_8004fb70) because retail's own xboxkrnl.exe is
// // itself an unoptimized debug build, so its call chain from KernelEntry down to
// // KeInitializeThread's self-bootstrap write (which constructs the idle thread's own
// // FX_SAVE_AREA + KSTART_FRAME + KSWITCHFRAME, 0x228 bytes, at KiIdleThreadStack top, working
// // downward, while still executing ON that same stack) always has far more than 0x228 bytes of
// // natural depth by that point -- there's no equivalent "retail Release kernel" to match here.
// // Measured directly (KLogDebug of ESP vs stack top immediately before the KeInitializeThread
// // call): a Release build of THIS kernel has only 0x14 bytes of headroom there, because the
// // optimizer collapses/inlines the same call chain retail's debug build leaves deep -- so that
// // self-bootstrap write clobbers this thread's own live return addresses and silently resets
// // (no crash log; the corrupted return address is usually the way back through KiSystemStartup
// // to KernelEntry). This reserve guarantees headroom regardless of optimization level. It only
// // affects the transient boot-time ESP; KiPcr.NtTib.StackBase/Thread->StackBase are still set to
// // the true, unmodified KiIdleThreadStack top elsewhere, matching retail's FX_SAVE_AREA addressing.
// #define KI_BOOT_STACK_RESERVE 0x800

// // Real retail mechanism (private/ntos/inc/ntosdef.h): marks a global as living in the "STICKY"
// // section instead of .data, so it survives a quick reboot's .data restore/clear untouched.
// // Confirmed via disassembly: MmRetailPfnRegion/MmAvailablePages/MmAllocatedPagesByUsage sit at
// // 0x80012f78-0x80012f88, ~12KB past image base -- consistent with a small, early, dedicated
// // section, not ordinary .data. Apply to the definition, e.g.: PERSIST_DATA static ULONG Foo;
// #pragma section("STICKY", read, write)
// #define PERSIST_DATA __declspec(allocate("STICKY"))

// #define LOWER_32(A) ((A) & 0xFFFFFFFF)
// #define UPPER_32(A) ((A) >> 32)

// // VOID InitializeListHead(PLIST_ENTRY pListHead);
// // BOOLEAN IsListEmpty(PLIST_ENTRY pListHead);
// // VOID InsertTailList(PLIST_ENTRY pListHead, PLIST_ENTRY pEntry);
// // VOID InsertHeadList(PLIST_ENTRY pListHead, PLIST_ENTRY pEntry);
// // VOID RemoveEntryList(PLIST_ENTRY pEntry);
// // PLIST_ENTRY RemoveTailList(PLIST_ENTRY pListHead);
// // PLIST_ENTRY RemoveHeadList(PLIST_ENTRY pListHead);



#ifdef __cplusplus
}
#endif
