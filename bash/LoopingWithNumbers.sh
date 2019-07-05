#!/bin/bash
# Looping with Numbers
# https://www.hackerrank.com/challenges/bash-tutorials---looping-with-numbers

# `while` version
i=1
while [ $i -le 50 ]
do
	echo $i
	i=`expr $i + 1`
done

# `for` version
for i in {1..50}
do
	echo $i
done

# `seq` version
seq 1 50