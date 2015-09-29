//precondition: n is a list of strings
//postcondition: the strings of list n are printed 

#include "mylist.h"

void traverse_string(t_node* n) {
    t_node* listptr;
    if (n != NULL) {
        listptr = n;
        while (listptr->next != NULL) {
            my_str((char*)listptr->elem);
            listptr = listptr->next;
            my_char(' ');
        }
        my_str((char*)listptr->elem);
    }
}
