//precondition: n is a list of chars
//postcondition: the list of chars is printed with detail (i.e N<-54->23)

#include "mylist.h"

void debug_char(t_node* n) {
    t_node* listptr;
    if (n != NULL) {
        listptr = n;
        while (listptr->next != NULL) {
            print_char(listptr);
            listptr = listptr->next;
            my_char(' ');
        }
        print_char(listptr);
    } else
        my_str("The list is empty");
}
