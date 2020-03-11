cmake_minimum_required(VERSION 3.0)

add_executable (Demo Demo.cpp)
target_link_libraries(Demo MPU6050 rt)
target_include_directories(Demo PRIVATE ..)