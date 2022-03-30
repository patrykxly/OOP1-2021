CXX = g++
EXEC = main
CXXFLAGS = $(flag) -std=c++14 -Wall -pedantic #-DBASIC
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: $(EXEC) run clear

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

error: $(EXEC) run
error: flag=-DERROR

clean:
	rm -rf *.o $(EXEC)

clear:
	rm -rf *.o

run:
	./$(EXEC)

check: 
	valgrind ./$(EXEC)

.PHONY: all clean clear run check