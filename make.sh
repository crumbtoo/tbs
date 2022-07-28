#!/bin/bash

# todo: rewrite with sh instead of bash

if [[ "$1" == "clean" ]]; then
	rm tests/tbs-* && echo "rm tests/tbs-*"
	exit
fi

objs="
tbs-clang-32-c89
tbs-clang-64-c89

tbs-clang-32-c99
tbs-clang-64-c99

tbs-clang++-32-c++11
tbs-clang++-64-c++11

tbs-gcc-32-c89
tbs-gcc-64-c89

tbs-gcc-32-c99
tbs-gcc-64-c99

tbs-g++-32-c++11
tbs-g++-64-c++11
"

mkdir tests

while read line; do

	[[ "$line" == "" ]] && continue

	IFS='-' read -r -a info <<< "$line"

	echo "${info[1]} -o $line -m${info[2]} -std=${info[3]} test.c"
	${info[1]} -pedantic -o tests/$line -m${info[2]} -std=${info[3]} test.c

done <<< "$objs"

