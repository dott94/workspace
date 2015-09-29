#include "my_stdio.h"

/*pre: a file is open
* post: writes an array of n elements
* each is the size of s bites from the file pointer
* gets them from ptr
*/

size_t my_fwrite(void *ptr, size_t s, size_t n, t_my_file *fp){
	int count;
	int i = 0;
	if(ptr == NULL || fp == NULL || n == 0 || s == 0){
		return 0;
	}
	while(i < n){
		count = write(fp -> fd, (ptr + s*i), s);
		fp->pos += count;
		if(count < s){
			return (i * s) + count;
		}
		i++;
	}
	return i * s;	
} 
