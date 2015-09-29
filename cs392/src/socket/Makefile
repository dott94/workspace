CLINAME=client
CLISRC=client.c client_kill.c
SERVNAME=server
SERVSRC=server.c server_kill.c serv_child_proc_kill.c

CLIOBJ=$(CLISRC:.c=.o)
SERVOBJ=$(SERVSRC:.c=.o)

RM=rm -f

INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH)
LDFLAGS+= -L$(LIBPATH)
LDLIBS+= -lmy

all: my server client

client: $(CLIOBJ)

server: $(SERVOBJ)

my:
	cd ../my && make

myfclean:
	cd ../my && make fclean

myclean:
	cd ../my && make clean

clean: myclean
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: myfclean clean
	-$(RM) $(CLINAME)
	-$(RM) $(SERVNAME)

re: fclean all