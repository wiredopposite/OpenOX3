#pragma once

#include "krnl/krnl.h"
#include "ob/ob.h"
#include "ke/ke.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IO_CHECK_CREATE_PARAMETERS 0x0200

#define ACCESS_SYSTEM_SECURITY 0x01000000L

#define FILE_VALID_OPTION_FLAGS 0x00ffffff

#define FILE_DIRECTORY_FILE             0x00000001
#define FILE_WRITE_THROUGH              0x00000002
#define FILE_SEQUENTIAL_ONLY            0x00000004
#define FILE_NO_INTERMEDIATE_BUFFERING  0x00000008
#define FILE_SYNCHRONOUS_IO_ALERT       0x00000010
#define FILE_SYNCHRONOUS_IO_NONALERT    0x00000020
#define FILE_NON_DIRECTORY_FILE         0x00000040
#define FILE_CREATE_TREE_CONNECTION     0x00000080
#define FILE_COMPLETE_IF_OPLOCKED       0x00000100
#define FILE_NO_EA_KNOWLEDGE            0x00000200
#define FILE_OPEN_FOR_RECOVERY          0x00000400
#define FILE_RANDOM_ACCESS              0x00000800
#define FILE_DELETE_ON_CLOSE            0x00001000
#define FILE_OPEN_BY_FILE_ID            0x00002000
#define FILE_OPEN_FOR_BACKUP_INTENT     0x00004000
#define FILE_NO_COMPRESSION             0x00008000
#define FILE_RESERVE_OPFILTER           0x00100000
#define FILE_OPEN_REPARSE_POINT         0x00200000
#define FILE_OPEN_NO_RECALL             0x00400000
#define FILE_OPEN_FOR_FREE_SPACE_QUERY  0x00800000

#define FILE_SHARE_READ         0x00000001
#define FILE_SHARE_WRITE        0x00000002
#define FILE_SHARE_DELETE       0x00000004
#define FILE_SHARE_VALID_FLAGS  0x00000007

#define DELETE        0x00010000L
#define READ_CONTROL  0x00020000L
#define WRITE_DAC     0x00040000L
#define WRITE_OWNER   0x00080000L
#define SYNCHRONIZE   0x00100000L

#define FILE_SUPERSEDE            0x00000000
#define FILE_OPEN                 0x00000001
#define FILE_CREATE               0x00000002
#define FILE_OPEN_IF              0x00000003
#define FILE_OVERWRITE            0x00000004
#define FILE_OVERWRITE_IF         0x00000005
#define FILE_MAXIMUM_DISPOSITION  FILE_OVERWRITE_IF

#define STANDARD_RIGHTS_REQUIRED         (0x000F0000L)
#define STANDARD_RIGHTS_READ             (READ_CONTROL)
#define STANDARD_RIGHTS_WRITE            (READ_CONTROL)
#define STANDARD_RIGHTS_EXECUTE          (READ_CONTROL)

#define FILE_READ_DATA         0x0001
#define FILE_LIST_DIRECTORY    0x0001
#define FILE_WRITE_DATA        0x0002
#define FILE_ADD_FILE          0x0002
#define FILE_APPEND_DATA       0x0004
#define FILE_ADD_SUBDIRECTORY  0x0004
#define FILE_EXECUTE           0x0020
#define FILE_TRAVERSE          0x0020
#define FILE_DELETE_CHILD      0x0040
#define FILE_READ_ATTRIBUTES   0x0080
#define FILE_WRITE_ATTRIBUTES  0x0100
#define FILE_READ_EA           0x0008
#define FILE_WRITE_EA          0x0010
#define FILE_ALL_ACCESS        (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)

#define GENERIC_READ     0x80000000L
#define GENERIC_WRITE    0x40000000L
#define GENERIC_EXECUTE  0x20000000L
#define GENERIC_ALL      0x10000000L

#define FILE_SUPERSEDED      0x00000000
#define FILE_OPENED          0x00000001
#define FILE_CREATED         0x00000002
#define FILE_OVERWRITTEN     0x00000003
#define FILE_EXISTS          0x00000004
#define FILE_DOES_NOT_EXIST  0x00000005

