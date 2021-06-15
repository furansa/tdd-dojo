cmake_minimum_required(VERSION 3.18.4 FATAL_ERROR)

project(SoundexTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_COMPILER_LAUNCHER "ccache")
set(CMAKE_CXX_CPPCHECK "cppcheck")

# CPM packages
set(CPM_DOWNLOAD_VERSION 0.32.1) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
    NAME googletest
    GITHUB_REPOSITORY google/googletest
    GIT_TAG release-1.11.0
    VERSION 1.11.0
    OPTIONS
        "INSTALL_GTEST OFF"
        "gtest_force_shared_crt ON"
)

add_executable(SoundexTest
    ../../src/Soundex.hpp
    ../../src/Soundex.cpp
    SoundexTest.cpp
)

target_link_libraries(SoundexTest
    gmock
    gtest
)

enable_testing()