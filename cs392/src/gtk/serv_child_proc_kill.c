
#include "sockets.h"

extern struct s_gl_env gl_env;

/*
 * Precondition: None
 * Postcondition: The child process is stopped
 */
void serv_child_proc_kill()
{
  usleep(getpid());
  free(gl_env.username);
  close(gl_env.sockfd);
  exit(0);
}
