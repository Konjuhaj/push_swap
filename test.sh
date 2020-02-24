#!/bin/sh
gcc -Wall -Werror -Wextra -g srcs/*.c libraries/ft_printf/libft/libft.a libraries/ft_printf/libftprintf.a
# ./a.out 1 2 "4 5 6" 7 "8 3   9  12 "
./a.out 44 79 59 63 42 19 66 9 28 17 27 7 36 50 8 40 94
