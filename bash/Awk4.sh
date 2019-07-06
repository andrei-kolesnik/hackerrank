#!/bin/bash
# 'Awk' - 4
# https://www.hackerrank.com/challenges/awk-4

echo "A 25 27 50
B 35 37 75
C 75 78 80
D 99 88 76" | awk 'ORS = NR%2 ? ";" : "\n"'
