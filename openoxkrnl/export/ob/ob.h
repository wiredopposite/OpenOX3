#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

// Object attributes specified in OBJECT_ATTRIBUTES
#define OBJ_PERMANENT         0x00000010L
#define OBJ_EXCLUSIVE         0x00000020L
#define OBJ_CASE_INSENSITIVE  0x00000040L
#define OBJ_OPENIF            0x00000080L

// Object flags specified in OBJECT_HEADER
#define OB_FLAG_NAMED_OBJECT      0x01
#define OB_FLAG_PERMANENT_OBJECT  0x02
#define OB_FLAG_ATTACHED_OBJECT   0x04

#define OB_HANDLES_PER_TABLE_SHIFT   6
#define OB_HANDLES_PER_TABLE         (1 << OB_HANDLES_PER_TABLE_SHIFT) // 64
#define OB_BYTES_PER_TABLE           (OB_HANDLES_PER_TABLE * sizeof(HANDLE)) // 256
#define OB_TABLES_PER_SEGMENT        8
#define OB_HANDLES_PER_SEGMENT       (OB_TABLES_PER_SEGMENT * OB_HANDLES_PER_TABLE) // 512

#define NULL_HANDLE ((HANDLE)(ULONG_PTR)0)
#define NtCurrentThread() ((HANDLE)-2)
#define ObDosDevicesDirectory() ((HANDLE)-3)
#define ObWin32NamedObjectsDirectory() ((HANDLE)-4)

#define OB_NUMBER_HASH_BUCKETS 11

#define OB_PATH_DELIMITER '\\'

typedef struct _OBJECT_HANDLE_TABLE {
	LONG HandleCount;
	LONG_PTR FirstFreeTableEntry;
	HANDLE NextHandleNeedingPool;
	PVOID **RootTable;
	PVOID *BuiltinRootTable[OB_TABLES_PER_SEGMENT];
} OBJECT_HANDLE_TABLE, *POBJECT_HANDLE_TABLE;

typedef STRING OBJECT_STRING;
typedef OBJECT_STRING *POBJECT_STRING;

typedef PVOID(XBOXAPI *OB_ALLOCATE_METHOD)(
    SIZE_T NumberOfBytes,
    ULONG Tag
    );

typedef VOID(XBOXAPI *OB_FREE_METHOD)(
	PVOID Pointer
	);

typedef VOID(XBOXAPI *OB_CLOSE_METHOD)(
	PVOID Object,
	ULONG SystemHandleCount
	);

typedef VOID(XBOXAPI *OB_DELETE_METHOD)(
	PVOID Object
	);

typedef NTSTATUS(XBOXAPI *OB_PARSE_METHOD)(
	PVOID ParseObject,
	struct _OBJECT_TYPE *ObjectType,
	ULONG Attributes,
	POBJECT_STRING CompleteName,
	POBJECT_STRING RemainingName,
	PVOID Context,
	PVOID *Object
	);

typedef struct _OBJECT_TYPE {
	OB_ALLOCATE_METHOD AllocateProcedure;
	OB_FREE_METHOD FreeProcedure;
	OB_CLOSE_METHOD CloseProcedure;
	OB_DELETE_METHOD DeleteProcedure;
	OB_PARSE_METHOD ParseProcedure;
	PVOID DefaultObject;
	ULONG PoolTag;
} OBJECT_TYPE, *POBJECT_TYPE;

typedef struct _OBJECT_ATTRIBUTES {
	HANDLE RootDirectory;
	PSTRING ObjectName;
	ULONG Attributes;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef struct _OBJECT_HEADER {
	LONG PointerCount;
	LONG HandleCount;
	POBJECT_TYPE Type;
	ULONG Flags;
	QUAD Body;
} OBJECT_HEADER, *POBJECT_HEADER;

typedef struct _OBJECT_DIRECTORY {
	struct _OBJECT_HEADER_NAME_INFO *HashBuckets[OB_NUMBER_HASH_BUCKETS];
} OBJECT_DIRECTORY, *POBJECT_DIRECTORY;

typedef struct _OBJECT_SYMBOLIC_LINK {
	PVOID LinkTargetObject;
	OBJECT_STRING LinkTarget;
} OBJECT_SYMBOLIC_LINK, *POBJECT_SYMBOLIC_LINK;

typedef struct _OBJECT_HEADER_NAME_INFO {
	struct _OBJECT_HEADER_NAME_INFO *ChainLink;
	struct _OBJECT_DIRECTORY *Directory;
	OBJECT_STRING Name;
} OBJECT_HEADER_NAME_INFO, *POBJECT_HEADER_NAME_INFO;

EXPORTNUM(239) DLLEXPORT NTSTATUS XBOXAPI ObCreateObject
(
	POBJECT_TYPE ObjectType,
	POBJECT_ATTRIBUTES ObjectAttributes,
	ULONG ObjectBodySize,
	PVOID *Object
);

EXPORTNUM(240) DLLEXPORT extern OBJECT_TYPE ObDirectoryObjectType;

EXPORTNUM(241) DLLEXPORT NTSTATUS XBOXAPI ObInsertObject
(
	PVOID Object,
	POBJECT_ATTRIBUTES ObjectAttributes,
	ULONG ObjectPointerBias,
	PHANDLE ReturnedHandle
);

EXPORTNUM(242) DLLEXPORT VOID XBOXAPI ObMakeTemporaryObject
(
	PVOID Object
);

EXPORTNUM(243) DLLEXPORT NTSTATUS XBOXAPI ObOpenObjectByName
(
	POBJECT_ATTRIBUTES ObjectAttributes,
	POBJECT_TYPE ObjectType,
	PVOID ParseContext,
	PHANDLE Handle
);

EXPORTNUM(244) DLLEXPORT NTSTATUS XBOXAPI ObOpenObjectByPointer
(
	PVOID Object,
	POBJECT_TYPE ObjectType,
	PHANDLE ReturnedHandle
);

EXPORTNUM(245) DLLEXPORT extern OBJECT_HANDLE_TABLE ObpObjectHandleTable;

EXPORTNUM(246) DLLEXPORT NTSTATUS XBOXAPI ObReferenceObjectByHandle
(
	HANDLE Handle,
	POBJECT_TYPE ObjectType,
	PVOID *ReturnedObject
);

EXPORTNUM(247) DLLEXPORT NTSTATUS XBOXAPI ObReferenceObjectByName
(
	POBJECT_STRING ObjectName,
	ULONG Attributes,
	POBJECT_TYPE ObjectType,
	PVOID ParseContext,
	PVOID *Object
);

EXPORTNUM(248) DLLEXPORT NTSTATUS XBOXAPI ObReferenceObjectByPointer
(
	PVOID Object,
	POBJECT_TYPE ObjectType
);

EXPORTNUM(249) DLLEXPORT extern OBJECT_TYPE ObSymbolicLinkObjectType;

EXPORTNUM(250) DLLEXPORT VOID FASTCALL ObfDereferenceObject
(
	PVOID Object
);

EXPORTNUM(251) DLLEXPORT VOID FASTCALL ObfReferenceObject
(
	PVOID Object
);

#ifdef __cplusplus
}
#endif
