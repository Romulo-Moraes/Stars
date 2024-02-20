project('Stars', 'c', version : '3.1')

includes = include_directories('includes')

cc = meson.get_compiler('c')

deps = [dependency('ncurses')]

src = files()

subdir('src')

executable('stars', src, include_directories : includes, dependencies : deps, install : true)