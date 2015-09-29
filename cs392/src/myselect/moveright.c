#include "myselect.h"

/*
 * Precondition: Termcaps initialized
 * Postcondition: The cursor moved one spot to the right of current
 */

void moveright(){
	
	refreshout(gl_env.pos);
	gl_env.pos += gl_env.win.ws_row;
	
	if(gl_env.pos >= gl_env.nbelems){
		gl_env.pos = gl_env.nbelems - 1;
	}
	
	refreshin();
}