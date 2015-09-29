#include "my_stdio.h"
/*test main for my_stdio library*/



int main(){
	//vars
	t_my_file* file;
	char c;
	int i;
	char* buff = xmalloc(100);
	fpos_t pos;
	
	/*test for my_fopen()*/
	if (my_fopen(NULL, NULL) == NULL){
		my_str("Test1 my_fopen Pass");
		my_char('\n');
	}
	else{
		my_str("Test1 fopen fail");
		my_char('\n');
	}
	file = my_fopen("test.txt", "w"); //should open up a file for writing
	if(file == NULL){
		my_str("my_fopen did not work \n");
	}
	else{
		my_str("my_fopen did work \n");
	}
	
	
	
	
	/*test for fputc*/
	if(my_fputc(-1, NULL) == EOF){
		my_str("fputc NULL test pass \n");
	}
	else{
		my_str("fputc NULL test fail \n");
	}
	i = 'D';	
	if(my_fputc(i, file) == i){
		my_str("fputc test pass \n");
	}
	else{
		my_str("fputc test fail \n");
	}
	
	
	
	
	/*test for fput*/
	if(my_fput(-1, NULL) == EOF){
		my_str("fput NULL test pass \n");
	}
	else{
		my_str("fput NULL test fail \n");
	}
	i = 5;	
	if(my_fput(i, file) == i){
		my_str("fput test pass \n");
	}
	else{
		my_str("fput test fail \n");
	}



	/*test for fputs*/
	if(my_fputs(NULL, NULL) == EOF){
		my_str("fputs NULL test pass \n");
	}
	else{
		my_str("fputs NULL test fail \n");
	}	
	if(my_fputs("puts test\0", file) >  0){
		my_str("fputs test pass \n");
	}
	else{
		my_str("fputs test fail \n");
	}
	



	/*test for fwrite*/
	if(my_fwrite(NULL, 0, 0, NULL) == 0){
		my_str("fwrite NULL test pass \n");
	}
	else{
		my_str("fwrite NULL test fail \n");
	}	
	if(my_fwrite("write test", 1, 10, file) >  0){
		my_str("fwrite test pass \n");
	}
	else{
		my_str("fwrite test fail \n");
	}
	
	
	/*test for my_fclose()*/
	if (my_fclose(file) == 0){
		my_str("test1 my_fclose fail \n");
		my_char('\n');
	}
	else{
		my_str("test1 fclose pass \n");
	}
	
	
	
	
	
	file = my_fopen("test.txt", "r"); //should open up a file for reading
	
	
	/*testing fgetc*/
	if(my_fgetc(NULL) == EOF){
		my_str("fgetc NULL test pass \n");
	}
	else{
		my_str("fgetc NULL test fail \n");
	}
	
	if((c = my_fgetc(file)) != EOF){
		my_char(c);
		my_char('\n');
		my_str("fgetc test1 pass \n");
	}
	else{
		my_str("fgets test1 fail \n");
	}
	 
	
	
	

	 
	/*testing fget*/
	if(my_fget(NULL) == 0){
		my_str("fget NULL test pass \n");
	}
	else{
		my_str("fget NULL test fail \n");
	}
	
	if((i = my_fget(file)) != 0){
		my_int(i);
		my_char('\n');
		my_str("fget test1 pass \n");
	}
	else{
		my_str("fget test1 fail \n");
	} 
			
	
		
	
	/*testing fgets*/
	if(my_fgets(NULL, 0, NULL) == 0){
		my_str("fgets NULL test pass \n");
	}
	else{
		my_str("fgets NULL test fail \n");
	}
	if(my_fgets(buff, 9, file) == buff){
		my_str(buff);
		my_str("fgets test1 pass \n");
	}
	else{
		my_str("fgets test1 fail \n");
	}
	
	
	

	/*test for ftell*/
	if(my_ftell(file) == 14){
		my_str("ftell test pass, correct spot \n");
	}else{
		my_str("ftell test failed \n");
		my_int(my_ftell(file));
		my_char('\n');
	}
	
	
	
	/*test for my_fread*/
	if(my_fread(NULL, 0, 0, NULL) == 0){
		my_str("fread NULL test pass \n");
	}
	else{
		my_str("fread NULL test fail \n");
	}
	if(my_fread(buff, 1, 10, file) == 10){
		my_str(buff);
		my_char('\n');
		my_str("fread 10 char pass \n");
	}
	else{
		my_str("fread 10 char fail \n");
	}
	
	my_fclose(file);
	
	file = my_fopen("test.txt", "r"); //should open up a file for read 
	
	
	/*fgetpos test*/
	my_fgetpos(file, &pos);
	if(pos == 0){
		my_str("fgetpos test pass, correct spot \n");
	}else{
		my_str("fgetpos test failed \n");
	}
	
	for(i = 0; i < 100; i++){
		buff[i] = '\0';
	}
	
	/*fseek test*/
	my_fseek(file, 13, SEEK_SET);
	if(my_ftell(file) == 13){
		my_str("fseek test pass, correct spot \n");
	}else{
		my_str("fseek test failed \n");
		my_int(my_ftell(file));
		my_char('\n');
	}
	my_fread(buff, 1, 5, file); 
	my_str(buff);
	my_char('\n');
	
	
	for(i = 0; i < 100; i++){
		buff[i] = '\0';
	}
	
	/*fsetpos test*/
	pos = 20;
	if(my_fsetpos(file, &pos) == 0){
		my_str("fsetpos test pass, correct spot \n");
	}else{
		my_str("fsetpos test failed \n");
	}	
	my_fread(buff, 1, 2, file); //should read st, last 2 positions
	my_str(buff);
	my_char('\n');
	
	
 
 /*flush is unnecessary to test because it is being called in the previous methods*/
 



}

