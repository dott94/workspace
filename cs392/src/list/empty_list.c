//precondition: ph is a list
//postcondition: ph is an empty list

#include "mylist.h"

void empty_list(t_node** ph) {
    t_node* listptr;
    if (ph != NULL) {
        listptr = (*ph)->next;
        free(*ph);
        *ph = NULL;
        while (listptr->next != NULL) {//parsing though list
            listptr = listptr->next;
            free(listptr->prev);//freeing nodes
        }
        free(listptr);
    }
}
