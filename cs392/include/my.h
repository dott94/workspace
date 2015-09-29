#ifndef LIBMY_MY_H_
#define LIBMY_MY_H_
#ifndef NULL
#define NULL ((void*)0)
#endif
#include <unistd.h>
#include <stdlib.h>



void my_char(char c);
void my_alpha();
void my_int(int i);
void my_str(char* s);
int my_revstr(char* s);
int my_strindex(char* s, char c);
int my_strrindex(char* s, char c);
int my_strlen(char* s);
void my_digits();
void my_num_base(int num, char* string);


void* xmalloc(unsigned int n);
char *my_strdup(char*);
char *my_strcpy(char *dst, char *src);
char *my_strncpy(char *dst, char *src, unsigned int n);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, unsigned int n);
char *my_strconcat(char *s1, char *s2);
char *my_strnconcat(char *s1, char *s2, unsigned int n);
char *my_strcat(char *s1, char *s2);
char *my_strfind(char*, char);
char *my_strrfind(char*, char);

char* my_vect2str(char**);
char **my_str2vect(char*);
void my_panic(char *, unsigned int n);

void my_vectfree(char**);

int my_atoi(char*);

int my_strpos(char*, char);
int my_strrpos(char*, char);

#endif /* LIBMY_MY_H_ */