#define FILE_ATTRIBUTE_READONLY      0x00000001
#define FILE_ATTRIBUTE_HIDDEN        0x00000002
#define FILE_ATTRIBUTE_SYSTEM        0x00000004
#define FILE_ATTRIBUTE_DIRECTORY     0x00000010
#define FILE_ATTRIBUTE_ARCHIVE       0x00000020
#define FILE_ATTRIBUTE_NORMAL        0x00000080
#define FILE_ATTRIBUTE_VALID_FLAGS   0x00007FB7

#define OPEN_PACKET_PATTERN              0xbeaa0251

#define FO_SYNCHRONOUS_IO                0x00000001
#define FO_ALERTABLE_IO                  0x00000002
#define FO_NO_INTERMEDIATE_BUFFERING     0x00000004
#define FO_SEQUENTIAL_ONLY               0x00000008
#define FO_CLEANUP_COMPLETE              0x00000010
#define FO_HANDLE_CREATED                0x00000020
#define FO_CACHE_SUPPORTED               0x00000040
#define FO_APPEND_ONLY                   0x00000080

#define IO_TYPE_ADAPTER                  0x00000001
#define IO_TYPE_CONTROLLER               0x00000002
#define IO_TYPE_DEVICE                   0x00000003
#define IO_TYPE_DRIVER                   0x00000004
#define IO_TYPE_FILE                     0x00000005
#define IO_TYPE_IRP                      0x00000006
#define IO_TYPE_MASTER_ADAPTER           0x00000007
#define IO_TYPE_OPEN_PACKET              0x00000008
#define IO_TYPE_TIMER                    0x00000009
#define IO_TYPE_VPB                      0x0000000a
#define IO_TYPE_ERROR_LOG                0x0000000b
#define IO_TYPE_ERROR_MESSAGE            0x0000000c
#define IO_TYPE_DEVICE_OBJECT_EXTENSION  0x0000000d

#define FILE_DEVICE_CD_ROM              0x00000002
#define FILE_DEVICE_CD_ROM_FILE_SYSTEM  0x00000003
#define FILE_DEVICE_DISK                0x00000007
#define FILE_DEVICE_DISK_FILE_SYSTEM    0x00000008
#define FILE_DEVICE_MEMORY_UNIT         0x0000003a
#define FILE_DEVICE_MEDIA_BOARD         0x0000003b

#define DO_RAW_MOUNT_ONLY               0x00000001
#define DO_EXCLUSIVE                    0x00000002
#define DO_DIRECT_IO                    0x00000004
#define DO_DEVICE_HAS_NAME              0x00000008
#define DO_DEVICE_INITIALIZING          0x00000010
#define DO_SCATTER_GATHER_IO            0x00000040

#define SL_CASE_SENSITIVE               0x00000080
#define SL_OPEN_TARGET_DIRECTORY        0x00000004 // same as IO_OPEN_TARGET_DIRECTORY used by IoCreateFile

#define IO_FORCE_ACCESS_CHECK           0x00000001
#define IO_OPEN_TARGET_DIRECTORY        0x00000004
#define IO_NO_PARAMETER_CHECKING        0x00000100

#define SL_PENDING_RETURNED              0x01
#define SL_MUST_COMPLETE                 0x02
#define SL_INVOKE_ON_CANCEL              0x20
#define SL_INVOKE_ON_SUCCESS             0x40
#define SL_INVOKE_ON_ERROR               0x80

#define IRP_NOCACHE                     0x00000001
#define IRP_MOUNT_COMPLETION            0x00000002
#define IRP_SYNCHRONOUS_API             0x00000004
#define IRP_CREATE_OPERATION            0x00000008
#define IRP_READ_OPERATION              0x00000010
#define IRP_WRITE_OPERATION             0x00000020
#define IRP_CLOSE_OPERATION             0x00000040
#define IRP_DEFER_IO_COMPLETION         0x00000080
#define IRP_OB_QUERY_NAME               0x00000100
#define IRP_UNLOCK_USER_BUFFER          0x00000200
#define IRP_SCATTER_GATHER_OPERATION    0x00000400
#define IRP_UNMAP_SEGMENT_ARRAY         0x00000800
#define IRP_NO_CANCELIO                 0x00001000

