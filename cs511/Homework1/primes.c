/*David Ott
 primes.c assingment

 This assignment can be built with make
 The program creates all child processes, children computes primes concurrently and send data back to parent
 Parent uses select() to wait for data from children

 I pledge my honor that I have abided by the stevens honor system
 */

#include "primes.h"
int isPrime(int input) { /*Method for determining whether a input is prime*/
	int i;
	for (i = 2; i < input / 2; i++) {
		if (input % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv) {
	char buffer[BUFFER_SIZE];
	int pipes[BUFFER_SIZE][2];
	int pid[BUFFER_SIZE];
	int pidFd[BUFFER_SIZE];
	int pidPipe[BUFFER_SIZE];
	int bytesIn; /*used to store read data from pipes and fd*/
	int previ = 2;
	int i;
	int foundPrimes;/* used to store findprimes values*/
	int status; /*for wait method*/
	int procCountFd[BUFFER_SIZE]; /*used to count FIFO processes*/
	int procCountPipe[BUFFER_SIZE]; /*used to cound pipe processes*/
	char fifoName[BUFFER_SIZE][BUFFER_SIZE]; /*name of the files for fifo process (unique to each fifo)*/
	char* fifoNamePrefix = "./fifo"; /*prefix of all Fifo file names*/
	int fd[BUFFER_SIZE]; /*file descriptor*/
	int fd_num = -1; /*number of the file descritpor*/
	int pipe_num = -1; /*number of the pipe*/
	fd_set fdset;
	int pid1;
	int retval; /*return val used in select */
	struct timeval tv;
	int aliveChildren = 0; /*count used for num of child processes*/
	FD_ZERO(&fdset);
	tv.tv_sec = 60;
	tv.tv_usec = 0;


	int findPrimes(int start, int finish, int* pipe1) { /*finds prime numbers in an index*/
		char buffer[BUFFER_SIZE];
		int i;
		int c = 0;
		for (i = start; i <= finish; i++) {
			if (isPrime(i)) {
				c++;
				sprintf(buffer, "%d is prime \n", i);
				write(pipe1[1], buffer, BUFFER_SIZE - 1); /*writes the data to pipe1*/
			}
		}
		sprintf(buffer, "x"); /* x is used as a marker to determine the end of the buffer*/
		write(pipe1[1], buffer, BUFFER_SIZE - 1);
		return c;
	}
	int findPrimesFifo(int start, int finish, char* fifoName) { /*finds primes in an index*/
		char buffer[BUFFER_SIZE];
		int i;
		int c = 0;
		int fd = open(fifoName, O_WRONLY); /*fd is the file descriptor of openfile*/
		for (i = start; i <= finish; i++) {
			if (isPrime(i)) {
				c++;
				sprintf(buffer, "%d is prime \n", i);
				write(fd, buffer, BUFFER_SIZE - 1); /*writes data to file from buffer*/
			}
		}
		sprintf(buffer, "x");
		write(fd, buffer, BUFFER_SIZE - 1);
		close(fd);
		return c;
	}


	if (argc < 2) {
		printf("usage: ./primes <increasing positive integers>\n"); /*Usage error*/
		exit(0);
	}
	/*creating all child processes*/
	for (i = 1; i < argc; i++) {
		if (i % 2 == 1) {
			pipe_num++;
			pipe(pipes[pipe_num]);
		}
		else {
			fd_num++;
			sprintf(fifoName[fd_num], "%s_%d", fifoNamePrefix, fd_num);
			mkfifo(fifoName[fd_num], S_IRUSR | S_IWUSR);

		}
		aliveChildren++;
		if ((pid[i] = fork()) < 0) { /*pid should not be negative*/
			printf("Error creating child process\n");
			exit(0);
		}
		if (pid[i] == 0) {
			printf("Child %d : Bottom = %d, Top = %d \n", getpid(), previ, atoi(argv[i]));
			if (i % 2 == 1) {
				foundPrimes = findPrimes(previ, atoi(argv[i]), pipes[pipe_num]);
			}
			else {
				foundPrimes = findPrimesFifo(previ, atoi(argv[i]), fifoName[fd_num]);
				unlink(fifoName[fd_num]);
			}
			exit(foundPrimes);
		} else {
			if (i % 2 == 1) {
				pidPipe[pipe_num] = pid[i];
			} else {
				pidFd[fd_num] = pid[i];
			}
			previ = atoi(argv[i]) + 1;
		}
	}

	/*computing primes amongst child processes concurrently */
	for (i = 0; i <= fd_num; i++) {
		fd[i] = open(fifoName[i], O_RDONLY);
		procCountFd[i] = 0;
	}
	for (i = 0; i <= fd_num; i++) {
		procCountPipe[i] = 0;
	}

	while (aliveChildren > 0) {

		/* load pipes to fdset*/
		for (i = 0; i <= pipe_num; i++) {
			FD_SET(pipes[i][0], &fdset);
		}
		/* load fds to fdset*/
		for (i = 0; i <= fd_num; i++) {
			FD_SET(fd[i], &fdset);
		}
		retval = select(FD_SETSIZE, &fdset, NULL, NULL, &tv);
		if (retval == -1) {
			perror("Select failed.\n");
		}
		else if (retval)
		{
			/* Section used to child communication via pipe*/
			for (i = 0; i <= pipe_num; i++) {
				if (FD_ISSET(pipes[i][0], &fdset)) {
					bytesIn = read(pipes[i][0], buffer, sizeof(buffer) - 1);
					if (bytesIn > 0) {
						if (buffer[0] == 'x') {
							buffer[0] = '\0'; /*setting null char*/
							if ((pid1 = waitpid(pidPipe[i], &status, 0)) != -1) {
								if (procCountPipe[i] == WEXITSTATUS(status)) { /*child ready to exit*/
									printf("Child %d exited correctly \n", pid1);
								}
								else {
									printf("Child %d did not exit correctly \n", pid1);
								}
								aliveChildren--;
								break;
							}
						} else {
							printf("%s", buffer);
							procCountPipe[i]++;
						}
					}
				}
			}
			/* Section for child communication via FIFO*/
			for (i = 0; i <= fd_num; i++) {
				if (FD_ISSET(fd[i], &fdset)) {
					bytesIn = read(fd[i], buffer, sizeof(buffer) - 1);
					if (bytesIn > 0) {
						if (buffer[0] == 'x') {
							buffer[0] = '\0'; /*setting null char*/
							if ((pid1 = waitpid(pidFd[i], &status, 0)) != -1) {
								if (procCountFd[i] == WEXITSTATUS(status)) { /*child ready to exit */
									printf("Child %d exited correctly \n", pid1);
								}
								else {
									printf("Child %d did not exit correctly \n", pid1);
								}
								aliveChildren--;
								break;
							}
						} else {
							printf("%s", buffer);
							procCountFd[i]++;
						}
					}
				}
			}
		}
	}


	return 0;
}
