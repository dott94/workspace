#include "my_stdio.h"

/*pre: a file exists
* post: returns at most n - 1 characters from the file,
* will stop when new line has been read 
*/

char* my_fgets(char * buffer, int n, t_my_file *fp){
	int count;
	int i = 0;
	int eof = 0;
	int this_char = 0;
	char c;
	if(buffer == 0 ||n == 0 || fp == 0){
		return NULL;
	}
	while(i < n && this_char != '\n' && eof != 1){
		count = read(fp -> fd, &c, sizeof(char));
		fp->pos += count;
		if(count <= 0){
			eof = 1;
			i--;
		}
		else if(c != '\n'){
			buffer[i] = c;
		}
		i++;		
	}
	return buffer;
}