#define IRP_MJ_CREATE                   0x00
#define IRP_MJ_CLOSE                    0x01
#define IRP_MJ_READ                     0x02
#define IRP_MJ_WRITE                    0x03
#define IRP_MJ_QUERY_INFORMATION        0x04
#define IRP_MJ_SET_INFORMATION          0x05
#define IRP_MJ_FLUSH_BUFFERS            0x06
#define IRP_MJ_QUERY_VOLUME_INFORMATION 0x07
#define IRP_MJ_DIRECTORY_CONTROL        0x08
#define IRP_MJ_FILE_SYSTEM_CONTROL      0x09
#define IRP_MJ_DEVICE_CONTROL           0x0a
#define IRP_MJ_INTERNAL_DEVICE_CONTROL  0x0b
#define IRP_MJ_SHUTDOWN                 0x0c
#define IRP_MJ_CLEANUP                  0x0d
#define IRP_MJ_MAXIMUM_FUNCTION         0x0d

#define FILE_WRITE_TO_END_OF_FILE       0xFFFFFFFF
#define FILE_USE_FILE_POINTER_POSITION  0xFFFFFFFE

#define IOCTL_DISK_GET_DRIVE_GEOMETRY   0x00070000
#define IOCTL_DISK_GET_PARTITION_INFO   0x00074004
#define IOCTL_DISK_VERIFY               0x00070014
#define IOCTL_IDE_PASS_THROUGH          0x0004D028
#define IOCTL_SCSI_PASS_THROUGH_DIRECT  0x0004D014

typedef enum _FILE_INFORMATION_CLASS {
	FileDirectoryInformation = 1,
	FileFullDirectoryInformation,
	FileBothDirectoryInformation,
	FileBasicInformation,
	FileStandardInformation,
	FileInternalInformation,
	FileEaInformation,
	FileAccessInformation,
	FileNameInformation,
	FileRenameInformation,
	FileLinkInformation,
	FileNamesInformation,
	FileDispositionInformation,
	FilePositionInformation,
	FileFullEaInformation,
	FileModeInformation,
	FileAlignmentInformation,
	FileAllInformation,
	FileAllocationInformation,
	FileEndOfFileInformation,
	FileAlternateNameInformation,
	FileStreamInformation,
	FilePipeInformation,
	FilePipeLocalInformation,
	FilePipeRemoteInformation,
	FileMailslotQueryInformation,
	FileMailslotSetInformation,
	FileCompressionInformation,
	FileObjectIdInformation,
	FileCompletionInformation,
	FileMoveClusterInformation,
	FileQuotaInformation,
	FileReparsePointInformation,
	FileNetworkOpenInformation,
	FileAttributeTagInformation,
	FileTrackingInformation,
	FileMaximumInformation
} FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;

typedef enum _FS_INFORMATION_CLASS {
	FileFsVolumeInformation = 1,
	FileFsLabelInformation,
	FileFsSizeInformation,
	FileFsDeviceInformation,
	FileFsAttributeInformation,
	FileFsControlInformation,
	FileFsFullSizeInformation,
	FileFsObjectIdInformation,
	FileFsMaximumInformation
} FS_INFORMATION_CLASS, *PFS_INFORMATION_CLASS;

typedef PVOID PFILE_SEGMENT_ELEMENT;

typedef NTSTATUS(XBOXAPI *PIO_COMPLETION_ROUTINE)(
	struct _DEVICE_OBJECT *DeviceObject,
	struct _IRP *Irp,
	PVOID Context
	);

typedef VOID(XBOXAPI *PIO_APC_ROUTINE)(
	PVOID ApcContext,
	struct _IO_STATUS_BLOCK *IoStatusBlock,
	ULONG Reserved
	);

typedef VOID(XBOXAPI *PDRIVER_STARTIO)(
	struct _DEVICE_OBJECT *DeviceObject,
	struct _IRP *Irp
	);

typedef VOID(XBOXAPI *PDRIVER_DELETEDEVICE)(
	struct _DEVICE_OBJECT *DeviceObject
	);

typedef NTSTATUS(XBOXAPI *PDRIVER_DISMOUNTVOLUME)(
	struct _DEVICE_OBJECT *DeviceObject
	);

typedef NTSTATUS(XBOXAPI *PDRIVER_DISPATCH)(
	struct _DEVICE_OBJECT *DeviceObject,
	struct _IRP *Irp
	);

