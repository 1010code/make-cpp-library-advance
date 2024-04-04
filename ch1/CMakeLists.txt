cmake_minimum_required(VERSION 3.20)

project(Example VERSION 0.1 LANGUAGES CXX )

include(GNUInstallDirs)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/bin/package/macx86_64")
    message(STATUS  "Target platform: macOS " ${CMAKE_CXX_COMPILER_ID})
elseif(UNIX)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/bin/package/aarch64")
    message(STATUS  "Target platform: UNIX")
else()
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/bin/package/mingw64")
    message(STATUS  "Target platform: Windows")
endif()

add_subdirectory(src bin)
