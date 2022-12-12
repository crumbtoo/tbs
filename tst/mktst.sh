#!/bin/sh

if [ "$1" = "clean" ]; then
	rm -rf sizeof-*.c
fi

tbs_types=$(echo "$tbs_types" | tr ':' '\n')

for i in $tbs_types; do
	echo "$i" | grep 'Max'

	if [ $? -eq '0' ]; then
		type=$(echo "$i" | sed 's/^\([uif]\)Max/\1/')

		if [ "$type" = "f" ]; then
			size="$fMax_size"
		elif [ "$type" = "u" ]; then
			size="$uMax_size"
		elif [ "$type" = "i" ]; then
			size="$iMax_size"
		fi
	else
		size=$(echo "$i" | sed 's/^[uif]//')
	fi
	
	echo \
	"#define SIZEOFTEST_TYPE $i
#define SIZEOFTEST_SIZE $size
#include \"sizeof-test-template.h\"" > "sizeof-$i.c"
done
