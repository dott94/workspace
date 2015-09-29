//precondition: n is list of chars
//postcondition: characters of n are printed to the screen

#include "mylist.h"

void traverse_char(t_node* n) {
    t_node* listptr;
    if (n != NULL) {
        listptr = n;
        while (listptr->next != NULL) {
            my_char(*(char*)listptr->elem);
            listptr = listptr->next;
            my_char(' ');
        }
        my_char(*(char*)listptr->elem);
    }
}
