#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

EXPORTNUM(35) DLLEXPORT ULONG XBOXAPI FscGetCacheSize();

EXPORTNUM(36) DLLEXPORT VOID XBOXAPI FscInvalidateIdleBlocks();

EXPORTNUM(37) DLLEXPORT NTSTATUS XBOXAPI FscSetCacheSize
(
	ULONG NumberOfCachePages
);

#ifdef __cplusplus
}
#endif
