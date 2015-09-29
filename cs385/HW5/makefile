CXX			= g++
OBJS		= inversioncounter.o
CXXFLAGS	= -O2 -Wall -pedantic-errors -fmessage-length=0 
TARGET		= inversioncounter

all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
	