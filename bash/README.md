# Linux / Bash Shell Guide

## Output

```Bash
echo -n "HELLO " # -n option stops echo from breaking the line
echo 'WORLD'
> HELLO WORLD
```

```Bash
echo Welcome, $USER!
echo Your current directory is $PWD
> Welcome, andrei!
> Your current directory is /Users/andrei/projects
```

## Input
```Bash
read name
echo Welcome, $name!
> Andrei
> Welcome, Andrei!
```
#### with prompt, silent, limited to 1 character
```Bash
read -p "Enter your gender: " -s -n 1 gender 
echo "You entered $gender"
```

## File Redirection
```Bash
ls -l > list # output to file, errors to console
ls -l > list 2>&1 # output and errors to file
ls -l &> list # shortcut for output and errors to file
```

```Bash
filter body | cat header /dev/fd/0 footer | lp # prints header+body+footer
```

```Bash
ls > /dev/null; echo $? # success
>>> 0
```
```Bash
ls --bad-option 2> /dev/null; echo $? # illegal option
>>> 1 
```
```Bash
./non-existing.file 2>/dev/null; echo $? # command/file not found
>>> 127
```

## Conditions
### Comparing numbers
```Bash
X=3
Y=4
if [ $X -lt $Y ]
then
	echo "\$X=${X} is smaller than \$Y=${Y}"
fi
> $X=3 is smaller than $Y=4
```

### Using logic
```Bash
A=3
B=-4
if [ $A -gt 0 ] && [ $B -gt 0 ]; then
	echo "Both A and B are positive"
elif [ $A -gt 0 ] || [ $B -gt 0 ]; then
	echo "Either A or B is positive"
fi
```
#### alternative
```bash
if [ $A -gt 0 -a $B -gt 0 ]; then
	echo "Both A and B are positive"
elif [ $A -gt 0 -o $B -gt 0 ]; then
	echo "Either A or B is positive"
fi
> Either A or B is positive
```

### Comparing strings
```Bash
X="text"
Y=""

if [ -n "$X" ]; then
  echo "Variable X is not empty"
fi
> Variable X is not empty
```
```Bash
if [ ! -n "$Y" ]; then
  echo "Variable Y is empty"
fi
> Variable Y is empty
```
```Bash
if [ $X != "Text" ]; then
  echo "Variable X is not 'Text'"
fi
> Variable X is not 'Text'
```
```bash
if [ "$X" = "$Y" ]; then
  echo "SAME"
else
  echo "DIFFERENT"
fi
```
Safer: prevents an error message should one of the variables be empty.
The prepended "X" characters cancel out.
```bash
if [ "X$X" = "X$Y" ]; then
  echo "SAME"
else
  echo "DIFFERENT"
fi
```
#### using if
```Bash
read ch

if [ $ch = "Y" ] || [ $ch = "y" ]; then
	echo "YES"
elif [ $ch = "N" ] || [ $ch = "n" ]; then
	echo "NO"
fi
```
#### using regular expressions
```Bash
if [[ "$ch" == [yY] ]]; then
	echo "YES"
elif [[ "$ch" == [nN] ]]; then
	echo "NO"
fi
```
#### using case
```Bash
case $ch in
	Y | y) echo "YES";;
	N | n) echo "NO";;
esac
```

### Checking file existence
```Bash
file="bash.md"
if [ -e $file ]; then
	echo File $file exists
else
	echo File $file does not exist
fi
> File bash.md exists 
```

### List of all the operators
```Bash
help test 
```

## Loops

### `for` loops
```Bash
for X in 1 2 3; do
	echo -n "$X "
done
> 1 2 3
```
```Bash
for X in {1..3}; do
	echo -n "$X "
done
> 1 2 3
```
```Bash
for X in {1..5..2}; do # Bash versions 4.0+ 
	echo -n "$X "
done
> 1 2 3
```
```Bash
for (( i=1; i<=6; i+=2 )); do 
	echo -n "$i " 
done
> 1 3 5
```
```Bash
i=0
for (( ; ; )); do # infinite loop
  i=$((i+1))
  if [ $i -gt 5 ]; then
    break
  elif [ $(( $i % 2 )) -eq 0 ]; then
    continue
  else
		echo -n "$i " 
  fi
done
> 1 3 5
```

### `seq` command (outdated)
```Bash
echo `seq 1 2 5` # "echo" to convert new lines into spaces
> 1 3 5
```

### `while` Loops
```Bash
X=0
while [ $X -le 3 ]; do
	echo -n "$X "
	X=$((X+1)) # alternative: 	X=`expr $X + 1`
done
> 1 2 3
```

## Command Substitution

### Brace Expansion: `$(command)`
```Bash
files=$(ls)
echo "$files" # double quotes to preserve new lines (otherwise converted to spaces)
> test.sh
> ...
```
```Bash
X=$(expr 2 + $(expr 1 + 2)) # can be nested
echo $X
> 5
```

### Back-tick Expansion: `` `command` ``
```Bash
files=`ls`
echo "$files" # double quotes to preserve new lines (otherwise converted to spaces)
> test.sh
> ...
```
```Bash
X=`expr 2 + 3` # cannot be nested
echo $X
> 5
```

