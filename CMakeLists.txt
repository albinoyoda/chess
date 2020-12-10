cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
project(chess_project)

include_directories(common/include/)

add_executable(chess main.cpp)
target_link_libraries(chess chess_library)

add_subdirectory(Google_tests)
add_subdirectory(common)