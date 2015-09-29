#include "socketsgtk.h"

/*
 * Precondition: The main window is created
 * Postcondition: All of the widgets on the main window are enabled
 */

void enable_main()
{
	gtk_widget_set_sensitive((GtkWidget*) gl_env.send_button, TRUE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.message_input, TRUE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.quit_button, TRUE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.connect_button, TRUE);

}
