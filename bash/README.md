# Linux / Bash Shell Guide

## General Syntax

#### Creating a new script file
```bash
cat > test.sh
#!/bin/bash
echo Hello World!
^C
```
#### Setting permissions to execute for the current user
```bash
chmod u+x test.sh
# or
chmod 755 test.sh
```
#### Running
```bash
./test.sh

>>> Hello World!
```

### Comments
```bash
# This is a comment
```

### Joining Lines by ";"
```bash
echo "Line 1"; echo "Line 2"
>>> Line 1
>>> Line 2
```

### Splitting Lines by "\"
```bash
echo "Long \
Long Line"
>>> Long Long Line
```

## Output

```bash
echo -n "HELLO " # -n option stops echo from breaking the line
echo 'WORLD'
> HELLO WORLD
```

```bash
echo Welcome, $USER!
echo Your current directory is $PWD
> Welcome, andrei!
> Your current directory is /Users/andrei/projects
```

```bash
echo *
>>> {list of the files in the current folder, same as `ls`}
```

## Input
```bash
read name
echo Welcome, $name!
> Andrei
> Welcome, Andrei!
```
#### with prompt, silent, limited to 1 character
```bash
read -p "Enter your gender: " -s -n 1 gender 
echo "You entered $gender"
```
#### from a file
```bash
while read f; do
	echo "$f" # process the line
done < filename
```

## Variables

### Declaring / Assigning
```bash
MSG1="Hello" # No spaces around the "=" sign
msg2=World # No need to quote if the value is one word
echo $MSG1 $msg2
>>> Hello World
```

### No types, everything is stored as a string
```bash
PI=3.14159
ALSO_PI="3.14159"
```

### Escaping
```bash
echo "Need to escape: \" \$ \` \\"
```

### Using in a string context
```bash
read USER_NAME
touch "${USER_NAME}_file"
```

### Basic string manipulations

#### length
```bash
STR ="Abcd"
echo ${#STR} #=> 4
```

#### default values
```bash
STR ="Abcd"
${STR:-val}	    # $STR, or val if not set
${STR:=val}	    # Set $STR to val if not set
${STR:+val}	    # val if $STR is set
${STR:?message}	# Show error message and exit if $STR is not set
```

#### substrings
```bash
STR="Abcd"
echo ${STR}        #=> "Abcd"
echo ${STR:0:2}    #=> "Ab" (slicing)
echo ${STR::2}     #=> "Ab" (slicing)
echo ${STR::-1}    #=> "Abc" (slicing)
echo ${STR:(-1)}   #=> "d" (slicing from right)
echo ${STR:(-2):1} #=> "c" (slicing from right)
```

#### substitutions
```bash
STR="/path/to/file.php"
echo ${STR%.php}     # /path/to/file
echo ${STR%.php}.bak # /path/to/file.bak

echo ${STR##*.}      # php (extension)
echo ${STR##*/}      # file.php (basepath)

echo ${STR#*/}       # path/to/file.php
echo ${STR##*/}      # file.php

echo ${STR/file/index} # /path/to/index.php

BASE=${STR##*/}   #=> "file.php" (basepath)
DIR=${STR%$BASE}  #=> "/path/to/" (dirpath)
```

#### change case
```bash
STR="HELLO WORLD"
echo ${STR,}   #=> "hELLO WORLD" (lowercase 1st letter)
echo ${STR,,}  #=> "hello world" (all lowercase)

STR="hello world"
echo ${STR^}   #=> "Hello world" (uppercase 1st letter)
echo ${STR^^}  #=> "HELLO WORLD" (all uppercase)
```

### Preset variables

#### script parameters: `$#`, `$0-$9`, `$@`
```bash
echo "This program was called with $# parameters"
echo "This program's name is `basename $0`" # `basename` -- return filename of pathname
echo "The first parameter is $1"
echo "The second parameter is $2"
echo "All parameters are $*"
echo "All parameters in array, individually quoted, are $@"
```
#### the exit value of the last run command: `$?`
```bash
read X
echo $X | grep "[^0-9]" > /dev/null 2>&1
[ "$?" -eq "0" ] &&  echo "'$X' is not a number"
```
#### PID (Process IDentifier) of the currently running shell: `$$`
```bash
echo $$
```
#### PID of the last run background process: `$!`
```bash
sort words > sorted-words &        # launch the first background process
p1=$!
sort -n numbers > sorted-numbers & # launch the second background process
p2=$!
wait $p1
wait $p2
echo Both files have been sorted.
```


