set(NANOPDCLIB_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/functions/string/memcmp.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/string/memcpy.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/string/memmove.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/string/memset.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/string/strcmp.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/string/strlen.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/string/strncmp.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/string/strncpy.c"

    "${CMAKE_CURRENT_LIST_DIR}/functions/wchar/wcschr.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/wchar/wmemcmp.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/wchar/wmemcpy.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/wchar/wmemmove.c"
    "${CMAKE_CURRENT_LIST_DIR}/functions/wchar/wcsrchr.c"
)

set(NANOPDCLIB_INCLUDES
    "${CMAKE_CURRENT_LIST_DIR}/nanoprintf"
    "${CMAKE_CURRENT_LIST_DIR}/include"
    "${CMAKE_CURRENT_LIST_DIR}/platform/xbox/include"
)