#!/bin/bash
# 'Awk' - 3
# https://www.hackerrank.com/challenges/awk-3

echo "A 25 27 50
B 35 37 75
C 75 78 80
D 99 88 76" | awk '{
  ave = ($2+$3+$4)/3;
  if (ave<50) print $0,": FAIL";
  else if (ave<60) print $0,": C" 
  else if (ave<80) print $0,": B" 
  else print $0,": A" 
}'
