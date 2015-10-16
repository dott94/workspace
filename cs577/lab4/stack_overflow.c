#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char mybuf[4096];


void unbelievable()
{
	printf("I don't believe it!\n");
	exit(0);
}

void echo_input(char* arg)
{
	char buf[256];

	strcpy(buf, arg);
	printf("echo: %s\n", buf);
}

void read_input(FILE *fp, char *buf, size_t len)
{
	if (fread(buf, len, 1, fp) < 0) {
		perror("error reading input");
		exit (1);
	}
}

int main(int argc, char* argv[]) 
{
	read_input(stdin, mybuf, sizeof(mybuf));

	echo_input(mybuf);

	return 0;
}
