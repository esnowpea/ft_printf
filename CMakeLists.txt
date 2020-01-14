cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 90)

add_executable(ft_printf src/main.c src/ft_printf.c src/parsing.c src/ft_c.c src/ft_s.c)
target_include_directories(ft_printf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)


target_include_directories(ft_printf PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libft/inc)
find_library(FT ft libft)
target_link_libraries(ft_printf LINK_PUBLIC ${FT})