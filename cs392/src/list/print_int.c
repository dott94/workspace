//precondition: n is a node that contains an integer
//postcondition: the contents of n are printed 
#include "mylist.h"

void print_int(t_node* n) {
    if (n != NULL) {
        my_char('(');
        if (n->prev == NULL)
            my_char('N');
        else
            my_int(*(int*)n->prev->elem);
        my_str("<-");
        if(n->elem == NULL)
	  my_char('N');
	    
	else
	  my_int(*(int*)n->elem);
        my_str("->");
        if (n->next == NULL)
            my_char('N');
        else
            my_int(*(int*)n->next->elem);
        my_char(')');
    }
}
