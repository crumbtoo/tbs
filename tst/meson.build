required_types = [
  'i8',
  'i16',
  'i32',
  'iMax',

  'u8',
  'u16',
  'u32',
  'uMax',

  'f32',
  'f64',
  'fMax',
]

optional_types = [
  'i128',
  'u128',
  'f128',
  'f80'
]

fMax_size = '64'
uMax_size = '32'
iMax_size = '32'

cpu = build_machine.cpu_family() 

if cpu == 'x86_64' or cpu == 'aarch64' or cpu == 'riscv64'
  required_types += 'i64'
  required_types += 'u64'
  fMax_size = '128'
  uMax_size = '64'
  iMax_size = '64'
endif

run_command(
  'mktst.sh',
  env : {
    'tbs_types': required_types,
    'fMax_size': fMax_size,
    'uMax_size': uMax_size,
    'iMax_size': iMax_size,
  },
  check : true,
)

foreach t : required_types
  exe = executable(t, f'sizeof-@t@.c', include_directories : tbs_inc)
  test(f'sizeof(@t@)', exe)
endforeach

