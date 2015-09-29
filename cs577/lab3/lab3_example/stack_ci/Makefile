CFLAGS=-fno-stack-protector -O0 #-mpreferred-stack-boundary=2 
TARGETS=exploit
CC=gcc

all: $(TARGETS)

stack_overflow: stack_overflow.o
	$(CC) -z execstack $(LDFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -rf $(TARGETS) *.o
