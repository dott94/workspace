#define CLIENT_INC
#include "sockets.h"

/*
 * The client side of the socket assignment 
 * Precondition: Server is running 
 * Postcondition: Client is running and is connected to server 
 */


int sockfd;

int main(int argc, char** argv)
{
  struct hostent* server;
  char message[BUFFER_SIZE];
  int bytes_read;
  int port;
  struct sockaddr_in serv_addr;
  
  
  signal(SIGINT, client_kill);
  
  if(argc != 3)
    {
      my_str("Usage: ./client serverName portNum\n");
      exit(1);
    }
  port = my_atoi(argv[2]);
  if(port <= 0 || port > 65535)
    {
      my_str("Invalid port number\n");
      exit(1);
    }
  
  memset(&serv_addr.sin_zero, 0, 8);
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  server = gethostbyname(argv[1]);
  
  if(server== NULL)
    {
      my_str("Invalid server host name\n");
      exit(1);
    }
  
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  
  if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
    {
      my_str("Connection to server failed!\n");
      exit(1);
    }
  
  my_str("Nickname: ");
  bytes_read = read(0, message, BUFFER_SIZE - 1);
  message[bytes_read - 1] = '\0';
  my_char('\n');
  
  if(write(sockfd, message, bytes_read) < 0)
    {
      my_str("Unable to send message to server\n");
      exit(1);
    }
  
  while(1)
    {
      bytes_read = read(sockfd, message, BUFFER_SIZE - 1);
      if(bytes_read < 1)
	{
	  my_str("Server closed connection!\n");
	  exit(1);
	}
      my_str("> ");
      bytes_read = read(0, message, BUFFER_SIZE - 1);
      message[bytes_read - 1] = '\0';
      write(sockfd, message, bytes_read);
      if(my_strncmp(message, "/exit\0", 6) == 0 && my_strncmp(message, "/exit ", 6) == 0)
	{
	  my_str("Bye\n");
	  exit(0);
	}
    }
  
  return 0;
}
