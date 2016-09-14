#!/bin/bash
output=$(./sudoku < test)
solution=$(cat ./solution)
echo Easy
if [ "$output" == "$solution" ]
then
	echo Correct;
else
	echo Incorrect;
	exit 1; #Error status
fi

output=$(./sudoku < test2)
solution=$(cat ./solution2)
echo Difficult
if [ "$output" == "$solution" ]
then
        echo Correct;
else
        echo Incorrect;
        exit 1; #Error status
fi
