#include "myselect.h"

/*
 * Precondition: None
 * Postcondition: Terminal is ready for myselect
 */

void init_terminal(){
	int file;
	struct termio termchange;
	char* name;
	
	ioctl(0, TCGETA, &(gl_env.line_backup));
	termchange = gl_env.line_backup;

	termchange.c_lflag &= ~(ICANON | ECHO | ISIG);
	termchange.c_cc[VTIME] = READTIME;
	termchange.c_cc[VMIN] = READMIN;
	
	ioctl(0, TCSETA, &termchange);

	name = ttyname(0);
	file = open(name, O_WRONLY);
	gl_env.pos = 0;
	gl_env.stdio_backup = dup(1);
	dup2(file, 1);

	
}