CXX			= g++
OBJS		= sieve.o
CXXFLAGS	= -g -Wall -Werror -pedantic-errors -fmessage-length=0 
TARGET		= sieve

all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
	