## File Redirection
#### output to file, errors to console
```bash
ls -l > filename 
```
#### output and errors to file
```bash
ls -l > filename 2>&1
```
#### output and errors to file (shortcut)
```bash
ls -l &> filename
```
#### print header+body+footer from files
```bash
filter body | cat header /dev/fd/0 footer | lp
```

```bash
ls > /dev/null; echo $? # success
>>> 0
```
```bash
ls --bad-option 2> /dev/null; echo $? # illegal option
>>> 1 
```
```bash
./non-existing.file 2>/dev/null; echo $? # command/file not found
>>> 127
```

## Control Structures

### Conditions and `test` -- condition evaluation utility (called as `[`)

#### list of all the operators
```bash
help test 
```

#### Comparing numbers
```bash
X=3
Y=4
if [ $X -lt $Y ]
then
	echo "\$X=${X} is smaller than \$Y=${Y}"
fi
> $X=3 is smaller than $Y=4
```

#### Using logic
```bash
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
#### Using logic instead of `if` statement
```bash
X=3
Y=4
[ $X -lt $Y ] && echo "\$X=${X} is smaller than \$Y=${Y}"
> $X=3 is smaller than $Y=4
```

#### Comparing strings
```bash
X="text"
Y=""

if [ -n "$X" ]; then
  echo "Variable X is not empty"
fi
> Variable X is not empty
```
```bash
if [ ! -n "$Y" ]; then
  echo "Variable Y is empty"
fi
> Variable Y is empty
```
```bash
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
```bash
read ch

if [ $ch = "Y" ] || [ $ch = "y" ]; then
	echo "YES"
elif [ $ch = "N" ] || [ $ch = "n" ]; then
	echo "NO"
fi
```
#### using regular expressions
```bash
if [[ "$ch" == [yY] ]]; then
	echo "YES"
elif [[ "$ch" == [nN] ]]; then
	echo "NO"
fi
```
#### using case
```bash
case $ch in
	Y | y) echo "YES";;
	N | n) echo "NO";;
	*)     echo "Unexpected input: $ch";;
esac
```

#### Checking file existence
```bash
file="bash.md"
if [ -e $file ]; then
	echo File $file exists
else
	echo File $file does not exist
fi
> File bash.md exists 
```

### Loops

#### `for` loops
```bash
for X in 1 2 3 hello \* * goodbye # any values 
do
	echo -n "$X "
done
> 1 2 3 hello * {list of the files in the current folder} goodbye
```
```bash
for X in {1..3}; do
	echo -n "$X "
done
> 1 2 3
```
```bash
for X in {1..5..2}; do # Bash versions 4.0+ 
	echo -n "$X "
done
> 1 2 3
```
```bash
for (( i=1; i<=6; i+=2 )); do 
	echo -n "$i " 
done
> 1 3 5
```
#### infinite loop
```bash
i=0
for (( ; ; )); do 
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
#### using `seq` command (outdated)
```bash
echo `seq 1 2 5` # "echo" to convert new lines into spaces
> 1 3 5
```

#### `while` Loops
```bash
X=0
while [ $X -le 3 ]; do
	echo -n "$X "
	X=$((X+1)) # alternative: 	X=`expr $X + 1`
done
> 1 2 3
```
```bash
while [ "$USER_INPUT" != "bye" ]; do
  echo "Enter something (\"bye\" to quit)"
  read USER_INPUT
  echo "You typed: $USER_INPUT"
done
```
#### infinite loop
```bash
i=0
while :
do 
  i=$((i+1))
  if [ $i -gt 5 ]; then
    break
  elif [ $(( $i % 2 )) -eq 0 ]; then
    continue
  else
		echo -n "$i " 
  fi
done
```

## Arrays

### Declaring and Assigning

#### automatically
```bash
os[0]='Unix'
os[1]='MacOS'
os[2]='Windows'
echo ${os[0]}
>>> Unix
```
#### at once
```bash
os=('Unix' 'MacOS' 'Windows')
```
#### declaring with assigning
```bash
declare -a os=('Unix' 'MacOS' 'Windows')
echo ${os[0]}
>>> Unix
```

### Reading from Input 

#### new line separated
```bash
os=( $(cat) )
```
```bash
while read line
do
    os=("${os[@]}" $line)
