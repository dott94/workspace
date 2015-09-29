CXX			= g++
OBJS		= unique.o
CXXFLAGS	= -g -Wall -Werror -pedantic-errors -fmessage-length=0 
TARGET		= unique

all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
	