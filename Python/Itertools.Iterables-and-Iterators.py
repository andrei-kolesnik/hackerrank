# Iterables and Iterators
# https://www.hackerrank.com/challenges/iterables-and-iterators

# Input:
# 4
# a a c d
# 2

# Output:
# 0.8333

from itertools import permutations
N = int(input()) # 4
L = input().split()  # ['a', 'a', 'c', 'd']
K = int(input()) # 2
total = 0
has_a = 0
for perm in permutations(L, K):
    total += 1
    if 'a' in perm:
        has_a += 1
print(has_a / total)
