#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

int stringToInt(char* s); // changes string to int
long int timeStampToSeconds(char* timeStamp); // gets number of seconds
void sortTimestamp(); // 
char** extractTimestamps(FILE* f);
void sortTimestampsArray(char** timeStamp); //sorts timestamp array
void findTimestampsFromYear(char** timeStamp); //finds timestamps from 2016

// function main begins program execution
int main(void) {

	FILE* inFilePtr; // pointer to input file
	FILE* outFilePtr; // pointer to output file
	char inputFileName[30] = "";
	char outputFileName[30] = "";
	char** timestampsArr;

	// prompt for name of input file. if file not found - repprompt
	while (1)
	{
		printf("Enter the name of the input file: ");
		scanf("%s", inputFileName);  // annoying warning, still works
		inFilePtr = fopen(inputFileName, "r");
		if (inFilePtr == NULL)
		{
			printf("File does not exist. Please try again.\n");
		}
		else
		{
			break;
		}
	}

	// DYNAMIC ARRAY of Strings
	timestampsArr = extractTimestamps(inFilePtr); // functions

	sortTimestampsArray(timestampsArr);

	findTimestampsFromYear(timestampsArr);

	return 0;
}

// converts a string to an int 
int stringToInt(char* s)
{
	return atoi(s);
}

//Create a function called timeStampToSeconds() that converts a timestamp string to a long int, 
//which represents the number of seconds elapsed since 01 / 01 / 2000 00:00 : 00.
long int timeStampToSeconds(char* timeStamp)
{
	long int totalDays;
	long int totalHours;
	long int totalMinutes;
	long int totalSeconds;

	char day[3], mon[3], year[5], hours[3], minutes[3], seconds[3];// timestamp in to strings

	int yearNum, monNum, dayNum, hoursNum, minutesNum, secondsNum; // strings in to ints

	sscanf(timeStamp, "%2s/%2s/%4s-%2s:%2s:%2s", day, mon, year, hours, minutes, seconds); 

	yearNum = stringToInt(year);
	monNum = stringToInt(mon);
	dayNum = stringToInt(day);
	hoursNum = stringToInt(hours);
	minutesNum = stringToInt(minutes);
	secondsNum = stringToInt(seconds);


	totalDays = (yearNum - 2000) * 365.25; // year in to days
	totalDays += (monNum - 1) * 30.4; // mon in to days
	totalHours = (totalDays * 24) + hoursNum; // add all days in to hours
	totalMinutes = (totalHours * 60) + minutesNum; // hours in to minutes 
	totalSeconds = (totalMinutes * 60) + secondsNum;

	//printf("Total seconds: %ld \n", totalSeconds);

	return totalSeconds;
}

void sortTimestamp()
{
	for (int i = 0; i < SIZE; i++) {

	}
}


// DYNAMIC ARRAY of Strings
char** extractTimestamps(FILE* f)
{
	char line[20];// variable the line is stored in
	char** timestampsArr = malloc(SIZE * sizeof(char*));
	if (timestampsArr == NULL) {
		printf("Memory could not be allocated");
		exit(1);
	}

	int i = 0;
	while (fscanf(f, "%s", line) != EOF) {  // store in line 
		timestampsArr[i] = malloc(strlen(line) * sizeof(char));
		if (timestampsArr[i] == NULL) {
			printf("Memory could not be allocated");
			exit(1);
		}
		strcpy(timestampsArr[i], line);
		i++;
	}

	fclose(f);
	return timestampsArr;
}

void sortTimestampsArray(char** timestampsArray) {

	int ARRAY_SIZE = 50;
	char hold[50];
	char** sortedTimestamps = timestampsArray;
	FILE* outFilePtr; // pointer to output file
	char outputFileName[50] = "sortedTs.txt";

	// loop to control number of passes
	for (int pass = 1; pass <= ARRAY_SIZE; pass++) {
		// loop to control number of comparisons per pass //
		for (int i = 0; i < ARRAY_SIZE - pass; i++) {

			//Bubble sort - swap if first element is greater than second element
			if (timeStampToSeconds(sortedTimestamps[i]) > timeStampToSeconds(sortedTimestamps[i + 1])) {
				strcpy(hold, sortedTimestamps[i]);
				strcpy(sortedTimestamps[i], sortedTimestamps[i + 1]);
				strcpy(sortedTimestamps[i + 1], hold);
			} // end if //
		} // end inner for //
	} // end outer for //

	for (int i = 0; i < 50; i++) {
		printf("\n");
		printf("TimeStamp: %s\n", sortedTimestamps[i]);
		printf("Seconds from date: %ld\n", timeStampToSeconds(sortedTimestamps[i]));
		
	}

	/* fopen opens file. Exit program if unable to create file  */
	if ((outFilePtr = fopen(outputFileName, "w")) == NULL) {
		printf("File could not be opened\n");
	} /* end if */

	else {

		for (int i = 0; i < ARRAY_SIZE; i++) {
			// fprintf prints to file
			fprintf(outFilePtr, sortedTimestamps[i], "%s");
			fprintf(outFilePtr, "\n");
		}

		fclose(outFilePtr); /* fclose closes file */
	} /* end else */
}

void findTimestampsFromYear(char** timestampsArray) {
	char day[3], mon[3], year[5], hours[3], minutes[3], seconds[3];// timestamp in to strings
	for (int i = 0; i < 50; i++) {
		sscanf(timestampsArray[i], "%2s/%2s/%4s-%2s:%2s:%2s", day, mon, year, hours, minutes, seconds);
		if (stringToInt(year) == 2016) {
			printf("\n");
			printf("Timestamps from 2016: %s\n", timestampsArray[i]);
		}
	}
}