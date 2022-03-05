//Jacob Biles
//CS 2060 MW
//WINDOWS
//LA07 
//Due 3/4/22

/*DESC
* The Goal of this assignment is to create a POS system that allows an admin to log on/off and set up totals for the day. Post this it will set a % of sales
* for charity and then allow users to select their seats, amount of tickets, and confirm their choices. A strong focus on modulurzation is requested by use
* of functions within this assignment.
*/
#include <stdio.h>

//prototyping
char getUserInput();
void clearBuffer();

//Defining possible inputs (#*2 (Upper/Lower case))
#define SIZE 8

//Correct input array
const char CORRECT_INPUT[SIZE] = { 'Q', 'q','C','c','M','m','U','u' };

//MAIN
int main(void)
{
	//Get input
	char userInput = getUserInput();

	//Print for debuging 
	printf("Entered character: %c", userInput);

	return 1;
}//END MAIN

//Getting character input -- For Seat Selection
char getUserInput() {
	//initilizing
	char userInput = ' ';
	// 1 || 0
	unsigned int isInput = 0;

	do {
		//Puts 
		puts("Enter a valid seating choice! Upper(U/u), Midlle(M/m), or Upper(U/u)");
		scanf("%c", &userInput);
		clearBuffer();
		for (size_t i = 0; i < SIZE; i++) {
			//set to true if in valid inputs
			if (userInput == CORRECT_INPUT[i]) {
				isInput = 1;
			}

			else {
			}
		}
	} while (isInput == 0); // while false


	return userInput;
} // End Get user input function

//Clear Buffer function
void clearBuffer() {
	while (getchar() != '\n');
}//END clr Buffer