done
```
#### space separated
```bash
read -a os 
```
#### from file (word by word)
```bash
os=( `cat “inputfile” `)
# or
os=( `< “inputfile” `)
```

### Concatenating Two Arrays
```bash
os1=('Unix' 'MacOS' 'Windows')
os2=('OS/360' 'MS-DOS')
os=("${os1[@]}" "${os2[@]}")
echo "${os[@]}"
>>> Unix MacOS Windows OS/360 MS-DOS
```

### Copying
```bash
os1=('Unix' 'MacOS' 'Windows')
os2=("${os1[@]}")
echo "${os2[@]}"
>>> Unix MacOS Windows
```

### Adding Elements
#### version 1
```bash
os=("${os[@]}" 'OS/360') 
```
#### version 2 (# Bash versions 3.0+)
```bash
os+=('OS/360') 
```

### Removing Elements

#### by setting to null
```bash
unset os[1]
echo ${os[@]}
>>> Unix Windows
```
#### removing completely
```bash
pos=1
os=(${os[@]:0:$pos} ${os[@]:$(($pos + 1))})
echo ${os[@]}
```
#### entire array
```bash
unset os
```

### Printing

#### the whole array
```bash
echo ${os[@]}
# or
echo ${os[*]}
>>> Unix MacOS Windows
```
#### individually
```bash
echo ${os} # no index - 0 is assumed
>>> Unix
echo ${os[1]}
>>> MacOS
```
#### in a loop
```bash
for e in ${os[@]}; do
	echo $e
done
>>> Unix
>>> MacOS
>>> Windows
```
#### using indices
```bash
for i in ${!os[@]}; do
	echo $i: ${os[$i]}
