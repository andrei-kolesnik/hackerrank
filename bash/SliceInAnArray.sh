#!/bin/bash
# Slice in an Array
# https://www.hackerrank.com/challenges/bash-tutorials-slice-an-array

countries=( $(cat) )
echo ${countries[@]:3:5}