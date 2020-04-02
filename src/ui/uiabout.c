/* vim: set et ts=4 sw=4 sts=4 fdm=marker syntax=c.doxygen: */

/** \file   uiabout.c
 * \brief   About dialog
 */

#include <gtk/gtk.h>
#include "debug.h"


#include "uiabout.h"


/** \brief  List of authors for the "Credits" tab of the About dialog
 */
static const char *authors[] = {
    "Bas Wassink <b.wassink@ziggo.nl>",
    NULL
};


/** \brief  List of artist for the "Credits" tab of the About dialog
 */
static const char *artists[] = {
    "Bas Wassink <b.wassink@ziggo.nl>",
    NULL
};



/** \brief  Handler for the 'response' event of the \a dialog
 *
 * \param[in,out]   dialog      About dialog instance
 * \param[in]       response_id response ID
 * \param[in]       user_data   extra event data (unused)
 */
static void on_response(GtkDialog *dialog,
                        gint response_id,
                        gpointer user_data)
{
    debug_gtk3("called with response ID %d.", response_id);
    if (response_id == GTK_RESPONSE_DELETE_EVENT) {
        gtk_widget_destroy(GTK_WIDGET(dialog));
    }
}


/** \brief  Show About dialog
 *
 * \param[in]   parent  parent widget (this should be the GtkApplicationWindow)
 */
void ui_about_dialog_popup(GtkWidget *parent)
{
    GtkWidget *dialog;


    dialog = gtk_about_dialog_new();
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog),
                                      "Focus Pixel Editor");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog),
                                 "0.0.1-git");
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog),
                                   "(c) 2019 Bas Wassink (Compyx/Focus)");
    gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(dialog),
                                      GTK_LICENSE_GPL_2_0);
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog),
                                 "https://github.com/Compyx/pixeleditor");
    gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(dialog),
                                 authors);
    gtk_about_dialog_set_artists(GTK_ABOUT_DIALOG(dialog),
                                 artists);



    gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(parent));
    gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
    g_signal_connect(dialog, "response", G_CALLBACK(on_response), NULL);

    gtk_widget_show(dialog);
}

