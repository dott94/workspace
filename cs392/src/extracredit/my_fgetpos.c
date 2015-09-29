#include "my_stdio.h"
/*pre: an open file
* post: returns current position in file
*/
int	my_fgetpos(t_my_file *fp, fpos_t *pos){
	if(fp == NULL || pos == NULL){
		return -1;
	}
	*pos = my_ftell(fp);
	return 0;
}
