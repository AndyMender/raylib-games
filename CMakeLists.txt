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

set(raylib_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/raylib")
set(raylib_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/raylib")
set(raylib_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${raylib_INSTALL_DIR})
set(raylib_VERSION "4.2.0")

# Check raylib install
find_package(raylib ${raylib_VERSION})

# Install raylib from upstream
if (NOT raylib_FOUND)
	find_package(Git REQUIRED)
	include(ExternalProject)
	ExternalProject_Add(raylib
		PREFIX ${raylib_PREFIX}
		GIT_REPOSITORY	https://github.com/raysan5/raylib.git
		GIT_TAG			${raylib_VERSION}
		INSTALL_DIR 	${raylib_INSTALL_DIR}
		CMAKE_ARGS 		${raylib_CMAKE_ARGS}
		STEP_TARGETS	build
	)
endif()

# TODO: make this step platform-dependent
include_directories(
	"/usr/include"
	"/usr/local/include"
	"${raylib_INSTALL_DIR}/include")

# TODO: make this step platform-dependent
link_directories(
	"/usr/lib"
	"/usr/lib64"
	"/usr/local/lib")

# make sure targets end up in specific places for easier distribution
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/apps")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

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
