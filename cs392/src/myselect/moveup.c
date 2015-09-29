#include "myselect.h"

/*
 * Precondition: Termcaps intialized
 * Precondition: cursor position is set to one position above current
 */

void moveup(){
	
	refreshout(gl_env.pos);
	gl_env.pos--;
	if(gl_env.pos < 0)
	{
		gl_env.pos = gl_env.nbelems - 1;
	}
	refreshin();
}