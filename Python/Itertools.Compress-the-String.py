# Compress the String!
# https://www.hackerrank.com/challenges/compress-the-string

# Input: '1222311'
# Output: (1, 1) (3, 2) (1, 3) (2, 1)

from itertools import groupby
S = '1222311' # input()
print(*[ (len(list(g)), int(k)) for k, g in groupby(S)])
