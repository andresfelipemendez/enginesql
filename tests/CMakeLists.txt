project(myGameTests LANGUAGES CXX)

add_executable(myGameTests test1.cpp)

target_link_libraries(myGameTests PRIVATE enginelib)

add_test(NAME myGameTests COMMAND myGameTests)