#!/bin/sh
gcc -Wall -Werror -Wextra -g srcs/*.c libraries/ft_printf/libft/libft.a libraries/ft_printf/libftprintf.a
# ./a.out 1 2 "4 5 6" 7 "8 3   9  12 "
./a.out 54  15  31  8  81  46  30  29  37  78  83  99  82  50  26  62  79  32  88  98
