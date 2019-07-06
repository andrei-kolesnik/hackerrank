#!/bin/bash
# 'Awk' - 1
# https://www.hackerrank.com/challenges/awk-1

awk 'NF<4 {print "Not all scores are available for",$1}'
