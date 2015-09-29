#include "my_stdio.h"
/*pre:file is open
* post: file pointer is set to start of file
*/
void my_rewind(t_my_file *fp){
	my_fseek(fp, 0, SEEK_SET);
}
