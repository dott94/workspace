#ifndef _SOCKETSGTK_H_
#define _SOCKETSGTK_H_

#define BUFFER_SIZE 512

#include "my.h"
#include <gtk/gtk.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <signal.h>
#include <netdb.h>


typedef struct s_gl
{
	int sockfd;
	char* username;
	int pid;
	gulong connect_id;
	GtkWidget* user_input[3];
	GtkWidget* connect_button;
	GtkWidget* send_button;
	GtkWidget* quit_button;
	GtkWidget* message_input;
} t_gl;

t_gl gl_env;

void disconnect();
void create_connect_window(GtkWidget*, GdkEvent*, gpointer);
void connect_server(GtkWidget*, gpointer);
void send_message(GtkWidget*, gpointer);
void create_quit_window();
gint quit_button();
void close_window(GtkWidget*, gpointer);
void close_connect_window(GtkWidget*, gpointer);
void close_quit_window(GtkWidget*, gpointer);
void disable_main();
void enable_main();
void close_program(GtkWidget*, gpointer);
#endif
