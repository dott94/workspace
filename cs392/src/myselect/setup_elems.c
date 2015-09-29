#include "myselect.h"

/*
 * Precondition: There is at least one element
 * Postcondition: Element information is saved globally 
 */

void setup_elems(int num, char** elems){

	int i;
	gl_env.nbelems = num;
	gl_env.elements = xmalloc(num * sizeof(t_elem));

	for(i = 0; i < num; i++){
		gl_env.elements[i].elem = elems[i];
		gl_env.elements[i].size = my_strlen(elems[i]);
		gl_env.elements[i].mode = 0;
	}
}