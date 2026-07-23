#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TIME_ZONE_NAME_LENGTH 4
#define XBOX_KEY_LENGTH 16

typedef UCHAR XBOX_KEY_DATA[XBOX_KEY_LENGTH];

typedef struct _XBOX_ENCRYPTED_SETTINGS {
	UCHAR Checksum[20];
	UCHAR Confounder[8];
	UCHAR HDKey[XBOX_KEY_LENGTH];
	ULONG GameRegion;
} XBOX_ENCRYPTED_SETTINGS, *PXBOX_ENCRYPTED_SETTINGS;

typedef struct _XBOX_FACTORY_SETTINGS {
	ULONG Checksum;
	UCHAR SerialNumber[12];
	UCHAR EthernetAddr[6];
	UCHAR Reserved1[2];
	UCHAR OnlineKey[16];
	ULONG AVRegion;
	ULONG Reserved2;
} XBOX_FACTORY_SETTINGS, *PXBOX_FACTORY_SETTINGS;

typedef struct _XBOX_TIMEZONE_DATE {
	UCHAR Month;
	UCHAR Day;
	UCHAR DayOfWeek;
	UCHAR Hour;
} XBOX_TIMEZONE_DATE, *PXBOX_TIMEZONE_DATE;

typedef struct _XBOX_USER_SETTINGS {
	ULONG Checksum;
	LONG TimeZoneBias;
	CHAR TimeZoneStdName[TIME_ZONE_NAME_LENGTH];
	CHAR TimeZoneDltName[TIME_ZONE_NAME_LENGTH];
	ULONG Reserved1[2];
	XBOX_TIMEZONE_DATE TimeZoneStdDate;
	XBOX_TIMEZONE_DATE TimeZoneDltDate;
	ULONG Reserved2[2];
	LONG TimeZoneStdBias;
	LONG TimeZoneDltBias;
	ULONG Language;
	ULONG VideoFlags;
	ULONG AudioFlags;
	ULONG ParentalControlGames;
	ULONG ParentalControlPassword;
	ULONG ParentalControlMovies;
	ULONG OnlineIpAddress;
	ULONG OnlineDnsAddress;
	ULONG OnlineDefaultGatewayAddress;
	ULONG OnlineSubnetMask;
	ULONG MiscFlags;
	ULONG DvdRegion;
} XBOX_USER_SETTINGS, *PXBOX_USER_SETTINGS;

typedef struct _XBOX_UEM_INFO {
	UCHAR LastCode;
	UCHAR Reserved;
	USHORT History;
} XBOX_UEM_INFO, *PXBOX_UEM_INFO;
STATIC_ASSERT(sizeof(XBOX_UEM_INFO) == 4);

typedef struct _XBOX_EEPROM {
	XBOX_ENCRYPTED_SETTINGS EncryptedSettings;
	XBOX_FACTORY_SETTINGS FactorySettings;
	XBOX_USER_SETTINGS UserSettings;
	UCHAR Unused[58];
	XBOX_UEM_INFO UEMInfo;
	UCHAR Reserved1[2];
} XBOX_EEPROM, *PXBOX_EEPROM;
STATIC_ASSERT(sizeof(XBOX_EEPROM) == 256);

typedef struct _XBOX_HARDWARE_INFO {
	ULONG Flags;
	UCHAR GpuRevision;
	UCHAR McpRevision;
	UCHAR Unknown3;
	UCHAR Unknown4;
} XBOX_HARDWARE_INFO;

typedef struct _XBOX_KRNL_VERSION {
	USHORT Major;
	USHORT Minor;
	USHORT Build;
	USHORT Qfe;
} XBOX_KRNL_VERSION;

// XBOX_REFURB_INFO: 16-byte refurbishment info structure stored at partition offset 0x600.
// On-disk layout: first DWORD is magic 0x52465242 ('BRBF'), followed by 3 more DWORDs.
// Disassembly evidence: ExReadWriteRefurbInfo at 5838_dis_debug.txt:18261-18340
typedef struct _XBOX_REFURB_INFO {
	ULONG Signature;              // 0x52465242 ('BRBF') on disk
	ULONG PowerCycleCount;
	ULONG FirstBootTime;
	ULONG Reserved;
} XBOX_REFURB_INFO, *PXBOX_REFURB_INFO;
STATIC_ASSERT(sizeof(XBOX_REFURB_INFO) == 0x10);

EXPORTNUM(321) DLLEXPORT extern XBOX_KEY_DATA XboxEEPROMKey;

EXPORTNUM(322) DLLEXPORT extern XBOX_HARDWARE_INFO XboxHardwareInfo;

// Disassembly: _XboxHDKey, 0x8005f910, ordinal 323
EXPORTNUM(323) DLLEXPORT extern UCHAR XboxHDKey[16];

EXPORTNUM(324) DLLEXPORT extern XBOX_KRNL_VERSION XboxKrnlVersion;

// Disassembly: _XboxSignatureKey, 0x8005fa20, ordinal 325 — populated by XepExtractCertificateKeys
EXPORTNUM(325) DLLEXPORT extern UCHAR XboxSignatureKey[16];

// Disassembly: _XboxLANKey, 0x8005fa30, ordinal 353 — populated by XepExtractCertificateKeys
EXPORTNUM(353) DLLEXPORT extern UCHAR XboxLANKey[16];

// Disassembly: _XboxAlternateSignatureKeys, 0x8005f920, ordinal 354 — 16 alternate 16-byte signature keys
EXPORTNUM(354) DLLEXPORT extern UCHAR XboxAlternateSignatureKeys[16][16];

#ifdef __cplusplus
}
#endif
