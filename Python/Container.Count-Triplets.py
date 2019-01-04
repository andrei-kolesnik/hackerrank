# Count Triplets
# https://www.hackerrank.com/challenges/count-triplets-1

# Sample Input 0
# 4 2
# 1 2 2 4

# Sample Output 0
# 2

# Sample Input 1
# 6 3
# 1 3 9 9 27 81

# Sample Output 1
# 6

# Sample Input 2
# 5 5
# 1 5 5 25 125

# Sample Output 2
# 4

#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

# Version 1: simple, but does not consider the order (i < j < k)
# def countTriplets(arr, r):
#     result = 0
#     nums = Counter(arr)
#     for k in list(nums):
#         if r == 1:
#             # pick r out of n, no repeating, order does not matter
#             result += int(math.factorial(nums[k]) / math.factorial(nums[k] - 3) / math.factorial(3)) 
#         else:
#             result += nums[k] * nums[k*r] * nums[k*r*r]
#     return result

# Version 2: two hash tables, considers the order (i < j < k)
def countTriplets(arr, r):
    result = 0
    num1, num2 = {}, {}
    for a in arr:
        ra = int(a/r)
        if ra > 0 and ra in num1:
            rra = int(ra/r)
            if rra > 0 and (rra, ra) in num2:
                result += num2[(rra, ra)]
            if (ra, a) in num2:
                num2[(ra, a)] += num1[ra]
            else:
                num2[(ra, a)] = num1[ra]
        if a in num1:
            num1[a] += 1
        else:
            num1[a] = 1
    return result

# f = open("Count-Triplets-input06.txt", "r", encoding="ascii")
# nr = f.readline().rstrip().split()
# n = int(nr[0])
# r = int(nr[1])
# arr = list(map(int, f.readline().rstrip().split()))
# print(countTriplets(arr, r))  # 2325652489

print(countTriplets([1, 2, 2, 4], 2)) # 2
print(countTriplets([1, 2, 1, 2, 4], 2)) # 3, not 4
print(countTriplets([1, 3, 9, 9, 27, 81], 3)) # 6
print(countTriplets([1, 5, 5, 25, 125], 5)) # 4
print(countTriplets([1 for _ in range(100)], 1))  # 161700
