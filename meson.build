project('ByteNet', 'cpp',
  version: '1.0.0',
  default_options: ['cpp_std=c++17'])

# Define directories
src_dir = 'src'
include_dir = 'include'
cmd_dir = 'cmd'
test_dir = 'tests'

# Create executable for the simple_server command-line tool
simple_server_exe = executable('simple_server', cmd_dir / 'simple_server.cpp',
  include_directories: include_directories(include_dir),
  dependencies: [])

# Create executable for the simple_client command-line tool
simple_client_exe = executable('simple_client', cmd_dir / 'simple_client.cpp',
  include_directories: include_directories(include_dir),
  dependencies: [])

# Create the main library
byte_network_lib = library('bytenet',
  sources: [src_dir / 'bytenet.cpp', src_dir / 'network.cpp'],
  include_directories: include_directories(include_dir))

# Add tests
test('network_test', executable('network_test', test_dir / 'test_network.cpp',
  include_directories: include_directories(include_dir),
  dependencies: [dependency('gtest')]))

# Optionally, you might want to install your library and executables
install_targets = [
  byte_network_lib,
  simple_server_exe,
  simple_client_exe
]

install_data(install_targets, install_dir: join_paths(meson.install_dir(), 'bin'))
