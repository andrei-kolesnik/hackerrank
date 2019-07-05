#!/bin/bash
# Getting started with conditionals
# https://www.hackerrank.com/challenges/bash-tutorials---getting-started-with-conditionals

read ch

# using case
case $ch in
	Y | y) echo "YES";;
	N | n) echo "NO";;
esac

# using if
if [ $ch = "Y" ] || [ $ch = "y" ]; then
	echo "YES"
elif [ $ch = "N" ] || [ $ch = "n" ]; then
	echo "NO"
fi

if [[ "$ch" == [yY] ]]; then
	echo "YES"
elif [[ "$ch" == [nN] ]]; then
	echo "NO"
fi
