all: main_sudoku

main_sudoku:sudoku.cpp main.cpp
	g++ main.cpp sudoku.cpp -o sudoku.o -std=c++11

.PHONY: clean test
clean:
	rm *.o

test:
	chmod u+x ./test.sh
	./test.sh
