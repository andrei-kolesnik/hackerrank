# DefaultDict Tutorial
# https://www.hackerrank.com/challenges/defaultdict-tutorial

# Sample Input:
# 5 2
# a
# a
# b
# a
# b
# a
# b

# Sample Output:
# 1 2 4
# 3 5

from collections import defaultdict

n, m = map(int, input().split())
A = []
for _ in range(n):
    A.append(input())
d = defaultdict(list)
for _ in range(m):
    m_str = input()
    for i in range(n):
        if A[i] == m_str:
            if A[i] == m_str:
                d[m_str].append(i+1)
    if len(d[m_str]) == 0:
        print(-1)
    else:
        print(*d[m_str])

# f = open("DefaultDict-input01.txt", "r", encoding="ascii")
# fw = open("DefaultDict-output01-aak.txt", "w", encoding="ascii")

# n, m = map(int, f.readline().split())
# A = []
# for _ in range(n):
#     A.append(f.readline())
# d = defaultdict(list)
# for _ in range(m):
#     m_str = f.readline()
#     for i in range(n):
#         if A[i] == m_str:
#             if i+1 not in d[m_str]:
#                 d[m_str].append(i+1)
#     if len(d[m_str]) == 0:
#         fw.write(str(-1)+"\n")
#     else:
#         for i in d[m_str]:
#             fw.write(str(i) + " ")
#         fw.write("\n")

# f.close()
# fw.close()
