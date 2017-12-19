#include <stdio.h>
#include <stdlib.h>

/**
* A program for the task "Entwickeln Sie factorial_factors.c, das für eine übergebene Zahl zuerst die Fakultät berechnet und anschließend eine Primzahlzerlegung
* durchführt. Beachten Sie, dass in der Primzahlzerlegung ein Primfaktor u.U. mehrfach enthalten ist (z.B. 5! = 2 * 2 * 2 * 3 * 5). Die Fakultät muss
* nicht ausgegeben werden." 
* @author: Joana Bergsiek
* @version: 18-12-2017
*/


/**
* Checks if secondaryNumber is a valid factor of primaryNumber in the domain of natural numbers.
* Note: By looking at the tasks I chose to set both of my parameters as long long s so that we can compute larger numbers (-2^63+1 to 2^63-1).
* @param primaryNumber: The number which will be divided by secondaryNumber.
* @param secondaryNumber: The number dividing primaryNumber to see if it's a valid factor.
* @return: 0 if it's not a valid factor or/and an error has occured
* 	   1 if secondaryNumber is a valid factor of primaryNumber
*/
int isFactor(long long primaryNumber, long long secondaryNumber) {
	//division by 0 is invalid
	if (secondaryNumber == 0) {
		return 0;
	}
	//since we are in the realm of the natural numbers, primaryNumber and secondaryNumber must be positive
	else if (secondaryNumber < 0 || primaryNumber < 0) {  
		return 0;
	}
	//when secondaryNumber is larger than primaryNumber it's already clear that secondaryNumber isn't a valid factor
	else if (secondaryNumber > primaryNumber) {
		return 0;
	} else {
		//if primaryNumber can be divided by secondaryNumber w/o leaving a rest, it's a valid factor
		if (primaryNumber % secondaryNumber == 0) {
			return 1;
		}
	}
	return 0;
}

/*
* Checks if number is a prime number.
* Note: When looking at the tasks I chose to set my parameters as long long s so that we can compute larger numbers (-2^63+1 to 2^63-1).
* @param number: The number to be checked.
* @return: 0 if number isn't a prime number
* 	   1 if number is a prime number
*/
int isPrimeNumber(long long number) {
	//1 is a special case and going after definition of prime numbers, not a prime number itself so we can already return 0
	if (number == 1) {
		return 0;
	}
	//Check every factor of number and if it has another one than itself or one, return 0
	for (long long i=1; i <= number; i++) {
		if (isFactor(number, i) && !( i == 1 || i == number)) {
			return 0;
		}
	}
	//If the loop didn't cancel we have a valid prime number
	return 1;
}

/**
* Checks if secondaryNumber is a valid prime factor of primaryNumber in the domain of natural numbers.
* Note: By looking at the next tasks I chose to set both of my parameters as long long s so that we can compute larger numbers (-2^63+1 to 2^63-1).
* @param primaryNumber: The number which will be divided by secondaryNumber.
* @param secondaryNumber: The number dividing primaryNumber to see if it's a valid factor.
* @return: 0 if it's not a valid factor or/and an error has occured
* 	   1 if secondaryNumber is a valid factor of primaryNumber
*/
int isPrimeFactor(long long primaryNumber, long long secondaryNumber) {
	//Checks if secondaryNumber is a factor of primaryNumber and if secondaryNumber is a prime number
	if (isFactor(primaryNumber, secondaryNumber) == 1 && isPrimeNumber(secondaryNumber) == 1){
		return 1;
	}
	return 0;
}

/*
* Calculates and returns the faculty of number.
* Note: I chose short int for my parameter and long long for my returned data since the faculty of a number gets huge very quickly.
* @param number: The number which faculty should be calculated.
* @return: The faculty of number.
*/
long long getFacultyOf(short int number) {
	//0! is defined as 1
	if (number == 0) {
		return 1;
	}
	// number! is the same as number-1! * number
	return number * getFacultyOf(number - 1);
}



//Takes a single positive number as an input, valid range: 0 to 20. If the input is higher than that, the program won't work correclty anymore (since log2(21!) > 63 -> not supported by long long and log2(20) < 63 -> supported by long long).
int main(int argc, char const *argv[]) {
	//The user didn't type in a number, print out an error message or an alert if more than a single number was given
	if (argc < 2) {
		printf("Please type in a number.\n");
		return 0;
	} else if (argc > 2) {
		printf("You have typed in more than a single number. Only the first number is going to be processed.\n");
	}

	//The number which the user typed in and its faculty
	int userNumber = atoi(argv[1]);
	long long facultyOfUserNumber = getFacultyOf(userNumber);

	//The user has entered a negative number or one out of range, print out an error message.
	if (! ( 0 <= userNumber && userNumber <= 20 ) ){
		printf("Please enter a number from 0 to 20.\n");
		return 0;
	}

	//The user has typed in a floating number, notice the user that their number will be rounded
	if (atof(argv[1]) != userNumber) {
		printf("This program only works with natural numbers. Your input will be changed to: %d.\n", userNumber);
	}
	
	//If userNumber already is a prime number, its factors are obviously 1 and itself but 1 isn't a prime number so only print out the number itself
	if(isPrimeNumber(facultyOfUserNumber) == 1) {
		printf("%lli\n", facultyOfUserNumber);
		return 0;
	}
	
	//Start the algorithm for the Primzahlzerlegung by dividing facultyOfUserNumber each time a prime factor has been found by the found prime number
	while (facultyOfUserNumber > 1){
		for (long long i = 1; i <= facultyOfUserNumber; i++) {
			if (isPrimeFactor(facultyOfUserNumber, i) == 1) {
				printf("%lli\n", i);
				facultyOfUserNumber = facultyOfUserNumber / i;
				break;
			}
		}
	}
	return 0;
}


