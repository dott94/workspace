/*David Ott
pipes.c assingment
I pledge my honor that I have abided by the stevens honor system
*/
#include <sys/wait.h>
#include "my.h"
#define BUFFER_SIZE 100

int main(int argc, char** argv) {
    char buffer[BUFFER_SIZE];
    int pipe1[2];
    int pipe2[2];
    int pid;
    int bytesIn;
    char* c;

    if (argc < 2) {
        my_str("Use: ./pipes arg1 [arg2] [arg3] [...]\n"); //Usage error
        exit(0);
    }

    pipe(pipe1);

    if ((pid = fork()) < 0) { //pid should not be negative
        my_str("Error creating father process\n");
        exit(0);
    }

    if (pid == 0) { //this is the Father process
        close(pipe1[1]);
        bytesIn = read(pipe1[0], buffer, BUFFER_SIZE - 1); //reading from Grandfather
        buffer[bytesIn] = '\0';
        my_str("Dad is receiving \"");
        my_str(buffer);
        my_str("\"\n");

        pipe(pipe2);

        if ((pid = fork()) < 0) { //pid should not be negative
            my_str("Error creating child process \n");
            exit(0);
        }

        if (pid == 0) { //this is the child process
            close(pipe2[1]);
            bytesIn = read(pipe2[0], buffer, BUFFER_SIZE - 1); //reading from Father
            buffer[bytesIn] = '\0';

            my_str("Child is receiving \"");
            my_str(buffer);
            my_str("\"\n");
            exit(0);

        } else { //this is the father process
            close(pipe2[0]);
            write(pipe2[1], buffer, BUFFER_SIZE - 1); //sending to Child process
            wait(NULL);

        }

    } else { //this is the Grandfather process
        close(pipe1[0]);

        c = my_vect2str(&argv[1]);
        my_str("Grandpa is sending \"");
        my_str(c);
        my_str("\"\n");

        write(pipe1[1], c, BUFFER_SIZE - 1); //sending to Father process
        wait(NULL);

    }

    return 0;
}
