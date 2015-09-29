NAME = minishell.a
SRC = minishell.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS += -I$(INCLPATH)
EXENAME = minishell

all:$(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)
	cc -I$(INCLPATH) -L$(LIBPATH) $(SRC) -lmy -o $(EXENAME)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*
	
fclean:clean
	-$(RM) $(LIBPATH)/$(NAME)
	
re: fclean all
