#!/bin/sh

if [ $# != 2 ]
then
	echo "Error: two arguments required" 
	exit 1;
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ]
then
	echo "Error: not a directory"
	exit 1
fi

x=$(find "$filesdir" -type f | wc -l)
y=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $x and the number of matching lines are $y"

