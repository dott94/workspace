#include "myselect.h"

/*
 * Precondition: termcaps initialized
 * Postcondition: The elem is displayed with underline
 */

void refreshin(){

	term_move_to_item(gl_env.pos);
	term_underline();
	
	if(gl_env.elements[gl_env.pos].mode){
		term_standout();
	}
	
	my_str(gl_env.elements[gl_env.pos].elem);
	term_standend();
	term_underend();
}