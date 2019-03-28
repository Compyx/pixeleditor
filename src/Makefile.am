# vim: set noet ts=8 sw=8 sts=8:

SUBDIRS = lib ui

AM_CPPFLAGS = \
	      -I$(top_builddir)/src \
	      -I$(top_srcdir)/src/lib \
	      -I$(top_srcdir)/src/ui

bin_PROGRAMS = pixeleditor
# pixeleditor_LDFLAGS = $(LDFLAGS)

LDADD = $(top_builddir)/src/ui/libui.a
pixeleditor_SOURCES = main.c


