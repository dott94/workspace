#include "myselect.h"

/*
 * Precondition: None
 * Postcondition: The character chr is written to the terminal
 */

int my_termprint(int chr){
	int result = write(1, &chr, 1);
	return result;
}