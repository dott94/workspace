#define SERVER
#include "minitalk.h"

/*This is the server program 
 *This first prints the server pid
 *The server then acknowledges the client reception, then sends signal back to client
 *pauses until the entire message is received from the client
 */

struct  s_gl_env gl_env;

void killserver()
{
  my_str("\nServer Killed\n");
  exit(0);
}

int     main()
{
  int count;
  
  signal(SIGINT, killserver); 
  my_str("The Server PID: ");
  my_int(getpid());
  my_str("\n");
  
  while(1)
    {
      gl_env.clientpid = 0;
      gl_env.done   = 0;
      
      signal(SIGUSR1, getclientpid);
      signal(SIGUSR2, getclientpid);
      
      for(count = 0; count < (8 * sizeof(pid_t)); count++)
	{
	  pause();
	}
      
      signal(SIGUSR1, getmessage);
      signal(SIGUSR2, getmessage);
      
      kill(gl_env.clientpid, SIGUSR1);
		
		while(!gl_env.done)
		  {
		  pause();
		}
		my_str("\n");
    }
  
  return 0;
}
