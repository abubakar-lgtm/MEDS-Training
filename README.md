# <ins>MEDS Training<ins>

<p align="center">
<img width=200 height=200 src='https://avatars.githubusercontent.com/u/166413978?s=280&v=4'>
</p>

## Topics:
 - [x] **Learn Shell Scripting**
 - [x] **Vim Editor Commands**
 - [x] **Git branching**
 - [x] **Markdown File**
 - [ ] **Make File**
 - [ ] **Verilator**

## Shell Scripting Tutorial:

### Some basic commands:
```
pwd                        Show Current Directory 
cd foldername              Change current Directry
ls                         Show contents of current Directory
mkdir foldername           Make new folder in directory
touch filename             Make new file in the current directory
rm filename                Delete this file 
cp filename1 filename2     Copy a file 
mv filename1 folder/       move a file to a folder
cat filename               Shows file conenets 
```
### How to Run a Simple script:
- Create a file:
  ```
   nano my_script.sh
  ```
- Add some Content:
  ```
   #!/bin/bash
   echo "Hello World"
  ```
- Ctrl+o then Enter and then Ctrl+x to Exit the file.
- Make it Excutable:
  ```
   chmod +x my_script.sh
  ```
- Run it:
  ```
   ./my_script.sh
  ```
- output:
  ```
  Hello World
  ```

### Variables:
```
name=Abubakar
# no space around '='
# access it using $name
```
### Conditions:
```
num=10

if [ $num -eq 10 ]; then
    echo "Number is 10"
else
    echo " Number is not 10"
fi    
```
 - `fi` ends the conditional block

**Operators that can be used:**
- -eq (Equal to)
- -ne (not equal to)
- -lt (less than)
- -gt (greater than)
- -le (less than or equal to)
- -ge (greater than or equal to)

### Loops:
#### For loops:
```
for i in 1,2,3,4,5
do 
    echo "number is $i"
done    
```
#### while loop:
```
count=1
while [ $count -le 5 ]
do 
    echo " number is $count"
    count=$((count+1))
done      
```
#### until loop:
```
count=1
untill [ $count -gt 5 ]
do 
    echo " number is $count"
    count=$((count+1))
done     
```
### Functions:
Group code into Reusable blocks:
```
greet(){
    echo "Hello, $1"
}
greet "Abubakar"
```
- $1 means first argument to function

You can pass values to script from command line
Example script `greeting.sh`
```
#!/bin/bash
echo "Hello, $@"
```
- Run it:
  ```
  ./greeting.sh Abubakar Abdullah Azaan
  ```
- Output:
  ```
  Hello, Abubakar Abdullah Azaan
  ```
Special Variables:
- `$1,$2,....` : First ,second etc arguments
- `$@` : All arguments
- `$#` : Number of Argumnents

### Input/Output Redirection:
Create/overwrite file :
```
echo "Hello" > file.txt
```
Append to file : 
```
echo "World" >> file.txt
```
Input redirection : 
```
cat < file.txt
```
- gives the conent of the file to cat command

### Grep commands:
#### Basic Grep Command:
```
grep "text" filename
```
finds and prints lines in `filename` that contain `text`

#### Use commands:
| Commands | Explaination|
|----------|-------------|
|-c| prints only a count of the lines that matches the pattern|
|-h| display the matched lines but do not display the filenames|
|-i| case insensitive search|
|-l| display list of filenames only|
|-n| display the matched line and their line numbers|
|-v| prints out all the lines that matches that do not matches the pattern|
|-E| treats pattern as an extented regular expression|
|-w| match whole word|
|-o| prints only the matched parts of a matching line, with each such part on a separte output line|

### Piping:
Sends output from one command to another : 
```
ls | grep "myfile"
```
- find files named `myfile` and list them 

### Permission:

```
chmod +x my_script.sh
```
- add excuute permission so user can run it

If you type a command `ls -l`, you'll see permissions for all the files in the directory:

| Permission | Meaning |
|------------|---------|
|-| means regular file|
|rwx| you can read, write and execute|
|r-x| Group can read and execute|
|r--| others can read only|

### Error Handling:
- **Check if a command succeded:**
   - 0 = success
   - non-zero = failure
  ```
   if [ $? -ne 0 ]; then
   echo ""command failed"
   fi
  ```
  - `$?` gives the exit status of the last command
<br>
  
- **Imediate check:**
  ```
  mkdir new_folder || echo " failed to create new_folder"
  ```  
  `||` means command failed
  `&&` means command passed
<br>
- **Exit on error automatically:**
  At the start of the script, add:
  ```
  set -e
  ```
  Now if any command fails, yout script stops immediately.

### Mini Project:
`file_checker.sh` will check if filename(*ourfile.txt*) exists, if not then it will create it.
- First, we will write in the terminal `nano file_checker.sh`, it will iniate the script where you will write this code:
  ```
    filename="ourfile.txt"

    if [ -e "$f filename" ]; then
        echo "file '$filename' already exist"
    else
        echo "file '$filename' does not exist, we are creating it now...."
        echo "file is being created by the the script" > "$filename"
        echo "file '$filename' is created successfully"
    fi    
  ```
- Now Save it and exit the script file, then Execute it and then run it, and we will see:
  ```
   file 'ourfile.txt' does not exist, we are creating it now....
   file 'ourfile.txt' is created successfully 
  ``` 

### Conclusion
Write few scripts like this and you will be good to go.
<br>
I hope you got Shell Scripting 👍
Bye Bye 👋





