#pragma once

#include "krnl/krnl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AV_PACK_NONE                      0x00000000
#define AV_PACK_STANDARD                  0x00000001
#define AV_PACK_RFU                       0x00000002
#define AV_PACK_SCART                     0x00000003
#define AV_PACK_HDTV                      0x00000004
#define AV_PACK_VGA                       0x00000005
#define AV_PACK_SVIDEO                    0x00000006
#define AV_PACK_MAX                       0x00000007
#define AV_PACK_MASK                      0x000000FF

#define AV_STANDARD_NTSC_M                0x00000100
#define AV_STANDARD_NTSC_J                0x00000200
#define AV_STANDARD_PAL_I                 0x00000300
#define AV_STANDARD_PAL_M                 0x00000400
#define AV_STANDARD_MAX                   0x00000500
#define AV_STANDARD_MASK                  0x00000F00
#define AV_STANDARD_SHIFT                 8

#define AV_FLAGS_HDTV_480i                0x00000000 // Bogus 'flag'
#define AV_FLAGS_HDTV_720p                0x00020000
#define AV_FLAGS_HDTV_1080i               0x00040000
#define AV_FLAGS_HDTV_480p                0x00080000
#define AV_HDTV_MODE_MASK                 0x000E0000 // Exclude AV_FLAGS_WIDESCREEN !

#define AV_FLAGS_NORMAL                   0x00000000
#define AV_FLAGS_WIDESCREEN               0x00010000
#define AV_FLAGS_LETTERBOX                0x00100000
#define AV_ASPECT_RATIO_MASK              0x00110000 // = AV_FLAGS_WIDESCREEN | AV_FLAGS_LETTERBOX

#define AV_FLAGS_INTERLACED               0x00200000

#define AV_FLAGS_60Hz                     0x00400000
#define AV_FLAGS_50Hz                     0x00800000
#define AV_REFRESH_MASK                   0x00C00000 // = AV_FLAGS_60Hz | AV_FLAGS_50Hz

#define AV_FLAGS_FIELD                    0x01000000
#define AV_FLAGS_10x11PAR                 0x02000000

#define AV_USER_FLAGS_MASK                (AV_HDTV_MODE_MASK | AV_ASPECT_RATIO_MASK | AV_REFRESH_MASK) // TODO : Should AV_REFRESH_MASK be AV_FLAGS_60Hz instead?
#define AV_USER_FLAGS_SHIFT               16

// Options to AvSendTVEncoderOption
#define AV_OPTION_MACROVISION_MODE        1
#define AV_OPTION_ENABLE_CC               2
#define AV_OPTION_DISABLE_CC              3
#define AV_OPTION_SEND_CC_DATA            4
#define AV_QUERY_CC_STATUS                5
#define AV_QUERY_AV_CAPABILITIES          6
#define AV_OPTION_BLANK_SCREEN            9
#define AV_OPTION_MACROVISION_COMMIT      10
#define AV_OPTION_FLICKER_FILTER          11
#define AV_OPTION_ZERO_MODE               12
#define AV_OPTION_QUERY_MODE              13
#define AV_OPTION_ENABLE_LUMA_FILTER      14
#define AV_OPTION_GUESS_FIELD             15
#define AV_QUERY_ENCODER_TYPE             16
#define AV_QUERY_MODE_TABLE_VERSION       17
#define AV_OPTION_CGMS                    18
#define AV_OPTION_WIDESCREEN              19

EXPORTNUM(1) DLLEXPORT PVOID XBOXAPI AvGetSavedDataAddress();

EXPORTNUM(2) DLLEXPORT VOID XBOXAPI AvSendTVEncoderOption
(
	PVOID RegisterBase,
	ULONG Option,
	ULONG Param,
	ULONG *Result
);

EXPORTNUM(3) DLLEXPORT ULONG XBOXAPI AvSetDisplayMode
(
	PVOID pNV2A,
	ULONG Step,
	ULONG Mode,
	ULONG Format,
	ULONG Pitch,
	ULONG ColorKey
);

EXPORTNUM(4) DLLEXPORT VOID XBOXAPI AvSetSavedDataAddress
(
	PVOID Address
);

#ifdef __cplusplus
}
#endif
