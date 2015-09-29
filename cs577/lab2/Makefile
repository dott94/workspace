CRANAME=cracker
CRASRC=cracker.cpp 
CRAOBJ=$(CRASRC:.cpp=.o)
RM=rm -f

INCLPATH=/lab2
CFLAGS+= -I$(INCLPATH)
LDFLAGS+= -ldl
LDFLAGS+= -lssl 
LDFLAGS+= -lcrypto


all: cracker

cracker: $(CRAOBJ)
	g++ $(CFLAGS) $(CRAOBJ) -o cracker $(LDFLAGS)

clean: 
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: clean
	-$(RM) $(CRANAME)

re: fclean all
