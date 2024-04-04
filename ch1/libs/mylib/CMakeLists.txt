PROJECT(mylib  LANGUAGES C CXX VERSION 1.0.0)
file(GLOB_RECURSE PdM_lib_FILES CONFIGURE_DEPENDS  
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
add_library(mylib STATIC ${PdM_lib_FILES})

target_include_directories(mylib 
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                           "$<INSTALL_INTERFACE:mylib/include>"
                           )


#-----Install Script-----
# 安裝mylib庫的目標文件到特定目錄中
install(TARGETS mylib
        EXPORT mylib
        LIBRARY DESTINATION mylib/lib
        ARCHIVE DESTINATION mylib/lib
        RUNTIME DESTINATION mylib/bin
        INCLUDES DESTINATION mylib/include
)
# 安裝include目錄下的頭文件到mylib/include目錄中
install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    DESTINATION "mylib/include"
    FILES_MATCHING PATTERN "*.h"
)
# 將mylib庫的CMake封裝導出為mylib.cmake文件
# 這裡的NAMESPACE 為 Mylib::mylib
# YouprPackage::your_target
install(EXPORT mylib
        FILE mylib.cmake
        NAMESPACE Mylib::
        DESTINATION  mylib/cmake
)

# 生成mylib的配置文件和版本文件
include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/mylibConfig.cmake"
  INSTALL_DESTINATION cmake
)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/mylibConfigVersion.cmake"
  VERSION "${version}"
  COMPATIBILITY AnyNewerVersion
)
# 安裝mylib的配置文件和版本文件到mylib/cmake目錄中
install(FILES
          "${CMAKE_CURRENT_BINARY_DIR}/mylibConfig.cmake"
          "${CMAKE_CURRENT_BINARY_DIR}/mylibConfigVersion.cmake"
        DESTINATION  mylib/cmake
)
