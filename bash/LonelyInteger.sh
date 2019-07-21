#!/bin/bash
# Lonely Integer - Bash!
# https://www.hackerrank.com/challenges/lonely-integer-2

read n
read -a numbers

lonely=()

for n in ${numbers[@]}; do
  found=0
  for i in ${!lonely[@]}; do
    if [[ n -eq ${lonely[$i]} ]]; then
      unset lonely[$i]
      found=1
      break
    fi
  done
  if [[ found -eq 0 ]]; then
    lonely+=($n)
  fi
done

echo ${lonely[@]}
