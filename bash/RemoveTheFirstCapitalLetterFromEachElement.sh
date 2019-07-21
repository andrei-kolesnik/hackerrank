#!/bin/bash
# Filter an Array with Patterns
# https://www.hackerrank.com/challenges/bash-tutorials-filter-an-array-with-patterns

countries=( $(cat) )
countries=( ${countries[@]/#[A-Z]/.} )
echo ${countries[@]}
