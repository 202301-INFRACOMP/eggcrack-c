cmake_minimum_required(VERSION 3.24)

project(eggcrack LANGUAGES C)

add_subdirectory(src)

add_executable(main main.c)
target_link_libraries(main PRIVATE eggcrack)
