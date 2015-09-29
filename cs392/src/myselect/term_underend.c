#include "myselect.h"

/*
 * Precondition: Termcaps initialized
 * Postcondition: Underline is disabled
 */

void term_underend(){
	tputs(gl_env.under_end, 1, my_termprint);
}