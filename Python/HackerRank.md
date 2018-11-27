

```python
#Say "Hello, World!" With Python
#https://www.hackerrank.com/challenges/py-hello-world
print("Hello, World!")
```

    Hello, World!
    


```python
#Python If-Else
#https://www.hackerrank.com/challenges/py-if-else
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
    


```python
#Arithmetic Operators
#https://www.hackerrank.com/challenges/python-arithmetic-operators
a = 3
b = 2
print (a+b)
print (a-b)
print (a*b)
```

    5
    1
    6
    


```python
#Python: Division
#https://www.hackerrank.com/challenges/python-division
a = 4
b = 3
print (a//b)
print (a/b)
```

    1
    1.3333333333333333
    


```python
#Loops
#https://www.hackerrank.com/challenges/python-loops
n = 5
for i in range(n):
    print (i**2)
```

    0
    1
    4
    9
    16
    


```python
#Write a function
#https://www.hackerrank.com/challenges/write-a-function
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
    


```python
#Print Function
#https://www.hackerrank.com/challenges/python-print
n = 30
for i in range(1, n+1):
    print (i, sep = '', end = '')
```

    123456789101112131415161718192021222324252627282930


```python
#Find the Runner-Up Score!
#https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list
arr = [2, 3, 6, 6, 5]
arr2 = [x for x in arr if x != max(arr)]
max(arr2)
```




    5




```python
#Nested Lists
#https://www.hackerrank.com/challenges/nested-list/problem
students = [['Harry', 37.21], ['Berry', 37.21], ['Tina', 37.2], ['Akriti', 41], ['Harsh', 39]]
second_lowest = sorted(list(set([mark for name, mark in students])))[1]
for x in sorted([name for name, mark in students if mark == second_lowest]):
    print(x)
```

    Berry
    Harry
    


```python
#Finding the percentage
#https://www.hackerrank.com/challenges/finding-the-percentage
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
    


```python
#List Comprehensions
#https://www.hackerrank.com/challenges/list-comprehensions
x = 1
y = 1
z = 1
n = 2

print ([[i, j, k] for i in range(x + 1) for j in range (y + 1) for k in range (z + 1) if i+j+k != n])
```

    [[0, 0, 0], [0, 0, 1], [0, 1, 0], [1, 0, 0], [1, 1, 1]]
    


```python
#Lists
#https://www.hackerrank.com/challenges/python-lists
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
    


```python
#Tuples
#https://www.hackerrank.com/challenges/python-tuples
integer_list = map(int, '1 2'.split())
print(hash(tuple(integer_list)))
```

    1299869600
    


```python
#XML 1 - Find the Score
#https://www.hackerrank.com/challenges/xml-1-find-the-score
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
    
