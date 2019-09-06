# myUtil

#####  HOW TO INSTALL:

git clone https://github.com/CoderTypist/myUtil.git

./myUtil/installMyUtil

=====================================

#####  WHAT IS MYUTIL?

myUtil is a series of aliases and bash scripts I made to make it easier to navigate through directories and add custom scripts to /usr/local/bin

=====================================

##### WHY DID I MAKE MYUTIL?

ls will list multiple directory entries on the same line in the terminal. ls -l will list all of the entries on their own line, but add a bunch of extra information. Sometimes I don't need the extra information, so I made a script that would list the name of each directory entry on its own line. I then made a script that could add things to /usr/local/bin since it lies on the PATH.

=====================================

##### WHAT EACH SCRIPT DOES

====================

##### cs 

Lists each directory entry on its own line

====================

##### plain

Lists each item in the current directory on its own line (all text is white)


====================

##### path

lists each directory on the PATH on its own line

====================

##### cplbin

copies the specified item to /usr/local/bin

====================

##### mvlbin

moves the specified item to /usr/local/bin

====================

##### trim 

Removes the first and last character from the received text. You must use xargs when piping input to trim.

Ex: trim "done"

output: on

Ex: echo "This" | xargs trim

output: hi

====================

##### randtemp

Description:

Creates a random file in the format: ./some_directory/temp_randomNumber

How it works:

If no input is provided, the file is created in the current directory

If a directory is provided, randtemp checks to see if the directory exists.

If the directory does not exist, no file is created.

Purposes:

1) You may need to create multiple temporary files during your script, and randtemp will create one for you. You won't have to make up the name yourself or worry about the file already existing.

2) You may write want to write to a file named "temp", but a file named "temp" may already exist, and you may not want to overwrite the contents of that file.

Disclaimer:

randtemp can only generate 1 of 32768 possible filenames

If all 32768 filenames already exist, this program program will run forever

====================

##### dewiki

Removes all instances of [*one or more numbers*] from the specified file

Ex: dewiki textFromWikipedia.txt

====================

##### rmbl

Removes all blank lines from the specified file

====================

##### rmbldir

Removes all blank lines from files in the specified directory

