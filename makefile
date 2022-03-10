#makefile comment

CC = g++
CFLAGS = -C
LFLAGS = 
SOURCES = math.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = making_ex1

all: $(EXECUTABLE) $(SOURCES)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXECUTABLE) $(OBJECTS)

%.o:%.cpp
	$(CC) $(CFLAGS) $<

-include

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
	rm -f *.d