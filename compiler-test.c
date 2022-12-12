#include <stdio.h>
#include "tbs/types.h"

#if(TBS_WORDSIZE == 64)
	#define  TBS_WS_F  "%lu"
#else
	#define  TBS_WS_F  "%u"
#endif

#define STRING(s) #s
#define EXPAND_AND_STRING(s) STRING(s)

#define BITS(t) (sizeof(t) * 8)

int main()
{
	printf("%s\n", EXPAND_AND_STRING(TBS_ARCH));
	printf("tbs wordsize : %d\n", TBS_WORDSIZE);
	printf("wordsize     : " TBS_WS_F "\n", BITS(void*));
	printf("char         : " TBS_WS_F "\n", BITS(char));
	printf("short        : " TBS_WS_F "\n", BITS(short));
	printf("int          : " TBS_WS_F "\n", BITS(int));
	printf("long         : " TBS_WS_F "\n", BITS(long));
	printf("float        : " TBS_WS_F "\n", BITS(float));
	printf("double       : " TBS_WS_F "\n", BITS(double));
	printf("long double  : " TBS_WS_F "\n", BITS(long double));
	puts("------------------------------");

	printf("u8   : " TBS_WS_F "\n", BITS(u8));
	printf("u16  : " TBS_WS_F "\n", BITS(u16));
	printf("u32  : " TBS_WS_F "\n", BITS(u32));
#ifdef TBS_HAS_64
	printf("u64  : " TBS_WS_F "\n", BITS(u64));
#endif
#ifdef TBS_HAS_128
	printf("u128 : " TBS_WS_F "\n", BITS(u128));
#endif
	printf("uMax : " TBS_WS_F "\n", BITS(uMax));

	puts("");

	printf("i8   : " TBS_WS_F "\n", BITS(i8));
	printf("i16  : " TBS_WS_F "\n", BITS(i16));
	printf("i32  : " TBS_WS_F "\n", BITS(i32));
#ifdef TBS_HAS_64
	printf("i64  : " TBS_WS_F "\n", BITS(i64));
#endif
#ifdef TBS_HAS_128
	printf("i128 : " TBS_WS_F "\n", BITS(i128));
#endif
	printf("iMax : " TBS_WS_F "\n", BITS(iMax));

	puts("");

	printf("f32  : " TBS_WS_F "\n", BITS(f32));
	printf("f64  : " TBS_WS_F "\n", BITS(f64));
#if(TBS_MAX_FLOAT_BITS == 96)
	printf("f96  : " TBS_WS_F "\n", BITS(f96));
#endif
#if(TBS_MAX_FLOAT_BITS == 128)
	printf("f128 : " TBS_WS_F "\n", BITS(f128));
#endif
	printf("fMax : " TBS_WS_F "\n", BITS(fMax));
}
