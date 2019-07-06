#!/bin/bash
# 'Awk' - 2
# https://www.hackerrank.com/challenges/awk-2

awk '{ print $1,":",($2<50 || $3<50 || $4<50) ? "Fail" : "Pass" ;}'
