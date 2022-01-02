project('quickjs-footprint', 'c',
  default_options: [
    'c_std=gnu99',
    'default_library=static',
    'optimization=s',
    'b_ndebug=true',
    'b_lto=true',
    'strip=true',
  ],
)

quickjs_dep = dependency('quickjs',
  default_options: [
    'libc=false',
    'bignum=true',
    'atomics=disabled',
    'stack_check=disabled',
  ],
)

host_os = host_machine.system()
if host_os == 'android'
  host_os_family = 'linux'
else
  host_os_family = host_os
endif

extra_c_args = []
extra_link_args = []
extra_link_depends = []

# Get rid of unused code.
if host_os_family == 'darwin'
  extra_link_args += '-Wl,-dead_strip'
elif host_os_family != 'windows'
  extra_c_args += ['-ffunction-sections', '-fdata-sections']
  extra_link_args += '-Wl,--gc-sections'
endif

# Ensure no symbols are visible, so the static linker can eliminate more code.
if host_os_family == 'darwin'
  symlist = 'no-exports.symbols'
  extra_link_args += '-Wl,-exported_symbols_list,' + meson.current_source_dir() / symlist
  extra_link_depends += symlist
elif host_os_family != 'windows'
  symscript = 'no-exports.version'
  extra_link_args += '-Wl,--version-script,' + meson.current_source_dir() / symscript
  extra_link_depends += symscript
endif

add_project_arguments(extra_c_args, language: 'c')
add_project_link_arguments(extra_link_args, language: 'c')

executable('quickjs-footprint-run-js', 'run-js.c',
  link_depends: extra_link_depends,
  dependencies: [quickjs_dep],
  install: true,
)

executable('quickjs-footprint-run-bytecode', 'run-bytecode.c',
  link_depends: extra_link_depends,
  dependencies: [quickjs_dep],
  install: true,
)
