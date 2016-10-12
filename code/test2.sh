#!/bin/bash

DATALOC="database"

for n in `seq 1 3`
do
	output=$(./sudoku < $DATALOC/test$n)
	solution=$(cat $DATALOC/solution$n)
	if [ "$output" == "$solution" ]
	then
		echo Correct;
	else
		echo Incorrect;
		exit 1; #Error status
	fi
done