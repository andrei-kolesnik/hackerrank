# No Idea!
# https://www.hackerrank.com/challenges/no-idea

# Sample Input:
# 3 2
# 1 5 3
# 3 1
# 5 7

# Sample Output:
# 1

n, m = 3, 2 # map(int, raw_input().split())
N = [1, 5, 3]  # list(map(int, raw_input().split()))
A = set([3, 1]) # set(map(int, raw_input().split()))
B = set([5, 7]) # set(map(int, raw_input().split()))

happiness = 0
for n in N:
    if n in A:
        happiness += 1
    elif n in B:
        happiness -= 1
print(happiness)
