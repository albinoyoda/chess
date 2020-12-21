set(CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION 3.14)
project(chess_library)

if (CMAKE_BUILD_TYPE MATCHES Debug)

    message("CMAKE IN DEBUG MODE")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -Werror -Wall -Wextra")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Werror -Wall -Wextra")
    #    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

else ()

    message("CMAKE IN RELEASE MODE")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -ffast-math")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -ffast-math")

endif ()

include_directories(include)

add_library(
        chess_library STATIC
        source/Chess_board.cpp
        source/Piece.cpp
        source/Moves.cpp
        source/Types.cpp
        source/Test_functions.cpp
        include/Test_functions.tcc
        source/Tree_search.cpp)

