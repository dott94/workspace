#include "my_stdio.h"
/*pre: an open file
* post: position is set in file
*/
int	my_fsetpos(t_my_file *fp, fpos_t *pos){
	if(fp == NULL || pos == NULL){
		return EOF;
	}
	if(my_fseek(fp, *pos, SEEK_SET) != 0){
		return EOF;
	}
	return 0;
}
