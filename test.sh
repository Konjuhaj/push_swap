#!/bin/sh
gcc -Wall -Werror -Wextra -g srcs/*.c libraries/ft_printf/libft/libft.a libraries/ft_printf/libftprintf.a
# ./a.out 1 2 "4 5 6" 7 "8 3   9  12 "
./a.out 5 19 10 3 2 11 18 17
