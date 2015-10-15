#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 100


int main(int argc, char** argv) {
	FILE* inFile;
	FILE* outFile;
	char* buffer = 0;
	size_t buffer_size = BUFFER_SIZE;
	
	inFile = fopen(argv[1], "r");
	outFile = fopen(argv[2], "w");

	while(-1 != getline(&buffer, &buffer_size, inFile))
	{
		fprintf(outFile, "%s", buffer);
	}
	return 0; 
}