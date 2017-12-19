#include <stdio.h>
#include <stdlib.h>

/**
* A program for the task "Entwickeln Sie ein Programm factors.c, das für eine natürliche Zahl N alle Teiler ausgibt, die kleiner als N sind. N soll als *Kommandozeilenparameter übergeben werden. Die Teiler sollen auf der Standardausgabe ausgegeben werden, mit einer Zahl pro Zeile im Dezimalsystem. (z.B. f(12) = *1, 2, 3, 4, 6)" 
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

	//Start counting from 1 to userNumber-1 and print out every i that's a valid factor of userNumber
	for (long long i = 1; i < userNumber; i++) {
		if (isFactor(userNumber, i) == 1) {
			printf("%lli\n", i);
		}
	}
	return 0;
}

