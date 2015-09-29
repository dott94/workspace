#include "myselect.h"

/*
 * This program displays all of the files in the current directory. The user can navigate through the
 * files with his arrow keys. The program ends when the user presses the esc and enter keys.
 * 
 * Precondition: None
 * Postcondition: None
 */

int main(int argc, char** argv){

	int  data;
	char input[READMIN + 2];

	if(argc < 2){
		my_str("Usage: ./myselect itemSelector\n");
		exit(1);
	}
	if(my_strpos(argv[1], '*') == 0){
		my_str("No files were found\n");
		exit(1);
	}

	signal(SIGWINCH, show_elems);

	init_caps(); //Get the termcaps

	init_terminal();  //initilize the terminal

	setup_elems(argc - 1, &argv[1]);  //Setup elems

	tputs(gl_env.cursoroff, 0, my_termprint);  //Turn off cursor	

	show_elems();  //actually show the elements

	while(1){
		data = read(0, &input, READMIN + 2);
		input[data] = '\0';

		if(!gl_env.flag){
			check_char(input);
		}
	}
	
	return 0;
}