#!/bin/sh

tests32="tbs-clang++-32-c++11
tbs-clang-32-c89
tbs-clang-32-c99
tbs-g++-32-c++11
tbs-gcc-32-c89
tbs-gcc-32-c99"

tests64="tbs-clang++-64-c++11
tbs-clang-64-c89
tbs-clang-64-c99
tbs-g++-64-c++11
tbs-gcc-64-c89
tbs-gcc-64-c99"

# if -32 is passed, add 32-bit tests to $tests
# if -64 is passed, add 64-bit tests to $tests
# if both are passed, add both to $tests
# if neither is passed, error out
if [ "$1" = "-32" ]; then
	tests="$tests32"
elif [ "$1" = "-64" ]; then
	tests="$tests64"
elif [ "$1" = "-both" ]; then
	tests="$tests32 $tests64"
else
	echo "ERROR: Specify either 32-bit tests only, 64-bit tests only, or both."
	echo "Usage: $0 [-32|-64|-both]"
	exit 1
fi

if [ ! -d tests ]; then
	mkdir tests
fi

for i in $tests; do

	ar1=$(echo "$i" | cut -d'-' -f2)
	ar2=$(echo "$i" | cut -d'-' -f3)
	ar3=$(echo "$i" | cut -d'-' -f4)

	echo "${ar1} -m${ar2} -std=${ar3} -o $i"

	${ar1} -m"${ar2}" -std="${ar3}" -o "tests/$i" "test.c"
done
