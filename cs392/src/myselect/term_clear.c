#include "myselect.h"

/*
 * Precondition: None
 * Postcondition: terminal is cleared
 */

void term_clear(){
	tputs(gl_env.clear, 1, my_termprint);
}