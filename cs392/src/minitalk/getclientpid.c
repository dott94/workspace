#include "minitalk.h"

/*
 * callback function for call to signal()
 * Precondition: N/A
 * Postcondition: If signal is received the client pid is updated with the next bit
 */
void getclientpid(int sig)
{
  gl_env.clientpid <<= 1;
  if(sig == SIGUSR1)
    {
      gl_env.clientpid |= 1;
    }
  
}
