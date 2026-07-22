include(ExternalProject)

find_program(_meson
    NAMES meson meson.exe
    HINTS "$ENV{APPDATA}/Python/Python312/Scripts" "$ENV{APPDATA}/../Roaming/Python/Python312/Scripts"
    REQUIRED
)

set(_mlibc_src      "${CMAKE_CURRENT_LIST_DIR}/../../thirdparty/mlibc")
set(_mlibc_cross    "${CMAKE_CURRENT_LIST_DIR}/mlibc-cross.ini")
set(_mlibc_build    "${CMAKE_CURRENT_LIST_DIR}/build")
set(_mlibc_install  "${CMAKE_CURRENT_LIST_DIR}/install")

ExternalProject_Add(mlibc_build
    SOURCE_DIR              "${_mlibc_src}"
    DOWNLOAD_COMMAND        ""
    CONFIGURE_COMMAND
        "${_meson}" setup "${_mlibc_build}" "${_mlibc_src}"
            --cross-file "${_mlibc_cross}"
            -Dheaders_only=false
            -Dno_headers=false
            -Dposix_option=enabled
            -Dlinux_option=disabled
            -Dglibc_option=disabled
            -Dbsd_option=disabled
            -Dlibgcc_dependency=false
            -Ddefault_library=static
            -Db_staticpic=false
            -Dcpp_std=c++23
    BUILD_COMMAND           "${_meson}" compile -C "${_mlibc_build}"
    INSTALL_COMMAND         "${_meson}" install -C "${_mlibc_build}" --destdir "${_mlibc_install}"
    BUILD_BYPRODUCTS        "${_mlibc_install}/lib/libc.a"
    BUILD_IN_SOURCE         FALSE
    USES_TERMINAL_CONFIGURE TRUE
    USES_TERMINAL_BUILD     TRUE
    USES_TERMINAL_INSTALL   TRUE
)

file(MAKE_DIRECTORY "${_mlibc_install}/include")

add_library(libc STATIC IMPORTED GLOBAL)
add_dependencies(libc mlibc_build)

set_target_properties(libc PROPERTIES
    IMPORTED_LOCATION             "${_mlibc_install}/lib/libc.a"
    INTERFACE_INCLUDE_DIRECTORIES "${_mlibc_install}/include"
)