### Arithmetic Expansion: `$((expression))`
```Bash
num1=1
num2=2
num3=3
echo $(($num1+$num2*$num3))
> 7
```

### Rounding/scaling
```bash
echo "2/3"| bc
>>> 0
```
```bash
echo "2/3"| bc -l
>>> .66666666666666666666 
```
```bash 
echo "scale = 3; 2/3"| bc
>>> .66
```
```bash 
echo "scale = 3; 2/3"| bc -l
>>> .666
```
```bash 
printf "%.3f\n" $(echo "2/3" | bc -l)
>>> .667	
```


## Text processing

### `cat` -- concatenate and print files

#### create a file from command line
```Bash
cat > filename # press [Enter]
# start typing 
# press [Enter] for new lines
# press [Ctrl+Z] when done
>>> [1]+  Stopped cat > filename
```

### `cut` -- cut out selected portions of each line of a file

#### 3rd character on every line of a file
```Bash
cut -c3 filename
```
#### 2nd and 4th character on every line
```Bash
cut -c2,4
```
#### from 2nd to 4th character on every line
```Bash
cut -c2-4
```
#### first four characters on every line
```Bash
cut -c-4
```
#### from 2nd character to the end on every line
```Bash
cut -c2-
```
#### first 3 fields (tab separated) in a file
```Bash
cut -f-3 filename
```
#### fourth word of every line sentence (space separated) in a file
```Bash
cut -d ' ' -f4 filename
```

### `grep` -- file pattern searcher

#### search for the given string in a single file
```Bash
grep "literal_string" filename
```
#### search for the given string in all log files, case insensitive
```Bash
grep -i "literal_string" *.log
```
#### search for the given word in the stdin
```Bash
grep -w "the"
```
#### search for the given multiple words in the stdin, case sensitive
```Bash
grep -Ew 'the|that|then|those'
```
#### search for the given string in all log files, recursively
```Bash
grep -r "literal_string" *.log
```
#### search for the lines without the given word in the stdin
```Bash
grep -v "the"
```

### `head` -- display first lines of a file

#### first 20 lines of an input file
```Bash
head -n20
head -20 # or
```
#### first 20 characters
```Bash
head -c20
```

### `paste` -- merge corresponding or subsequent lines of files

#### join all lines using the comma delimiter
```Bash
paste -d, -s
```
#### merge lines in a file by pasting the data into 2 columns using the default tab delimiters
```Bash
paste - - < filename
>>> line1    line2
>>> line3    ...
```
#### merge a file into 3 columns using 2 different delimiters
```Bash
paste -d ':,' - - - < filename
>>> line1:line2,line3
>>> line4:line5,...
```
#### paste contents of 2 files side by side with a comma separator
```Bash
paste -d, filename1 filename2
```

### `sed` -- stream editor

#### change one word to another once
```Bash
sed 's/day/night/'
```
#### change the second occurrence of a word to another
```Bash
sed 's/day/night/2'
```
#### change all the occurrences of a word starting from the second to another (keep the first one)
```Bash
sed 's/day/night/2g'
```
#### change one path to another, using a different delimiter
```Bash
sed 's|/usr|/admin|'
```
#### put every word into parenthesis
```Bash
sed 's/[a-z]*/(&)/g'
```
#### delete empty lines in a file
```Bash
sed '/^$/d' filename
```
#### print only lines containing the given word
```Bash
sed '/word/p'
```
#### mask first 12 digit of a credit card number
```Bash
echo "1234 1234 1234 1234" | sed -E 's/[0-9]{4} /**** /g' # -E on mac, -r on LINUX
>>> **** **** **** 1234
```

### `sort` -- sort or merge records (lines) of text and binary files

#### sort a file in alphabetical order
```Bash
sort
```
#### sort a file in reverse alphabetical order
```Bash
sort -r
```
#### sort by number
```Bash
sort -n
```
#### sort by second column/field
```Bash
sort -k2
```
#### sort by second column numerically, and then third column alphabetically in reverse, in a tab-separated file
```Bash
sort -k2n,2 -k3r,3 -t $'-'
```

### `tail` -- display the last part of a file

#### last 20 lines
```Bash
tail -n20
tail -20 # or
```
#### last 20 characters
```Bash
tail -c20
```

### `tr` -- translate characters

#### replace all parentheses () with box brackets []
```bash
tr "()" "[]"
```
#### convert lower case to upper case 
```bash
tr abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ
tr a-z A-Z
tr [:lower:] [:upper:]
```
#### translate spaces into tabs, squeeze the repetition
```Bash
tr -s [:space:] '\t'
```
#### remove all digits
```Bash
tr -d [:digit:]
```
#### remove all characters except digits
```Bash
tr -cd [:digit:]
```
#### all non-printable characters
```Bash
tr -cd [:print:]
```
#### join all the lines in a file into a single line
```Bash
tr -s '\n' ' '
```

### `uniq` -- report or filter out repeated lines in a file

#### remove duplicate lines and display unique lines 
```Bash
uniq
```
#### count occurrence of lines 
```Bash
uniq -c
```
#### print only repeated lines
```Bash
uniq -d
```
#### print only unique lines
```Bash
uniq -u
```

