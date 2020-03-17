#!/bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
push_swap="./push_swap"
checker="./checker"

echo "#############  PUSHSWAP TESTs  #############
"

TEST_ARRAY=("2 1 3 6 5 8"
 "1 2 4 5 6 7 8 3 9  12 "
 "34 84 65 109 11 7 18 55 72 44 27 58 62 46 23 76 54 106 104 41"
 "56 36 17 54 32 63 20 107 55 64 5 52 57 75 23 108 59 31 58 89"
"53 47 28 109 59 108 33 38 67 95 66 93"
"56 36 17 54 32 63 20 107 55 64 5 52 57 75 23 108 59 31 58 89 1"
"7 91 -7 14 73 83 90 101 25 44 11 71 81 17 107 53 47 28 109 59 108 33 38 67 95 66 93 22 54 18 41 110 51 92 42 55 82 96 86 5 70 "
"-7 91 7 14 73 83 90 101 25 44 11 71 81 17 107 53 47 28 109 59 108 33 38 67 95 66 93 22 54 18 41 110 51 92 42 55 82 96 86 5 70 94 40 43 103 12 52 1 57 58 99 105 2 46 27 23 84 80 39 98 104 21 49 60 76 72 19 89 32 16 77 34 35 6 8 69 50 3 106 102 24 20 48 29 4 10 75 87 64 79 65 56 85 26 63 30 68 13 88 31"
)
for t in ${!TEST_ARRAY[@]}; do
	temp=${TEST_ARRAY[$t]}
	echo "OK_TEST	-> $(echo $temp | wc -w)"
	VAR=$($push_swap $temp | $checker $temp | grep OK)
	LINES=$($push_swap $temp | wc -l)
	if [ $VAR ]; then
		echo "		${GREEN}OK${NC}	linecount = $LINES"
	else
		echo "${RED}FAIL${NC}"
	fi
	echo "----------------------------------------------------"
done

echo "

#############  PUSH SWAP ERROR TESTs  #############
"

TEST_ARRAY=("12 3x4"
"-u"
"12ee"
"ee13"
"dd34gg"
"12 dd 45"
"12 56 -"
"""-"
"--6"
"- -13"
"- 12"
"-l -l"
"12 45 2147483648"
"45 2147483648 67"
"2147483648 45 16"
"12 45 -2147483649"
"45 -2147483649 67"
"-2147483649 45 16"
"45 23 45"
"23 23 45"
"45 23 23"
)

for t in ${!TEST_ARRAY[@]}; do
	temp=${TEST_ARRAY[$t]}
	echo "ERROR_TEST	-> $temp"
	VAR=$($push_swap $temp 2>&1)
	if [ $VAR ]; then
		echo "		${GREEN}OK${NC}"
	else
		echo "${RED}FAIL${NC}"
	fi
	echo "----------------------------------------------------"
done

echo "

#############  CHECKER ERROR TESTs  #############
"
TEST_ARRAY=("12 3x4"
"-u"
"12ee"
"ee13"
"dd34gg"
"12 dd 45"
"12 56 -"
"""-"
"--6"
"- -13"
"- 12"
"-l -l"
"12 45 2147483648"
"45 2147483648 67"
"2147483648 45 16"
"12 45 -2147483649"
"45 -2147483649 67"
"-2147483649 45 16"
"45 23 45"
"23 23 45"
"45 23 23"
)
for t in ${!TEST_ARRAY[@]}; do
	temp=${TEST_ARRAY[$t]}
	echo "ERROR_TEST	-> $temp"
	VAR=$($checker $temp 2>&1)
	if [ $VAR ]; then
		echo "		${GREEN}OK${NC}"
	else
		echo "${RED}FAIL${NC}"
	fi
	echo "----------------------------------------------------"
done

echo "#############  CHECKER COMMANDS OK TESTs  #############"
echo "ALL OK"
	echo "1:"
	NUMS="12 34 6"
	ARG=$($checker $NUMS <<EOF
pb
pb
pb
pb
pb
pb
pa
pa
pa
pa
pa
pa
rra)
	echo $ARG $ARG $ARG $ARG $ARG
	echo "2:"
	$checker 12 34 6 <<EOF
pb
pb
pb
pb
pb
pb
rb
pa
pa
pa
pa
pa
pa
EOF
	echo "3:"
	$checker 34 12 6 <<EOF
sa
rra
EOF
	echo "4:"
	$checker 34 12 6 <<EOF
sa
ra
ra
EOF
	echo "5:"
	ARG=$($checker -99999 -9999 999 -0 1 6 <<EOF
rb
rb
ss
sb
sa
rrr
rrr
rrr
rra
ss
rr
sa
ra
sa
rr
rr)
echo $ARG
	echo "6:"
	$checker -99999 -9999 999 -0 1 6 <<EOF
rr
ss
rrr
sb
sa
rr
EOF
	echo "7:"
	$checker -99999 -9999 999 -0 1 6 <<EOF
rb
ra
sa
ss
ss
rrb
rr
rrr
rra
sb
sa
rr
EOF
	echo "8:"
	$checker -99999 -9999 999 -0 1 6 <<EOF
rr
ss
rrr
sb
sa
rr
EOF
	echo "ALL KO"
	echo "1:"
	$checker 34 12 6 <<EOF
sa
ra
EOF
	echo "2:"
	$checker 34 12 6 <<EOF
sa
ra
EOF
	echo "3:"
	$checker -99999 -9999 999 -0 1 6 <<EOF
rb
rb
ss
rrr
sb
rrb
EOF
