#include <stdio.h>
#include "tbs/types.h"

#if(TBS_WORDSIZE == 64)
	#define TBS_WS_F "%lu"
#else
	#define TBS_WS_F "%u"
#endif

#define STRING(s) #s
#define EXPAND_AND_STRING(s) STRING(s)

int main()
{
	printf("%s\n", EXPAND_AND_STRING(TBS_ARCH));
	printf("tbs wordsize: %d\n", TBS_WORDSIZE);
	printf("wordsize    : "TBS_WS_F"\n", sizeof(void*));
	printf("char        : "TBS_WS_F"\n", sizeof(char));
	printf("short       : "TBS_WS_F"\n", sizeof(short));
	printf("int         : "TBS_WS_F"\n", sizeof(int));
	printf("long        : "TBS_WS_F"\n", sizeof(long));
	/* printf("long long   : "TBS_WS_F"\n", sizeof(long long)); */
	printf("float       : "TBS_WS_F"\n", sizeof(float));
	printf("double      : "TBS_WS_F"\n", sizeof(double));
	printf("long double : "TBS_WS_F"\n", sizeof(long double));
	printf("__int128 : "TBS_WS_F"\n", sizeof(long double));
	puts("------------------------------");

	printf("u8   : "TBS_WS_F"\n", sizeof(u8));
	printf("u16  : "TBS_WS_F"\n", sizeof(u16));
	printf("u32  : "TBS_WS_F"\n", sizeof(u32));
#ifdef TBS_HAS_64
	printf("u64  : "TBS_WS_F"\n", sizeof(u8));
#endif
#ifdef TBS_HAS_128
	printf("u128 : "TBS_WS_F"\n", sizeof(u128));
#endif
}
