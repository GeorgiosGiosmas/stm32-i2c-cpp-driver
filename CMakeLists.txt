cmake_minimum_required(VERSION 3.14)
project(stm32-i2c-cpp-driver)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)                    

if(NOT CMAKE_CROSSCOMPILING)
    enable_testing()
    add_subdirectory(tests)
else()
    add_subdirectory(port/stm32f4)
    add_subdirectory(app)
endif()