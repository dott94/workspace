#include "socketsgtk.h"

/*
 * Precondition: connect window is open
 * Postcondition: The window is closed, connect button is reset, main window's widgets are running
 */
void close_connect_window(GtkWidget* w, gpointer d)
{
	gtk_signal_handler_block(gl_env.connect_button, gl_env.connect_id);
	gtk_toggle_button_set_active((GtkToggleButton*) gl_env.connect_button, FALSE);
	gtk_signal_handler_unblock(gl_env.connect_button, gl_env.connect_id);
	enable_main();
	gtk_widget_destroy(w);
}
