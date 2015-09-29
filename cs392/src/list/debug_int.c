//precondition: n is a list of ints
//postcondition: the list of ints is printed with detail (i.e N<-54->23))



#include "mylist.h"

void debug_int(t_node* n) {
    t_node* listptr;
    if (n != NULL) {
      listptr = n;
      while (listptr->next != NULL) {
	print_int(listptr);
	listptr = listptr->next;
	my_char(' ');
      }
      print_int(listptr);
    } else
      my_str("The list is empty \n");
}
