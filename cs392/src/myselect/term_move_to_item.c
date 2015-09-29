#include "myselect.h"

/*
 * Precondition: position is valid 
 * Postcondition: The cursor is moved to the item at position
 */

void term_move_to_item(int position){
	tputs(tgoto(gl_env.move, gl_env.elements[position].x, gl_env.elements[position].y), 1, my_termprint);
}