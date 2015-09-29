CXX			= g++
OBJS		= knapsack.o
CXXFLAGS	= -O2 -Wall -pedantic-errors -Werror -fmessage-length=0 
TARGET		= knapsack

all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
	