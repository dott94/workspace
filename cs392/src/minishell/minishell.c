/*
 * precondition: No precondition
 * postcondition: A working shell with a user prompt showing the current directory
 *
 * minishell is a functioning shell that takes takes in all command line arguments.
 * It's functionalities are similar to Unix shell(bash)
 *
 * I pledge my honor that I have abided by the Stevens honor system
 */
#include <sys/wait.h>
#include "my.h"
#define BUFFER_SIZE 100

int main(int argc, char** argv) {
    char buffer[BUFFER_SIZE];
    char** usrinput;
    int size;
    int pid;
    char* current;
    int retval;

    while (1) {
        my_str("Prompt> ");
        current = getcwd(current, BUFFER_SIZE); //current directory
        my_str(current);
        my_str(": ");

        if ((size = read(0, buffer, BUFFER_SIZE - 1)) < 0) { //invalid read
            my_str("Error reading\n");
            exit(0);
        }
        buffer[size - 1] = '\0';
        usrinput = my_str2vect(buffer); //user input conversion

        if (my_strcmp(usrinput[0], "exit") == 0) { //program exiting
            my_str("successfully exited. Come back soon!!!!!!!\n");
            my_vectfree(usrinput);
            exit(0);
        } else if (my_strcmp(usrinput[0], "cd") == 0) {
            if ((retval = chdir(usrinput[1])) < 0) { //not a valid directory
                if (usrinput[1] == NULL) {
                    my_str("User input not valid\n");
                } else {
                    my_str(usrinput[1]);
                    my_str("> No such Directory\n");
                }
            }
        } else {
            if ((pid = fork()) < 0) { //invalid pid
                my_str("fork error\n");
                exit(0);
            }

            if (pid > 0) {
                wait(NULL);
            } else {
                if ((retval = execvp(usrinput[0], usrinput)) < 0) { //invalid command
                    my_str(usrinput[0]);
                    my_str(": Command not found\n");
                    exit(0);
                }
            }
        }
        my_vectfree(usrinput);
    }

    return 0;
}
