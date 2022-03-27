
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

///***PREFAB INTILIZATION***///
//ADMIN INFO
#define ADMIN_PIN 4932
#define MAX_LOGON_ATTEMPTS 3

//SEATING CHOICES
#define SEATING_CHOICES_SIZE 3
const char SEATING_CHOICES_VAL_INPUT[SEATING_CHOICES_SIZE + 1] = { 'Q', 'C', 'M', 'U' };
const char* SEATING_CHOICES_PTR[SEATING_CHOICES_SIZE][32] = {
{"(C)Courtside Seats" },
{"(M)Middle Level Seats"},
{"(U)Upper Level Seats"}
};

//TICKET CHOICES
#define TICKET_CHOICES_SIZE 4
const char TICKET_CHOICES_VAL_INPUT[TICKET_CHOICES_SIZE] = { 1,2,3,4 };
const char* TICKET_CHOICES_PTR[TICKET_CHOICES_SIZE][32] = {
{"Single Pack (1 ticket)" },
{"Double Pack (2 tickets)"},
{"Triple Pack (3 tickets)"},
{"Family Pack (4 tickets)"}
};


///***Prototypes -- LONG DESC***///
/***DESC***
Adming Logon starts the program off by asking the user for a predetermined pin that has ben set up. The
user will have 3 attempts to log on to the program. If the user fails to do so the program will end.
It returns a bool of TRUE for a sucessful logon and FALSE for a failed one.
***END DESC***/
bool adminLogOn(void);

/***DESC***
Day Set Up takes in the seatPrice array[] and the charityPercentage of the sales Program and calls the changePrice
function with predetermined ranges for each seat determined. The same goes for the charity percentage where a range
has been determined.
***NOTE*** New seating options needs to be added inside the switch for i.
***END DESC***/
void daySetUp(double[], double*);

/***DESC***
Clear Buffer uses the getChar function to detect when the buffer is left with the new line character -- if not it will clear
out the buffer leaving the new line character ending the function.
***END DESC***/
void clearBuffer(void);

/***DESC***
Change Price takes in two doubles min and max respectively, it also takes in a third double* value. From these inputs it prompts the user to
enter a new value for the third double* value whilst respecting the range. It contiues to promp the user until they do so.
***END DESC***/
void changePrice(double, double, double*);


double seatSelection(const double[], const double*);

int ticketSelection(void);
/***DESC***
Confirm Selection returns a BOOL value based off a user selection of yes or no. It first prompts the user with some pre-entered
data to confirm the users choice. It will then reprompt the user untill a correct selection is made (Y/N)
***END DESC***/
bool confirmSelection(const int);


///***MAIN***///
int main(void) {

	///***INITILIZATION***///
	//Price&Percentage
	double seatPrices[SEATING_CHOICES_SIZE] = { 0, 0, 0 };
	double charityPercentage = 0;

	//Logon Paramaters
	unsigned int attempts = 0;
	bool loggedOn = false;

	///***START OF DAY LOG ON***///
	//Admin logon -- breaks if -- correct PIN#
	//-- OR -- 
	//Over 3 attempts
	do {
		puts("#######################################################################");
		printf("%s", "             Please enter the admin loging PIN #:");
		//Calls adminLogOn -- Returns T/F
		loggedOn = adminLogOn();
		puts("#######################################################################");
		attempts++;

	} while ((!loggedOn) && (attempts < MAX_LOGON_ATTEMPTS)); //While not logged on and Attemts less than 3 (0,1,2 -- attempts)


	///***LOGON CHECK***///
	//Sucessful Logon (TRUE)
	if (loggedOn) {
		double userSeatSelection = '\0';
		int userTicketSelection = 0;

		//Filler text
		puts("");
		puts("#######################################################################");
		puts("");
		puts("                            Sucessful Logon  ");
		puts("");
		puts("#######################################################################");

		//Setting up Prices
		daySetUp(seatPrices, &charityPercentage);

		//Performing sales
		userSeatSelection = seatSelection(seatPrices, &charityPercentage);
		userTicketSelection = ticketSelection();

		printf("%lf", userSeatSelection);
		printf("%d", userTicketSelection);
	}//END SUCCESSFUL LOGON


	//***END PROGRAM***//
	//Unsucessful Logon (FALSE -- initial login)
	else {
		printf("             Logon attempts exceded %ui! Seek admin!  ", MAX_LOGON_ATTEMPTS);
	}


	///***RETURN 0 FOR MAIN***///
	return 0;

} //END MAIN


///***FUNCTIONS***///
///***clearBuffer***///
//Short DESC:: Clears the buffer
// 
//Prints: VOID
// 
//Requires:: VOID
// 
//Input:: VOID
//Output:: VOID
void clearBuffer(void) {

	while (getchar() != '\n');

}//END CLEAR_BUFFER

