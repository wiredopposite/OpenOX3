#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

// Disassembly: _PhyGetLinkState@4, 0x8003d73a
EXPORTNUM(252) DLLEXPORT ULONG XBOXAPI PhyGetLinkState(BOOL update);

// Disassembly: _PhyInitialize@8, 0x8003d574
EXPORTNUM(253) DLLEXPORT NTSTATUS XBOXAPI PhyInitialize(BOOL forceReset, PVOID param);

#ifdef __cplusplus
}
#endif
