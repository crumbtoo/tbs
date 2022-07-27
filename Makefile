all: types-test

types-test: types-test.c
	clang -std=c89 -ansi -o types-test-ansi types-test.c
	clang -std=c89 -ansi -m32 -o types-test-ansi-32 types-test.c
	clang -o types-test types-test.c
	clang -o types-test-32 -m32 types-test.c

.PHONY:
clean:
	rm -rf *.out

.PHONY:
install:
	cp -r tbs /usr/include/

.PHONY:
uninstall:
	rm -rf /usr/include/tbs
