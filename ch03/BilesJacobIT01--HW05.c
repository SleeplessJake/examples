//Jacob Biles
//CS 2060 MW
//WINDOWS
//HW 05
//Due 3/14/22

/*DESC
* The Goal of this assignment is to create a POS system that allows an admin to log on/off and set up totals for the day. Post this it will set a % of sales
* for charity and then allow users to select their seats, amount of tickets, and confirm their choices. A strong focus on modulurzation is requested by use
* of functions within this assignment.
* 
* HW 05
* 
* The goal of this assignment is to add multiple functions that take in multiple datasets -- primarly checking the user input at the very beggining to see if 
* they can input the admin passcode. If they can do it within 3 tries the next step of setting up the prices for the three seatting options appears. It knows the 
* range of the amount of seats and allows the admin to change the prices of the seats. It will then end on asking for the percentage change and change this as well
* finally going back into the previous iteration of asking a user for their input -- in this case now untill the admin hits q or Q to quit out of the program.
*/
#include <stdio.h>
#include <stdbool.h>


//prototyping
char getUserInput();
void clearBuffer();
bool adminLogin(double[], double);
bool isValidPin(unsigned int);
double seatPrices(double, double);
void charityPercentChange(double, double, double);


//Defining possible inputs (#*2 (Upper/Lower case))
#define SIZE 8

//Defining NumSeats Array Size
#define NUMSEATS 3

//Define admin pin #
#define ADMIN_PIN 4932


//Correct input array
const char CORRECT_INPUT[SIZE] = { 'Q', 'q','C','c','M','m','U','u' };


//MAIN
int main(void)
{

	// Seat Prices
	//0 == Courtside
	//1 == Mid Level
	//2 == Upper
	double priceOfSeats[NUMSEATS] = { 500,200,75 };


	//Charity Percentage 
	double charityPercentage = .25;

	// Initilizing userInput for seat selection
	char userInput = ' ';


	//Logging in if false wont contiue.
	if (adminLogin(priceOfSeats, charityPercentage)) {

		//Printing Prices of seats
		for (size_t i = 0; i < NUMSEATS; i++) {
			printf("Seat Area %llu, Price: %.2f\n", i, priceOfSeats[i]);
		}

		//Printing charity %
		printf("Charity Percentage: %.2f\n", charityPercentage);

		//Get user input until Q/q entered 
		while (userInput != CORRECT_INPUT[0] && userInput != CORRECT_INPUT[1]) {
			userInput = getUserInput();

			//Print for debuging 
			printf("Entered character: %c\n", userInput);

		}//end While loop

	}//End Valid Pin

	else {
		puts("\n\n*********Shutting down...*************\n\n");
	}

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


// adminLogin for the day -- 3 attempts to login
bool adminLogin(double seatPricesArray[], double charityPerc) {
	unsigned int loginAttempts = 0;
	unsigned int login = 0;

	// Allows setup of the day -- 3 attempts
	do {
		//First attempt
		if (loginAttempts == 0) {
			printf("%s", "PIN #:");
			scanf("%u", &login);
			clearBuffer();
			loginAttempts++;
		}

		//Other Two attempts 
		else {
			printf("%s", "ERROR INCORRECT PIN #:");
			scanf("%u", &login);
			clearBuffer();
			loginAttempts++;
		}

	} while (loginAttempts < 3 && isValidPin(login) != true);

	//Returns true if sucesful login (correct pin)
	if (isValidPin(login)) {

		//Setting up Seat prices
		//0 == Courtside
		//1 == Mid Level
		//2 == Upper
		seatPricesArray[0] = seatPrices(500, 201);
		seatPricesArray[1] = seatPrices(200, 76);
		seatPricesArray[2] = seatPrices(75, 10);
		charityPercentChange(.25, .05, charityPerc);

		//Return True to Continue program
		return true;
	}
	//Returns false if unscuessful login (3+ attempts w/o pin)
	else {
		printf("%s", "Seek Admin");
		return false;
	}

}// End Admin setup


//isValidPin functuin t/f if == Defined admin pin
bool isValidPin(unsigned int pinNumber) {
	if (pinNumber != ADMIN_PIN) {
		return false;
	}

	else {
		return true;
	}

}//End is valid pin


//Edit seat prices function -- Takes in a seat and a max/min
double seatPrices(double max, double min) {

	double temp = 0;

	//Continues to ask for price of seats within range
	do {
		printf("This seat's max is %.2f, and min is %.2f\n", max, min);
		scanf("%lf", &temp);
		clearBuffer();
	} while (temp > max || temp < min);


	return temp;
} // End Seat Price Editor

void charityPercentChange(double max, double min, double charityPerc) {

	double temp = 0;
	double* charityPtr = &charityPerc;
	//Continues to ask for price of seats within range
	do {
		printf("Enter the Charity Percentage max is %.2f, and min is %.2f\n", max, min);
		scanf("%lf", &temp);
		clearBuffer();
	} while (temp > max || temp < min);


	*charityPtr = temp;
} // End Seat Price Editor


//Clear Buffer function
void clearBuffer() {
	while (getchar() != '\n');
}//END clr Buffer