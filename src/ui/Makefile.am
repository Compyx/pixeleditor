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
		  uiabout.c \
		  uiabout.h \
		  fpe-resources.c \
		  fpe-resources.h

noinst_LIBRARIES = libui.a

# Files to include in the GResource bin/sources
RES_FILES = $(top_srcdir)/data/gears-menu.ui \
	    $(top_srcdir)/data/c64/chargen \
	    $(top_srcdir)/data/c64/c64hq.vpl \
	    $(top_srcdir)/data/c64/c64s.vpl \
	    $(top_srcdir)/data/c64/ccs64.vpl \
	    $(top_srcdir)/data/c64/cjam.vpl \
	    $(top_srcdir)/data/c64/colodore.vpl
	    $(top_srcdir)/data/c64/community-colors.vpl \
	    $(top_srcdir)/data/c64/deekay.vpl \
	    $(top_srcdir)/data/c64/frodo.vpl \
	    $(top_srcdir)/data/c64/godot.vpl \
	    $(top_srcdir)/data/c64/pc64.vpl \
	    $(top_srcdir)/data/c64/pepto-ntsc-sony.vpl \
	    $(top_srcdir)/data/c64/pepto-ntsc.vpl \
	    $(top_srcdir)/data/c64/pepto-palold.vpl \
	    $(top_srcdir)/data/c64/pepto-pal.vpl \
	    $(top_srcdir)/data/c64/ptoing.vpl \
	    $(top_srcdir)/data/c64/rgb.vpl \
	    $(top_srcdir)/data/c74/vice.vpl

# all: fpe-resources.c fpe-resources.h

fpe-resources.c: $(top_srcdir)/data/resources.gresource.xml $(RES_FILES)
	glib-compile-resources \
		--sourcedir=$(srcdir) \
		--sourcedir=$(top_builddir)/data \
		--target=$@ \
		--generate-source \
		--c-name fpe \
		--manual-register \
		$(top_srcdir)/data/resources.gresource.xml

fpe-resources.h: $(top_srcdir)/data/resources.gresource.xml $(RES_FILES)
	glib-compile-resources \
		--sourcedir=$(srcdir) \
		--sourcedir=$(top_builddir)/data \
		--target=$@ \
		--generate-header \
		--c-name fpe \
		--manual-register \
		$(top_srcdir)/data/resources.gresource.xml

BUILT_SOURCES = fpe-resources.c \
		fpe-resources.h
