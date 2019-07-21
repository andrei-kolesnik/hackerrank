#!/bin/bash
# Display an element of an array
# https://www.hackerrank.com/challenges/bash-tutorials-display-the-third-element-of-an-array

countries=( $(cat) )
echo ${countries[3]}
