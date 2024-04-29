/*
* FILE : source.cpp
* PROGRAMMER : Valentyn Novosydliuk
* FIRST VERSION : 04/20/2024
* DESCRIPTION :
* This C program calculates hotel bills for meeting attendees based on check-in and check-out dates,
* ensuring attendees arrive no later than Thursday and depart no earlier than Thursday.
* It employs modular functions for input validation, cost calculation, and error handling, offering a streamlined interface for managing hotel bookings.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const int kErrorValue = -1;
const int kNumberOfPeople = 4;
const int kStringSize = 100;

double calculateCostOfRoom(const double[], int, int);
int indexTheDay(char[]);
void takeOffEscapeSequence(char[]);


int main(void) {

	/*initialized all of the variables that are used in main fucntion and set their values
	to 0 to prevent unexpected behaviour*/
	const double valueByDay[6] = { 137.50, 138.25, 130.50, 150, 150, 162.50 };
	char guestName[kStringSize] = "";
	char checkInDay[kStringSize] = "";
	char checkOutDay[kStringSize] = "";
	int checkInIndex = 0;
	int checkOutIndex = 0;
	double costPerPerson = 0;
	double grandTotal = 0;


	for (int i = 0; i < kNumberOfPeople; i++) {

		/*This for loop does 4 repetitions, and ask the user his name, check-in,checkout days and
		and also calculates total room cost for 1 person and grand total for everyone.*/
		printf("Enter Name: ");
		fgets(guestName, kStringSize, stdin);

		if (guestName[0] == '\n') {

			printf("Invalid name entry. Moving on to next guest.\n\n");
			continue;
			/*checks if user wrote his name and it is not empty*/

		}
		else {

			takeOffEscapeSequence(guestName);

		}

		printf("Enter check-in day: ");
		fgets(checkInDay, kStringSize, stdin);
		takeOffEscapeSequence(checkInDay);
		checkInIndex = indexTheDay(checkInDay);

		if (checkInIndex == -1) {

			printf("Invalid check-in day. Moving on to next guest...\n\n");
			continue;
			/*checks if the check in day matches any of the results and gives an error in case it doesn't*/

		}
		else if (checkInIndex > 4) {

			printf("This person is missing the meeting. Moving on to next guest...\n\n");
			continue;

		}

		printf("Enter check-out day: ");
		fgets(checkOutDay, kStringSize, stdin);
		takeOffEscapeSequence(checkOutDay);
		checkOutIndex = indexTheDay(checkOutDay);

		if (checkOutIndex == -1) {

			printf("Invalid check-out day. Moving on to next guest...\n\n");
			continue;

		}
		else if (checkOutIndex < 4) {

			printf("This person is missing the meeting. Moving on to next guest...\n\n");
			continue;

		}
		else if (checkOutIndex == checkInIndex) {

			printf("Invalid length of stay.Moving on to next guest...\n\n");
			continue;
			/*if checkin and check out day are thursday - shows an error*/

		}

		/*Call functions to calculate the cost and print the amount*/
		costPerPerson = calculateCostOfRoom(valueByDay, checkInIndex, checkOutIndex);
		printf("The total room cost for %s is %.2f\n\n", guestName, costPerPerson);
		grandTotal += costPerPerson;

	}

	/*Print the total of all the people up to 2 desmo points*/
	printf("Grand total: %.2f", grandTotal);
	return 0;

}

//
// FUNCTION : calculateCostOfRoom
// DESCRIPTION : This fucntion counts the cost of stay in a room
// PARAMETERS : double roomRates: price for a night
//				int checkIn: check in day as an index of an array
//				int checkOut: check out day as an index of an array
// RETURNS : return costOfRoom: returns the cost of living for a 1 person in a period that he stayed.
//
double calculateCostOfRoom(const double roomRates[], int checkIn, int checkOut) {

	double costOfRoom = 0;
	for (int i = checkIn; i < checkOut; i++) {

		costOfRoom += roomRates[i];

	}

	return costOfRoom;

}


//
// FUNCTION : indexTheDay
// DESCRIPTION : This fucntion compares user input to see if it correct and matches a week day
//				 Then this program checks if the weekday is allowed to be used
//				 or if the string is empty
// PARAMETERS : char dayEntered: user input  in a form of a string
// RETURNS : return kErrorValue: in case that string enter by the user does not match anything
//			 return 1,2,3,4,5,6: respectivly to the weekdays
//
int indexTheDay(char dayEntered[]) {

	if (strcmp(dayEntered, "sun") == 0) return 0;
	else if (strcmp(dayEntered, "mon") == 0) return 1;
	else if (strcmp(dayEntered, "tue") == 0) return 2;
	else if (strcmp(dayEntered, "wed") == 0) return 3;
	else if (strcmp(dayEntered, "thu") == 0) return 4;
	else if (strcmp(dayEntered, "fri") == 0) return 5;
	else if (strcmp(dayEntered, "sat") == 0) return 6;

	/*If non of the conditions were met*/
	return kErrorValue;

}


//
// FUNCTION : takeOffEscapeSequence
// DESCRIPTION : This fucntion takes away the "\n" which fgets function automaticly adds everytime.
//				 This is crucial for a proper comperisson of strings
// PARAMETERS : char userInput[]: string that needs to be modified
// RETURNS : void: does not return anything
//
void takeOffEscapeSequence(char userInput[]) {

	size_t lenghtOfArray = strlen(userInput);

	if (lenghtOfArray > 0 && userInput[lenghtOfArray - 1] == '\n') {

		userInput[lenghtOfArray - 1] = '\0';

	}
	/*Checks if the string is not empty and sets the value of the \n to the ascii value 0*/

}