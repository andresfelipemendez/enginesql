project(sqlite3 LANGUAGES CXX)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/lib/SQLite3/*.c")
add_library(sqlite3 ${SOURCES})

target_include_directories (sqlite3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})