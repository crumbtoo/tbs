project(
	'tbs',
	'c',
	version: '1.0.0',
	license: 'MIT',
    default_options: [
		'c_std=c99',
        # 'cpp_std=c++11',
        'warning_level=3'
	],

)

cc = meson.get_compiler('c')

p = '#include <types.h>'
i = include_directories('./tbs')
a = ['-Wall', '-pedantic', '-ansi', '-std=c89']
assert(cc.sizeof('i8',   include_directories : i, prefix : p, args : a) == 1)
assert(cc.sizeof('i16',  include_directories : i, prefix : p, args : a) == 2)
assert(cc.sizeof('i32',  include_directories : i, prefix : p, args : a) == 4)
assert(cc.sizeof('i64',  include_directories : i, prefix : p, args : a) == 8)
assert(cc.sizeof('i128', include_directories : i, prefix : p, args : a) == 16 or cc.sizeof('i128', prefix : tbstypes) == -1)
assert(cc.sizeof('iMax', include_directories : i, prefix : p, args : a) >= 8)

assert(cc.sizeof('u8',   include_directories : i, prefix : p, args : a) == 1)
assert(cc.sizeof('u16',  include_directories : i, prefix : p, args : a) == 2)
assert(cc.sizeof('u32',  include_directories : i, prefix : p, args : a) == 4)
assert(cc.sizeof('u64',  include_directories : i, prefix : p, args : a) == 8)
assert(cc.sizeof('u128', include_directories : i, prefix : p, args : a) == 16 or cc.sizeof('u128', prefix : tbstypes) == -1)
assert(cc.sizeof('uMax', include_directories : i, prefix : p, args : a) >= 8)

assert(cc.sizeof('f32',  include_directories : i, prefix : p, args : a) == 4)
assert(cc.sizeof('f64',  include_directories : i, prefix : p, args : a) == 8)
assert(cc.sizeof('f128', include_directories : i, prefix : p, args : a) == 16 or cc.sizeof('f128', prefix : tbstypes) == -1)
assert(cc.sizeof('fMax', include_directories : i, prefix : p, args : a) >= 8)

install_headers(
    'tbs/types.h',
    'tbs/arch.h',
    subdir : 'tbs'
)
