#!/bin/bash

DATALOC="database"

output=$(./sudoku < $DATALOC/easy/test1)
solution=$(cat $DATALOC/easy/solution1)
echo -n Easy:
if [ "$output" == "$solution" ]
then
	echo Correct;
else
	echo Incorrect;
	exit 1; #Error status
fi

output=$(./sudoku < $DATALOC/hard/test1)
solution=$(cat $DATALOC/hard/solution1)
echo -n Difficult:
if [ "$output" == "$solution" ]
then
        echo Correct;
else
        echo Incorrect;
        exit 1; #Error status
fi

output=$(./sudoku < $DATALOC/nosolution/test1)
solution=$(cat $DATALOC/nosolution/solution1)
echo -n No solution:
if [ "$output" == "$solution" ]
then
        echo Correct;
else
        echo Incorrect;
        exit 1; #Error status
fi
