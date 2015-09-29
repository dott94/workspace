#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void echo_input(char* arg)
{
	char buf[256];

	/* Oops! Vulnerable Code */
	strcpy(buf, arg);
	printf("echo: %s\n", buf);
}

int main(int argc, char* argv[]) 
{
	char mybuf[4096];

	fread(mybuf, sizeof(mybuf), 1, stdin);

	echo_input(mybuf);

	return 0;
}
