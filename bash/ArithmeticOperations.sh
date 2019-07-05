#!/bin/bash
# Arithmetic Operations

#read expr
s='5+50*3/20 + (19*2)/7' # 17.929
s='-105+50*3/20 + (19^2)/7' # -45.929
s='(-105.5*7+50*3)/20 + (19^2)/7' # 22.146
printf "%.3f\n" $(echo $s | bc -l)
