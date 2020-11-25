#This can be shared.

# Problem Statement:
# "We have a text file with a single column of data, and we want to find the average of the numbers in that set of data."

# Name of command: various commands including awk and bc

# Example of its usage: 
# $ current_count=0; total_count=0; for i in $( awk '{ print $2; }' data.txt );\ 
#  do total_count=$(echo $total_count+$i | bc );\ 
#  ((current_count++)); done; echo "scale=2; $total_count / $current_count" | bc
# 7.00

# Here is the myScript.sh script that will find the average of a column of data in a text file.
# usage: sh myScript.sh


#!/bin/bash

# data.txt must be in the current working directory

current_count=0;
total_count=0;

# we use a for loop to iterate through the numbers in the data
# awk is a function that reads data from files
for i in $( awk '{ print $2; }' data.txt )

   do 
	# bs is bash calculator, it performs arithmetic operations
	# in this case it is adding up the total count
	total_count=$(echo $total_count + $i | bc )

	# we increment the current count to get to the next number
	((current_count++)) 

   done

# we use bc again to find the final value
echo "scale=2; $total_count / $current_count" | bc


