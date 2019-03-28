/* vim: set et ts=4 sw=4 sts=4 fdm=marker syntax=c.doxygen: */

/** \file   statusbar.c
 * \brief   Main window statusbar
 */

#include <gtk/gtk.h>
#include "debug.h"

#include "statusbar.h"


GtkWidget *statusbar_create(void)
{
    GtkWidget *bar;
    GtkWidget *label;

    bar = gtk_grid_new();
    label = gtk_label_new("Hello World!");
    gtk_grid_attach(GTK_GRID(bar), label, 0, 0, 1, 1);

    gtk_widget_show_all(bar);
    return bar;
}

