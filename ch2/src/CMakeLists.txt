# 設置庫安裝路徑前綴
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/package/macx86_64")
    message(STATUS  "Target platform: macOS " ${CMAKE_CXX_COMPILER_ID})
elseif(UNIX)
    set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/package/aarch64")
    message(STATUS  "Target platform: UNIX")
else()
    set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/package/mingw64")
    message(STATUS  "Target platform: Windows")
endif()


# 尋找庫
find_package(mylib)
add_executable(myapp main.cpp)
# 創建myapp並連結相依庫
target_link_libraries(myapp
    PRIVATE
    Mylib::mylib
)