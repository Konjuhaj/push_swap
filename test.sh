#!/bin/sh
gcc -Wall -Werror -Wextra -g srcs/*.c libraries/ft_printf/libft/libft.a libraries/ft_printf/libftprintf.a -o push_swap
gcc -Wall -Werror -Wextra -g srcs/*.c libraries/ft_printf/libft/libft.a libraries/ft_printf/libftprintf.a -o checker

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

mkdir test_results 2>/dev/null | echo "" >/dev/null
rm -f /test_results/*.txt

echo "-------------------SHORT TESTs-----------------------"

ARG_ZERO="2 1 3 6 5 8"
VAR=$(./a.out $ARG_ZERO | grep OK)
echo "Short test	-> 6 numbers"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_ZERO | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_ZERO > 0SHORT_TEST.txt

echo "----------------------------------------------------"

ARG_ONE="1 2 4 5 6 7 8 3 9  12 "
VAR=$(./a.out $ARG_ONE | grep OK)
echo "Short test	-> 10 numbers"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_ONE | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_ONE > 1SHORT_TEST.txt

echo "----------------------------------------------------"

ARG_SMALL="34 84 65 109 11 7 18 55 72 44 27 58 62 46 23 76 54 106 104 41"
VAR=$(./a.out $ARG_SMALL | grep OK)
echo "Short2 test	-> 20 numbers"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_SMALL | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_SMALL > 2SHORT_TEST.txt

echo "----------------------------------------------------"

ARG_SMALL2="56 36 17 54 32 63 20 107 55 64 5 52 57 75 23 108 59 31 58 89"
VAR=$(./a.out $ARG_SMALL2 | grep OK)
echo "Short3 test	-> 20 numbers"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_SMALL2 | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_SMALL > 3SHORT_TEST.txt

echo "----------------------------------------------------"

ARG_THREE="53 47 28 109 59 108 33 38 67 95 66 93"
VAR=$(./a.out $ARG_THREE | grep OK)
echo "Mid test	-> 12 numbers"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_THREE | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_THREE > 4SHORT_TEST.txt

echo "\n\n--------------------LONG TESTs-----------------------"

ARG_BIG2="56 36 17 54 32 63 20 107 55 64 5 52 57 75 23 108 59 31 58 89 1"
VAR=$(./a.out $ARG_BIG2 | grep OK)
echo "BIG1 test	-> 21 numbers"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_BIG2 | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_BIG2 > BIG1.txt

echo "----------------------------------------------------"

ARG_MID="7 91 -7 14 73 83 90 101 25 44 11 71 81 17 107 53 47 28 109 59 108 33 38 67 95 66 93 22 54 18 41 110 51 92 42 55 82 96 86 5 70 "
VAR=$(./a.out $ARG_MID | grep OK)
echo "Mid-long test	-> 41 numbers"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_MID | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_MID > BIG2.txt

echo "----------------------------------------------------"

ARG_TWO="-7 91 7 14 73 83 90 101 25 44 11 71 81 17 107 53 47 28 109 59 108 33 38 67 95 66 93 22 54 18 41 110 51 92 42 55 82 96 86 5 70 94 40 43 103 12 52 1 57 58 99 105 2 46 27 23 84 80 39 98 104 21 49 60 76 72 19 89 32 16 77 34 35 6 8 69 50 3 106 102 24 20 48 29 4 10 75 87 64 79 65 56 85 26 63 30 68 13 88 31"
VAR=$(./a.out $ARG_TWO | grep 'OK')
echo "LONG test	-> 100 numbers"
if [ $VAR ]; then
	LINES=$(./a.out $ARG_TWO | wc -l)
	echo "		${GREEN}OK${NC}	linecount = $LINES"
else
		echo "${RED}FAIL${NC}"
fi
./a.out $ARG_TWO > BIG3.txt

mv *.txt test_results
