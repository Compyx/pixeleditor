/* vim: set et ts=4 sw=4 sts=4 fdm=marker syntax=c.doxygen: */

/** \file   mainwindow.c
 * \brief   Main Window
 */

#include <gtk/gtk.h>
#include "debug.h"

#include "fpe-resources.h"

#include "mainheader.h"
#include "statusbar.h"
#include "uiabout.h"

#include "mainwindow.h"


static GtkWidget *main_window;
static GtkWidget *drawing_area;
static GtkWidget *statusbar;
static cairo_surface_t *surface;

static void on_settings_activate(GSimpleAction *action,
                                 GVariant *parameter,
                                 gpointer data)
{
    debug_gtk3("settings activated.");
}


/** \brief  Signal handler to show the 'About' dialog
 *
 * \param[in,out]   action      GAction triggering the event
 * \param[in]       parameter   parameter associated with \a action (ignored)
 * \param[in]       data        extra data for the event (ignored)
 */
static void on_about_activate(GSimpleAction *action,
                              GVariant *parameter,
                              gpointer data)
{
    debug_gtk3("about activated.");
    ui_about_dialog_popup(data);
}


/** \brief  Fullscreen toggle handler
 *
 * Switches the UI to/from fullscreen.
 *
 * The current code looks a little silly due to \a value returning the old
 * value and having to manually switch state.
 *
 * \param[in,out]   action  action
 * \param[in]       value   ignored
 * \param[in]       data    ingored
 */
static void on_toggle_fullscreen(GSimpleAction *action,
                                 GVariant *value,
                                 gpointer data)
{
    GVariant *state = g_action_get_state(G_ACTION(action));
    gboolean b = g_variant_get_boolean(state);
    g_variant_unref(state);

    /* flip the value so the rest of the code kinda makes sense */
    b = !b;

    /* 'floating', so do not unref, the change_state() call 'consumes' it
     * according to the docs */
    state = g_variant_new_boolean(b);
    g_action_change_state(G_ACTION(action), state);

    debug_gtk3("toggle fullscreen activated: new state = %s.",
            b ? "TRUE" : "FALSE");
    if (b) {
        gtk_window_fullscreen(GTK_WINDOW(main_window));
    } else {
        gtk_window_unfullscreen(GTK_WINDOW(main_window));
    }
}


/** \brief  I need docs */
static void on_set_palette(GSimpleAction *action,
                           GVariant *parameter,
                           gpointer data)
{
    debug_gtk3("set_palette activated.");
    debug_gtk3("parameter is '%s'.", g_variant_get_string(parameter, NULL));
    g_simple_action_set_state(action, parameter);
}


/** \brief  I need docs */
static const char *fullscreen_accels[] = { "<Control><Shift>f", NULL };


/** \brief  List of GAction's that handle the UI's menu items
 */
static GActionEntry app_entries[] = {
    {
        .name = "toggle_fullscreen",
        .activate = on_toggle_fullscreen,
        .state = "false"
    },
    {
        .name = "settings",
        .activate = on_settings_activate
    },
    {
        .name = "about",
        .activate = on_about_activate
    },
    {
        .name = "set_palette",
        .parameter_type = "s",
        .state = "'c64hq'",
        .change_state =  on_set_palette
    }
};


/** \brief  I need docs */
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

    debug_gtk3("adding GActionEntry's.");
    g_action_map_add_action_entries(G_ACTION_MAP(app),
            app_entries, G_N_ELEMENTS(app_entries),
            window);
    gtk_application_set_accels_for_action(GTK_APPLICATION(app),
                                          "app.toggle_fullscreen",
                                          fullscreen_accels);
    grid = gtk_grid_new();

    header = mainheader_create();
    gtk_header_bar_set_title(GTK_HEADER_BAR(header), "Pixel Editor");
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

    main_window = window;

    return window;
}
