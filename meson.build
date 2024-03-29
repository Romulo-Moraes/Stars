project('Stars', 'c', version : '3.1')

includes = include_directories('includes')

cc = meson.get_compiler('c')

deps = [dependency('ncurses')]

lib_dir = meson.current_source_dir() + '/libs'
message(lib_dir)
anemone_lib = cc.find_library('anemone', dirs: lib_dir + '/Anemone/public/')

deps += anemone_lib

src = files()

subdir('src')

executable('stars', src, include_directories : includes, dependencies : deps, install : true)