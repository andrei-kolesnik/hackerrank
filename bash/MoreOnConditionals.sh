#!/bin/bash
# More on Conditionals
# https://www.hackerrank.com/challenges/bash-tutorials---more-on-conditionals
read x
read y
read z

if (( $x == $y && $y == $z )); then
	echo "EQUILATERAL"
elif (( $x == $y || $y == $z )); then
	echo "ISOSCELES"
else
	echo "SCALENE"
fi

#alternative
unique_vals=($( cat - | sort -u ))

if [[ ${#unique_vals[@]} -eq 3 ]]; then
  echo "SCALENE"
elif [[ ${#unique_vals[@]} -eq 2 ]]; then
  echo "ISOSCELES"
else 
  echo "EQUILATERAL"
fi
