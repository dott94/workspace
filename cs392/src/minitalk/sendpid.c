#include "minitalk.h"
/*
 *sendpid send the process id over to the server
 *precondition: the client process exists
 *postcondition: the clients pid is sent to the server
 */


void    sendpid(pid_t clientpid, pid_t serverpid)
{
  
  int i;
  int pidsize = 8 * sizeof(pid_t);
  int mask = 1 << (pidsize - 1);
  
  for(i = 0; i < pidsize; i++)
    {
      if(clientpid & mask)
	{
	  kill(serverpid, SIGUSR1);
	}
      else
	{
	  kill(serverpid, SIGUSR2);
	}
      clientpid <<= 1;
      usleep(5000);
    }
  
}
