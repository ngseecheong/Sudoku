all: main_sudoku

main_sudoku:sudoku.cpp main.cpp
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 main.cpp sudoku.cpp -o sudoku.o -std=c++11

.PHONY: clean test
clean:
	rm *.o

test:
	chmod u+x ./test.sh
	./test.sh > test_output.txt
