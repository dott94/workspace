NAME = libmylist.a
SRC = new_node.c add_node.c add_elem.c append.c add_node_at.c remove_node.c remove_node_at.c remove_last.c count_nodes.c empty_list.c node_at.c elem_at.c traverse_int.c traverse_string.c traverse_char.c debug_string.c debug_int.c debug_char.c print_char.c print_string.c print_int.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS += -I$(INCLPATH)

all: $(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all
