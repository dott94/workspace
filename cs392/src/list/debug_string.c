//precondition: n is a list of strings
//postcondition: the list of strings is printed with detail (i.e N<-54->23))


#include "mylist.h"

void debug_string(t_node* n) {
    t_node* listptr;
    if (n != NULL) {
        listptr = n;
        while (listptr->next != NULL) {
            print_string(listptr);
            listptr = listptr->next;
            my_char(' ');
        }
        print_string(listptr);
    } else
        my_str("The list is empty");
}
