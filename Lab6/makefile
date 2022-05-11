# lab6 Makefile

CC = g++
CFLAGS = -c -MMD -g
LFLAGS = -lX11
# Change w/ every new project
SOURCES = main.cpp gcontext.cpp x11context.cpp row.cpp matrix.cpp shape.cpp line.cpp triangle.cpp image.cpp mydrawing.cpp viewcontext.cpp
OBJECTS = $(SOURCES:.cpp=.o)
# Change w/ every new project
EXECUTABLE = Lab6

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