cmake_minimum_required(VERSION 3.14)
project(stm32-i2c-cpp-driver)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)                    always — portable, both builds

IF not cross-compiling:
    enable_testing()
    add_subdirectory(tests)
ELSE:
    add_subdirectory(port/stm32f4)
    add_subdirectory(app)
