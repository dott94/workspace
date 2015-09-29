CLINAME=client
CLISRC=client.c 
SERVNAME=server
SERVSRC=server.c 

CLIOBJ=$(CLISRC:.c=.o)
SERVOBJ=$(SERVSRC:.c=.o)

RM=rm -f

INCLPATH=/Proxy
LIBPATH=/Proxy
CFLAGS+= -I$(INCLPATH)
LDFLAGS+= -L$(LIBPATH)
LDFLAGS+= -ldl
LDFLAGS+= -lssl 
LDFLAGS+= -lcrypto

all: my server client

client: $(CLIOBJ)
	$(CC) $(CFLAGS) $(CLIOBJ) -o client $(LDFLAGS)
server: $(SERVOBJ)
	$(CC) $(CFLAGS) $(SERVOBJ) -o server $(LDFLAGS)
my:
	cd ../../cs392/src/my && make

myfclean:
	cd ../../cs392/src/my && make fclean

myclean:
	cd ../../cs392/src/my && make clean

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
