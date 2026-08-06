#!/bin/sh

if [ $# -ne 2 ]
then
    echo "Error: two arguments required"
    exit 1
fi

writefile=$1
writestr=$2

dirpath=$(dirname "$writefile")
mkdir -p "$dirpath"
if [ $? -ne 0 ]
then
    echo "Error: failed to create the directory path $dirpath"
    exit 1
fi

echo "$writestr" > "$writefile"
if [ $? -ne 0 ]
then
    echo "Error: failed to create the file $writefile"
    exit 1
fi
