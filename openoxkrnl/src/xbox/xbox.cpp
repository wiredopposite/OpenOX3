#include <cstring>
#include "xbox/xbox.hpp"
#include "util/section.hpp"

namespace Xbox {

uint32_t BootFlags;

SECTION_INIT void SetBootFlags(const char *Args)
{
    if (std::strstr(Args, BootArgShadow)) {
        BootFlags |= BootFlagShadow;
    }
    if (std::strstr(Args, BootArgDisk)) {
        BootFlags |= BootFlagDisk;
    }
    if (std::strstr(Args, BoorArgCdrom)) {
        BootFlags |= BootFlagCdrom;
    }
    if (std::strstr(Args, BootArgDash)) {
        BootFlags |= BootFlagDash;
    }
}

}