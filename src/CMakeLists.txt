project(enginelib LANGUAGES CXX)
add_library(enginelib enginelib.cpp)

project(enginesrc LANGUAGES CXX)

add_executable(enginesrc main.cpp)
target_link_libraries(enginesrc PUBLIC enginelib)