#ifndef _MINITALK_H_
#define _MINITALK_H_

#include "my.h"
#include <signal.h>

extern struct s_gl_env
{
	int clientpid;
	char done;
} gl_env;

extern int gl_ack;

#ifdef SERVER


void getclientpid(int);
void getmessage(int);

#else

void messagesender(char*, pid_t);
void sendpid(pid_t, pid_t);

#endif
#endif