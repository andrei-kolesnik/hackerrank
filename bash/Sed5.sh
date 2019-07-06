#!/bin/bash
# 'Sed' command #5
# https://www.hackerrank.com/challenges/sed-command-5

sed -E 's/([0-9]{4}) ([0-9]{4}) ([0-9]{4}) ([0-9]{4})/\4 \3 \2 \1/g' GrepB.txt