#ifndef SIZEOF_TEST_TEMPLATE_H
#define SIZEOF_TEST_TEMPLATE_H

#ifndef SIZEOFTEST_TYPE
#	error "define SIZEOFTEST_TYPE to test a type's size"
#endif

#ifndef SIZEOFTEST_SIZE
#	error "define SIZEOFTEST_SIZE to test a type's size"
#endif

#include <tbs/types.h>

int main()
{
	return sizeof(SIZEOFTEST_TYPE) == (SIZEOFTEST_SIZE);
}

#endif /* SIZEOF_TEST_TEMPLATE_H */
