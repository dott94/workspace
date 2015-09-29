#include "myselect.h"

/*
 * Precondition: Termcaps initialized
 * Postcondition: Underline is enabled 
 */
void term_underline(){
	tputs(gl_env.underline, 1, my_termprint);
}