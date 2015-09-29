#include "myselect.h"

/*
 * Precondition: Termcaps initialized
 * Postcondition: The cursor is moved down one position from the current
 */

void movedown(){
	
	refreshout(gl_env.pos);
	gl_env.pos++; 
	
	if(gl_env.pos > gl_env.nbelems - 1){
		gl_env.pos = 0;
	}
	
	refreshin();
}