typedef struct _DRIVER_OBJECT {
	PDRIVER_STARTIO DriverStartIo;
	PDRIVER_DELETEDEVICE DriverDeleteDevice;
	PDRIVER_DISMOUNTVOLUME DriverDismountVolume;
	PDRIVER_DISPATCH MajorFunction[IRP_MJ_MAXIMUM_FUNCTION + 1];
} DRIVER_OBJECT, *PDRIVER_OBJECT;

typedef struct _DEVICE_OBJECT {
	CSHORT Type;
	USHORT Size;
	LONG ReferenceCount;
	struct _DRIVER_OBJECT *DriverObject;
	struct _DEVICE_OBJECT *MountedOrSelfDevice;
	struct _IRP *CurrentIrp;
	ULONG Flags;
	PVOID DeviceExtension;
	UCHAR DeviceType;
	UCHAR StartIoFlags;
	CCHAR StackSize;
	BOOLEAN DeletePending;
	ULONG SectorSize;
	ULONG AlignmentRequirement;
	KDEVICE_QUEUE DeviceQueue;
	KEVENT DeviceLock;
	ULONG StartIoKey;
} DEVICE_OBJECT, *PDEVICE_OBJECT;

typedef struct _IO_COMPLETION_CONTEXT {
	PVOID Port;
	PVOID Key;
} IO_COMPLETION_CONTEXT, *PIO_COMPLETION_CONTEXT;

#pragma pack(push, 4)
typedef struct _FILE_OBJECT {
	CSHORT Type;
	BOOLEAN DeletePending : 1;
	BOOLEAN ReadAccess : 1;
	BOOLEAN WriteAccess : 1;
	BOOLEAN DeleteAccess : 1;
	BOOLEAN SharedRead : 1;
	BOOLEAN SharedWrite : 1;
	BOOLEAN SharedDelete : 1;
	BOOLEAN Synchronize : 1;
	UCHAR Flags;
	PDEVICE_OBJECT DeviceObject;
	PVOID FsContext;
	PVOID FsContext2;
	NTSTATUS FinalStatus;
	LARGE_INTEGER CurrentByteOffset;
	struct _FILE_OBJECT *RelatedFileObject;
	PIO_COMPLETION_CONTEXT CompletionContext;
	LONG LockCount;
	KEVENT Lock;
	KEVENT Event;
} FILE_OBJECT, *PFILE_OBJECT;

typedef struct _DUMMY_FILE_OBJECT {
	OBJECT_HEADER ObjectHeader;
	CHAR FileObjectBody[sizeof(FILE_OBJECT)];
} DUMMY_FILE_OBJECT, *PDUMMY_FILE_OBJECT;
#pragma pack(pop)

typedef struct _FILE_NETWORK_OPEN_INFORMATION {
	LARGE_INTEGER CreationTime;
	LARGE_INTEGER LastAccessTime;
	LARGE_INTEGER LastWriteTime;
	LARGE_INTEGER ChangeTime;
	LARGE_INTEGER AllocationSize;
	LARGE_INTEGER EndOfFile;
	ULONG FileAttributes;
} FILE_NETWORK_OPEN_INFORMATION, *PFILE_NETWORK_OPEN_INFORMATION;

typedef struct _FILE_FS_SIZE_INFORMATION {
	LARGE_INTEGER TotalAllocationUnits;
	LARGE_INTEGER AvailableAllocationUnits;
	ULONG SectorsPerAllocationUnit;
	ULONG BytesPerSector;
} FILE_FS_SIZE_INFORMATION, *PFILE_FS_SIZE_INFORMATION;

