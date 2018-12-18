# Hash Tables: Ransom Note
# https://www.hackerrank.com/challenges/ctci-ransom-note

# Input 0:
# 6 4
# give me one grand today night
# give one grand today

# Output 0:
# Yes

# Input 1:
# 6 5
# two times three is not four
# two times two is four

# Output 1:
# No
# Explanation 1: 'two' only occurs once in the magazine.

# Input 2:
# 7 4
# ive got a lovely bunch of coconuts
# ive got some coconuts

# Output 2:
# No

#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    words = Counter(magazine)
    for word in note:
        if words[word] < 1:
            print('No')
            return
        words[word] -= 1
    print('Yes')

if __name__ == '__main__':
    # mn = input().split()
    # m = int(mn[0])
    # n = int(mn[1])
    # magazine = input().rstrip().split()
    # note = input().rstrip().split()
    # checkMagazine(magazine, note)
    checkMagazine('give me one grand today night'.split(), 
                  'give one grand today'.split()) # Yes
    checkMagazine('two times three is not four'.split(), 
                  'two times two is four'.split()) # No
    checkMagazine('ive got a lovely bunch of coconuts'.split(),
                  'ive got some coconuts'.split())  # No
