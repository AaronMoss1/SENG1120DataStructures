CC=g++ 
CFLAGS=-c -Wall -std=c++98
LDFLAGS=
SOURCES=TowerHanoiDemo.cpp TowerHanoi.cpp Node.h LinkedList.h LStack.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=assignment2

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
