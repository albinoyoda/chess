set(CMAKE_CXX_STANDARD 14)
project(chess_library)

if (CMAKE_BUILD_TYPE MATCHES Debug)

    message("CMAKE IN DEBUG MODE")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -Werror -Wall -Wextra")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Werror -Wall -Wextra")
    #    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

else ()

    message("CMAKE IN RELEASE MODE")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

endif ()

include_directories(include)

add_library(
        chess_library STATIC
        source/Chess_board.cpp
        source/Piece.cpp
        source/Moves.cpp
        source/Types.cpp source/Test_functions.cpp include/Test_functions.hpp source/Tree_search.cpp include/Tree_search.hpp)

