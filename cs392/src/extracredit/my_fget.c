#include "my_stdio.h"

/*pre: a file exists
* post: returns the next integer in the file  
*/

int	my_fget(t_my_file *fp){
	int count;
	int ret;
	if(fp == NULL){
		return 0;
	}
	count = read(fp -> fd, &ret, sizeof(int));
	fp->pos += count;
	if(count <= 0){
		return EOF;
	}
	return ret;
}
