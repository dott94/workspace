NAME = libmy_stdio.a
SRC = my_fopen.c my_fclose.c my_fgetc.c my_fget.c my_fgets.c my_fflush.c my_fputc.c my_fput.c my_fputs.c my_fseek.c my_rewind.c my_ftell.c my_fgetpos.c my_fsetpos.c my_fread.c my_fwrite.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS += -I$(INCLPATH)

all:$(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*
	
fclean:clean
	-$(RM) $(LIBPATH)/$(NAME)
	
re: fclean all
