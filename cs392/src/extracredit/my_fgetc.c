#include "my_stdio.h"

/*pre: a file exists
* post: returns the next character in the file  
*/

int	my_fgetc(t_my_file *fp){
	int count;
	int ret;
	if(fp == NULL){
		return EOF;
	}
	count = read(fp -> fd, &ret, sizeof(char));
	fp->pos += count;
	if(count <= 0){
		return EOF;
	}
	return ret;
}
