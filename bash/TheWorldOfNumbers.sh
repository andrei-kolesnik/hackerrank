#!/bin/bash
# The World of Numbers
# https://www.hackerrank.com/challenges/bash-tutorials---the-world-of-numbers
read x
read y

# arithmetic expansion
echo $((x + y))
echo $((x - y))
echo $((x * y))
echo $((x / y))

# expression expansion
echo $[x + y]
echo $[x - y]
echo $[x * y]
echo $[x / y]
