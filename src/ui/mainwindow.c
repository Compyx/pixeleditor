/* vim: set et ts=4 sw=4 sts=4 fdm=marker syntax=c.doxygen: */

/** \file   mainwindow.c
 * \brief   Main Window
 */

#include <gtk/gtk.h>
#include "debug.h"

#include "statusbar.h"

#include "mainwindow.h"


static GtkWidget *mainwindow_grid;
static GtkWidget *drawing_area;
static GtkWidget *statusbar;


static cairo_surface_t *surface;

static void clear_surface(void)
{
    cairo_t *cr;

    debug_gtk3("called.");

    cr = cairo_create(surface);
    cairo_set_source_rgb(cr, 0, 0.5, 1);
    cairo_paint(cr);

    cairo_destroy(cr);
}



static gboolean on_canvas_configure(GtkWidget *widget,
                                    GdkEventConfigure *event,
                                    gpointer data)
{

    debug_gtk3("called.");
    if (surface != NULL) {
        cairo_surface_destroy(surface);
    }

    surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
            CAIRO_CONTENT_COLOR,
            gtk_widget_get_allocated_width(widget),
            gtk_widget_get_allocated_height(widget));

    clear_surface();

    return TRUE;
}


static gboolean on_canvas_draw(GtkWidget *widget,
                                cairo_t *cr,
                                gpointer data)
{
    debug_gtk3("called.");
    cairo_set_source_surface(cr, surface, 0, 0);
    cairo_paint(cr);
    return FALSE;
}


/** \brief  Generate the main application window
 *
 * \param[in]   app Application reference
 *
 * \return  A GtkWindow
 */
GtkWidget *mainwindow_create(GtkApplication *app)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *header;

    debug_gtk3("called.");

    window = gtk_application_window_new(app);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    grid = gtk_grid_new();

    header = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(header), "Pixel Editor");
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header), TRUE);
    gtk_window_set_titlebar(GTK_WINDOW(window), header);

    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_hexpand(drawing_area, TRUE);
    gtk_widget_set_vexpand(drawing_area, TRUE);
    gtk_grid_attach(GTK_GRID(grid), drawing_area, 0, 0, 1, 1);

    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_canvas_draw), NULL);
    g_signal_connect(drawing_area, "configure-event",
            G_CALLBACK(on_canvas_configure), NULL);

    statusbar = statusbar_create();
    gtk_grid_attach(GTK_GRID(grid), statusbar, 0, 1, 1, 1);

    gtk_container_add(GTK_CONTAINER(window), grid);

    return window;
}
