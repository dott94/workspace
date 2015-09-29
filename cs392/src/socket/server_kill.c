#include "sockets.h"

/*
 * Precondition: Server is running
 * Postcondition: The server is killed
 */
void server_kill()
{
  usleep(2 * getpid());
  my_str("\n bye\n");
  exit(0);
}
