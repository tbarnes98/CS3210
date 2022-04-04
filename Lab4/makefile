# lab4 Makefile

CC = g++
CFLAGS = -c -MMD -g
LFLAGS = -lX11
# Change w/ every new project
SOURCES = main.cpp gcontext.cpp x11context.cpp
OBJECTS = $(SOURCES:.cpp=.o)
# Change w/ every new project
EXECUTABLE = Lab4

all: $(EXECUTABLE) $(SOURCES)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LFLAGS)

-include *.d

%.o:%.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(EXECUTABLE)
	rm -f $(OBJECTS)
	rm -f *.d