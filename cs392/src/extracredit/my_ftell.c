#include "my_stdio.h"

/*pre: a file is open
* post: returns the position of the file pointer
*/

long my_ftell(t_my_file *fp){
	if(fp == NULL){
		return 0;
	}
	return fp -> pos;
}
