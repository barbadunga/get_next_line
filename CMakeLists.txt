cmake_minimum_required(VERSION 3.13)
project(get_next_line)

set(CMAKE_CXX_STANDARD 14)

add_executable(get_next_line get_next_line.c)
target_link_libraries(get_next_line ${CMAKE_SOURCE_DIR}/libft/libft.a)
