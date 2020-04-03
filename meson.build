# vim: set syntax=meson:

project('pixeleditor', 'c')

gnome = import('gnome')
gtkdep = dependency('gtk+-3.0')

gresource_compiler = find_program('glib-compile-resources')

fpe_resources = gnome.compile_resources(
    'fpe-resources', 'data/resources.gresource.xml',
    source_dir : ['data', 'src/ui'],
    c_name : 'fpe',
    extra_args : '--manual-register')

incdirs = include_directories('.', 'src', 'src/ui', 'src/lib')


executable('pixeleditor',
           'src/main.c',
           fpe_resources,
           include_directories : incdirs,
           dependencies: [gtkdep] )
