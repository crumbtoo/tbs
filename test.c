#include <stdio.h>
#include "tbs/types.h"

#if(TBS_WORDSIZE == 64)
	#define  TBS_WS_F  "%lu"
#else
	#define  TBS_WS_F  "%u"
#endif

#define STRING(s) #s
#define EXPAND_AND_STRING(s) STRING(s)

int main()
{
	printf("%s\n", EXPAND_AND_STRING(TBS_ARCH));
	printf("tbs wordsize: %d\n", TBS_WORDSIZE);
	printf("wordsize    : " TBS_WS_F "\n", sizeof(void*));
	printf("char        : " TBS_WS_F "\n", sizeof(char));
	printf("short       : " TBS_WS_F "\n", sizeof(short));
	printf("int         : " TBS_WS_F "\n", sizeof(int));
	printf("long        : " TBS_WS_F "\n", sizeof(long));
	/* printf("long long   : " TBS_WS_F "\n", sizeof(long long)); */
	printf("float       : " TBS_WS_F "\n", sizeof(float));
	printf("double      : " TBS_WS_F "\n", sizeof(double));
	printf("long double : " TBS_WS_F "\n", sizeof(long double));
	printf("__int128 : " TBS_WS_F "\n", sizeof(long double));
	puts("------------------------------");

	printf("u8   : " TBS_WS_F "\n", sizeof(u8) * 8);
	printf("u16  : " TBS_WS_F "\n", sizeof(u16) * 8);
	printf("u32  : " TBS_WS_F "\n", sizeof(u32) * 8);
#ifdef TBS_HAS_64
	printf("u64  : " TBS_WS_F "\n", sizeof(u64) * 8);
#endif
#ifdef TBS_HAS_128
	printf("u128 : " TBS_WS_F "\n", sizeof(u128) * 8);
#endif

	printf("i8   : " TBS_WS_F "\n", sizeof(i8) * 8);
	printf("i16  : " TBS_WS_F "\n", sizeof(i16) * 8);
	printf("i32  : " TBS_WS_F "\n", sizeof(i32) * 8);
#ifdef TBS_HAS_64
	printf("i64  : " TBS_WS_F "\n", sizeof(i64) * 8);
#endif
#ifdef TBS_HAS_128
	printf("i128 : " TBS_WS_F "\n", sizeof(i128) * 8);
#endif

	printf("f32  : " TBS_WS_F "\n", sizeof(f32) * 8);
	printf("f64  : " TBS_WS_F "\n", sizeof(f64) * 8);
#if(TBS_LARGE_FLOAT_SIZE == 96)
	printf("f96  : " TBS_WS_F "\n", sizeof(f96) * 8);
#endif
#if(TBS_LARGE_FLOAT_SIZE == 128)
	printf("f128 : " TBS_WS_F "\n", sizeof(f128) * 8);
#endif
	printf("f64p : " TBS_WS_F "\n", sizeof(f64plus) * 8);
}
