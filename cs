#!/bin/bash

# if not directory was provided, the current directory is used
if [ $# -eq 0 ]; then
    entries=`ls -l | awk 'NR>1{printf("%s ", $1);for(i=9;i<=NF;i++){printf("%s", $i);}printf("\n");}'`

# if a directory was provided
else
    if [ ! -d "$*" ] && [ ! -f "$*" ]; then
        # use ls to generate error message
        errmsg=$(ls "$*" 2>&1)
        echo $(echo "$errmsg" | sed 's/^l/c/g')
        exit
    fi
    entries=`ls -l "$*" | awk 'NR>1{printf("%s ", $1);for(i=9;i<=NF;i++){printf("%s", $i);}printf("\n");}'`
fi

# formatting
if [ -z "$entries" ]; then
    exit
fi

echo

while read line; do
    
    perms=$(echo "$line" | sed -r "s/([^ ]*) (.*)/\1/g")
    entry=$(echo "$line" | sed -r "s/([^ ]*) (.*)/\2/g")
    isdir="${perms:0:1}"

    # is directory
    if [[ "$isdir" == "d" ]]; then
        tput bold
        tput setaf 4
        echo "  $entry"
        continue
    fi
    
    isexec=$(echo "$line" | sed -r "s/^[^x]*x.*$/YES/g")
    
    # is executable
    if [[ "$isexec" == "YES" ]]; then
        tput bold
        tput setaf 2
    
    # neither executable or directory
    else
        tput sgr0
    fi

    echo "  $entry"

done <<< "$entries"

echo
