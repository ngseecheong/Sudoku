#!/bin/bash

count=0;
total=0; 
runs=$1;

for n in `seq 1 10000`
do
	total=0;
	for i in `seq 1 $runs`
	do
		runtime="$($2 $n)";
		let total=runtime+total;
	done
	echo $n";"$[$total/$runs]";"$runs;
done
