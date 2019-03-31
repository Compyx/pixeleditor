# vim: set noet ts=8 sw=8 sts=8:

AM_CPPFLAGS = \
	      -I$(top_builddir)/data \
	      -I$(top_builddir)/src \
	      -I$(top_srcdir)/src \
	      -I$(top_srcdir)/src/lib \
	      -I$(top_srcdir)/src/ui

libui_a_SOURCES = mainwindow.c \
		  mainwindow.h \
		  mainheader.c \
		  mainheader.h \
		  statusbar.c \
		  statusbar.h \
		  $(top_builddir)/data/fpe-resources.c \
		  $(top_builddir)/data/fpe-resources.h

noinst_LIBRARIES = libui.a
