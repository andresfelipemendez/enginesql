project(imgui LANGUAGES CXX)

find_package(SDL2 CONFIG REQUIRED)

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/lib/imgui)
    
# Compile as static library
set (
	IMGUI_SOURCES

	${IMGUI_DIR}/imgui.cpp
	${IMGUI_DIR}/imgui.h
	${IMGUI_DIR}/imconfig.h
	${IMGUI_DIR}/imgui_demo.cpp
	${IMGUI_DIR}/imgui_draw.cpp
	${IMGUI_DIR}/imgui_internal.h
	${IMGUI_DIR}/imgui_tables.cpp
	${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_impl_win32.h
    ${IMGUI_DIR}/imgui_impl_win32.cpp
    ${IMGUI_DIR}/imgui_impl_opengl3.h
    ${IMGUI_DIR}/imgui_impl_opengl3.cpp
    ${IMGUI_DIR}/imgui_impl_sdl.h
    ${IMGUI_DIR}/imgui_impl_sdl.cpp
)

add_library(imgui STATIC
    ${IMGUI_SOURCES})

target_include_directories(imgui PUBLIC
   ${IMGUI_PATH} ${SDL2_INCLUDE_DIRS})

target_link_libraries(imgui )
