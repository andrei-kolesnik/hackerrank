#!/bin/bash
# Comparing Numbers
# https://www.hackerrank.com/challenges/bash-tutorials---comparing-numbers
read x
read y

# compound
if [ $x -gt $y ]; then
	echo "X is greater than Y"
elif [ $x -lt $y ]; then
	echo "X is less than Y"
else
	echo "X is equal to Y"
fi

# arithmetic version
if (( $x > $y )); then
	echo "X is greater than Y"
elif (( $x < $y )); then
	echo "X is less than Y"
else
	echo "X is equal to Y"
fi
