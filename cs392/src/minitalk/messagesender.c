#include "minitalk.h"

/*
 * send message from client to server
 *
 * Precondition: Message is a valid string and the server pid is valid
 * Postcondition: The message is sent to the server
 */

void     messagesender(char* message, pid_t serverpid)
{
  char mask;
  char i;
  
  if(message != NULL)
    {
      mask = 0x80;
      gl_ack = 0;
      i = 0;
      while(!gl_ack)
        {
	  if(*message & mask)
            {
	      kill(serverpid, SIGUSR1);
            }
	  else
            {
	      kill(serverpid, SIGUSR2);
            }
	  i++; 		
	  if(i == 8)
            {
	      message++;
	      i = 0;
            }
	  else
            {
	      *message <<= 1;
            }
	  pause();
        }
    }
}
