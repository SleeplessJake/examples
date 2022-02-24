//Jacob Biles
//CS 2060 MW
//WINDOWS
//LA05
//Due 2/15/22


#include <stdio.h>

//Function prototyping 
void initilizeArray(unsigned int array[]);
void displayArray(const unsigned int array[]);
unsigned int arraySum(const unsigned int array[]);

//Constant used for setting array size
// Couldnt get to work for creating array however -- works in 
// for loops to use pre-determined amount of times.
const unsigned int ARRAY_SIZE = 10;

//MAIN
int main(void)
{

	unsigned int numArray[10];
	initilizeArray(numArray);
	displayArray(numArray);
	unsigned int total = arraySum(numArray);

	printf("Sum of all Elements: %u", total);

	return 0;
}//END MAIN

//Function Clear Buffer -- Clears Buffer
void clearBuffer() {
	while (getchar() != '\n');
}//END clr Buffer

//initialize array method -- gets input for elements
void initilizeArray(unsigned int array[]) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		puts("Please enter a number");
		scanf("%u", &array[i]);
		clearBuffer();
	}
}//end initialize method

//displayArray method -- displays array #
void displayArray(const unsigned int array[]) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("Number %d: %u\n\n", i, array[i]);
	}
}//End displayArray method

//Array Sum Method -- Adds all elements in an array
unsigned int arraySum(const unsigned int array[]) {
	unsigned int total = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		total += array[i];
	}
	return total;
}//End arraySum method