done
>>> 0: Unix
>>> 1: MacOS
>>> 2: Windows
```

### Sizing

#### of the whole array
```bash
echo ${#os[@]}
>>> 3
```
#### of a single element
```bash
echo ${#os[1]}
>>> 5
```

### Slicing

#### an array
```bash
echo ${os[@]:1:2}
>>> MacOS Windows
```
#### an element
```bash
echo ${os[1]:1:2}
>>> ac
```

### Searching and Replacing
```bash
echo ${os[@]/Unix/Linux}
>>> Linux MacOS Windows
# will not permanently replace the array content:
echo ${os[@]}
>>> Unix MacOS Windows
```
#### removing by a pattern
```bash
os=( ${os[@]/*[Aa]*/} ) 
# will remove any words with 'A' or 'a'
echo ${os[@]}
>>> Unix Windows
```

## Command Substitution

### Brace Expansion: `$(command)`
```bash
files=$(ls)
echo "$files" # double quotes to preserve new lines (otherwise converted to spaces)
> test.sh
> ...
```
```bash
X=$(expr 2 + $(expr 1 + 2)) # can be nested
echo $X
> 5
```

### Back-tick Expansion: `` `command` ``
```bash
files=`ls`
echo "$files" # double quotes to preserve new lines (otherwise converted to spaces)
> test.sh
> ...
```
```bash
X=`expr 2 + 3` # cannot be nested
echo $X
> 5
```

### Arithmetic Expansion: `$((expression))`
```bash
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

### `awk` -- pattern-directed scanning and processing language

#### print all the lines in a file
```bash
awk '{print;}' filename
```
#### print all the lines matching a pattern
```bash
awk '/1234/' filename
# or
awk '/1234/ {print;}' filename
```
#### print all the lines matching multiple patterns
```bash
awk '/1234/ 
/5678/' filename
```
#### print field #4 (space separated)
```bash
awk '{print $4;}' filename
```
#### print the first and the last field
```bash
awk '{print $1,$NF;}' filename
```
#### print the fields as a report with a header and a footer
```bash
awk 'BEGIN {print "Field1\tField2\tField3\tField4";}
{print $1,"\t",$2,"\t",$3,"\t",$4;}
END {print "Report Generated\n--------------";}' filename
```
#### print the lines under a condition
```bash
awk '$1 > 1000' filename # comparison
awk '$4 ~/1234/' filename # regular expression
```
#### count the lines matching a condition
```bash
awk 'BEGIN { count=0; }
$4 ~ /1234/ { count++; } 
END { print "Total count =", count; }' filename 
```
#### using conditions
```bash
awk '{
if ($2 == "" || $3 == "")
	print "Required fields are missing for record", NR;
else
	print "Record",NR,"is valid";
}' filename 
# or with a ternary operator
awk '{ print ($2 == "" || $3 == "") ? "Required fields are missing" : "Record is valid";}' filename
```
#### concatenate every 2 lines of input with a semicolon
```bash
awk 'ORS = NR%2 ? ";" : "\n"'
```
#### remove duplicate lines in file (output unique lines only)
```bash
awk '!seen[$0]++' filename
```

### `cat` -- concatenate and print files

#### create a file from command line
```bash
cat > filename # press [Enter]
# start typing 
# press [Enter] for new lines
# press [Ctrl+Z] when done
>>> [1]+  Stopped cat > filename
```

### `cut` -- cut out selected portions of each line of a file

#### 3rd character on every line of a file
```bash
cut -c3 filename
```
#### 2nd and 4th character on every line
```bash
cut -c2,4
```
#### from 2nd to 4th character on every line
```bash
cut -c2-4
```
#### first four characters on every line
```bash
cut -c-4
```
#### from 2nd character to the end on every line
```bash
cut -c2-
```
#### first 3 fields (tab separated) in a file
```bash
cut -f-3 filename
```
#### fourth word of every line sentence (space separated) in a file
```bash
cut -d ' ' -f4 filename
```

### `grep` -- file pattern searcher

#### search for the given string in a single file
```bash
grep "literal_string" filename
```
#### search for the given string in all log files, case insensitive
```bash
grep -i "literal_string" *.log
```
#### search for the given word in the stdin
```bash
grep -w "the"
```
#### search for the given multiple words in the stdin, case sensitive
```bash
grep -Ew 'the|that|then|those'
```
#### search for the given string in all log files, recursively
```bash
grep -r "literal_string" *.log
```
#### search for the lines without the given word in the stdin
```bash
grep -v "the"
```

### `head` -- display first lines of a file

#### first 20 lines of an input file
```bash
head -n20
head -20 # or
```
#### first 20 characters
```bash
head -c20
```

### `paste` -- merge corresponding or subsequent lines of files

#### join all lines using the comma delimiter
```bash
paste -d, -s
```
#### merge lines in a file by pasting the data into 2 columns using the default tab delimiters
```bash
paste - - < filename
>>> line1    line2
>>> line3    ...
```
#### merge a file into 3 columns using 2 different delimiters
```bash
paste -d ':,' - - - < filename
>>> line1:line2,line3
>>> line4:line5,...
```
#### paste contents of 2 files side by side with a comma separator
```bash
paste -d, filename1 filename2
```

### `sed` -- stream editor

#### change one word to another once
```bash
sed 's/day/night/'
```
#### change the second occurrence of a word to another
```bash
sed 's/day/night/2'
```
#### change all the occurrences of a word starting from the second to another (keep the first one)
```bash
sed 's/day/night/2g'
```
#### change one path to another, using a different delimiter
```bash
sed 's|/usr|/admin|'
```
#### put every word into parenthesis
```bash
sed 's/[a-z]*/(&)/g'
```
#### delete empty lines in a file
```bash
sed '/^$/d' filename
```
#### print only lines containing the given word
```bash
sed '/word/p'
```
#### mask first 12 digit of a credit card number
```bash
echo "1234 1234 1234 1234" | sed -E 's/[0-9]{4} /**** /g' # -E on mac, -r on LINUX
>>> **** **** **** 1234
```

### `sort` -- sort or merge records (lines) of text and binary files

#### sort a file in alphabetical order
```bash
sort
```
#### sort a file in reverse alphabetical order
```bash
sort -r
```
#### sort by number
```bash
sort -n
```
#### sort by second column/field
```bash
sort -k2
```
#### sort by second column numerically, and then third column alphabetically in reverse, in a tab-separated file
```bash
sort -k2n,2 -k3r,3 -t $'-'
```

### `tail` -- display the last part of a file

#### last 20 lines
```bash
tail -n20
tail -20 # or
```
#### last 20 characters
```bash
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
```bash
tr -s [:space:] '\t'
```
#### remove all digits
```bash
tr -d [:digit:]
```
#### remove all characters except digits
```bash
tr -cd [:digit:]
```
#### all non-printable characters
```bash
tr -cd [:print:]
```
#### join all the lines in a file into a single line
```bash
tr -s '\n' ' '
```

### `uniq` -- report or filter out repeated lines in a file

#### remove duplicate lines and display unique lines 
```bash
uniq
```
#### count occurrence of lines 
```bash
uniq -c
```
#### print only repeated lines
```bash
uniq -d
```
#### print only unique lines
```bash
uniq -u
```

## File processing

### `ls` -- list directory contents

#### list multiple folders/subfolders
```bash
ls /{usr,usr/local}/{bin,sbin}
```