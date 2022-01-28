SFML_PATH=/usr/local/SFML-2.2/
CXXFLAGS= -std=c++14 -Wall -Wpedantic -I${SFML_PATH}include/
LDFLAGS=-L${SFML_PATH}lib/
CFLAGS=-g -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -pthread
CPPFLAGS=
LDLIBS=
LIBS=
CPP=g++

all: client #server

client: main.o Ball.o
	$(CPP) $(CXXFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@ $(CFLAGS)

run: client
	LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(SFML_PATH)/lib/ ./client
	

clean:
	\rm -f *.o client
