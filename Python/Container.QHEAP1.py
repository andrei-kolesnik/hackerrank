# QHEAP1
# https://www.hackerrank.com/challenges/qheap1

# Input: 
# 5
# 1 4
# 1 9
# 3
# 2 4
# 3

# Output:
# 4
# 9

import heapq
V = []
for _ in range(int(input())):
    command = list(map(int, input().split()))
    if command[0] == 1:
        heapq.heappush(V, command[1])
    elif command[0] == 2:
        V.remove(command[1])
        heapq.heapify(V)
    elif command[0] == 3:
        print(V[0])
