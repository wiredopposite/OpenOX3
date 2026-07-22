find_program(_clang_cl  clang-cl    REQUIRED)
find_program(_clang     clang       REQUIRED)
find_program(_llvm_ml   llvm-ml     REQUIRED)
find_program(_lld_link  lld-link    REQUIRED)
find_program(_llvm_ar   llvm-ar     REQUIRED)
find_program(_nasm      nasm        REQUIRED)

set(CMAKE_C_COMPILER        "${_clang_cl}"  CACHE FILEPATH "C compiler"     FORCE)
set(CMAKE_CXX_COMPILER      "${_clang_cl}"  CACHE FILEPATH "C++ compiler"   FORCE)
set(CMAKE_ASM_COMPILER      "${_clang}"     CACHE FILEPATH "ASM compiler"   FORCE)
set(CMAKE_NASM_COMPILER     "${_nasm}"      CACHE FILEPATH "NASM compiler"  FORCE)
set(CMAKE_MASM_COMPILER     "${_llvm_ml}"   CACHE FILEPATH "MASM compiler"  FORCE)
set(CMAKE_LINKER            "${_lld_link}"  CACHE FILEPATH "Linker"         FORCE)
set(CMAKE_AR                "${_llvm_ar}"   CACHE FILEPATH "Archiver"       FORCE)
set(CMAKE_C_COMPILER_AR     "${_llvm_ar}"   CACHE FILEPATH "C archiver"     FORCE)
set(CMAKE_CXX_COMPILER_AR   "${_llvm_ar}"   CACHE FILEPATH "C++ archiver"   FORCE)

set(CMAKE_C_COMPILER_TARGET     i686-pc-windows-msvc)
set(CMAKE_CXX_COMPILER_TARGET   ${CMAKE_C_COMPILER_TARGET})

set(CMAKE_SYSTEM_PROCESSOR i386)
set(CMAKE_SYSTEM_NAME      Generic)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Compiler-provided headers (intrin.h, etc.) that nanopdclib doesn't vend.
# Listed after NANOPDCLIB_INCLUDES so nanopdclib's own headers always win.
execute_process(
    COMMAND "${_clang_cl}" -print-resource-dir
    OUTPUT_VARIABLE _clang_resource_dir
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES   
    "${_clang_resource_dir}/include"
    "${CMAKE_CURRENT_LIST_DIR}/../libs/libc/install/include" 
)
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES 
    "${CMAKE_C_STANDARD_INCLUDE_DIRECTORIES}"
)

set(CMAKE_C_FLAGS_INIT "\
    --target=${CMAKE_C_COMPILER_TARGET} \
    -isystem ${_clang_resource_dir}/include \
    -isystem ${CMAKE_CURRENT_LIST_DIR}/../libs/libc/install/include \
    -U_WIN32 \
    -D_PDCLIB_STATIC_DEFINE \
    -D__STDC_NO_THREADS__ \
    -D_HAS_EXCEPTIONS=0 \
    -ffreestanding \
    -fno-exceptions \
    -fno-rtti \
    -nostdinc \
    -nostdinc++ \
    -nobuiltininc \
    -fno-stack-protector \
    -msse \
    -mno-sse \
")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_C_FLAGS_INIT}")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_INIT} /MTd /D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_INIT} /MT /O2 /Zi")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")

set(CMAKE_EXE_LINKER_FLAGS_INIT "\
    /DYNAMICBASE:NO \
    /FIXED \
    /LARGEADDRESSAWARE \
    /NODEFAULTLIB \
    /DEBUG:FULL \
    /INCREMENTAL:NO \
    /OPT:REF \
    /SUBSYSTEM:NATIVE \
    /IGNORE:4210 \
    /SAFESEH:NO \
")
# /OPT:ICF \

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(CMAKE_C_STANDARD   99)
set(CMAKE_CXX_STANDARD 17)