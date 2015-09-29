#include "myselect.h"

/*
 * Precondition: user has typed a character
 * Postcondition: the character translates into an action taken by the program
 */

char check_char(char* input){

	if(input != NULL){
		if(my_strcmp(input, KU) == 0){
			moveup();
		}else if(my_strcmp(input, KD) == 0){
			movedown();
		}else if(my_strcmp(input, KL) == 0){
			moveleft();
		}else if(my_strcmp(input, KR) == 0){
			moveright();
		}else if(my_strcmp(input, " ") == 0){
			doselect();
		}else{
			getout(input);
		}
	}
	return *input;
}