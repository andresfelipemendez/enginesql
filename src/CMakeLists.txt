project(enginelib LANGUAGES CXX)
find_package(SDL2 CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(enginelib ${SOURCES})
target_link_libraries(enginelib sqlite3 ${SDL2_LIBRARIES} )

add_subdirectory(exe)