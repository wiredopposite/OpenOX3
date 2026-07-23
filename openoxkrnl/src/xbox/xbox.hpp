#pragma once

#include <cstdint>
#include "xbox/xbox.h"

namespace Xbox {

static constexpr uint32_t BootFlagShadow  = (1ul << 0);
static constexpr uint32_t BootFlagDisk    = (1ul << 1);
static constexpr uint32_t BootFlagCdrom   = (1ul << 2);
static constexpr uint32_t BootFlagDash    = (1ul << 7);

static constexpr char BootArgShadow[] = "SHADOW";
static constexpr char BootArgDisk[]   = "/HDBOOT";
static constexpr char BoorArgCdrom[]  = "/CDBOOT";
static constexpr char BootArgDash[]   = "/DBBOOT";

// struct XboxState {
//     XBOX_KEY_DATA& EepromKey;
// };

void SetBootFlags(const char *Args);

}