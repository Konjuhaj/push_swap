#!/bin/sh
gcc -Wall -Werror -Wextra -g srcs/*.c libraries/ft_printf/libft/libft.a libraries/ft_printf/libftprintf.a
ARG_ONE="1 2 4 5 6 7 8 3 9  12 "
ARG_THREE="53 47 28 109 59 108 33 38 67 95 66 93"
ARG_TWO="7 91 7 14 73 83 90 101 25 44 11 71 81 17 107 53 47 28 109 59 108 33 38 67 95 66 93 22 54 18 41 110 51 92 42 55 82 96 86 5 70 94 40 43 103 12 52 1 57 58 99 105 2 46 27 23 84 80 39 98 104 21 49 60 76 72 19 89 32 16 77 34 35 6 8 69 50 3 106 102 24 20 48 29 4 10 75 87 64 79 65 56 85 26 63 30 68 13 88 31"
./a.out $ARG_ONE > short.txt
./a.out $ARG_THREE > mid.txt
./a.out $ARG_TWO > long.txt
tail -n 10 short.txt
echo "---------------------------------------"
tail -n 100 long.txt
