# Makefile for stdio project
RM=rm -f
INCLPATH=../include
LIBPATH=../lib

#libmylist variables
SRCLIST=test_stdio.c
LIBLIST= my_stdio
LISTFOLDER=extracredit
LISTNAME= my_stdio

all: allclean liblist

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) $(MYNAME)
	-$(RM) $(LISTNAME)

lib:
	cd ../src/$(LISTFOLDER) && make

liblist: lib
	cc -I$(INCLPATH) -L$(LIBPATH) $(SRCLIST) -l$(LIBLIST) -lmy -o $(LISTNAME)

fclean: clean
	cd ../src/$(LISTFOLDER) && make fclean

allclean: clean
	cd ../src/$(LISTFOLDER) && make clean
