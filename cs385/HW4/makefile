CXX			= g++
OBJS		= waterjugpuzzle.o
CXXFLAGS	= -O2 -Wall -pedantic-errors -fmessage-length=0 
TARGET		= waterjugpuzzle

all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
	