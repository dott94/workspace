#include "my_stdio.h"
/*pre: none
*post: flush a single file
*/
int my_fflush(t_my_file *fp){
	int ret;
	int i = 0;
	if(fp == NULL){
		return EOF;
	}
	while(i < fp->size){

		ret = write(fp->fd, &(fp->buff)[i], 1);		
		if(ret <= 0){
			return EOF;
		}
		i++;	
	}
	fp->pos += i;
	fp -> buff = NULL;
	fp ->size = 0;
	return 0;
}
