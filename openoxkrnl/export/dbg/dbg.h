#pragma once

#include "krnl/krnl.h"
#include "kd/kd.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DBG_PROCESS_ID ((ULONG_PTR)~0UL)

EXPORTNUM(5) DLLEXPORT VOID XBOXAPI DbgBreakPoint();

EXPORTNUM(6) DLLEXPORT VOID XBOXAPI DbgBreakPointWithStatus
(
	ULONG Status
);

EXPORTNUM(7) DLLEXPORT VOID XBOXAPI DbgLoadImageSymbols
(
    PSTRING FileName,
    PVOID ImageBase,
    ULONG_PTR ProcessId
);

EXPORTNUM(11) DLLEXPORT VOID XBOXAPI DbgUnLoadImageSymbols
(
    PSTRING FileName,
    PVOID ImageBase,
    ULONG_PTR ProcessId
);

EXPORTNUM(12) ULONG XBOXAPI DbgPrompt
(
	PCHAR Prompt, 
	PCHAR Response, 
	ULONG MaximumResponseLength
);

EXPORTNUM(8) DLLEXPORT ULONG CDECL DbgPrint
(
	const CHAR *Format,
	...
);

#ifdef __cplusplus
}
#endif
