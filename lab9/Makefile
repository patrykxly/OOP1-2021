CXX = g++
EXEC = main
CXXFLAGS = -std=c++14 -Wall -pedantic #-DBASIC
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: $(EXEC) run

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

clean:
	rm -rf *.o $(EXEC)

clear:
	rm -rf *.o

run:
	./$(EXEC)

check: 
	valgrind ./$(EXEC)

.PHONY: all clean clear run check
