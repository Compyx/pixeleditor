#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include "mainwindow.h"

/** \brief  Handler for the 'active' event of the main application
 *
 * Start the main application.
 *
 * \param[in]   app     main application
 * \param[in]   data    extra event data (unused)
 */
static void on_activate(GtkApplication *app,
                        gpointer        data)
{
    GtkWidget *window = mainwindow_create(app);

    gtk_widget_show_all(window);
}


/** \brief  Entry point
 *
 * \param[in]   argc    argument count
 * \param[in]   argv    argument vector
 *
 * \return  exit status
 */
int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new(
            "nl.compyx.pixeleditor",
            G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
