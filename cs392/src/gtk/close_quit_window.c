#include "socketsgtk.h"

/*
 * Precondition: quit window is open
 * Postcondition: The quit window is closed, main is enabled
 */
void close_quit_window(GtkWidget* w, gpointer d)
{
	enable_main();
	gtk_widget_destroy(w);
}
