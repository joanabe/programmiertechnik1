#include <stdio.h>
#include <stdlib.h>

/**
* A program for the task "Entwickeln Sie basierend auf der letzen Aufgabe primefactors.c, das nur die Primteiler der übergebenen Zahl ausgibt (z.B. pf(12) = 2, *3)" 
* @author: Joana Bergsiek
* @version: 18-12-2017
*/


/**
* Checks if secondaryNumber is a valid factor of primaryNumber in the domain of natural numbers.
* Note: By looking at the next tasks I chose to set both of my parameters as long long s so that we can compute larger numbers (-2^63+1 to 2^63-1).
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

/**
* Checks if number is a prime number.
* Note: By looking at the next tasks I chose to set my parameters as long long s so that we can compute larger numbers (-2^63+1 to 2^63-1).
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

//Takes a single positive number as an input, valid range: 0 to 2^63-1. If the input is higher than that, the program won't work correclty anymore.
int main(int argc, char const *argv[]) {
	//The user didn't type in a number, print out an error message or an alert if more than a single number was given
	if (argc < 2) {
		printf("Please type in a number.\n");
		return 0;
	} else if (argc > 2) {
		printf("You have typed in more than a single number. Only the first number is going to be processed.\n");
	}

	//The number which the user typed in
	long long userNumber = atoll(argv[1]);

	//The user has entered a negative number or one out of range, print out an error message.
	if (userNumber < 0){
		printf("Please enter a number from 0 to 2^63-1.\n");
		return 0;
	}

	//The user has typed in a floating number, notice the user that their number will be rounded
	if (atof(argv[1]) != userNumber) {
		printf("This program only works with natural numbers. Your input will be changed to: %lli.\n", userNumber);
	}

	//If userNumber already is a prime number, its factors are obviously 1 and itself but 1 isn't a prime number so only print out the number itself
	if(isPrimeNumber(userNumber) == 1) {
		printf("%lli\n", userNumber);
		return 0;
	}

	//Start counting from 2 to userNumber and print out every i that's a valid prime factor of userNumber
	if (isPrimeFactor(userNumber, 2) == 1) {
			printf("%d\n", 2);
			while ( userNumber % 2 == 0) {	
				userNumber /= 2;
			}
	}
	for (long long i = 3; i <= userNumber; i+=2) {
		if (isPrimeFactor(userNumber, i) == 1) {
			printf("%lli\n", i);
			while ( userNumber % i == 0) {	
				userNumber /= i;
			}
		}
	}
	return 0;
}


