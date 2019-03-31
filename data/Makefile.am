# vim: set noet ts=8 sw=8 sts=8:

# Files to include in the GResource bin/sources
RES_FILES = gears-menu.ui


all: fpe-resources.c fpe-resources.h

fpe-resources.c: $(srcdir)/resources.gresource.xml $(RES_FILES)
	glib-compile-resources \
		--sourcedir=$(srcdir) \
		--sourcedir=$(top_builddir)/data \
		--target=$@ \
		--generate-source \
		--c-name fpe \
		--manual-register \
		$(srcdir)/resources.gresource.xml

fpe-resources.h: $(srcdir)/resources.gresource.xml $(RES_FILES)
	glib-compile-resources \
		--sourcedir=$(srcdir) \
		--sourcedir=$(top_builddir)/data \
		--target=$@ \
		--generate-header \
		--c-name fpe \
		--manual-register \
		$(srcdir)/resources.gresource.xml




BUILT_SOURCES = fpe-resources.c \
		fpe-resources.h
