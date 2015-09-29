#include "myselect.h"

/*
 * Precondition: Termcaps initialized
 * Postcondition: Highlighting is disabled
 */

void term_standend(){
	tputs(gl_env.stand_end, 1, my_termprint);
}