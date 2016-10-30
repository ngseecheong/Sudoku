all: main_sudoku main2_sudoku

main_sudoku:sudoku.cpp main.cpp
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 main.cpp sudoku.cpp -o sudoku -std=c++11

main2_sudoku:sudoku.cpp main2.cpp
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 main2.cpp sudoku.cpp -o sudoku2 -std=c++11

.PHONY: clean test coverage
clean:
	rm -f *.o
	rm -f sudoku
	rm -f sudoku2
	rm -f *.gcda
	rm -f *.gcno
	rm -f test_output.txt

test:
	chmod u+x ./test2.sh
	./test2.sh > test_output.txt

coverage:
	gcovr -r .
