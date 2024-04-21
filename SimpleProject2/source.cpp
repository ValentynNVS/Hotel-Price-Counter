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

double calculateCostOfRoom(const double[], int, int) {


	return 0;

}

int indexTheDay(char[]) {

	return 0;
}

void takeOffEscapeSequence(char[]);