cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/cmake/toolchain.cmake")

project(OpenOX C CXX ASM ASM_NASM)

set(OPENOX_THIRDPARTY_DIR   "${CMAKE_CURRENT_LIST_DIR}/thirdparty")
set(OPENOX_LIBS_DIR         "${CMAKE_CURRENT_LIST_DIR}/libs")
set(OPENOX_CMAKE_DIR        "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory("${OPENOX_THIRDPARTY_DIR}")
add_subdirectory("${OPENOX_LIBS_DIR}")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/openoxkrnl")