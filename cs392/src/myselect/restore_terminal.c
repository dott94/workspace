#include "myselect.h"

/*
 * Precondition: Myselect has modified the terminal
 * Postcondition: Terminal is reset to prior state
 */

void restore_terminal(){

	tputs(gl_env.cursoron, 0, my_termprint);
	term_clear();
	ioctl(0, TCSETA, &(gl_env.line_backup));
	dup2(gl_env.stdio_backup, 1);
}