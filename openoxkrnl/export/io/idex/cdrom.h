#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

// IOCTL_SCSI_PASS_THROUGH_DIRECT and IOCTL_IDE_PASS_THROUGH from iop.hpp
#define IOCTL_CDROM_READ_TOC           0x24000
#define IOCTL_CDROM_READ_TOC_FORMAT    0x24038
#define IOCTL_CDROM_RAW_READ           0x2403e
#define IOCTL_CDROM_GET_DRIVE_GEOMETRY 0x2404c
#define IOCTL_CDROM_AUTHENTICATE_DISC  0x24080
#define IOCTL_CDROM_SET_SPINDLE_SPEED  0x24084
#define IOCTL_CDROM_CHECK_VERIFY       0x24800
#define IOCTL_DVD_START_SESSION        0x335000
#define IOCTL_DVD_READ_KEY             0x335004
#define IOCTL_DVD_SEND_KEY             0x335008
#define IOCTL_DVD_END_SESSION          0x33500c
#define IOCTL_DVD_READ_STRUCTURE       0x336140
#define IOCTL_DVD_SEND_KEY2            0x33e018

// Disassembly: DVDX2_CONTROL_DATA, 0x664 bytes
#pragma pack(1)
typedef struct _DVDX2_CONTROL_DATA {
	UCHAR ModeHeader[8];           // +0x000
	UCHAR Data[0x2fc];             // +0x008
	UCHAR Type;                    // +0x304
	UCHAR ChallengeEntryCount;     // +0x305
	UCHAR ChallengeEntries[0xfd];  // +0x306
	UCHAR Reserved[0xa0];          // +0x403
	UCHAR AuthData[0x2c];          // +0x4a3
	UCHAR SHA1Digest[0x14];        // +0x4cf
	UCHAR RSASignature[0x181];     // +0x4e3
} DVDX2_CONTROL_DATA, *PDVDX2_CONTROL_DATA;
STATIC_ASSERT(sizeof(DVDX2_CONTROL_DATA) == 0x664);

typedef struct _DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY {
	UCHAR Type;
	UCHAR Data[10];
} DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY, *PDVDX2_HOST_CHALLENGE_RESPONSE_ENTRY;
STATIC_ASSERT(sizeof(DVDX2_HOST_CHALLENGE_RESPONSE_ENTRY) == 0xb);
#pragma pack()

typedef struct _RAW_READ_INFO {
	LARGE_INTEGER DiskOffset;
	ULONG SectorCount;
	ULONG TrackMode;
} RAW_READ_INFO, *PRAW_READ_INFO;
STATIC_ASSERT(sizeof(RAW_READ_INFO) == 0x10);

typedef struct _CDROM_DRIVE_GEOMETRY {
	ULONG CylindersLow;
	ULONG CylindersHigh;
	ULONG MediaType;
	ULONG TracksPerCylinder;
	ULONG SectorsPerTrack;
	ULONG BytesPerSector;
} CDROM_DRIVE_GEOMETRY, *PCDROM_DRIVE_GEOMETRY;

// Source: Cxbx-Reloaded
typedef struct _SCSI_PASS_THROUGH_DIRECT {
	USHORT Length;
	UCHAR ScsiStatus;
	UCHAR PathId;
	UCHAR TargetId;
	UCHAR Lun;
	UCHAR CdbLength;
	UCHAR SenseInfoLength;
	UCHAR DataIn;
	ULONG DataTransferLength;
	ULONG TimeOutValue;
	PVOID DataBuffer;
	ULONG SenseInfoOffset;
	UCHAR Cdb[16];
} SCSI_PASS_THROUGH_DIRECT, *PSCSI_PASS_THROUGH_DIRECT;

#ifdef __cplusplus
}
#endif
