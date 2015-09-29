NAME = primes.a
SRC = primes.c
OBJ = $(SRC:.c=.o)
RM = rm -f

INCLPATH = ./
CFLAGS += -I$(INCLPATH)
EXENAME = primes

all:$(OBJ)
	cc -I$(INCLPATH) $(SRC) -o $(EXENAME)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*
	
fclean:clean
	-$(RM) 
	
re: fclean all