typedef struct _IO_STATUS_BLOCK {
	union {
		NTSTATUS Status;
		PVOID Pointer;
	};
	ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

#pragma pack(push, 4)
typedef struct _IO_STACK_LOCATION {
	UCHAR MajorFunction;
	UCHAR MinorFunction;
	UCHAR Flags;
	UCHAR Control;

	union {
		struct {
			ACCESS_MASK DesiredAccess;
			ULONG Options;
			USHORT FileAttributes;
			USHORT ShareAccess;
			POBJECT_STRING RemainingName;
		} Create;

		struct {
			ULONG Length;
			union {
				ULONG BufferOffset;
				PVOID CacheBuffer;
			};
			LARGE_INTEGER ByteOffset;
		} Read;

		struct {
			ULONG Length;
			union {
				ULONG BufferOffset;
				PVOID CacheBuffer;
			};
			LARGE_INTEGER ByteOffset;
		} Write;

		struct {
			ULONG Length;
			POBJECT_STRING FileName;
			FILE_INFORMATION_CLASS FileInformationClass;
		} QueryDirectory;

		struct {
			ULONG Length;
			FILE_INFORMATION_CLASS FileInformationClass;
		} QueryFile;

		struct {
			ULONG Length;
			FILE_INFORMATION_CLASS FileInformationClass;
			PFILE_OBJECT FileObject;
		} SetFile;

		struct {
			ULONG Length;
			FS_INFORMATION_CLASS FsInformationClass;
		} QueryVolume;

		struct {
			ULONG Length;
			FS_INFORMATION_CLASS FsInformationClass;
		} SetVolume;

		struct {
			ULONG OutputBufferLength;
			PVOID InputBuffer;
			ULONG InputBufferLength;
			ULONG FsControlCode;
		} FileSystemControl;

		struct {
			ULONG OutputBufferLength;
			PVOID InputBuffer;
			ULONG InputBufferLength;
			ULONG IoControlCode;
		} DeviceIoControl;

		struct {
			struct _SCSI_REQUEST_BLOCK *Srb;
		} Scsi;

		struct {
			ULONG Length;
			PUCHAR Buffer;
			ULONG SectorNumber;
			ULONG BufferOffset;
		} IdexReadWrite;

		struct {
			PVOID Argument1;
			PVOID Argument2;
			PVOID Argument3;
			PVOID Argument4;
		} Others;

	} Parameters;

	PDEVICE_OBJECT DeviceObject;
	PFILE_OBJECT FileObject;
	PIO_COMPLETION_ROUTINE CompletionRoutine;
	PVOID Context;
} IO_STACK_LOCATION, *PIO_STACK_LOCATION;
#pragma pack(pop)
STATIC_ASSERT(sizeof(IO_STACK_LOCATION) == 0x24, "IO_STACK_LOCATION size mismatch");
STATIC_ASSERT(offsetof(IO_STACK_LOCATION, FileObject) == 0x18, "IO_STACK_LOCATION::FileObject offset mismatch");

typedef struct _IRP {
	CSHORT Type;
	USHORT Size;
	ULONG Flags;
	LIST_ENTRY ThreadListEntry;
	IO_STATUS_BLOCK IoStatus;
	CHAR StackCount;
	CHAR CurrentLocation;
	BOOLEAN PendingReturned;
	BOOLEAN Cancel;
	PIO_STATUS_BLOCK UserIosb;
	PKEVENT UserEvent;
	union {
		struct {
			PIO_APC_ROUTINE UserApcRoutine;
			PVOID UserApcContext;
		} AsynchronousParameters;
		LARGE_INTEGER AllocationSize;
	} Overlay;
	PVOID UserBuffer;
	PFILE_SEGMENT_ELEMENT SegmentArray;
	ULONG LockedBufferLength;
	union {
		struct {
			union {
				KDEVICE_QUEUE_ENTRY DeviceQueueEntry;
				struct {
					PVOID DriverContext[5];
				};
			};
			PETHREAD Thread;
			struct {
				LIST_ENTRY ListEntry;
				union {
					PIO_STACK_LOCATION CurrentStackLocation;
					ULONG PacketType;
				};
			};
			PFILE_OBJECT OriginalFileObject;
		} Overlay;
		KAPC Apc;
		PVOID CompletionKey;
	} Tail;
} IRP, *PIRP;
STATIC_ASSERT(sizeof(IRP) == 0x68, "IRP size mismatch");
STATIC_ASSERT(offsetof(IRP, Overlay) == 0x28);
STATIC_ASSERT(offsetof(IRP, SegmentArray) == 0x34);
STATIC_ASSERT(offsetof(IRP, LockedBufferLength) == 0x38);
STATIC_ASSERT(offsetof(IRP, Tail.Overlay.DeviceQueueEntry) == 0x3C);
STATIC_ASSERT(offsetof(DEVICE_OBJECT, StartIoKey) == 0x44);

/* Source NXDK */
typedef VOID (XBOXAPI *PIDE_INTERRUPT_ROUTINE)(VOID);
typedef VOID (XBOXAPI *PIDE_FINISHIO_ROUTINE)(VOID);
typedef BOOLEAN (XBOXAPI *PIDE_POLL_RESET_COMPLETE_ROUTINE)(VOID);
typedef VOID (XBOXAPI *PIDE_TIMEOUT_EXPIRED_ROUTINE)(VOID);
typedef VOID (XBOXAPI *PIDE_START_PACKET_ROUTINE)(DEVICE_OBJECT *, IRP *);
typedef VOID (XBOXAPI *PIDE_START_NEXT_PACKET_ROUTINE)(VOID);
typedef VOID (XBOXAPI *PKSYSTEM_ROUTINE)(PKSTART_ROUTINE, PVOID);
typedef VOID (*PIDE_RESET_DEVICE_ROUTINE)(VOID);

typedef struct _IDE_CHANNEL_OBJECT {
    PIDE_INTERRUPT_ROUTINE InterruptRoutine;
    PIDE_FINISHIO_ROUTINE FinishIoRoutine;
    PIDE_POLL_RESET_COMPLETE_ROUTINE PollResetCompleteRoutine;
    PIDE_TIMEOUT_EXPIRED_ROUTINE TimeoutExpiredRoutine;
    PIDE_START_PACKET_ROUTINE StartPacketRoutine;
    PIDE_START_NEXT_PACKET_ROUTINE StartNextPacketRoutine;
    KIRQL InterruptIrql;
    BOOLEAN ExpectingBusMasterInterrupt;
    BOOLEAN StartPacketBusy;
    BOOLEAN StartPacketRequested;
    UCHAR Timeout;
    UCHAR IoRetries;
    UCHAR MaximumIoRetries;
    PIRP CurrentIrp;
    KDEVICE_QUEUE DeviceQueue;
    ULONG PhysicalRegionDescriptorTablePhysical;
    KDPC TimerDpc;
    KDPC FinishDpc;
    KTIMER Timer;
    KINTERRUPT InterruptObject;
} IDE_CHANNEL_OBJECT, *PIDE_CHANNEL_OBJECT;
STATIC_ASSERT(sizeof(IDE_CHANNEL_OBJECT) == 0x108);
STATIC_ASSERT(offsetof(IDE_CHANNEL_OBJECT, InterruptIrql) == 0x18);
STATIC_ASSERT(offsetof(IDE_CHANNEL_OBJECT, MaximumIoRetries) == 0x1e);
STATIC_ASSERT(offsetof(IDE_CHANNEL_OBJECT, CurrentIrp) == 0x20);
STATIC_ASSERT(offsetof(IDE_CHANNEL_OBJECT, PhysicalRegionDescriptorTablePhysical) == 0x30);
STATIC_ASSERT(offsetof(IDE_CHANNEL_OBJECT, TimerDpc) == 0x34);
STATIC_ASSERT(offsetof(IDE_CHANNEL_OBJECT, FinishDpc) == 0x50);
STATIC_ASSERT(offsetof(IDE_CHANNEL_OBJECT, Timer) == 0x70);

typedef struct _GENERIC_MAPPING {
	ACCESS_MASK GenericRead;
	ACCESS_MASK GenericWrite;
	ACCESS_MASK GenericExecute;
	ACCESS_MASK GenericAll;
} GENERIC_MAPPING, *PGENERIC_MAPPING;

// Disassembly: IDE pass-through ioctl parameter block (Irp->SegmentArray repurposed as PIDE_PASS_THROUGH)
typedef struct _IDE_PASS_THROUGH {
	UCHAR Features;       // +0x00 (output: error register)
	UCHAR SectorCount;    // +0x01
	UCHAR SectorNumber;   // +0x02
	UCHAR CylinderLow;    // +0x03
	UCHAR CylinderHigh;   // +0x04
	UCHAR DriveHead;      // +0x05
	UCHAR Command;        // +0x06 (output: status register)
	UCHAR WriteOperation; // +0x07 (0=read, nonzero=write)
	ULONG DataBufferSize; // +0x08
	PVOID DataBuffer;     // +0x0C
} IDE_PASS_THROUGH, *PIDE_PASS_THROUGH;
STATIC_ASSERT(sizeof(IDE_PASS_THROUGH) == 0x10);

// Disassembly: 512-byte identify buffer returned by IDENTIFY DEVICE command
typedef struct _IDE_IDENTIFY_DATA {
	UCHAR Data[512];
} IDE_IDENTIFY_DATA, *PIDE_IDENTIFY_DATA;

typedef struct _SHARE_ACCESS {
	UCHAR OpenCount;
	UCHAR ReadAccess;
	UCHAR WriteAccess;
	UCHAR DeleteAccess;
	UCHAR SharedRead;
	UCHAR SharedWrite;
	UCHAR SharedDelete;
} SHARE_ACCESS, *PSHARE_ACCESS;

EXPORTNUM(59) DLLEXPORT PIRP XBOXAPI IoAllocateIrp
(
	CCHAR StackSize
);

EXPORTNUM(60) DLLEXPORT PIRP XBOXAPI IoBuildAsynchronousFsdRequest
(
	ULONG MajorFunction,
	PDEVICE_OBJECT DeviceObject,
	PVOID Buffer,
	ULONG Length,
	PLARGE_INTEGER StartingOffset,
	PIO_STATUS_BLOCK IoStatusBlock
);

EXPORTNUM(62) DLLEXPORT PIRP XBOXAPI IoBuildSynchronousFsdRequest
(
	ULONG MajorFunction,
	PDEVICE_OBJECT DeviceObject,
	PVOID Buffer,
	ULONG Length,
	PLARGE_INTEGER StartingOffset,
	PKEVENT Event,
	PIO_STATUS_BLOCK IoStatusBlock
);

EXPORTNUM(61) DLLEXPORT PIRP XBOXAPI IoBuildDeviceIoControlRequest
(
	ULONG IoControlCode,
	PDEVICE_OBJECT DeviceObject,
	PVOID InputBuffer,
	ULONG InputBufferLength,
	PVOID OutputBuffer,
	ULONG OutputBufferLength,
	BOOLEAN InternalDeviceIoControl,
	PKEVENT Event,
	PIO_STATUS_BLOCK IoStatusBlock
);

EXPORTNUM(63) DLLEXPORT NTSTATUS XBOXAPI IoCheckShareAccess
(
	ACCESS_MASK DesiredAccess,
	ULONG DesiredShareAccess,
	PFILE_OBJECT FileObject,
	PSHARE_ACCESS ShareAccess,
	BOOLEAN Update
);

EXPORTNUM(65) DLLEXPORT NTSTATUS XBOXAPI IoCreateDevice
(
	PDRIVER_OBJECT DriverObject,
	ULONG DeviceExtensionSize,
	PSTRING DeviceName,
	ULONG DeviceType,
	BOOLEAN Exclusive,
	PDEVICE_OBJECT *DeviceObject
);

EXPORTNUM(66) DLLEXPORT NTSTATUS XBOXAPI IoCreateFile
(
	PHANDLE FileHandle,
	ACCESS_MASK DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PIO_STATUS_BLOCK IoStatusBlock,
	PLARGE_INTEGER AllocationSize,
	ULONG FileAttributes,
	ULONG ShareAccess,
	ULONG Disposition,
	ULONG CreateOptions,
	ULONG Options
);

EXPORTNUM(67) DLLEXPORT NTSTATUS XBOXAPI IoCreateSymbolicLink
(
	PSTRING SymbolicLinkName,
	PSTRING DeviceName
);

EXPORTNUM(68) DLLEXPORT VOID XBOXAPI IoDeleteDevice
(
	PDEVICE_OBJECT DeviceObject
);

EXPORTNUM(69) DLLEXPORT NTSTATUS XBOXAPI IoDeleteSymbolicLink
(
	PSTRING SymbolicLinkName
);

EXPORTNUM(64) DLLEXPORT extern OBJECT_TYPE IoCompletionObjectType;

EXPORTNUM(70) DLLEXPORT extern OBJECT_TYPE IoDeviceObjectType;

EXPORTNUM(71) DLLEXPORT extern OBJECT_TYPE IoFileObjectType;

EXPORTNUM(72) DLLEXPORT VOID XBOXAPI IoFreeIrp
(
	PIRP Irp
);

EXPORTNUM(73) DLLEXPORT VOID XBOXAPI IoInitializeIrp
(
	PIRP Irp,
	USHORT PacketSize,
	CCHAR StackSize
);

EXPORTNUM(74) DLLEXPORT NTSTATUS XBOXAPI IoInvalidDeviceRequest
(
	PDEVICE_OBJECT DeviceObject,
	PIRP Irp
);

EXPORTNUM(75) DLLEXPORT NTSTATUS XBOXAPI IoQueryFileInformation
(
	PFILE_OBJECT FileObject,
	FILE_INFORMATION_CLASS FileInformationClass,
	ULONG Length,
	PVOID FileInformation,
	PULONG ReturnedLength
);

EXPORTNUM(76) DLLEXPORT NTSTATUS XBOXAPI IoQueryVolumeInformation
(
	PFILE_OBJECT FileObject,
	FS_INFORMATION_CLASS FsInformationClass,
	ULONG Length,
	PVOID FsInformation,
	PULONG ReturnedLength
);

EXPORTNUM(77) DLLEXPORT VOID XBOXAPI IoQueueThreadIrp
(
	PIRP Irp
);

// Disassembly: _IoMarkIrpMustComplete@4, ordinal 359
EXPORTNUM(359) DLLEXPORT VOID XBOXAPI IoMarkIrpMustComplete
(
	PIRP Irp
);

EXPORTNUM(79) DLLEXPORT NTSTATUS XBOXAPI IoSetIoCompletion
(
	PKQUEUE IoCompletion,
	PVOID KeyContext,
	PVOID ApcContext,
	NTSTATUS IoStatus,
	ULONG_PTR IoStatusInformation
);

EXPORTNUM(78) DLLEXPORT VOID XBOXAPI IoRemoveShareAccess
(
	PFILE_OBJECT FileObject,
	PSHARE_ACCESS ShareAccess
);

EXPORTNUM(80) DLLEXPORT VOID XBOXAPI IoSetShareAccess
(
	ULONG DesiredAccess,
	ULONG DesiredShareAccess,
	PFILE_OBJECT FileObject,
	PSHARE_ACCESS ShareAccess
);

EXPORTNUM(81) DLLEXPORT VOID XBOXAPI IoStartNextPacket
(
	PDEVICE_OBJECT DeviceObject
);

EXPORTNUM(82) DLLEXPORT VOID XBOXAPI IoStartNextPacketByKey
(
	PDEVICE_OBJECT DeviceObject,
	ULONG Key
);

EXPORTNUM(83) DLLEXPORT VOID XBOXAPI IoStartPacket
(
	PDEVICE_OBJECT DeviceObject,
	PIRP Irp,
	PULONG Key
);

EXPORTNUM(84) DLLEXPORT NTSTATUS XBOXAPI IoSynchronousDeviceIoControlRequest
(
	ULONG IoControlCode,
	PDEVICE_OBJECT DeviceObject,
	PVOID InputBuffer,
	ULONG InputBufferLength,
	PVOID OutputBuffer,
	ULONG OutputBufferLength,
	PULONG ReturnedOutputBufferLength,
	BOOLEAN InternalDeviceIoControl
);

EXPORTNUM(85) DLLEXPORT NTSTATUS XBOXAPI IoSynchronousFsdRequest
(
	ULONG MajorFunction,
	PDEVICE_OBJECT DeviceObject,
	PVOID Buffer,
	ULONG Length,
	PLARGE_INTEGER StartingOffset
);

EXPORTNUM(86) DLLEXPORT NTSTATUS FASTCALL IofCallDriver
(
	PDEVICE_OBJECT DeviceObject,
	PIRP Irp
);

EXPORTNUM(87) DLLEXPORT VOID FASTCALL IofCompleteRequest
(
	PIRP Irp,
	CCHAR PriorityBoost
);

EXPORTNUM(90) DLLEXPORT NTSTATUS XBOXAPI IoDismountVolume
(
	PDEVICE_OBJECT DeviceObject
);

EXPORTNUM(91) DLLEXPORT NTSTATUS XBOXAPI IoDismountVolumeByName
(
	POBJECT_STRING VolumeName
);

EXPORTNUM(357) DLLEXPORT extern IDE_CHANNEL_OBJECT IdexChannelObject;

#ifdef __cplusplus
}
#endif
