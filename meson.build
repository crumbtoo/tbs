project(
	'tbs',
	'c',
	version: '2.0.0',
	license: 'MIT',
    default_options: [
		'c_std=c89',
        'warning_level=3'
	],
)

# cc = meson.get_compiler('c')

tbs_inc = include_directories(
    'inc'
)

# subproject stuff
tbs_dep = declare_dependency(
    include_directories : tbs_inc,
)

install_headers(
    'inc/tbs/arch.h',
    'inc/tbs/types.h',
    subdir : 'tbs',
)

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : 'type definitions by size',
  subdirs : meson.project_name(),
)

if not meson.is_subproject()
    subdir('tst')
endif

