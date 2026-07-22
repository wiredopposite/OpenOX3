cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/cmake/toolchain.cmake")

project(OpenOX3 C CXX ASM)

add_subdirectory(libs)
add_subdirectory(thirdparty)
add_subdirectory(openoxkrnl)