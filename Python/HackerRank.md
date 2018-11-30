
### Introduction

[Say "Hello, World!" With Python](https://www.hackerrank.com/challenges/py-hello-world)


```python
print("Hello, World!")
```

    Hello, World!
    

[Python If-Else](https://www.hackerrank.com/challenges/py-if-else)


```python
n = 3 #Weird
#n = 24 #Not Weird
if n % 2 == 1:
    print("Weird")
elif n >=2 and n <= 5:
    print("Not Weird")
elif n >=6 and n <= 20:
    print("Weird")
else:
    print("Not Weird")
```

    Weird
    

[Arithmetic Operators](https://www.hackerrank.com/challenges/python-arithmetic-operators)


```python
a = 3
b = 2
print (a+b)
print (a-b)
print (a*b)
```

    5
    1
    6
    

[Python: Division](https://www.hackerrank.com/challenges/python-division)


```python
a = 4
b = 3
print (a//b)
print (a/b)
```

    1
    1.3333333333333333
    

[Loops](https://www.hackerrank.com/challenges/python-loops)


```python
n = 5
for i in range(n):
    print (i**2)
```

    0
    1
    4
    9
    16
    

[Write a function](https://www.hackerrank.com/challenges/write-a-function)


```python
def is_leap(year):
    leap = False
    # Write your logic here
    if year % 400 == 0:
        leap = True
    elif year % 100 == 0:
        leap = False
    elif year % 4 == 0:
        leap = True
    return leap

year = 1990
print (is_leap(year)) # False
```

    False
    

[Print Function](https://www.hackerrank.com/challenges/python-print)


```python
n = 30
for i in range(1, n+1):
    print (i, sep = '', end = '')
```

    123456789101112131415161718192021222324252627282930

### Basic Data Types

[Find the Runner-Up Score!](https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list)


```python
arr = [2, 3, 6, 6, 5]
arr2 = [x for x in arr if x != max(arr)]
print(max(arr2))
```

    5
    

[Nested Lists](https://www.hackerrank.com/challenges/nested-list/problem)


```python
students = [['Harry', 37.21], ['Berry', 37.21], ['Tina', 37.2], ['Akriti', 41], ['Harsh', 39]]
second_lowest = sorted(list(set([mark for name, mark in students])))[1]
for x in sorted([name for name, mark in students if mark == second_lowest]):
    print(x)
```

    Berry
    Harry
    

[Finding the percentage](https://www.hackerrank.com/challenges/finding-the-percentage)


```python
student_marks = {
    'Krishna': [67, 68, 69],
    'Arjun': [70, 98, 63],
    'Malika': [52, 56, 60]
}
query_name = 'Malika'

query_marks = student_marks[query_name]
print("%.2f" % (sum(query_marks) / len(query_marks)))
```

    56.00
    

[List Comprehensions](https://www.hackerrank.com/challenges/list-comprehensions)


```python
x = 1
y = 1
z = 1
n = 2

print ([[i, j, k] for i in range(x + 1) for j in range (y + 1) for k in range (z + 1) if i+j+k != n])
```

    [[0, 0, 0], [0, 0, 1], [0, 1, 0], [1, 0, 0], [1, 1, 1]]
    

[Lists](https://www.hackerrank.com/challenges/python-lists)


```python
lst = []
def proc_command(command):
    global lst
    actions = command.split()
    if actions[0] == 'insert':
        lst.insert(int(actions[1]), int(actions[2]))
    elif actions[0] == 'print':
        print(lst)
    elif actions[0] == 'remove':
        lst.remove(int(actions[1]))
    elif actions[0] == 'append':
        lst.append(int(actions[1]))
    elif actions[0] == 'sort':
        lst.sort()
    elif actions[0] == 'pop':
        lst.pop()
    elif actions[0] == 'reverse':
        lst.reverse()
    return

commands = [
  'insert 0 5',
  'insert 1 10',
  'insert 0 6',
  'print',
  'remove 6',
  'append 9',
  'append 1',
  'sort',
  'print',
  'pop',
  'reverse',
  'print'    
]

for command in commands:
    proc_command(command)
```

    [6, 5, 10]
    [1, 5, 9, 10]
    [9, 5, 1]
    

[Tuples](https://www.hackerrank.com/challenges/python-tuples)


```python
integer_list = map(int, '1 2'.split())
print(hash(tuple(integer_list)))
```

    1299869600
    

### XML

[XML 1 - Find the Score](https://www.hackerrank.com/challenges/xml-1-find-the-score)


```python
import xml.etree.ElementTree as etree

def get_attr_number(node):
    # your code goes here
    result = len(node.attrib)
    for child in node:
        result += get_attr_number(child)
    return result
    
xml = '''
<feed xml:lang='en'>
    <title>HackerRank</title>
    <subtitle lang='en'>Programming challenges</subtitle>
    <link rel='alternate' type='text/html' href='http://hackerrank.com/'/>
    <updated>2013-12-25T12:00:00</updated>
</feed>
'''
tree = etree.ElementTree(etree.fromstring(xml))
root = tree.getroot()

print(get_attr_number(root))
```

    5
    

[XML2 - Find the Maximum Depth](https://www.hackerrank.com/challenges/xml2-find-the-maximum-depth)


```python
import xml.etree.ElementTree as etree

def get_depth(node):
    # your code goes here
    if len(node) == 0:
        return 0
    result = 0
    for child in node:
        result = max(result, get_depth(child))
    return result + 1
    
xml1 = '''
<feed xml:lang='en'>
    <title>HackerRank</title>
    <subtitle lang='en'>Programming challenges</subtitle>
    <link rel='alternate' type='text/html' href='http://hackerrank.com/'/>
    <updated>2013-12-25T12:00:00</updated>
</feed>
'''
tree = etree.ElementTree(etree.fromstring(xml1))
root = tree.getroot()

print(get_depth(root)) # 1

xml2 = '''
<feed xml:lang='en'>
  <title>HackerRank</title>
  <subtitle lang='en'>Programming challenges</subtitle>
  <link rel='alternate' type='text/html' href='http://hackerrank.com/'/>
  <updated>2013-12-25T12:00:00</updated>
  <entry>
  	<author gender='male'>Harsh</author>
    <question type='hard'>XML 1</question>
    <description type='text'>This is related to XML parsing</description>
  </entry>
</feed>
'''

tree = etree.ElementTree(etree.fromstring(xml2))
root = tree.getroot()

print(get_depth(root)) # 2
```

    1
    2
    

### Numpy

[Polynomials](https://www.hackerrank.com/challenges/np-polynomials)


```python
import numpy

coefs = list(map(float, input().split())) # 1.1 2 3
x = float(input()) # 0
print (numpy.polyval(coefs, x))
```

    1.1 2 3
    0
    3.0
    

[Linear Algebra](https://www.hackerrank.com/challenges/np-linear-algebra)


```python
n = int(input()) # 2
A = [list(map(float, input().split())) for _ in range(n)] 
# 1.1 1.1
# 1.1 1.1
print(round(numpy.linalg.det(A), 2)) # 0.0
```

    2
    1.1 1.1
    1.1 1.1
    0.0
    

[Floor, Ceil and Rint](https://www.hackerrank.com/challenges/floor-ceil-and-rint)


```python
numpy.set_printoptions(sign=' ')

A = numpy.array(list(map(float, input().split()))) # 1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9
print(numpy.floor(A)) # [ 1.  2.  3.  4.  5.  6.  7.  8.  9.]
print(numpy.ceil(A)) # [  2.   3.   4.   5.   6.   7.   8.   9.  10.]
print(numpy.rint(A)) # [  1.   2.   3.   4.   6.   7.   8.   9.  10.]
```

    1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9
    [ 1.  2.  3.  4.  5.  6.  7.  8.  9.]
    [  2.   3.   4.   5.   6.   7.   8.   9.  10.]
    [  1.   2.   3.   4.   6.   7.   8.   9.  10.]
    

[Sum and Prod](https://www.hackerrank.com/challenges/np-sum-and-prod)


```python
n, m = map(int, input().split()) # 2
A = [list(map(float, input().split())) for _ in range(n)] 
print(int(numpy.prod(numpy.sum(A, axis = 0))))
```

    2 2
    1 2
    3 4
    24
    

### Strings

[sWAP cASE](https://www.hackerrank.com/challenges/swap-case)


```python
s = "Pythonist 2"
print (s.swapcase())
```

    pYTHONIST 2
    

[String Split and Join](https://www.hackerrank.com/challenges/python-string-split-and-join)


```python
s = "this is a string"
print ('-'.join(s.split()))
```

    this-is-a-string
    

[What's Your Name?](https://www.hackerrank.com/challenges/whats-your-name)


```python
first_name = 'Ross'
last_name = 'Taylor'
print('Hello ' + first_name + ' ' + last_name + '! You just delved into python.')
```

    Hello Ross Taylor! You just delved into python.
    

[Mutations](https://www.hackerrank.com/challenges/python-mutations)


```python
#using list
string = "abracadabra"
string_list = [c for c in string]
string_list[5] = 'k'
string = ''.join(string_list)
print(string)

#using split
string = "abracadabra"
string = string[:5] + 'k' + string[6:]
print(string)
```

    abrackdabra
    abrackdabra
    

[Find a string](https://www.hackerrank.com/challenges/find-a-string)


```python
string = 'ABCDCDC'
sub_string = 'CDC'
start = 0
end = len(string)
result = 0
while start < end:
    start = string.find(sub_string, start, end) + 1
    if start > 0:
        result += 1
    else:
        break

print(result)
```

    2
    

[String Validators](https://www.hackerrank.com/challenges/string-validators)


```python
s = 'qA2'

print(any(c.isalnum() for c in s))
print(any(c.isalpha() for c in s))
print(any(c.isdigit() for c in s))
print(any(c.islower() for c in s))
print(any(c.isupper() for c in s))
```

    True
    True
    True
    True
    True
    

[Text Alignment](https://www.hackerrank.com/challenges/text-alignment)


```python
thickness = 5 #This must be an odd number
c = 'H'

#Top Cone
for i in range(thickness):
    print((c*i).rjust(thickness-1)+c+(c*i).ljust(thickness-1))

#Top Pillars
for i in range(thickness+1):
    print((c*thickness).center(thickness*2)+(c*thickness).center(thickness*6))

#Middle Belt
for i in range((thickness+1)//2):
    print((c*thickness*5).center(thickness*6))    

#Bottom Pillars
for i in range(thickness+1):
    print((c*thickness).center(thickness*2)+(c*thickness).center(thickness*6))    

#Bottom Cone
for i in range(thickness):
    print(((c*(thickness-i-1)).rjust(thickness)+c+(c*(thickness-i-1)).ljust(thickness)).rjust(thickness*6))

```

        H    
       HHH   
      HHHHH  
     HHHHHHH 
    HHHHHHHHH
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHHHHHHHHHHHHHHHHHHHHHH   
      HHHHHHHHHHHHHHHHHHHHHHHHH   
      HHHHHHHHHHHHHHHHHHHHHHHHH   
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHH               HHHHH             
      HHHHH               HHHHH             
                        HHHHHHHHH 
                         HHHHHHH  
                          HHHHH   
                           HHH    
                            H     
    

[Text Wrap](https://www.hackerrank.com/challenges/text-wrap)


```python
import textwrap
def wrap(string, max_width):
    return textwrap.fill(string, max_width)

string = 'ABCDEFGHIJKLIMNOQRSTUVWXYZ'
max_width = 4
print(wrap(string, max_width))
```

    ABCD
    EFGH
    IJKL
    IMNO
    QRST
    UVWX
    YZ
    

[Designer Door Mat](https://www.hackerrank.com/challenges/designer-door-mat)


```python
n = 9
m = 27
for i in range(n//2):
    print(('.|.'*(2*i+1)).center(m, '-'))
print('WELCOME'.center(m, '-'))
for i in range(n//2-1, -1, -1):
    print(('.|.'*(2*i+1)).center(m, '-'))

```

    ------------.|.------------
    ---------.|..|..|.---------
    ------.|..|..|..|..|.------
    ---.|..|..|..|..|..|..|.---
    ----------WELCOME----------
    ---.|..|..|..|..|..|..|.---
    ------.|..|..|..|..|.------
    ---------.|..|..|.---------
    ------------.|.------------
    

[String Formatting](https://www.hackerrank.com/challenges/python-string-formatting)


```python
n = 17
w = len("{0:b}".format(n))
for i in range(1, n+1):
    print("{0:{w}d} {0:{w}o} {0:{w}X} {0:{w}b}".format(i, i, i, i, w=w))

```

        1     1     1     1
        2     2     2    10
        3     3     3    11
        4     4     4   100
        5     5     5   101
        6     6     6   110
        7     7     7   111
        8    10     8  1000
        9    11     9  1001
       10    12     A  1010
       11    13     B  1011
       12    14     C  1100
       13    15     D  1101
       14    16     E  1110
       15    17     F  1111
       16    20    10 10000
       17    21    11 10001
    

[Alphabet Rangoli](https://www.hackerrank.com/challenges/alphabet-rangoli)


```python
from string import ascii_lowercase
size = 5
width = 2*(size+size-1)-1
for i in range(size-1, -1, -1):
    str = ascii_lowercase[i]
    for j in range(i+1, size):
        str = ascii_lowercase[j] + '-' + str + '-' + ascii_lowercase[j]
    print(str.center(width, '-'))
for i in range(1, size):
    str = ascii_lowercase[i]
    for j in range(i+1, size):
        str = ascii_lowercase[j] + '-' + str + '-' + ascii_lowercase[j]
    print(str.center(width, '-'))

```

    --------e--------
    ------e-d-e------
    ----e-d-c-d-e----
    --e-d-c-b-c-d-e--
    e-d-c-b-a-b-c-d-e
    --e-d-c-b-c-d-e--
    ----e-d-c-d-e----
    ------e-d-e------
    --------e--------
    


[Capitalize!](https://www.hackerrank.com/challenges/capitalize)


```python
s = "1 w 2 r 3g chris r alan they're bill's friends"

ret = ''
for i in range(len(s)):
    if s[i].islower() and (i == 0 or s[i-1] == ' '):
        ret = ret + s[i].upper()
    else:
        ret = ret + s[i] 

print (ret)
```

    1 W 2 R 3g Chris R Alan They're Bill's Friends
    

### Itertools

[itertools.product()](https://www.hackerrank.com/challenges/itertools-product)


```python
from itertools import product
A = [1, 2]
B = [3, 4]
#A = list(map(int, input().split())) 
#B = list(map(int, input().split())) 

print(*product(A, B))

#for t in list(product(A, B)):
#    print(t, sep=' ', end=' ')
```

    (1, 3) (1, 4) (2, 3) (2, 4)
    
