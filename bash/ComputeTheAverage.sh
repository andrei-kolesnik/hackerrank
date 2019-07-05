#!/bin/bash
# Compute the Average
# https://www.hackerrank.com/challenges/bash-tutorials---compute-the-average
read N
SUM=0
for (( i=1; i<=$N; i++))
do
	read M
	SUM=$((SUM + M))
done
printf "%.3f\n" $(echo $SUM/$N | bc -l)