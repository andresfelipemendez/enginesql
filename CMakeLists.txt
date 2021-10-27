cmake_minimum_required(VERSION 3.20)
project(engine)
set(CMAKE_CXX_STANDARD 20)


set(SDL2_DIR "${CMAKE_SOURCE_DIR}/lib/SDL2")
add_subdirectory(lib/SQLite3)
add_subdirectory(src)

set(TINYGLTF_HEADER_ONLY ON CACHE INTERNAL "" FORCE)
set(TINYGLTF_INSTALL OFF CACHE INTERNAL "" FORCE)
set(TINYGLTF_BUILD_LOADER_EXAMPLE OFF CACHE INTERNAL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/tinygltf)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(tests)
endif ()

enable_testing()