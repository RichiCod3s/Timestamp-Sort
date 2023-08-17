# Timestamp-Sort

The program is designed to read in a txt file of string timestamps, convert the timestamp in to a long int and calculate the number of seconds that have elapsed since the date 01/01/2020. It sorts the timestamps by using the timeStampsToSeconds() function. It then prints to screen timestamps from the year 2016. 

Pseudocode 
1.	Use scanf to prompt user for name of file input & file.
2.	Read in timestamps.txt file 
3.	Store timestamps in a dynamic array of strings
4.	Use sscanf to store timestamp in to variables
5.	Convert the variable in to long int using atoi function
6.	Make function that calculates the seconds from 01/01/2000
7.	Sort the timestamp by seconds and output to txt file
8.	Loop through the array and print to screen any timestamp from 2016.
