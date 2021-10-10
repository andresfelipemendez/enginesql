project(enginesrc LANGUAGES CXX)

set(CMAKE_EXE_LINKER_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

include_directories("${CMAKE_SOURCE_DIR}/src")

add_executable(enginesrc main.cpp)

target_link_libraries(enginesrc PUBLIC enginelib)