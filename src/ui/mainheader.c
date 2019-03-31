/* vim: set et ts=4 sw=4 sts=4 fdm=marker syntax=c.doxygen: */

/** \file   mainheader.c
 * \brief   Application header bar
 */

#include <gtk/gtk.h>
#include "debug.h"

#include "mainheader.h"


/** \brief  Create header bar for the application
 *
 * \return  GtkHeaderBar instance
 */
GtkWidget *mainheader_create(void)
{
    GtkWidget *header;
    GtkWidget *primary;
    GtkWidget *secondary;
    GtkBuilder *builder;
    GMenuModel *menu;

    header = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header), TRUE);

    primary = gtk_menu_button_new();
    gtk_header_bar_pack_start(GTK_HEADER_BAR(header), primary);

    secondary = gtk_menu_button_new();

    debug_gtk3("reading XML UI file to build gears menu");
    builder = gtk_builder_new_from_file("/home/vice/pixeleditor/data/gears-menu.ui");
    menu = G_MENU_MODEL(gtk_builder_get_object(builder, "menu"));
    gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(secondary), menu);
    g_object_unref(builder);

    gtk_header_bar_pack_end(GTK_HEADER_BAR(header), secondary);


    return header;
}
