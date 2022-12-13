# tbs
types by size - C header to define primative types by bit-width

## Install
#### With Meson
```
$ meson build && cd build
$ meson test               # optional, but highly recommended
$ sudo meson install       # install headers
```
#### Manually
You can copy the `inc/tbs/` directory into the appropriate include location if you insist on not using Meson.
pkgconfig files will not be made and tests will not be done.

## Types
#### Generics
`uint`, `ulong` typedef'd to `unsigned int` and `unsigned long`, respectively. Disabled by defining `TBS_NO_GENERICS`.

#### Unsigned Types
`u8`, `u16`, `u32`, `u64` (`u128` if supported by system, and if `TBS_ALLOW_128_BIT_INTS` is defined)

#### Signed Types
`i8`, `i16`, `i32`, `i64` (`i128` if supported by system, and if `TBS_ALLOW_128_BIT_INTS` is defined)

#### Floating-point Types
`f32`, `f64`, `f80`/`f128` (`float`, `double`, and `long double`, respectively)

Avoid using `f128`, and especially `f80`, if you don't have a specific reason to. 
Unless you are doing unportable bithacks or need the extra precision, it's pointless.


`fMax`, `uMax`, and `iMax` will be typedef'd to the widest respective type available

## Macros

 - `TBS_ARCH`               set to the detected cpu arch (see `arch.h`)

 - `TBS_WORDSIZE`           set to the wordsize, based on `TBS_ARCH`

 - `TBS_MAX_WIDTH`			amount of bits in `uMax` or `iMax`

## Verified Working On:

| OS		    	| arch		| gcc | clang | g++ | clang++ |
| ----------------- | --------- | --- | ----- | --- | ------- |
| Arch Linux	    | x86_64	| X   | X     | X   | X		  |
| Arch Linux	    | x86_32	| X   | X     | X   | X		  |
| MacOS 12.4    	| x86_64	| X   | X     | X   | X		  |
| Debian 11 on CrOS	| x86_64	| X   | X     | X   | X		  |

## Todo
[ ] add macros for printf sequences. eg. ``TBS_FMT_uMax`` would expand to ``%zu`` or ``%lu`` depending on the actual size.
[ ] better documentation; this is the laziest bare minumum shit currently lmfao
[ ] much more testing, especially on non-x86 machines
