cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)

project(Soundex LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER_LAUNCHER "ccache")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_CPPCHECK "cppcheck")

# CPM packages
set(CPM_DOWNLOAD_VERSION 0.32.1) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# CPMAddPackage("gh:Orphis/boost-cmake#7f97a08b64bd5d2e53e932ddf80c40544cf45edf@1.71.0")
# CPMFindPackage(
#     NAME boost-cmake
#     GITHUB_REPOSITORY Orphis/boost-cmake
#     VERSION 1.67.0
#     FIND_PACKAGE_ARGUMENTS "COMPONENTS system")

# CPMAddPackage(
#     NAME openssl
#     GITHUB_REPOSITORY openssl/openssl
#     GIT_TAG OpenSSL_1_1_1k
#     VERSION 1.1.1k
# )

# CPMAddPackage(
#     NAME openssl-cmake
#     GITHUB_REPOSITORY janbar/openssl-cmake
#     GIT_TAG 1.1.1k-20210430
#     VERSION 1.1.1k
# )

# CPMAddPackage(
#     NAME curl
#     GITHUB_REPOSITORY curl/curl
#     GIT_TAG curl-7_77_0
#     VERSION 7.77.0
# )

# CPMAddPackage(
#     NAME jsoncpp
#     GITHUB_REPOSITORY open-source-parsers/jsoncpp
#     GIT_TAG 1.9.4
#     VERSION 1.9.4
# )

add_subdirectory(./test/unit)

# add_executable(Soundex
#     src/Soundex.hpp
#     src/Soundex.cpp
# )