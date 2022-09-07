# tbs
types by size - C header to define types by bit-width

## types
unsigned types
`u8`-`u64` (`u128` when supported)

signed types
`i8`-`i64` (`i128` when supported)

floating point types
`f32`, `f64`, `f96`/`f128` (`float`, `double`, and `long double`, respectively)

`[uif]max` will be typedef'd to the widest type available

## macros

 - `TBS_ARCH`                set to the detected cpu arch (see arch.h)

 - `TBS_WORDSIZE`            set to the wordsize, based on TBS_ARCH

 - `TBS_HAS_64`              defined if 64-bit types are defined

 - `TBS_HAS_128`             defined if 128-bit types are defined

## tested on

| OS			| arch		| gcc | clang | g++ | clang++ |
| ------------- | --------- | --- | ----- | --- | ------- |
| Arch Linux	| x86_64	| X   | X     | X   | X		  |
| Arch Linux	| x86_32	| X   | X     | X   | X		  |
| MacOS 12.4	| x86_64	| X   | X     | X   | X		  |

