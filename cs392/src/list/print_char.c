//precondition: n is a node containing a char
//postcondition: the contents of n are printed

#include "mylist.h"

void print_char(t_node* n) {
    if (n != NULL) {
        my_char('(');
        if (n->prev == NULL)
            my_char('N');
        else
            my_char(*(char*)n->prev->elem);
        my_str("<-");
        if(n->elem == NULL)
	  my_char('N');
	else
	    my_char(*(char*)n->elem);
        my_str("->");
        if (n->next == NULL)
            my_char('N');
        else
            my_char(*(char*)n->next->elem);
        my_char(')');
    }
}
