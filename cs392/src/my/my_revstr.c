#include "my.h"

int my_revstr(char* s){
  int len = my_strlen(s);    
  int i = len - 1;
    if(!s) return -1;
    while(i >= 0){
        my_char(*(s + i));
        i--;
    }
    return len;
}




