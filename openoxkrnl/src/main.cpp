#include <cstring>
#include "xbox/xbox.hpp"
#include "util/section.hpp"

SECTION_INIT void MainCrtStartup(void *Options, const void *Keys)
{
    if (Options) {
        Xbox::SetBootFlags((const char *)Options);
    }

    // zero bootloader
    std::memset((void *)0x80100000, 0, 0x80400000 - 0x80100000);
}