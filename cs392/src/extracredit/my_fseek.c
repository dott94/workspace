#include "my_stdio.h"
/*pre: an open file
* post: cursor is set to specified position
*/
int	my_fseek(t_my_file * fp, long offset, int origin){
	int seeknum;
	int current;
	int seekpos;
	int ret = 1;
	int filesize = 0;
	char* dummy = xmalloc(1);
	
	if(fp == NULL){
		return EOF;
	}
	current = my_ftell(fp);
	switch(origin){
		case SEEK_SET:
		if(offset < 0){
			return EOF;
		}
		seekpos = offset;
		break;
		case SEEK_CUR:
		seekpos = current + offset;
		if(seekpos < 0){
			return EOF;
		}
		break;
		case SEEK_END:
		//find the size of the file
		filesize = fp -> pos;
		ret = read(fp -> fd, &dummy, 1);
		while(ret > 0){
			filesize++;
			ret = read(fp -> fd, &dummy, 1);
		}
		seekpos = filesize + offset;
		if(seekpos >= filesize || seekpos < 0){
			return EOF;
		}
		break;
		default:
		return EOF;
		break;
	}
	seeknum = seekpos - current;
	if(seeknum < 0){
		return EOF;
	}
	ret = read(fp -> fd, dummy, 1);
	while(ret > 0 && seeknum > 0){
		seeknum--;
		ret = read(fp -> fd, dummy, 1);
	}
	fp->pos = seekpos;
	return 0;
}
