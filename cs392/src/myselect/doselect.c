#include "myselect.h"

/*
 * Precondition: None
 * Postcondition: elem is highlighted or unhighlighted
 */

void doselect(){

	gl_env.elements[gl_env.pos].mode = !gl_env.elements[gl_env.pos].mode;
	
	if(gl_env.elements[gl_env.pos].mode){
		movedown();
	}else{
		refreshin();
	}
}