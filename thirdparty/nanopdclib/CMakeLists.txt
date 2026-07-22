include(${CMAKE_CURRENT_LIST_DIR}/filelists.cmake)

add_library(nanopdclib_bldr STATIC
    ${NANOPDCLIB_SOURCES}
)
target_include_directories(nanopdclib_bldr PUBLIC ${NANOPDCLIB_INCLUDES})
target_link_libraries(nanopdclib_bldr PUBLIC 
    debug libcmtd.lib
    optimized libcmt.lib
)
add_library(thirdparty::bldr::nanopdclib ALIAS nanopdclib_bldr)

add_library(nanopdclib STATIC
    "${CMAKE_CURRENT_LIST_DIR}/platform/xbox/functions/_PDCLIB/assert.c"
)
target_link_libraries(nanopdclib PUBLIC nanopdclib_bldr)
add_library(thirdparty::nanopdclib ALIAS nanopdclib)
