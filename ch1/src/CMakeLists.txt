# 將 mylib 資料夾下的 CMakeLists.txt 加入到專案中
add_subdirectory(../libs/mylib "${CMAKE_BINARY_DIR}/libs/mylib")
# 編譯main.cpp文件為myapp可執行文件
add_executable(myapp main.cpp)
# 將myapp與mylib庫進行連結
target_link_libraries(myapp
    PRIVATE mylib
)

