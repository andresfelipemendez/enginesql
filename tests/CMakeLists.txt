project(myGameTests LANGUAGES CXX)

find_package(SDL2 CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

include(CTest)
include(Catch)
add_executable(myGameTests test1.cpp)

target_link_libraries(myGameTests PRIVATE Catch2::Catch2WithMain enginelib)

catch_discover_tests(myGameTests)