project(enginesrc LANGUAGES CXX)

set(CMAKE_EXE_LINKER_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

include_directories("${CMAKE_SOURCE_DIR}/src")

add_executable(enginesrc main.cpp)

add_custom_command(TARGET enginesrc POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/lib/SDL2/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:enginesrc>)

add_custom_command(TARGET enginesrc POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/db"
        $<TARGET_FILE_DIR:enginesrc>)

add_custom_command(TARGET enginesrc POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets/"
        $<TARGET_FILE_DIR:enginesrc>/assets)

target_link_libraries(enginesrc PUBLIC enginelib)

