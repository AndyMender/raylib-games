cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

# NOTE: Bump VERSION as needed
project(raylib-games
	VERSION 0.2
	DESCRIPTION "A set of simple games using the raylib game framework"
	LANGUAGES C CXX
)

# enforce C standard and disallow non-portable compiler extensions
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# enforce C++ standard and disallow non-portable compiler extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# set pthreads correctly
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# Local third-party install paths
set(raylib_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/raylib")
set(glog_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/glog")

# Check raylib install
set(raylib_VERSION "4.2.0")
find_package(raylib ${raylib_VERSION} REQUIRED)

# Check glog install
set(glog_VERSION "0.6.0")
find_package(glog ${glog_VERSION} REQUIRED)

# TODO: make this step platform-dependent
include_directories(
	"/usr/include"
	"/usr/local/include"
)

# TODO: make this step platform-dependent
link_directories(
	"/usr/lib"
	"/usr/lib64"
	"/usr/local/lib")

# make sure targets end up in specific places for easier distribution
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/apps")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

# TODO: make flags platform dependent
# add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# add source code subdirs
add_subdirectory("src")

# link-time optimization (LTO)
include(CheckIPOSupported)
check_ipo_supported(RESULT LTO_SUPPORTED)

if(LTO_SUPPORTED)
	set(INTERPROCEDURAL_OPTIMIZATION ON)
else()
	message(STATUS "LTO not supported on this platform.")
endif()
