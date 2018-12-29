# Maximize It!
# https://www.hackerrank.com/challenges/maximize-it

# Input:
# 3 1000
# 2 5 4
# 3 7 8 9 
# 5 5 7 8 9 10 

# Output:
# 206

from itertools import product

def f(x):
    return x**2

K, M = map(int, input().split())
N = []
for _ in range(K):
    N.append(list(map(int, input().split()))[1:])
print(max([sum(list(map(f, t))) % M for t in product(*N)])) # 206
