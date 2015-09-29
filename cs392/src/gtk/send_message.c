#include "socketsgtk.h"

/*
 * Precondition: The client is connected to the server
 * Postcondition: The message is sent, or an error message is printed
 */
void send_message(GtkWidget* w, gpointer d)
{
	char  message[2];	
	int   bytes_read;
	char* usr_msg;
	usr_msg = (char*) gtk_entry_get_text((GtkEntry*) gl_env.message_input);

	if(gl_env.sockfd == -1)
	{
		g_print("error connecting to server\n");
		return;
	}

	if(my_strcmp(usr_msg, "") == 0)
	{
		g_print("Message entry required\n");
		return;
	}

	if(write(gl_env.sockfd, usr_msg, my_strlen(usr_msg) + 1) < 0)
	{
		g_print("failed to communicate with server\n");
		disconnect();
	}

	bytes_read = read(gl_env.sockfd, message, 3);

	if(bytes_read < 1)
	{
		my_str("Server connection closed\n");
		gtk_toggle_button_set_active((GtkToggleButton*) gl_env.connect_button, FALSE);
		return;
	}

	if(my_strncmp(usr_msg, "/exit", 5) == 0 && (usr_msg[5] == ' ' || !usr_msg[5]))
	{
		gtk_toggle_button_set_active((GtkToggleButton*) gl_env.connect_button, FALSE);
	}

	gtk_entry_set_text((GtkEntry*) gl_env.message_input, "");
}
