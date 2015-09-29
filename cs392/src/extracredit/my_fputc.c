#include "my_stdio.h"
/*pre: file is open
* post: character is written to file
*/
int	my_fputc(int i, t_my_file *fp){
	if(fp == NULL){
		return EOF;
	}
	fp -> buff = (char*)&i;
	fp -> size = 1;
	if(my_fflush(fp) == 0){
		return i;
	}
	else{
		return EOF;
	}
}
