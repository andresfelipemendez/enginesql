project(enginelib LANGUAGES CXX)
find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/lib/imgui)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_library(enginelib ${SOURCES})
target_link_libraries(enginelib imgui sqlite3 ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})

