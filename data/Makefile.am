# vim: set noet ts=8 sw=8 sts=8:

all: fpe-resources.c fpe-resources.h

fpe-resources.c: $(srcdir)/resources.gresource.xml \
		 gears-menu.ui
	glib-compile-resources \
		--sourcedir=$(srcdir) \
		--sourcedir=$(top_builddir)/data \
		--target=$@ \
		--generate-source \
		--c-name fpe \
		$(srcdir)/resources.gresource.xml

fpe-resources.h: $(srcdir)/resources.gresource.xml \
		 gears-menu.ui
	glib-compile-resources \
		--sourcedir=$(srcdir) \
		--sourcedir=$(top_builddir)/data \
		--target=$@ \
		--generate-header \
		--c-name fpe \
		$(srcdir)/resources.gresource.xml




BUILT_SOURCES = fpe-resources.c \
		fpe-resources.h
