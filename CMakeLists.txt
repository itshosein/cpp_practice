set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")


# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)


# Project name and version
project(Exercise VERSION 1.0)


# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optionally, add the global include directory if needed
include_directories(${CMAKE_SOURCE_DIR}/include)


# add_subdirectory("src/*")

add_subdirectory(src)