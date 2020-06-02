COMPILER = g++
COMPILER_FLAGS = -c -g -O0 -Wall -Werror
LINKER = g++


main: main.o Board.o Peice.o
	$(LINKER) main.o Board.o Peice.o -o main

main.o: main.cpp
	$(COMPILER) $(COMPILER_FLAGS) main.cpp


Board.o: Board.cpp Board.hpp
	$(COMPILER) $(COMPILER_FLAGS) Board.cpp

Peice.o: Peice.cpp Peice.hpp
	$(COMPILER) $(COMPILER_FLAGS) Peice.cpp


clean: 
	-rm -f *.o