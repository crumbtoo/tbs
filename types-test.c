#include <stdio.h>
#include <tbs/types.h>
/* #include "tbs/types.h" */

#if(TBS_WORDSIZE == 64)
#define FMT "%lu"
#else
#define FMT "%u"
#endif

int main()
{
	u8 n_u8;
	u16 n_u16;
	u32 n_u32;
#ifdef TBS_HAS_64
	u64 n_u64;
#endif
#if(TBS_LARGE_UINT_SIZE == 128)
	u128 n_u128;
#elif(TBS_LARGE_UINT_SIZE == 96)
	u96 n_u96;
#endif

	i8 n_i8;
	i16 n_i16;
	i32 n_i32;
#ifdef TBS_HAS_64
	i64 n_i64;
#endif
#if(TBS_LARGE_SINT_SIZE == 128)
	i128 n_i128;
#elif(TBS_LARGE_SINT_SIZE == 96)
	i96 n_i96;
#endif

	f32 n_f32;
	f64 n_f64;
#if(TBS_LARGE_FLOAT_SIZE == 128)
	f128 n_f128;
#elif(TBS_LARGE_FLOAT_SIZE == 96)
	f96 n_f96;
#endif

	printf("u8   : "FMT"\n", sizeof(n_u8));
	printf("u16  : "FMT"\n", sizeof(n_u16));
	printf("u32  : "FMT"\n", sizeof(n_u32));
#ifdef TBS_HAS_64
	printf("u64  : "FMT"\n", sizeof(n_u64));
#endif
#if(TBS_LARGE_UINT_SIZE == 128)
	printf("u128 : "FMT"\n", sizeof(n_u128));
#elif(TBS_LARGE_UINT_SIZE == 96)
	printf("u96  : "FMT"\n", sizeof(n_u96));
#endif

	printf("i8   : "FMT"\n", sizeof(n_i8));
	printf("i16  : "FMT"\n", sizeof(n_i16));
	printf("i32  : "FMT"\n", sizeof(n_i32));
#ifdef TBS_HAS_64
	printf("i64  : "FMT"\n", sizeof(n_i64));
#endif
#if(TBS_LARGE_SINT_SIZE == 128)
	printf("i128 : "FMT"\n", sizeof(n_i128));
#elif(TBS_LARGE_SINT_SIZE == 96)
	printf("i96  : "FMT"\n", sizeof(n_i96));
#endif

	printf("f32  : "FMT"\n", sizeof(n_f32));
	printf("f64  : "FMT"\n", sizeof(n_f64));
#if(TBS_LARGE_FLOAT_SIZE == 128)
	printf("f128 : "FMT"\n", sizeof(n_f128));
#elif(TBS_LARGE_FLOAT_SIZE == 96)
	printf("f96  : "FMT"\n", sizeof(n_f96));
#endif
}
