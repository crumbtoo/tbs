project(
	'tbs',
	'c',
	version: '1.0.0',
	license: 'MIT',
)

cc = meson.get_compiler('c')


tbstypes = '#include <tbs/types.h>'
assert(cc.sizeof('i8',   prefix : tbstypes) == 1)
assert(cc.sizeof('i16',  prefix : tbstypes) == 2)
assert(cc.sizeof('i32',  prefix : tbstypes) == 4)
assert(cc.sizeof('i64',  prefix : tbstypes) == 8)
assert(cc.sizeof('i128', prefix : tbstypes) == 16 or cc.sizeof('i128', prefix : tbstypes) == -1)
assert(cc.sizeof('imax', prefix : tbstypes) >= 8)

assert(cc.sizeof('u8',   prefix : tbstypes) == 1)
assert(cc.sizeof('u16',  prefix : tbstypes) == 2)
assert(cc.sizeof('u32',  prefix : tbstypes) == 4)
assert(cc.sizeof('u64',  prefix : tbstypes) == 8)
assert(cc.sizeof('u128', prefix : tbstypes) == 16 or cc.sizeof('u128', prefix : tbstypes) == -1)
assert(cc.sizeof('umax', prefix : tbstypes) >= 8)

assert(cc.sizeof('f32',  prefix : tbstypes) == 4)
assert(cc.sizeof('f64',  prefix : tbstypes) == 8)
assert(cc.sizeof('f128', prefix : tbstypes) == 16 or cc.sizeof('f128', prefix : tbstypes) == -1)
assert(cc.sizeof('fmax', prefix : tbstypes) >= 8)
