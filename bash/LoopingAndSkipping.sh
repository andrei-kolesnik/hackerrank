#!/bin/bash
# Looping and Skipping
# https://www.hackerrank.com/challenges/bash-tutorials---looping-and-skipping

# `for` version
for (( i=1; i<=100; i+=2 )) 
do 
	echo $i 
done

# `seq` version
seq 1 2 100