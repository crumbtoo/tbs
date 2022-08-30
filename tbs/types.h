#ifndef TBS_TYPES_H
#define TBS_TYPES_H

#include "arch.h"

/* unsigned integers */
#ifndef TBS_NO_UINTS
	typedef unsigned char		u8;
	typedef unsigned short		u16;
	typedef unsigned int		u32;

#	if(TBS_WORDSIZE == 64)
#		define TBS_HAS_64
#		define TBS_MAX_UINT_BITS 64
		typedef unsigned long		u64;

#		ifndef __STDC__
#			define TBS_HAS_128
#			define TBS_MAX_UINT_BITS 128
			typedef unsigned __int128	u128;	/* todo: make sure target can support u128 before typedefing */
			typedef u128 umax;
#		else
			typedef u64 umax;
#		endif

#	elif(__STDC_VERSION__ >= 199901l)
#		define TBS_HAS_64
#		define TBS_MAX_UINT_BITS 64
		typedef signed long long u64;
		typedef u64 umax;
#	endif
#endif





#ifndef TBS_NO_SINTS
	typedef signed char					i8;
	typedef signed short				i16;
	typedef signed int					i32;

#	if(TBS_WORDSIZE == 64)
#		define TBS_MAX_SINT_BITS		128
#		define TBS_HAS_64
		typedef signed long				i64;

#		ifndef __STDC__
			typedef signed __int128		i128;
			typedef i128				imax;
#		else
			typedef i64					imax;
#		endif

#	elif(__STDC_VERSION__ >= 199901l)
#		define TBS_HAS_64
		typedef signed long long		i64;
		typedef i64					imax;
#	endif
#endif





#ifndef TBS_NO_FLOATS
	typedef float						f32;
	typedef double						f64;

#	if(TBS_WORDSIZE == 64)
#		define TBS_MAX_FLOAT_BITS		128
		typedef long double				f128;

#	elif(defined __SIZEOF_LONG_DOUBLE__ && defined __SIZEOF_DOUBLE__)
#		if(__SIZEOF_LONG_DOUBLE__ > __SIZEOF_DOUBLE__)
#			define TBS_MAX_FLOAT_BITS	96
			typedef long double			f96;
#		else
#			define TBS_MAX_FLOAT_BITS	64
#		endif
#	endif

	typedef long double					fmax; /* will be at least 64 bits */
#endif



#endif /* tbs/types.h */
