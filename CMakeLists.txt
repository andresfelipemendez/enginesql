cmake_minimum_required(VERSION 3.20)
project(engine)
set(CMAKE_CXX_STANDARD 20)

include(CTest) # We include CTest which is part of CMake

set(SDL2_DIR "${CMAKE_SOURCE_DIR}/lib/SDL2")
add_subdirectory(lib/SQLite3)
add_subdirectory(src)

# We check if this is the main file
# you don't usually want users of your library to
# execute tests as part of their build
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(tests)
endif ()

enable_testing()