///***confirmSelection***///
//Short DESC:: Prompts the user with their input and confirms selection. For Characters
// 
//Prints: Prompts user (includes carried data), reprompts on error
// 
//Requires:: VOID
// 
//Input:: const int input(selective)
//Output:: BOOL -- T :: Yes -- F :: NO
bool confirmSelection(const int input) {

	//Initilization
	int userInput = 0;
	bool validInput = false;
	bool yesOrNo = false;

	//Basic check -- if character
	if (input > 4) {
		puts("#######################################################################");
		//Initil prompt and reminds user of original entry
		printf("            You entered %c Is this what you meant? (Y/N)\n\n", input);
		printf("%s", "                             Entry: ");
	}

	//basic check -- if int
	else {
		puts("#######################################################################");
		//Initil prompt and reminds user of original entry
		printf("            You entered %i Is this what you meant? (Y/N)\n\n", input);
		printf("%s", "                             Entry: ");
	}

	//Getting Confirmation
	//--AND--
	//Valid input
	do {

		//Get users input -- Specifically a character
		userInput = getchar();
		clearBuffer();
		puts("#######################################################################");
		//Yes entered -- Valid
		if (toupper(userInput) == 'Y') {
			yesOrNo = true;
			validInput = true;
		}

		//No entered -- Valid
		else if (toupper(userInput) == 'N') {
			yesOrNo = false;
			validInput = true;
		}

		//Invalid entry -- reminds user of Y/N
		else {
			puts("#######################################################################");
			printf("%s", "                       Error enter Y or N!\n");
			printf("%s", "                       Entry: ");
		}

	} while (!validInput); //Continue untill valid entry

	//Return yes or no bool (True or False)
	return yesOrNo;

}//END CONFRIM_SELECTION


///***adminLogon***///
//Short DESC:: Initial logon of the day -- allows for 3 attempts before ending program
// 
//Prints: Prompts user
// 
//Requires:: ADMIN_PIN definition
// 
//Input:: VOID
//Output:: BOOL -- T:: Correct PIN# -- F:: 3+Attempt
bool adminLogOn(void) {

	//Initilization
	unsigned int userLogon = 0;

	//Get user input
	scanf("%ui", &userLogon);
	clearBuffer();

	//User Input matches PIN#
	if (userLogon == ADMIN_PIN) {

		return true;

	}

	//User Input doesn't match PIN#
	else {

		return false;

	}

}//END ADMIN_LOGON

///***daySetUp***///
//Short DESC:: Takes the array[] seatPrices  and charityPercent values and passes them to changePrices Function
// 
//Prints: VOID
// 
//Requires:: void changePrice(double, double, double*) function, SEATING_CHOICES_SIZE definition
// 
//Input:: double ticketArray[] (ticketPrices), double* charityPercent (charityPercentage)
//Output:: VOID
void daySetUp(double ticketArray[], double* charityPercent) {

	//Pointer intilization
	double* ticketPTR = NULL;

	//For all seating options
	for (size_t i = 0; i < SEATING_CHOICES_SIZE; i++) {

		//Assigining pointer to incrementing slots in ticketArray
		ticketPTR = &ticketArray[i];

		//Switch for each seating choice
		switch (i) {
		case 0: //CourtSide Seating

			changePrice(200, 500, ticketPTR);
			break;


		case 1://Mid Seating

			changePrice(75, 200, ticketPTR);
			break;

		case 2://Upper-Level Seating

			changePrice(10, 75, ticketPTR);
			break;

		} // END CASE

	}// END TICKET

	//Charity Percentage change
	changePrice(.05, .25, charityPercent);

}//END DAY_SETUP

///***changePrice***///
//Short DESC:: Assigns a value for max/min and asks user for price within range.
// 
//Prints: Prompt user, Accept value, Reprompts on error
// 
//Requires:: void clearBuffer(void) function, BOOL Library 
// 
//Input:: double min (exclusive), double max (inclusive), double* price (seatPrices array[3])
//Output:: VOID
void changePrice(double min, double max, double* price) {

	//Initilization
	double userInput = 0;
	bool validChoice = false;

	//Intil prompt of price -- before error is made
	puts("#######################################################################");
	printf("     Please enter a price or percentage above %.2lf to %.2lf\n\n", min, max);
	printf("                          Enter Price: ");

	//Ask untill valid input for price is given
	do {

		//Get price input from admin
		scanf("%lf", &userInput);
		clearBuffer();
		puts("#######################################################################");

		//Within Range -- Shows user accepted result
		if (max >= userInput && userInput > min) {

			validChoice = true; // Sets validChoice to TRUE

			puts(" ");

			//For prices
			if (userInput > 1) {
				puts("#######################################################################");
				printf("#####################  Accepted at: $%.2lf  ##########################\n\n", userInput);//Shows accepted Result
			}

			//For Percentages
			else {
				puts("#######################################################################");
				printf("#######################  Accepted at: %.2lf%%  ##########################\n\n", userInput);//Shows accepted Result
			}

		}

		//Out of range -- Repeats range for user 
		else {
			puts("#######################################################################");
			printf("  Error %.2lf is out of range! The range is above %.2lf to %.2lf: \n\n", userInput, min, max);
			printf("                          Enter Price: ");
		}

	} while (!validChoice); //Continut untill a vlaid input is inputed

	//Assign user inputed price to actual ticket price
	//-- or --
	//Assign user inputed percentage to actual charity percentage
	*price = userInput;

}//END CHANGE_PRICE

