#include "my_stdio.h"

/*pre: a file exists
* post: file will be opened for read and write purposes 
*/

t_my_file *my_fopen(char *file, char *mode){
	int f;
	int flags;
	t_my_file* fp;
	if(file == NULL || mode == NULL){
		return NULL;
	}
	if(*mode == READ){
		flags = O_RDONLY;
	}
	else if(*mode == WRITE){
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	}
	else if(*mode == APPEND){
		flags = O_WRONLY | O_CREAT | O_APPEND;
	}
	else if(*mode == READWRITE){
		flags = O_CREAT | O_TRUNC | O_RDWR;
	}
	else{
		return NULL; 
	}							
	f = open(file, flags);
	if(f < 0){
		return NULL;
	}
	fp = xmalloc(sizeof(t_my_file));
	
	fp -> fd = f;
	fp -> pos = 0;
	fp -> posw = 0;
	fp -> size = 0;
	fp -> flag = flags;
	

return fp;
}
