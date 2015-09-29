#include "sockets.h"

/*
 * Precondition: Server and client are running
 * Postcondition: /exit is sent to the server and client is killed
 */

extern int sockfd;

void client_kill()
{
  write(sockfd, "/exit", 6);
  my_str(" Bye\n");
  exit(0);
}
