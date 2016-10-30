#!/bin/bash
PREFIX="database/"

for str in easy hard nosolution;
do
    DATALOC=$PREFIX"$str"
    NUM_FILES=`ls -l $DATALOC/solution* | wc -l`
    #echo $NUM_FILES
    for n in `seq 1 $NUM_FILES`
    do
	output=$(./sudoku < $DATALOC/test$n)
    sol_output=$(printf %s "$output" | head -n -1)
    sol_time=$(printf %s "$output" | tail -n -1)
	solution=$(cat $DATALOC/solution$n)
    #echo $sol_output;
	if [ "$sol_output" == "$solution" ]
	then
		echo -e $str - $n  Correct, time: $sol_time "\xC2\xB5"s;
	else
		echo $str - $n Incorrect;
		exit 1; #Error status
	fi
    done
done

#Test sudoku2 should only fill 1 position
./sudoku2 80
