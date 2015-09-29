#include "my_stdio.h"

/*pre: a file is open
* post: returns an array of n elements
* each is the size of s bites from the file pointer
* stores them in ptr
*/

size_t my_fread(void *ptr, size_t s, size_t n, t_my_file *fp){
	int count;
	int eof = 0;
	int i = 0;
	if(ptr == NULL || fp == NULL || n == 0 || s == 0){
		return 0;
	}
	while(i < n && eof != 1){
		count = read(fp -> fd, (ptr + s*i), s);
		fp->pos += count;
		if(count <= 0){
			eof = 1;
			i--;
		}
		i++;
	}
	return i * s;	
} 
