//precondition: n is a node that contains a string
//postcondition: the contents of n are printed to the screen

#include "mylist.h"

void print_string(t_node* n) {
    if (n != NULL) {
        my_char('(');
        if (n->prev == NULL)
            my_char('N');
        else
            my_str((char*)n->prev->elem);
        my_str("<-");
        if(n->elem == NULL)
	  my_char('N');
	my_str((char*)n->elem);
        my_str("->");
        if (n->next == NULL)
            my_char('N');
        else
            my_str((char*)n->next->elem);
        my_char(')');
    }
}
