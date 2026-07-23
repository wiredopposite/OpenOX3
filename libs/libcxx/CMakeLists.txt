include(ExternalProject)

set(_llvmroot     "${CMAKE_CURRENT_LIST_DIR}/../../thirdparty/llvm-project")
set(_toolchain    "${CMAKE_CURRENT_LIST_DIR}/../../cmake/toolchain.cmake")
set(_install_dir  "${CMAKE_CURRENT_LIST_DIR}/install")
set(_build_dir    "${CMAKE_CURRENT_LIST_DIR}/build")

if(NOT CMAKE_BUILD_TYPE)
    set(_libcxx_build_type Release)
else()
    set(_libcxx_build_type ${CMAKE_BUILD_TYPE})
endif()

ExternalProject_Add(libcxx_build
    SOURCE_DIR          "${_llvmroot}/runtimes"
    BINARY_DIR          "${_build_dir}"
    DEPENDS             libc
    CMAKE_ARGS
        -DCMAKE_TOOLCHAIN_FILE=${_toolchain}
        -DCMAKE_BUILD_TYPE=${_libcxx_build_type}
        -DCMAKE_INSTALL_PREFIX=${_install_dir}
        -DLLVM_ENABLE_RUNTIMES=libcxx
        -DLIBCXX_ENABLE_EXCEPTIONS=OFF
        -DLIBCXX_ENABLE_RTTI=OFF
        -DLIBCXX_ENABLE_THREADS=OFF
        -DLIBCXX_ENABLE_FILESYSTEM=OFF
        -DLIBCXX_ENABLE_RANDOM_DEVICE=OFF
        -DLIBCXX_ENABLE_LOCALIZATION=OFF
        -DLIBCXX_ENABLE_UNICODE=OFF
        -DLIBCXX_ENABLE_WIDE_CHARACTERS=OFF
        -DLIBCXX_ENABLE_STATIC=ON
        -DLIBCXX_ENABLE_SHARED=OFF
        -DLIBCXX_CXX_ABI=none
        -DLIBCXX_NO_VCRUNTIME=ON
        -DLIBCXX_ABI_FORCE_ITANIUM=ON
        -DLIBCXX_INCLUDE_TESTS=OFF
        -DLIBCXX_INCLUDE_BENCHMARKS=OFF
        -DLIBCXX_INCLUDE_DOCS=OFF
    BUILD_COMMAND       ${CMAKE_COMMAND} --build "${_build_dir}" --parallel 6
    BUILD_BYPRODUCTS    "${_install_dir}/lib/libc++.a"
    INSTALL_DIR         "${_install_dir}"
    USES_TERMINAL_CONFIGURE TRUE
    USES_TERMINAL_BUILD     TRUE
    USES_TERMINAL_INSTALL   TRUE
)

file(MAKE_DIRECTORY "${_install_dir}/include/c++/v1")

add_library(libcxx STATIC IMPORTED GLOBAL)
add_dependencies(libcxx libcxx_build)

set_target_properties(libcxx PROPERTIES
    IMPORTED_LOCATION             "${_install_dir}/lib/libc++.a"
    INTERFACE_INCLUDE_DIRECTORIES "${_install_dir}/include/c++/v1"
)
