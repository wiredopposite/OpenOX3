file(GLOB_RECURSE _openoxkrnl_srcs "${CMAKE_CURRENT_LIST_DIR}/src/*.c" "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_executable(openoxkrnl ${_openoxkrnl_srcs})

target_include_directories(openoxkrnl PRIVATE 
    "${CMAKE_CURRENT_LIST_DIR}/src"
    "${CMAKE_CURRENT_LIST_DIR}/export"
)

target_link_libraries(openoxkrnl 
    PUBLIC
        libc
    PRIVATE
        libcxx
        win32types
)

set_target_properties(openoxkrnl PROPERTIES LINK_FLAGS "\
    /BASE:0x80010000 \
    /ENTRY:MainCrtStartup \
    /DEBUG:FULL \
    /MAP \
    /SECTION:INIT,ERWD \
    /MANIFEST:NO \
")

# /DEF:\"${CMAKE_CURRENT_LIST_DIR}/xboxkrnl.exe.def\" \