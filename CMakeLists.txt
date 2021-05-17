cmake_minimum_required(VERSION 3.1.0)
project(dconv)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-address-of-packed-member")

file(STRINGS "${PROJECT_SOURCE_DIR}/VERSION" DCONV_VERSION)
string(REGEX REPLACE "([0-9]+)\\.[0-9]+\\.[0-9]+.*" "\\1" DCONV_VERSION_MAJOR ${DCONV_VERSION})
string(REGEX REPLACE "[0-9]+\\.([0-9])+\\.[0-9]+.*" "\\1" DCONV_VERSION_MINOR ${DCONV_VERSION})
string(REGEX REPLACE "[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" DCONV_VERSION_PATCH ${DCONV_VERSION})

message(STATUS "dconv version: ${DCONV_VERSION}")

option(DCONV_ENABLE_TESTS "Enable tests." OFF)

add_subdirectory(dconv)
