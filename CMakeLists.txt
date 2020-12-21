cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)
project(chess_project)

include_directories(util/include/)

add_executable(pepega_chess main.cpp)
target_link_libraries(pepega_chess chess_library)

add_executable(test_performance main_test_performance.cpp)
target_link_libraries(test_performance chess_library)

add_subdirectory(Google_tests)
add_subdirectory(util)