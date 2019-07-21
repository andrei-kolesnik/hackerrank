#!/bin/bash
# Count the number of elements in an Array
# https://www.hackerrank.com/challenges/bash-tutorials-count-the-number-of-elements-in-an-array

countries=( $(cat) )
echo ${#countries[@]}
