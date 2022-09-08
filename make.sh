#! /bin/sh

tests="
tbs-clang++-32-c++11
tbs-clang-32-c89
tbs-clang-32-c99
tbs-clang++-64-c++11
tbs-clang-64-c89
tbs-clang-64-c99
tbs-g++-32-c++11
tbs-g++-64-c++11
tbs-gcc-32-c89
tbs-gcc-32-c99
tbs-gcc-64-c89
tbs-gcc-64-c99"

for i in $tests; do
	IFS="-"
	read -ra arr <<< "$i"

	echo "${arr[1]} -m${arr[2]} -std=${arr[3]} -o $i"

	${arr[1]} -m"${arr[2]}" -std="${arr[3]}" -o "tests/$i" "test.c"
done
