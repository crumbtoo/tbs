# tbs
types by size - C header to define types by bit-width

## install

install headers with
`$ sudo make install`

uninstall with
`$ sudo make uninstall`

build tests with
`$ ./make.sh`

remove tests with
`$ ./make.sh clean`

## types
unsigned types
`u8`-`u64` (`u128` when supported)

signed types
`i8`-`i64` (`i128` when supported)

floating point types
`f32`, `f64`, `f96`/`f128` (`f128` when supported)

`f64plus` will be typedef'd to the largest floating type available (`f96` on 32-bit systems, `f128` on 64-bit)

## macros

 - `TBS_ARCH`                set to the detected cpu arch (see arch.h)

 - `TBS_WORDSIZE`            set to the wordsize, based on TBS_ARCH

 - `TBS_HAS_64`              defined if 64-bit types are defined

 - `TBS_HAS_128`             defined if 128-bit types are defined

## tested on

| arch		| gcc | clang | g++ | clang++ |
| --------- | --- | ----- | --- | ------- |
| x86_64	| X   | X     | X   | X		  |
| x86_32	| X   | X     | X   | X		  |

