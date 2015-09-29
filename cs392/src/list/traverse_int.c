//precondition: n is a list of integers 
//postcondition: the list of integers is printed 

#include "mylist.h"

void traverse_int(t_node* n) {
    t_node* listptr;
    if (n != NULL) {
        listptr = n;
        while (listptr->next != NULL) {
            my_int(*(int*)listptr->elem);
            my_char(' ');
            listptr = listptr->next;
        }
        my_int(*(int*)listptr->elem);
    }
}
