#define SERVER_INC
#include "sockets.h"



/*
 * server.c
 * The server portion the socket assignment
 * Precondition: Specified port is available
 * Postcondition: The server is running on specified port
 */

struct s_gl_env gl_env;

int main(int argc, char** argv)
{
  int port;
  int pid;
  int clientfd;
  int sockfd;
  int clientlength;
  int bytes_read;
  int input_idx;
  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  char buffer[BUFFER_SIZE];
  char** input;
  
  signal(SIGINT, server_kill);
  
  if(argc != 2)
    {
      my_str("Usage: ./server portNum\n");
      exit(1);
    }
  port = my_atoi(argv[1]);	
  if(port <= 0 || port > 65535)
    {
      my_str("Invalid port number\n");
      exit(1);
    }
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  server_addr.sin_port = htons(port);
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  
  memset(&server_addr.sin_zero, 0, 8);
  
  if(bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
    {
      my_str("Socket error\n");
      exit(1);
    }
  
  listen(sockfd, 5);
  
  clientlength = sizeof(client_addr);
  while(1)
    {
      clientfd = accept(sockfd, (struct sockaddr*) &client_addr, &clientlength);
      if(clientfd < 0)
        {
	  my_str("Client connection error\n");
	  exit(1);
        }
      
      pid = fork();
      if(pid < 0)
        {
	  my_str("fork error\n");
	  exit(1);
        }
      
      if(pid == 0)
        {
	  signal(SIGINT, serv_child_proc_kill);
	  gl_env.sockfd = clientfd;
	  bytes_read = read(clientfd, buffer, BUFFER_SIZE - 1);
	  buffer[bytes_read] = '\0';
	  gl_env.username = my_strdup(my_str2vect(buffer)[0]);
	  my_str("***");
	  my_str(gl_env.username);
	  my_str(" connected successfully\n");
	  
	  while(1)
	    {
	      write(clientfd, ".", 1);
	      if((bytes_read = read(clientfd, buffer, BUFFER_SIZE - 1)) < 0)
		{
		  my_str("Failed to read\n");
		  exit(1);
		}
	      input = my_str2vect(buffer);
	      if(my_strcmp(input[0], "/exit") == 0)
		{
		  my_str("***");
		  my_str(gl_env.username);
		  my_str(" disconnected\n");
		  close(clientfd);
		  free(gl_env.username);
		  my_vectfree(input);
		  exit(1);
		}
	      else if(my_strcmp("/nick", input[0]) == 0)
		{
		  if(input[1])
		    {
		      input_idx = 1;
		      while(my_strcmp(input[input_idx], "") == 0 || my_strcmp(input[input_idx], "\t") == 0)
			{
			  input_idx++;
			}
		      
		      my_str("***");
		      my_str(gl_env.username);
		      my_str(" changed name to ");
		      free(gl_env.username);
		      gl_env.username = my_strdup(input[input_idx]);
		      my_str(gl_env.username);
		      my_char('\n');
		    }
		}
	      else if(my_strcmp("/me", input[0]) == 0)
		{
		  my_str("***");
		  my_str(gl_env.username);
		  if(input[1])
		    {
		      my_str(" ");
		      for(input_idx = 1; input[input_idx]; input_idx++)
			{
			  if(!my_strcmp(input[input_idx], "") == 0 && !my_strcmp(input[input_idx], "\t") == 0)
			    {
			      my_str(input[input_idx]);
			      my_str(" ");
			    }
			}
		    }
		  my_char('\n');
		}
	      else if(my_strcmp(buffer, "") != 0)
		{
		  my_str(gl_env.username);
		  my_str(": ");
		  my_str(buffer);
		  my_char('\n');
		}
	      my_vectfree(input);
	    }
        }
    }
  
  return 0;
}
