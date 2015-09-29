#include "myselect.h"

/*
 * Precondition: Int desplayed in terminal
 * Postcondition: The element at position is printed
 */

void refreshout(int position){

	term_move_to_item(position);
	
	if(gl_env.elements[position].mode){
		term_standout();
	}
	
	my_str(gl_env.elements[position].elem);
	term_standend();
}