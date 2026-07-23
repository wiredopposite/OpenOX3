/*
 * ergo720                Copyright (c) 2022
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// First bug code used in KeBugCheck(Ex)
#define INIT_FAILURE                      0
#define PDCLIB_ERROR                      1
#define IRQL_NOT_GREATER_OR_EQUAL         2
#define IRQL_NOT_LESS_OR_EQUAL            3
#define KERNEL_UNHANDLED_EXCEPTION        4
#define INVALID_CONTEXT                   5
#define UNHANDLED_NESTED_EXCEPTION        6
#define UNHANDLED_UNWIND_EXCEPTION        7
#define NORETURN_FUNCTION_RETURNED        8
#define XBE_LAUNCH_FAILED                 9
#define UNREACHABLE_CODE_REACHED          10
#define BAD_POOL_HEADER                   0x19
#define APC_IRQL_MISMATCH                 200
#define KERNEL_APC_PENDING_DURING_EXIT    32
#define MULTIPLE_IRP_COMPLETE_REQUESTS    68
#define NO_MORE_IRP_STACK_LOCATIONS       0x35
#define NO_PAGES_AVAILABLE                0x4D   // retail KiInitializeKernel 0x80026c46: DpcStack alloc failure
#define UNEXPECTED_KERNEL_MODE_TRAP       0x7F
#define KMODE_EXCEPTION_NOT_HANDLED       0x1E

// Optional bug codes used in following arguments in KeBugCheckEx
#define MM_FAILURE 0
#define OB_FAILURE 1
#define IO_FAILURE 2
#define PS_FAILURE 3
#define HAL_FAILURE 4

#ifdef __cplusplus
}
#endif
