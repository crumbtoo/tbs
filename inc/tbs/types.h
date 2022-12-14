#ifndef TBS_TYPES_H
#define TBS_TYPES_H

#include "arch.h"

#ifndef TBS_NO_GENERICS
	typedef unsigned int uint;
	typedef unsigned long ulong;
#endif

/* oh the horror
 * we're only supporting 32 and 64-bit systems **AT THE MOMENT** */
#define TBS_CHAR_WIDTH					8
#define TBS_INT_WIDTH					32

typedef unsigned char					u8;
typedef unsigned short					u16;
typedef unsigned int					u32;

typedef signed char						i8;
typedef signed short					i16;
typedef signed int						i32;

typedef float							f32;
typedef double							f64;
typedef long double						fMax;

#if(TBS_WORDSIZE == 64)
	typedef unsigned long int			u64;
	typedef signed long int				i64;
	typedef long double					f128;
#else
	/* dont ever use `f80` unless you're doing some batshit insane bithacks lmfao */
	typedef long double					f80; /* 80-bit extended + 16 bits of padding */
#	if(__STDC_VERSION__ >= 199901l)
		typedef unsigned long long		u64;
		typedef unsigned long long		i64;
#	endif
#endif

#if defined(__SIZEOF_INT128__) && defined(TBS_ALLOW_128_BIT_INTS)
	typedef unsigned __int128			u128;
	typedef signed __int128				i128;
#endif


#if (defined(__SIZEOF_INT128__) && defined(TBS_ALLOW_128_BIT_INTS))
#	define TBS_MAX_WIDTH 128
#elif (TBS_WORDSIZE == 64)
#	define TBS_MAX_WIDTH 64
#elif ((TBS_WORDSIZE == 32) && (__STDC_VERSION__ >= 199901l))
#	define TBS_MAX_WIDTH 64
#elif (TBS_WORDSIZE == 32)
#	define TBS_MAX_WIDTH 32
#endif


#if TBS_MAX_WIDTH == 128 && defined(TBS_ALLOW_128_BIT_INTS)
	typedef u128						uMax;
	typedef i128						iMax;
#elif(TBS_MAX_WIDTH >= 64)
	typedef u64							uMax;
	typedef i64							iMax;
#elif(TBS_MAX_WIDTH == 32)
	typedef u32							uMax;
	typedef i32							iMax;
#endif


#endif /* guard */

