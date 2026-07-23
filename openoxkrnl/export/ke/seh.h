#pragma once

#include "krnl/krnl.h"
#include "ke/ke.h"

#ifdef __cplusplus
extern "C" {
#endif

#define EXCEPTION_NONCONTINUABLE  0x01
#define EXCEPTION_UNWINDING       0x02
#define EXCEPTION_EXIT_UNWIND     0x04
#define EXCEPTION_STACK_INVALID   0x08
#define EXCEPTION_NESTED_CALL     0x10
#define EXCEPTION_TARGET_UNWIND   0x20
#define EXCEPTION_COLLIDED_UNWIND 0x40
#define EXCEPTION_UNWIND (EXCEPTION_UNWINDING | EXCEPTION_EXIT_UNWIND | EXCEPTION_TARGET_UNWIND | EXCEPTION_COLLIDED_UNWIND)
#define EXCEPTION_MAXIMUM_PARAMETERS 15
#define TRYLEVEL_NONE -1

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_SEARCH 0
#define EXCEPTION_CONTINUE_EXECUTION (-1)

typedef enum _EXCEPTION_DISPOSITION {
	ExceptionContinueExecution = 0,
	ExceptionContinueSearch = 1,
	ExceptionNestedException = 2,
	ExceptionCollidedUnwind = 3,
} EXCEPTION_DISPOSITION;

typedef struct _EXCEPTION_REGISTRATION_RECORD {
	struct _EXCEPTION_REGISTRATION_RECORD *Prev;
	PVOID Handler;
} EXCEPTION_REGISTRATION_RECORD, *PEXCEPTION_REGISTRATION_RECORD;

typedef struct _EXCEPTION_RECORD {
	NTSTATUS ExceptionCode;
	ULONG ExceptionFlags;
	struct _EXCEPTION_RECORD *ExceptionRecord;
	PVOID ExceptionAddress;
	ULONG NumberParameters;
	ULONG_PTR ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
} EXCEPTION_RECORD, *PEXCEPTION_RECORD;

typedef struct _EXCEPTION_POINTERS {
	PEXCEPTION_RECORD ExceptionRecord;
	PCONTEXT ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;

#pragma pack(1)
typedef struct _KTRAP_FRAME {
	ULONG DbgEbp;
	ULONG DbgEip;
	ULONG DbgArgMark;
	ULONG DbgArgPointer;
	ULONG TempSegCs;
	ULONG TempEsp;
	ULONG Edx;
	ULONG Ecx;
	ULONG Eax;
	PEXCEPTION_REGISTRATION_RECORD ExceptionList;
	ULONG Edi;
	ULONG Esi;
	ULONG Ebx;
	ULONG Ebp;
	ULONG ErrCode;
	ULONG Eip;
	ULONG SegCs;
	ULONG EFlags;
} KTRAP_FRAME, *PKTRAP_FRAME;
#pragma pack()

STATIC_ASSERT(offsetof(KTRAP_FRAME, DbgEbp) == 0x00);
STATIC_ASSERT(offsetof(KTRAP_FRAME, DbgEip) == 0x04);
STATIC_ASSERT(offsetof(KTRAP_FRAME, DbgArgMark) == 0x08);
STATIC_ASSERT(offsetof(KTRAP_FRAME, DbgArgPointer) == 0x0C);
STATIC_ASSERT(offsetof(KTRAP_FRAME, TempSegCs) == 0x10);
STATIC_ASSERT(offsetof(KTRAP_FRAME, TempEsp) == 0x14);
STATIC_ASSERT(offsetof(KTRAP_FRAME, Edx) == 0x18);
STATIC_ASSERT(offsetof(KTRAP_FRAME, Ecx) == 0x1C);
STATIC_ASSERT(offsetof(KTRAP_FRAME, Eax) == 0x20);
STATIC_ASSERT(offsetof(KTRAP_FRAME, ExceptionList) == 0x24);
STATIC_ASSERT(offsetof(KTRAP_FRAME, Edi) == 0x28);
STATIC_ASSERT(offsetof(KTRAP_FRAME, Esi) == 0x2C);
STATIC_ASSERT(offsetof(KTRAP_FRAME, Ebx) == 0x30);
STATIC_ASSERT(offsetof(KTRAP_FRAME, Ebp) == 0x34);
STATIC_ASSERT(offsetof(KTRAP_FRAME, ErrCode) == 0x38);
STATIC_ASSERT(offsetof(KTRAP_FRAME, Eip) == 0x3C);
STATIC_ASSERT(offsetof(KTRAP_FRAME, SegCs) == 0x40);
STATIC_ASSERT(offsetof(KTRAP_FRAME, EFlags) == 0x44);
STATIC_ASSERT(sizeof(KTRAP_FRAME) == 0x48);

typedef EXCEPTION_DISPOSITION(CDECL *PEXCEPTION_ROUTINE)(
    EXCEPTION_RECORD *, 
    EXCEPTION_REGISTRATION_RECORD *,
	CONTEXT *, 
    EXCEPTION_REGISTRATION_RECORD **);

// Disassembly: _KdpStub@20/_KdpTrap@20 -- the @20 decoration confirms __stdcall (5 DWORD
// args, callee cleans the stack). KiDebugRoutine can point to externally-compiled code
// (e.g. xbdm.dll installing its own routine), so this must match the real ABI exactly --
// a plain __cdecl call here double-pops the stack against a __stdcall callee's own `ret 20`.
typedef BOOLEAN(XBOXAPI *PKDEBUG_ROUTINE)(
	PKTRAP_FRAME TrapFrame,
	PVOID ExceptionFrame,
	PEXCEPTION_RECORD ExRecord,
	PCONTEXT Context,
	BOOLEAN FirstChance);

#ifdef __cplusplus
}
#endif
