tar = find_program('tar')
custom_target(
  'flatpak-self-test-data',
  input : 'flatpakrepos.tar.gz',
  output : 'done',
  command : [
    tar,
    '--directory=' + meson.current_build_dir(),
    '-xf', '@INPUT@',
  ],
  build_by_default : true,
)

custom_target(
  'flatpak-self-test-bundle',
  output : 'flatpakrepos.tar.gz',
  command : [
    tar,
    '-czf', '@OUTPUT@',
    'app-missing-runtime/repo/',
    'app-update/repo/',
    'app-with-runtime/repo/',
    'only-runtime/repo/',
  ],
)
