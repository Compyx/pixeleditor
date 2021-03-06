AC_INIT(pixeleditor, 0.0.1)
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_RANLIB
AM_PROG_AR

AC_MSG_NOTICE([Running configure, fingers crossed...])

dnl
dnl Optional stuff:
dnl

dnl Add --enable-debug, disabled by default
AC_ARG_ENABLE([debug],
              AS_HELP_STRING([--enable-debug],
                             [Enable debugging]))
AS_IF([test "x$enable_debug" == "xyes"],
      [AC_DEFINE([HAVE_DEBUG], 1, [Enable debugging.])])


dnl Check for a proper C99 compiler
AC_LANG(C)
AC_PROG_CC([gcc clang cc])
AC_PROG_CC_C99

dnl Check for pkg-config
dnl AC_PROG(pkg-config, [], [AC_ERROR([pkg-config is required])])


dnl Check for zlib
AC_CHECK_HEADERS(zlib.h, [], [AC_ERROR([A working zlib is required])])
AC_SEARCH_LIBS(deflate, z, [], [AC_ERROR([A working zlib is required])])

AC_CHECK_PROG([HAVE_XMLLINT], [xmllint], [true], [false])

dnl Look for pkg-config and search for required modules
PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([GTK], gtk+-3.0 >= 3.22)
dnl Seems to me installing Gtk3 will install the minimum GLib-.2.0 version, so
dnl just checking for GLib 2.0 should be enough
PKG_CHECK_MODULES([GLIB], glib-2.0)

EXTRA_CFLAGS="-Wall -Wextra -std=c99 -Wno-unused-parameter -Wstrict-prototypes -Wmissing-prototypes -Wswitch-default -Wswitch-enum -Wuninitialized -Wconversion -Wredundant-decls -Wnested-externs -Wunreachable-code -O3 -g"

CFLAGS="$CFLAGS $GTK_CFLAGS $GLIB_CFLAGS $EXTRA_CFLAGS"
LDFLAGS="$LDFLAGS $GTK_LIBS $GLIB_LIBS"



AC_SUBST([CFLAGS])
AC_SUBST([LDFLAGS])

echo "----------------"
echo "CFLAGS = $CFLAGS"
echo "LDFLAGS = $LDFLAGS"
echo "HAVE_XMLLINT = $HAVE_XMLLINT"

dnl Process Makefile.am to generate Makefile
AC_CONFIG_FILES([data/Makefile
                 src/Makefile
                 src/lib/Makefile
                 src/ui/Makefile])

AC_OUTPUT(Makefile)

