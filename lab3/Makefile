CXX = g++
EXEC = main
CXXFLAGS = -std=c++11 -Wall -pedantic
DEP_FLAGS=-MMD
DEP_FLAGS+=-MP

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP=${SRC:.cpp=.d}

CXXFLAGS+=$(DEP_FLAGS)

all: $(EXEC) run

$(EXEC): $(OBJ)
	$(CXX) $^ -o $@

clean:
	rm -rf *$(OBJ) $(DEP) $(EXEC)

run:
	./$(EXEC)

check: 
	valgrind ./$(EXEC)

.PHONY: all clean run check

-include $(DEP) 