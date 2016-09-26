#!/bin/bash
output=$(./sudoku < test)
solution=$(cat ./solution)
echo -n Easy:
if [ "$output" == "$solution" ]
then
	echo Correct;
else
	echo Incorrect;
	exit 1; #Error status
fi

output=$(./sudoku < test2)
solution=$(cat ./solution2)
echo -n Difficult:
if [ "$output" == "$solution" ]
then
        echo Correct;
else
        echo Incorrect;
        exit 1; #Error status
fi

output=$(./sudoku < test3)
solution=$(cat ./solution3)
echo -n No solution:
if [ "$output" == "$solution" ]
then
        echo Correct;
else
        echo Incorrect;
        exit 1; #Error status
fi
