cmake_minimum_required(VERSION 3.13)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -Werror -Wextra")

file(GLOB LIBFT libft/*.c libft/*.h )

set(SOURCES  push_swap.h ft_check_argv.c ft_creat_stack.c ft_print_stack.c ft_operations.c ft_sa_sb_ss_pa_pb.c ft_ra_rb_rr_rra_rrb.c ft_rrr.c ft_sorting.c checker.c)

add_executable(push_swap ${SOURCES} ${LIBFT})