#include "myselect.h"

/*
 * Precondition: program is running
 * Postcondition: Program is exited
 */

void getout(char* in){

	int i;
	if(in != NULL){
		if(my_strcmp(in, "\E") == 0){
			restore_terminal();
			exit(0);
		}else if(my_strcmp(in, "\n") == 0){
			restore_terminal();
			for(i = 0; i < gl_env.nbelems; i++){
				if(gl_env.elements[i].mode){
					my_str(gl_env.elements[i].elem);
					my_str(" ");
				}
			}
			my_char('\n');
			exit(0);
		}
		
	}
}