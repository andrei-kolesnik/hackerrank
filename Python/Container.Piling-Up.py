# Piling Up!
# https://www.hackerrank.com/challenges/piling-up

# Input:
# 2
# 6
# 4 3 2 1 3 4
# 3
# 1 3 2

# Output:
# Yes
# No
import sys
from collections import deque

for _ in range(1): # range(int(input())):
    n = 6 # int(input())
    A = [4, 3, 2, 1, 3, 4]  # list(map(int, input().split()))
    q = deque(A)
    base = sys.maxsize
    result = True
    while(len(q) > 0):
        if q[0] >= q[-1]: # also works for if there is only one element left
            new_base = q.popleft()
        else:
            new_base = q.pop()
        if new_base > base:
            result = False
            break
        else:
            print(new_base)
            base = new_base
    if result:
        print("Yes")
    else:
        print("No")
