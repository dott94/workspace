#include "myselect.h"

/*
 * Precondition: termcap is != null
 * Postcondition: string representation of termcap is returned
 */

char* term_get_cap(char* termcap){

	static char area[2048];
	char* result = tgetstr(termcap, (char**) &area);
	if(!result){
		if(!my_strcmp(termcap, CURSOROFF) || !my_strcmp(termcap, CURSORON)){
			if(!my_strcmp(termcap, CURSOROFF)){
				result = VICAP;
			}else{
				result = VECAP;
			}
		}else{
			my_str("Termcap ");
			my_str(termcap);
			my_str(" was not found\n");
			restore_terminal();
			exit(1);
		}
	}

	return result;
}