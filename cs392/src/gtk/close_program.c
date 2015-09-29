#include "socketsgtk.h"

/*
 * Precondition: None
 * Postcondition: The disconnect signal is sent to the server, and the program quits
 */
void close_program(GtkWidget* w, gpointer d)
{
	if(gl_env.sockfd > -1)
	{
		disconnect();
	}

	gtk_main_quit();
}
