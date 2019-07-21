#!/bin/bash
# Concatenate an array with itself
# https://www.hackerrank.com/challenges/bash-tutorials-concatenate-an-array-with-itself

countries=( $(cat) )
countries=("${countries[@]}" "${countries[@]}" "${countries[@]}")
echo ${countries[@]}
