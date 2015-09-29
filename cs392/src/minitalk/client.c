#define CLIENT
#include "minitalk.h"

/*
 *this is the client program
 *checks args >3
 *checks to make sure the server pid is valid
 *sets up sigusr1 and sigusr2
 *sends our own pid to server
 *alarms if !gl_ack
 */


int       gl_ack;

void donothing()
{
}

void acknowledge()
{
  gl_ack = 1;
}

void myalarm()
{
  my_str("timed out, BYE! \n");
  exit(0);
}


int       main(int argc, char** argv)
{
  pid_t serverpid;
  
  gl_ack = 0;
  
  if(argc < 3)
    {
      my_str("Usage: ./client serverpid message1 [message2] ... \n");
      exit(0);
    }
  serverpid = my_atoi(argv[1]);
  if(serverpid <= 0)
    {
      my_str("Bad server PID \n");
      exit(0);
    }
  
  signal(SIGUSR1, acknowledge);
  signal(SIGUSR2, donothing);
  signal(SIGALRM, myalarm);
  
  sendpid(getpid(), serverpid);
  
  if(!gl_ack)
    {
      alarm(2);
      pause();
    }
  alarm(0);
  
  messagesender(my_vect2str(&argv[2]), serverpid);
  
  return 0;
}

