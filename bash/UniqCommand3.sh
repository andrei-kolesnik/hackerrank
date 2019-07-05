#!/bin/bash
# 'Uniq' Command #3
# https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-3

uniq -ci | tr -s " " | cut -c2-
