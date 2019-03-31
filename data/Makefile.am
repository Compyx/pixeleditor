RESOURCES_BIN = $(builddir)/resources.bin
RESOURCES_XML = $(srcdir)/resources.gresource.xml

all: $(RESOURCES_BIN)


$(RESOURCES_BIN): $(RESOURCES_XML)
	glib-compile-resources --target $@ $<

