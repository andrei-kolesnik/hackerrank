#!/bin/bash
# Read in an Array
# https://www.hackerrank.com/challenges/bash-tutorials-read-in-an-array

# Version 1: new line separated
countries=( $(cat) )

# Version 2: space separated
while read line
do
    countries=("${countries[@]}" $line)
done

# Version 3: space separated
read -a countries

echo ${countries[@]}