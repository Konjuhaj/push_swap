#!/bin/sh
gcc -Wall -Werror -Wextra -g srcs/*.c libraries/ft_printf/libft/libft.a libraries/ft_printf/libftprintf.a

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir test_results 2>/dev/null | echo "" >/dev/null

ARG_ONE="1 2 4 5 6 7 8 3 9  12 "
VAR=$(./a.out $ARG_ONE | grep OK)
echo "Short test"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_ONE | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_ONE > SHORT_TEST.txt

ARG_THREE="53 47 28 109 59 108 33 38 67 95 66 93"
VAR=$(./a.out $ARG_THREE | grep OK)
echo "Mid test"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_ONE | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_THREE > MID_TEST.txt

ARG_MID="7 91 7 14 73 83 90 101 25 44 11 71 81 17 107 53 47 28 109 59 108 33 38 67 95 66 93 22 54 18 41 110 51 92 42 55 82 96 86 5 70 "
VAR=$(./a.out $ARG_MID | grep OK)
echo "Mid-long test"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_ONE | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_MID > MID_LONG.txt


ARG_TWO="7 91 7 14 73 83 90 101 25 44 11 71 81 17 107 53 47 28 109 59 108 33 38 67 95 66 93 22 54 18 41 110 51 92 42 55 82 96 86 5 70 94 40 43 103 12 52 1 57 58 99 105 2 46 27 23 84 80 39 98 104 21 49 60 76 72 19 89 32 16 77 34 35 6 8 69 50 3 106 102 24 20 48 29 4 10 75 87 64 79 65 56 85 26 63 30 68 13 88 31"
VAR=$(./a.out $ARG_TWO | grep -q 'OK')
echo "LONG test"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_ONE | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_TWO > LONG_TEST.txt

mv *.txt test_results
