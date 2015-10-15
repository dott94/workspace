#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 100
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "cbuf.h"

struct argument_t {
	FILE* file; sem_t* mutex; sem_t* items; sem_t* spaces;
};

void* fillThreadFunc(void* argsIn) {
	struct argument_t* args = argsIn;
	int lineNum = 1;
	char* lineBuffer;
	size_t buffer_size = CBUF_CAPACITY;
	size_t nread;
	lineBuffer = (char*)malloc(buffer_size);
	nread = getline(&lineBuffer, &buffer_size, args->file);
	while (-1 != nread)
	{
		usleep(50);
		while (!cbuf_space_available()) {
			printf("fillThread: Could not write\n");
		}
		sem_wait(&(*args->spaces));
		sem_wait(&(*args->mutex));
		cbuf_copy_in(lineBuffer);
		sem_post(&(*args->mutex));
		sem_post(&(*args->items));
		printf("fillThread: wrote line %d into buffer (nwritten = %d )\n", lineNum, (int)nread);
		lineNum++;
		nread = getline(&lineBuffer, &buffer_size, args->file);
	}
	free(lineBuffer);
	sem_wait(&(*args->spaces));
	sem_wait(&(*args->mutex));
	cbuf_copy_in("QUIT");
	sem_post(&(*args->mutex));
	sem_post(&(*args->items));
	return NULL;
}
void* drainThreadFunc(void* argsIn) {
	struct argument_t* args = argsIn;
	int lineNum = 1;
	size_t nread;
	char lineBuffer[CBUF_CAPACITY];
	while (!cbuf_data_is_available()) {
		printf("drainThread: No new string in buffer\n");
	}
	sem_wait(&(*args->mutex));
	sem_wait(&(*args->items));
	cbuf_copy_out(lineBuffer);
	sem_post(&(*args->spaces));
	sem_post(&(*args->mutex));
	while (strcmp(lineBuffer, "QUIT") != 0)
	{
		usleep(50);
		fprintf(args->file, "%s", lineBuffer);
		nread = strlen(lineBuffer);
		printf("drainThread: read line %d from buffer (nread = %d )\n", lineNum, (int)nread);
		while (!cbuf_data_is_available()) {
			printf("drainThread: No new string in buffer\n");
		}
		sem_wait(&(*args->mutex));
		sem_wait(&(*args->items));
		cbuf_copy_out(lineBuffer);
		sem_post(&(*args->spaces));
		sem_post(&(*args->mutex));
		lineNum++;
	}
	return NULL;
}

int main(int argc, char** argv) {
	FILE* inFile;
	FILE* outFile;
	pthread_t fillThread;
	pthread_t drainThread;
	sem_t mutex;
	sem_t items;
	sem_t spaces;
	struct argument_t fillThreadArgs;
	struct argument_t drainThreadArgs;
	inFile = fopen(argv[1], "r");
	outFile = fopen(argv[2], "w");
	fillThreadArgs.file = inFile;
	drainThreadArgs.file = outFile;
	drainThreadArgs.mutex = &mutex;
	fillThreadArgs.mutex = &mutex;
	drainThreadArgs.items = &items;
	fillThreadArgs.items = &items;
	drainThreadArgs.spaces = &spaces;
	fillThreadArgs.spaces = &spaces;
	cbuf_init();
	sem_init(&mutex, 0, 1);
	sem_init(&items, 0, 0);
	sem_init(&spaces, 0, CBUF_CAPACITY);

	if (pthread_create(&fillThread, NULL, fillThreadFunc, &fillThreadArgs)) {

		fprintf(stderr, "Error creating thread\n");
		return 1;

	}
	if (pthread_create(&drainThread, NULL, drainThreadFunc, &drainThreadArgs)) {

		fprintf(stderr, "Error creating thread\n");
		return 1;

	}

	if (pthread_join(fillThread, NULL)) {

		fprintf(stderr, "Error joining thread\n");
		return 2;

	}
	if (pthread_join(drainThread, NULL)) {

		fprintf(stderr, "Error joining thread\n");
		return 2;

	}
	sem_destroy(&mutex);
	sem_destroy(&items);
	sem_destroy(&spaces);
	cbuf_terminate();


	return 0;
}