
## 前言
本教學將會學習到如何自己製作函式庫並使用 CMake 的 export 指令匯出庫安裝包，使可以在另一個 CMake c++ 專案中使用它。有兩中方法可以在外部專案使用到已寫好的庫，ch1會需要酷的原始碼一起編譯，ch2的方法是將庫先匯出安裝包並手動放在指定資料夾讓專案尋找並連結。

- [ch1](./ch1/)方法是透過add_subdirectory將mylib庫與應用程式專案一起編譯。同時會將mylib輸出安裝靜態庫
- [ch2](./ch2/)會介紹如何使用find_package方式將已編譯好的靜態庫與其他專案連結。

> 靜態庫和動態庫的構建可以先參考這一個repo教學[make-cpp-library](https://github.com/1010code/make-cpp-library)

## Reference
- [Simple find_package config file example](https://stackoverflow.com/questions/49857596/simple-find-package-config-file-example)