#include "my_stdio.h"

/*pre: a file open
* post: the file is closed
*/

int	my_fclose(t_my_file *fp){
	if(fp == NULL){
		return 0;
	}
	if(fp ->flag == 0){
		return EOF;
	}
	free(fp -> buff);
	free(fp);
	return EOF;
}
