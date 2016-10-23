#!/bin/bash
PREFIX="database/"

for str in easy hard nosolution;
do
    DATALOC=$PREFIX"$str"
    for n in `seq 1 1`
    do
	output=$(./sudoku < $DATALOC/test$n)
	solution=$(cat $DATALOC/solution$n)
	if [ "$output" == "$solution" ]
	then
		echo $str - $n  Correct;
	else
		echo $str - $n Incorrect;
		exit 1; #Error status
	fi
    done
done
