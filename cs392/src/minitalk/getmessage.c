#include "minitalk.h"

/*
 * Callback for signal function in order to print a message
 * Precondition: N/A
 * Postcondition: every 8 bits is interpreted as a character and printed tro the screen
 */
void getmessage(int sig)
{
  static char thischar = 0;
  static int i = 0;
  
  thischar <<= 1;
  
  if(sig == SIGUSR1)
    {
      thischar |= 1;
    }
  i++;
  if(i >= 8)
    {
      if(thischar == '\0')
	{
	  gl_env.done = 1;
	  kill(gl_env.clientpid, SIGUSR1);
	}
      else
	{
	  my_char(thischar);
	}
      thischar = 0;
      i = 0;
    }
  
  kill(gl_env.clientpid, SIGUSR2);
}
