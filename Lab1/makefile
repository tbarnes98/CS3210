# lab1barnestr Makefile

CC = g++
CFLAGS = -c -MMD
LFLAGS = 
# Change w/ every new project
SOURCES = ReadSTL.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
# Change w/ every new project
EXECUTABLE = lab1barnestr

all: $(EXECUTABLE) $(SOURCES)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) -o $@ $(OBJECTS)

-include *.d

%.o:%.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(EXECUTABLE)
	rm -f $(OBJECTS)
	rm -f *.d