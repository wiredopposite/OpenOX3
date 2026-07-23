#pragma once

#pragma section("STICKY", read, write)
#define SECTION_PERSIST __declspec(allocate("STICKY"))

#define SECTION_INIT __declspec(code_seg("INIT"))