///***dailySales***///
//Short DESC:: Processes sales for the day
// 
//Requires:: bool confirmSelection(const int) function, SEATING_CHOICES_SIZE definition, 
//SEATING_CHOICE_VAL_INPUT[] definition, SEATING_CHOICES_PTR definition
//TICKET_CHOICES_SIZE definiton, TICKET_CHOICES_PTR definiton, BOOL Library
// 
//Input:: const double array[] (tickey array[]), const double* (charityPerect)
//Output:: VOID
double seatSelection(const double ticketArray[], const double* charityPercent) {

	//Initilizaiton
	int userInput = '\0';
	double const* price = &ticketArray[0];
	bool validInput = false;


	///***Seat Selection or Admin Quit (hidden option)***///
	//Initil text -- What guests will see before proceeding or making a mistake
	printf(
		"#######################################################################\n"
		"#######################################################################\n"
		"\n"
		"                     Hello welcome to Biles Big Game\n"
		"\n"
		"#######################################################################\n"
		"#######################################################################\n"
		"\n");

	//for the size of the seat selection array[] (3) List them out
	for (size_t i = 0; i < SEATING_CHOICES_SIZE; i++) {
		printf("                     %s at $%.2lf\n", *SEATING_CHOICES_PTR[i], ticketArray[i]);
	}

	//Spacer
	puts("");
	puts("#######################################################################");
	//Priting out charity perecent for the night
	printf(
		"\n"
		"                      Where %.2lf of tonights procedes\n"
		"                      will be goings to the: Getting\n"
		"                      Lost in the Rain and Pina Colada\n"
		"                      Fund Against Yoga!\n\n"
		"                               Entry: ", *charityPercent);


	//Seat Selection
	do {

		//Initial gathering of user input
		
		userInput = getchar();
		clearBuffer();

		puts("#######################################################################");

		//Check all characters in constnat array[] seatingChoices to see if users input is valid
		for (size_t i = 0; i < SEATING_CHOICES_SIZE + 1; i++) {

			//if there is a valid selection
			if (toupper(userInput) == SEATING_CHOICES_VAL_INPUT[i]) {

				//confirms slection before fully setting to true
				validInput = confirmSelection(toupper(userInput));
				price = &ticketArray[i];
			}

		}

		//If invalid reinforms user of correct choices
		if (!validInput) {
			puts("#######################################################################");
			puts("   Incorrect entry... Please enter C, M, or U for valid selection!\n");
			printf("                               Entry: ");
		}

	} while (!validInput); // Keep going until valaid entry

	return *price;

}

int ticketSelection(void) {

	//Initilizaiton
	int userInput = '\0';
	bool validInput = false;


	///***Ticket Selection***///
	//Initial text
	puts("#######################################################################");
	puts("    Great! Now make a selection of how many tickets you'd like.");

	//for the size of the ticket selection array[] (4) List them out
	for (size_t i = 1; i < TICKET_CHOICES_SIZE + 1; i++) {
		printf("                      %llu. %s\n", i, *TICKET_CHOICES_PTR[i - 1]);
	}

	//Ticket Selection
	do {
		//Initial gathering of user input
		scanf("%i", &userInput);
		clearBuffer();

		//Check all characters in constnat char array[] TICKET_CHOICES_VAL_INPUT to see if users input is valid
		for (size_t i = 0; i < TICKET_CHOICES_SIZE; i++) {

			//If the input is inside the array
			if (userInput == TICKET_CHOICES_VAL_INPUT[i]) {

				//confirms selection before fully setting to true
				validInput = confirmSelection(toupper(userInput));
			}
		} // End For loop checking entry

		//If invalid reinforms user of correct choices
		if (!validInput) {
			puts("  Incorrect entry... Please enter 1, 2, 3, or 4 for valid selection!");
			printf("                               Entry: ");
		}

	} while (!validInput); // Keep going until valaid entry

	return userInput;

}

