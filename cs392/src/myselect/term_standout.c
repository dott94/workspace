#include "myselect.h"

/*
 * Precondition: Termcaps initialized
 * Postcondition: Highlighting is enabled
 */

void term_standout(){
	tputs(gl_env.standout, 1, my_termprint);
}