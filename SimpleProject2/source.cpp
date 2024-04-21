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

	const double valueByDay[6] = { 137.50, 138.25, 130.50, 150, 150, 162.50 };
	char guestName[kStringSize] = "";
	char checkInDay[kStringSize] = "";
	char checkOutDay[kStringSize] = "";
	int checkInIndex = 0;
	int checkOutIndex = 0;
	double costPerPerson = 0;
	double grandTotal = 0;



}

//
// FUNCTION : calculateCostOfRoom
// DESCRIPTION : This fucntion counts the cost of stay in a room
// PARAMETERS : double roomRates: price for a night
//				int checkIn: check in day as an index of an array
//				int checkOut: check out day as an index of an array
// RETURNS : return costOfRoom: returns the cost of living for a 1 person in a period that he stayed.
//
double calculateCostOfRoom(const double[], int, int) {


	return 0;

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
int indexTheDay(char[]) {

	return 0;
}


//
// FUNCTION : takeOffEscapeSequence
// DESCRIPTION : This fucntion takes away the "\n" which fgets function automaticly adds everytime.
//				 This is crucial for a proper comperisson of strings
// PARAMETERS : char userInput[]: string that needs to be modified
// RETURNS : void: does not return anything
//
void takeOffEscapeSequence(char[]) {



}