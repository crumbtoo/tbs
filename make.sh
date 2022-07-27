#!/bin/sh

if [[ "$1" == "clean" ]]; then
	rm tests/tbs-* && echo "rm tests/tbs-*"
	exit
fi

objs="tbs-clang-32-c89
tbs-clang-64-c89

tbs-clang-32-c90
tbs-clang-64-c90

tbs-gcc-32-c89
tbs-gcc-64-c89

tbs-gcc-32-c90
tbs-gcc-64-c90"

mkdir tests

while read line; do

	[[ "$line" == "" ]] && continue

	IFS='-' read -r -a info <<< "$line"

	echo "${info[1]} -o $line -m${info[2]} -std=${info[3]} test.c"
	${info[1]} -pedantic -o tests/$line -m${info[2]} -std=${info[3]} test.c

done <<< "$objs"

