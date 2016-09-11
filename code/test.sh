#!/bin/bash
output=$(./sudoku.o < test)
solution=$(cat ./solution)
if [ "$output" == "$solution" ]
then
	echo Correct;
else
	echo Incorrect;
	exit 1; #Error status
fi
