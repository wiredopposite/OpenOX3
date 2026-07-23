#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

// Disassembly: KD_MODULE_INFO passed to DbgLoadImageSymbols
typedef struct _KD_MODULE_INFO {
	PVOID DllBase;     // +0x00
	ULONG Unknown;     // +0x04 = 0xFFFFFFFF
	ULONG CheckSum;    // +0x08
	ULONG SizeOfImage; // +0x0C
} KD_MODULE_INFO, *PKD_MODULE_INFO;

EXPORTNUM(88) DLLEXPORT extern BOOLEAN KdDebuggerEnabled;

EXPORTNUM(89) DLLEXPORT extern BOOLEAN KdDebuggerNotPresent;

#ifdef __cplusplus
}
#endif