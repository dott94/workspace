#include "my_stdio.h"
/*pre: an open file
* post: integer is written to file
*/
int	my_fput(int i, t_my_file *fp){
	if(fp == NULL){
		return EOF;
	}
	fp -> buff = (char*)&i;
	fp -> size = sizeof(int);
	if(my_fflush(fp) == 0){
		return i;
	}
	else{
		return EOF;
	}
}
