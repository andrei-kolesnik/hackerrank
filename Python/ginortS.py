# ginortS
# https://www.hackerrank.com/challenges/ginorts

# Input: Sorting1234
# Output: ginortS1324

def decorate_char(c):
    if c.islower():
        return 1, c
    elif c.isupper():
        return 2, c
    elif int(c) % 2 == 1:
        return 3, c
    elif int(c) % 2 == 0:
        return 4, c
    else:
        return 5, c

S = 'Sorting1234'  # input()
print(''.join(sorted(S, key=decorate_char)))
