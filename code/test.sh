#!/bin/bash

DATALOC="database"

output=$(./sudoku < $DATALOC/test)
solution=$(cat $DATALOC/solution)
echo -n Easy:
if [ "$output" == "$solution" ]
then
	echo Correct;
else
	echo Incorrect;
	exit 1; #Error status
fi

output=$(./sudoku < $DATALOC/test2)
solution=$(cat $DATALOC/solution2)
echo -n Difficult:
if [ "$output" == "$solution" ]
then
        echo Correct;
else
        echo Incorrect;
        exit 1; #Error status
fi

output=$(./sudoku < $DATALOC/test3)
solution=$(cat $DATALOC/solution3)
echo -n No solution:
if [ "$output" == "$solution" ]
then
        echo Correct;
else
        echo Incorrect;
        exit 1; #Error status
fi
