/* vim: set et ts=4 sw=4 sts=4 fdm=marker syntax=c.doxygen: */

/** \file   debug.h
 * \brief   Debugging helpers - header
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#if 0
#include "../config.h"
#endif

#ifdef HAVE_DEBUG


# include <gtk/gtk.h>
# include <stdlib.h>

/** \brief  Print debugging info on stdout
 *
 * Works just like g_print() and printf(), except that every line is prefixed
 * with "[debug-gtk3] $FILE:$LINE::$FUNC(): ".
 * This macro outputs a newline. so the user should not provide one in the
 * message, unless an extra newline is preferred.
 */
# define debug_gtk3(...) \
    g_print("[debug-gtk3] %s:%d::%s(): ", __FILE__, __LINE__, __func__); \
    g_print(__VA_ARGS__); \
    g_print("\n");

#else

# define debug_gtk3(...)
#endif

#endif

