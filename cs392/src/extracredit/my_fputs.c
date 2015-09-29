#include "my_stdio.h"
/*pre: an open file
* post: the string s is written to file
*/
int	my_fputs(char *s, t_my_file *fp){
	char c;
	int i = 0;
	if(fp == NULL){
		return EOF;
	}
	fp -> buff = s;
	c = s[i];
	while(c != '\0'){
		i++;
		c = s[i];
	}
	fp -> size = i;
	if(my_fflush(fp) == 0){
		return i;
	}
	else{
		return EOF;
	}
}
