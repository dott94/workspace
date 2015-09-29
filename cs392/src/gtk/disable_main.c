#include "socketsgtk.h"

/*
 * Precondition: The main window exists
 * Postcondition: main window widgets are disabled 
 */
void disable_main()
{
	gtk_widget_set_sensitive((GtkWidget*) gl_env.send_button, FALSE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.message_input, FALSE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.quit_button, FALSE);
	gtk_widget_set_sensitive((GtkWidget*) gl_env.connect_button, FALSE);

}
