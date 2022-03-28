


//// #****#  LIBRARIES  #****# ////

/// ***  Libraries  *** ///
// Standard Input Output
#include <stdio.h>

// c Type
#include <ctype.h>

// Standard Bool
#include <stdbool.h>



//// #****#  PREFAB INTILIZATION  #****# ////

/// ***  ADMIN INFO  *** ///
// ADMIN PIN
#define ADMIN_PIN 4932

// Max Logon Attempts
#define MAX_LOGON_ATTEMPTS 4

// Login Quit Number -- for ('SEATING_CHOICES_VAL_INPUT')
#define LOGIN_QUIT_NUMBER 3


/// ***  SEATING INFO  *** ///
// Number of Seating Choices -- Excluding Quit ('Q')
#define SEATING_CHOICES_SIZE 3

// Valid Character Input Array -- +1 for Inclusion of Quit ('Q')
const char SEATING_CHOICES_VAL_INPUT[SEATING_CHOICES_SIZE + 1] = { 'C', 'M', 'U','Q' };

// Character Pointer for Listing out Seating Options
const char* SEATING_CHOICES_PTR[SEATING_CHOICES_SIZE][32] = {
{"(C)Courtside Seats" },
{"(M)Middle Level Seats"},
{"(U)Upper Level Seats"}
};


/// ***  TICKET INFO  *** ///
// Number of Ticket Options
#define TICKET_CHOICES_SIZE 4

// Valid Character Input 
const unsigned int TICKET_CHOICES_VAL_INPUT[TICKET_CHOICES_SIZE] = { 1,2,3,4 };
const char* TICKET_CHOICES_PTR[TICKET_CHOICES_SIZE][32] = {
{"Single Pack (1 ticket)" },
{"Double Pack (2 tickets)"},
{"Triple Pack (3 tickets)"},
{"Family Pack (4 tickets)"}
};



/// #***#  Prototypes -- LONG DESC  #***# ///


/***DESC***
Clear Buffer uses the getChar function to detect when the buffer is left with the new line character -- if not it will clear
out the buffer leaving the new line character ending the function.
***END DESC***/
void clearBuffer(void);


/***DESC***
Adming Logon starts the program off by asking the user for a predetermined pin that has ben set up. The
user will have 3 attempts to log on to the program. If the user fails to do so the program will end.
It returns a bool of TRUE for a sucessful logon and FALSE for a failed one.
***END DESC***/
bool adminLogOn(void);


/***DESC***
Change Price takes in two doubles min and max respectively, it also takes in a third double* value. From these inputs it prompts the user to
enter a new value for the third double* value whilst respecting the range. It contiues to promp the user until they do so.
***END DESC***/
void changePrice(double, double, double*);


/***DESC***
Day Set Up takes in the seatPrice array[] and the charityPercentage of the sales Program and calls the changePrice
function with predetermined ranges for each seat determined. The same goes for the charity percentage where a range
has been determined.
***NOTE*** New seating options needs to be added inside the switch for i.
***END DESC***/
void daySetUp(double[], double*);


/***DESC***
Confirm Selection returns a BOOL value based off a user selection of yes or no. It first prompts the user with some pre-entered
data to confirm the users choice. It will then reprompt the user untill a correct selection is made (Y/N)
***END DESC***/
bool confirmSelection(const int, const size_t);



size_t seatSelection(const double[], const double);



size_t ticketSelection(void);



double calculateTotal(const double*, const size_t);



double giveToCharity(const double, const double);



void updateTicketsSold(unsigned int*, const size_t, const size_t);



void updateSeatSales(double*, const size_t, const double);



void updateCharityTotals(double*, const size_t, const double);



//// #***#  MAIN  #***# ////

/// ***  MAIN  *** ///
int main(void) {


	/// ***  INITILIZATION  *** ///
	// Seats and Tickets
	double seatPrices[SEATING_CHOICES_SIZE] = { 0, 0, 0 };
	unsigned int ticketsSold[SEATING_CHOICES_SIZE] = { 0, 0, 0 };
	double seatSales[SEATING_CHOICES_SIZE] = { 0, 0, 0 };

	// Charity
	double charityPercentage = 0;
	double charityTotals[SEATING_CHOICES_SIZE] = { 0, 0, 0 };

	// Logon Paramaters
	unsigned int attempts = 0;
	bool loggedOn = false;


	//// #****#  INITIL LOG ON  #****# ////

	///***START OF DAY LOG ON***///
	// Admin Logon -- Breaks for
	// Correct PIN# -- SETS loggedOn == TRUE
	// -- OR -- 
	// Over 3 Attempts -- SETS/KEEPS == FALSE
	do {


		/// ***  INITIL PROMPT TO USER  *** ///
		// Filler Text
		puts("#######################################################################");
		printf("%s", "             Please enter the admin loging PIN #:");


		//C alls adminLogOn -- Returns ('T' -or- 'F')
		loggedOn = adminLogOn();
		puts("#######################################################################");

		// Increaments Attempts
		attempts++;


	} while ((!loggedOn) && (attempts < MAX_LOGON_ATTEMPTS)); // Do untill ('validInput') is Set to True && ('attempts') is below ('MAX_LOGON_ATTEMPTS') Definition



	//// #****#  SUCESSFUL LOG ON -- DAY SALES  #****# ////

	/// ***  SUCESSFUL LOGON CHECK  *** ///
	// Sucessful Logon (TRUE)
	if (loggedOn) {



		/// ***  Initilizaing  **** ///
		// User Selections
		size_t userSeatSelection = '\0';
		size_t userTicketSelection = '\0';

		// Users Total
		double userTotal = '\0';

		// Charity Take
		double charityTake = '\0';

		// Stadium Profits
		double actualProfit = '\0';


		// Filler Text
		puts("#######################################################################");
		puts("");
		puts("                            Sucessful Logon  ");
		puts("");
		puts("#######################################################################");



		//// #****#  SETTING UP DAYS PRICES -- CHANGES PRICES FOR SEATS AND THE CHARITY PERCENTAGE  #****# ////

		/// ***  SETTING UP DAY   *** ///
		// Setting up Prices and Percentage
		daySetUp(seatPrices, &charityPercentage);


		/// *** DO-WHILE UNTILL HIDDEN OPTION ('Q') IS PRESSED AND LOGGED ON WITH ('ADMIN_PIN') DECLERATION  *** ///
		// Daily Sales Coninutes Untill Admin Logs In to Quit
		do {


			/// *** PERFORMING SALES -- CONTINUES UNTIll ('Q') is pressed continuing to ('adminLogon')  *** ///
			// Getting ('userSeatSelection') by Calling ('seatSelection')
			// RETURNING -- SIZE_T ('userSeatSelection')
			userSeatSelection = seatSelection(seatPrices, charityPercentage);


			/// ***  QUIT BUTTON PRESSED AND CONFIRMED CHECK  *** ///
			// Checks to See if Incomming Character is the Quit Character
			if (userSeatSelection != LOGIN_QUIT_NUMBER) {


				// Getting ('userSeatSelection') by calling ('ticketSelection')
				// RETURNING -- UNSIGNED INT ('userTicketSelection')
				userTicketSelection = ticketSelection();


				/// ***  CALCULATING USERS TOTAL AND CHARITIES TAKE  *** ///
				// Getting Users Initl Total Before ('charityTake')
				// RETURNING -- DOUBLE ('userTotal')
				userTotal = calculateTotal(&seatPrices[userSeatSelection], userTicketSelection);


				/// ***  CALCULATING STADIUM -VS- CHARITY TAKE  *** ///
				// Takes ('userTotal') and ('charityPercentage') to calculate
				// the amount charity Takes
				// REURNING -- DOUBLE ('charityTake')
				charityTake = giveToCharity(userTotal, charityPercentage);

				// Takes ('userTotal') and ('charityTake') to calculate
				// the Actual Profit for the Stadium
				// REURNING -- DOUBLE ('actualProfit')
				actualProfit += userTotal - charityTake;

				/// ***  UPDATING TOTALS  *** //
				// Tickets Sold Updated
				updateTicketsSold(&ticketsSold[userSeatSelection], userSeatSelection, userTicketSelection);

				// Seats Sold Updated
				updateSeatSales(&seatSales[userSeatSelection], userSeatSelection, actualProfit);

				// Charity Totals Updated
				updateCharityTotals(&charityTotals[userSeatSelection], userSeatSelection, charityTake);
			}// END QUIT CHARACTER CHECK


			/// ***  QUIT OPTION SELECTED  **** ///
			// If Quit Option is Selected and Confirmed
			else {

				/// ***  PROMPT USER  *** ///  
				//////////////////////////////////////////////////////////////////////////////////////////////////////////ENDED HERE 1/2
				puts("#######################################################################");
				puts("");
				printf("%s", "                         Enter PIN : ");
				loggedOn = !adminLogOn();

				if (!loggedOn) {
					puts("");
					puts("#######################################################################");
					puts("#######################################################################");
					puts("");
					puts("                            Sucessful Logout  ");
					puts("");
					puts("#######################################################################");

				}

				else {
					puts("#######################################################################");
					puts("#######################################################################");
					puts("");
					puts("                               Seek Admin   ");
					puts("");
					puts("#######################################################################");

				} //
			}


		} while (loggedOn); // Continue While ('loggedOn') is TRUE


	}//END SUCCESSFUL LOGON CHECK



	//// #****#  END PROGRAM CONDITIONS  #****# ////

	/// ***  Unsucessful Logon -- (FALSE -- Initial Login) --  *** ///
	// The User Maxed Out Attempts of the Admin Pin Authentication
	else {


		/// ***  PRITING OUT FAILED LOGON  *** ///
		// Shows User Failed Based on 'MAX_LOGON_ATTEMPTS' Condition
		printf("             Logon attempts exceded %u! Seek admin!  ", MAX_LOGON_ATTEMPTS);


	}// END UNSUCESSFUL LOGON CHECK


	/// ***  LOGGED OFF  *** ///
	//Logged Off Check
	if (!loggedOn) {

		////////////////////////////////////////////////////////////////////////////////////////////////////////// ENDED HERE 2/2
		for (size_t i = 0; i < SEATING_CHOICES_SIZE; i++) {

		}

	}// END LOGGED OFF CHECK




	//// #****#  RETURNING 0 FOR MAIN  #****# ////

	/// ***  RETURN -- INT -- 0 -- FOR MAIN  *** ///
	//Returns :(INT): -- 0 -- for Sake of Proper Return for Main
	return 0;


} //END MAIN


//// #***#  FUNCTIONS -- SHORT DESC, REQUIREMENTS, INPUT/OUTPUT --  #***# ////

/// ****  clearBuffer  **** ///
//Short DESC:: Clears the buffer
// 
//Prints: VOID
// 
//Requires:: VOID
// 
//Input:: VOID
//Output:: VOID
void clearBuffer(void) {


	/// ***  CLEARING BUFFER  *** ///
	// If the return of )'getchar'_ is Not ('\n')
	// Then Will Continue to call ('getchar') 
	// Untill it is ('\n')
	while (getchar() != '\n');


}//END CLEAR_BUFFER


/// ****  adminLogon  **** ///
//Short DESC:: Initial logon of the day -- allows for 3 attempts before ending program
// 
//Prints: Prompts user
// 
//Requires:: ADMIN_PIN definition
// 
//Input:: VOID
//Output:: BOOL -- T:: Correct PIN# -- F:: 3+Attempt
bool adminLogOn(void) {


	/// ***  INITILIZATION  *** ///
	/// User Input 
	unsigned int userLogon = 0;


	/// *** GETTING USER INPUT -- UNSGINED INT -- userLogon*** ///
	scanf("%ui", &userLogon);
	clearBuffer();


	/// ***  TRUE VALIDITY CHECK  *** ///
	// User Input Matches ('ADMINT_PIN') Definition
	if (userLogon == ADMIN_PIN) {


		/// ***  RETURN STATMENT -- BOOL -- TRUE *** //
		// Returns :(TRUE): -- Matches the ('ADMIN_PIN') Definition
		return true;


	}// END TRUE CHECK


	/// ***  FALSE VALIDITY CHECK  *** ///
	// User Input Doesn't Match ('ADMINT_PIN') Definition
	else {


		/// ***  RETURN STATMENT -- BOOL -- FALSE *** //
		// Returns :(TRUE): -- Matches the ('ADMIN_PIN') Definition
		return false;


	}// END FALSE CHECK


}// END ADMIN_LOGON


/// ****  changePrice  **** ///
//Short DESC:: Assigns a value for max/min and asks user for price within range.
// 
//Prints: Prompt user, Accept value, Reprompts on error
// 
//Requires:: void clearBuffer(void) function, BOOL Library 
// 
//Input:: double min (exclusive), double max (inclusive), double* price (seatPrices array[3])
//Output:: VOID
void changePrice(const double min, const double max, double* price) {


	/// ***  Initilization  *** ////
	//User Input
	double userInput = 0;

	bool validChoice = false;


	/// ***  INITIL PROMPTING OF USER FOR PRICE OR PERCENTAGE  *** ///
	//Intil Prompt of Price -- Before Error is Made
	puts("#######################################################################");
	printf("     Please enter a price or percentage above %.2lf to %.2lf\n\n", min, max);
	printf("                          Enter Price: ");


	/// ***  DO-WHILE UNTILL A VALID ENTRY IS GIVEN  *** ///
	// Continues Untill a Valid Price or Percentage is 
	// Given From the Admin That is Within the Given
	// ('min') and ('max') Range
	do {


		/// ***  GETTING USER INPUT  *** ///
		//Get Price From Admin Input
		scanf("%lf", &userInput);
		clearBuffer();

		//Buffer Text
		puts("#######################################################################");


		/// ***  INPUT IS VALID -- WITHIN RANGE *** ///
		//Within Range -- Shows user accepted result
		if (max >= userInput && userInput > min) {


			/// ***  CONFIRMING VALIDITY  *** ///
			// Sets validChoice to TRUE
			validChoice = true;


			/// ***  CHANGING SEAT PRICES  *** ///
			// For Seat Prices -- Input Must be at Least 1, Thus Greater Than a Percentage.
			if (userInput >= 1) {


				/// *** PRINTING ACCEPTED PRICE  *** ///
				// Allows the Admin to See the Price they Entered
				puts("#######################################################################");
				puts(" ");

				//Printing of Accepted Inpiut
				printf("#####################  Accepted at: $%.2lf  ##########################\n\n", userInput);
				puts("#######################################################################");


			}// END SEAT PRICE CHECK


			/// ***  CHANGING CHARITY PERCENTAGE  *** ///
			//For Charity Percentage -- Input is Less than 1, Thus a Percentage
			else {


				/// *** PRINTING ACCEPTED PERCENTAGE  *** ///
				// Allows the Admin to See the Percentage They Entered
				puts("#######################################################################");
				puts(" ");

				// Printing of Accepted Input
				printf("#######################  Accepted at: %.2lf%%  ##########################\n\n", userInput);
				puts("#######################################################################");


			}// END CHAIRTY PERCENTAGE CHECK



		}// END WITHIN RANGE CHECK


		/// ***  INVALID ENTRY -- OUT OF RANGE *** ///
		// Reprints Correct Range For User
		else {


			/// ***  REPRINTING OF OPTIONS  *** ///
			// Reprints the Correct Options for the User
			puts("#######################################################################");
			printf("  Error %.2lf is out of range! The range is above %.2lf to %.2lf: \n\n", userInput, min, max);
			printf("                          Enter Price: ");


		} // END INVALID INPUT CHECK


	} while (!validChoice);// Do untill ('validInput') is Set to True


	/// ***  ASSINGING VALUES  *** //
	// Assigns ('userInput') to Deference of ('*price')
	*price = userInput;


}// END CHANGE_PRICE


/// ****  daySetUp  **** ///
//Short DESC:: Takes the array[] seatPrices  and charityPercent values and passes them to changePrices Function
// 
//Prints: VOID
// 
//Requires:: void changePrice(double, double, double*) function, SEATING_CHOICES_SIZE definition
// 
//Input:: double ticketArray[] (ticketPrices), double* charityPercent (charityPercentage)
//Output:: VOID
void daySetUp(double seatArray[], double* charityPercent) {


	/// ***  INITILIZATION  *** ///
	// Pointer Intilization
	double* ticketPTR = NULL;


	/// ***  FOR ALL ELEMENTS IN ('SEATING_CHOICES_SIZE') DEFINITION  **** ///
	// For All Seating Choices Set Up the Price for Them Appropriatley
	// Based on the Predetermined Min (EXCLUSIVE (E)) and Max (INCLUSIVE (I)) Range Given.
	for (size_t i = 0; i < SEATING_CHOICES_SIZE; i++) {


		/// ***  POINTER ASSIGNING  *** ///
		// Assins Pointer to Incremential Spots in the ('seatArray[]') -or- ('seatPrices[]') Proper
		ticketPTR = &seatArray[i];


		/// ***  SWITCH CASE FOR ALL ELEMENTS IN ('SEATING_CHOICES_SIZE') Predefiniton  *** ///
		// Switches for Case ('i') Where ('i') is All Options Within the ('seatArray') -or- ('seatPrices[]') Proper
		switch (i) {


			/// ***  CASES  *** ///
		case 0:// Courtside Seating 

			// MIN(E): 200      MAX(I): 500
			changePrice(200, 500, ticketPTR);

			break; // END C::0


		case 1:// Mid-Level Seating

			// MIN(E): 75      MAX(I): 200
			changePrice(75, 200, ticketPTR);

			break; //END C::1


		case 2:// Upper-Level Seating

			// MIN(E): 10       MAX(I):75
			changePrice(10, 75, ticketPTR);

			break;//END C::2


		default:// Default Case

			break;//END C::DEF


		} // END SWITCH FOR EACH ELEMENT IN ('seatArray[]')


	}// END TICKET SETUP LOOP FOR EACH ELEMENT IN ('seatArray[]')


	/// ***  PRICE CHANGE  *** ///
	// Calls ('changePrice') With a Predetermined
	// Range and Passes Adress or Pointer
	changePrice(.05, .25, charityPercent);


}//END DAY_SETUP


/// ****  confirmSelection  **** ///
//Short DESC:: Prompts the user with their input and confirms selection. For Characters
// 
//Prints: Prompts user (includes carried data), reprompts on error
// 
//Requires:: VOID
// 
//Input:: const int input(selective)
//Output:: BOOL -- T :: Yes -- F :: NO
bool confirmSelection(const int input, size_t nameLocation) {

	/// ***  INITILIZATION *** ///
	bool validInput = false;

	// User Input
	int userInput = 0;
	bool yesOrNo = false;


	/// ***  CHARACTER CHECK  *** ///
	// Checks to See if Input Value is Above 31 to See if Input is
	// a Character or Int
	// This Accounts for All 31 Special ASCII Characters 
	// Found Here: https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
	if (input > 31) {


		/// ***  PROMPTING USER FOR INPUT -- NORMAL SALE *** ///
		///More Effiecnet To Check for Sale Than Admin Quitting
		if (nameLocation != LOGIN_QUIT_NUMBER) {


			/// ***  PROMPTING USER FOR INPUT -- ('Y' -or- 'N')  *** ///
			//Filler Text
			puts("#######################################################################");
			printf("You entered (%c)--%s, Is this what you meant? (Y/N)\n\n", input, *SEATING_CHOICES_PTR[nameLocation]);
			printf("%s", "                             Entry: ");


		}// END SALE CHECK


		/// ***  PROMPTING USER FOR INPUT -- Quting System *** //
		//Checks Less Often Case -- If ('Q')
		else {


			/// ***  PROMPTING USER FOR INPUT -- ('Y' -or- 'N')  *** ///
			//Filler Text
			puts("#######################################################################");
			printf("You entered (%c)--Quit, Is this what you meant? (Y/N)\n\n", input);
			printf("%s", "                             Entry: ");


		}// END QUIT CHECK



	}//END CHARACTER CHECK


	/// ***  INT CHECK  *** ///
	// Checks to See if Input Value is Above 31 to See if Input is
	// a Character or Int
	// This Accounts for All 31 Special ASCII Characters 
	// Found Here: https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.htmlk
	else {

		/// ***  PROMPTING USER FOR INPUT  *** //
		//Filler Text
		puts("#######################################################################");
		printf("You entered (%i)--%s, Is this what you meant? (Y/N)\n\n", input, *TICKET_CHOICES_PTR[nameLocation]);
		printf("%s", "                             Entry: ");


	}// END INT CHECK


	/// ***  DO-WHILE LOOP FOR CHECKING VALID INPUT -- ('Y') -or- ('N') --  *** ///
	// Continues Untill a Valid Choice of Yes('Y') or No('N') is Made 
	do {


		/// ***  GETTING USER INPUT -- CHARACTER -- ('userInput')  *** ///
		// Gets the Users input
		userInput = getchar();
		clearBuffer();

		//Filler Text
		puts("#######################################################################");


		/// ***  VALID INPUT CHECK -- ('Y') -or- ('y') --  *** ///
		// Yes entered -- Valid
		if (toupper(userInput) == 'Y') {


			/// *** ASSINING VALUES -- ('yesOrNo') , ('validInput') --  *** //
			//Sets ('yesOrNo') to TRUE to Represent Yes ('Y')
			yesOrNo = true;

			//Breaks Loop Since Yes ('Y') is Valid
			validInput = true;


		} // END VALID CHECK (YES)


		/// ***  VALID INPUT CHECK -- ('N') -or- ('n') --  *** ///
		// No Entered -- Valid
		else if (toupper(userInput) == 'N') {


			/// *** ASSINING VALUES -- ('yesOrNo') , ('validInput') --  *** //
			//Sets 'yesOrNo' to FALSE to Represent No ('N')
			yesOrNo = false;

			//Breaks Loop Since No ('N') is Valid
			validInput = true;


		} // END VALID CHECK (NO)


		/// ***  REPROMPTING USER  *** ///
		//Invalid Entry -- Reminds User of Correct Entry
		else {


			// ***  REMINDING USER OF CORRECT ENTRY -- ('Y') -or- ('N') --  *** ///
			//Filler Text
			puts("#######################################################################");

			//Reminding User of Correct Choices -- ('Y') -or- ('N') --  *** ///
			printf("%s", "                       Error enter Y or N!\n");
			printf("%s", "                       Entry: ");


		} // END INVALID CHECK


	} while (!validInput); //CONTINUE UNTILL VALID ENTRY



	/// ***  RETURNING VALUE -- BOOL ('yesOrNo') --  *** ///
	//Returns ('yesOrNo') Which Returns
	//TRUE :: User Selected ('Y')
	//FALSE :: User Sleceted ('N')
	return yesOrNo;


}//END CONFRIM_SELECTION



size_t seatSelection(const double ticketArray[], const double charityPercent) {


	/// ***  INITILIZATION  *** ///
	bool validInput = false;

	// User Input
	int userInput = '\0';

	// Returned Info
	size_t seatSelection = 0;


	/// ***  INITIL TEXT AND PRINTING OF OPTIONS  *** ///
	// Initil Text -- What Guests Will See Before Proceeding 
	// --or-- 
	// Making a Mistake
	printf(
		"#######################################################################\n"
		"\n"
		"                     Hello welcome to Biles Big Game\n"
		"\n"
		"#######################################################################\n"
		"#######################################################################\n"
		"\n"); // END BEGGINING TEXT PRINT


	/// ***  LOOPS FOR ALL ELEMENTS IN ('SEATING_CHOICES_SIZE')  *** ///
	// Prints Out All Seating Choices From Predefined ('SEATING_CHOICES_PTR')
	for (size_t i = 0; i < SEATING_CHOICES_SIZE; i++) {


		/// ***  SEATING CHOICES PRITING  *** ///
		// Prints Out All Seat Choices
		printf("                     %s at $%.2lf\n", *SEATING_CHOICES_PTR[i], ticketArray[i]);


	} // END SEAT PRINTING FOR LOOP

	//Spacer
	puts(" ");

	// Buffer Text
	puts("#######################################################################");
	puts("#######################################################################");

	/// ***  PRINTING OUT CHARITY PERCENTAGE  *** ///
	// Prints Out Filler Text With Charity Percentage Attached
	printf(
		"\n"
		"                      Where %.2lf%% of tonights procedes\n"
		"                      will be goings to the: Getting\n"
		"                      Lost in the Rain and Pina Colada\n"
		"                      Fund Against Yoga!\n\n"
		"                               Entry: ", charityPercent
	);// END CHARITY PERCENTAGE PRINT


	/// ***  DO-WHILE UNTILL USER SEAT SELECTION IS VALID  *** /
	// Seat Selection -- Untill a Valid Input is Given
	do {


		/// ***  GETTING USER INPUT  *** ///
		// User Input
		userInput = getchar();
		clearBuffer();

		// Buffer Text
		puts("#######################################################################");


		/// ***  VALIDATION FOR LOOP FOR ALL ELEMENTS IN TICKET CHOICES  *** ///
		// Loops Through All Elements Using the ('SEATING_CHOICES_SIZE') Definition
		// With an Extra Loop For the Quit Option
		for (size_t i = 0; i < SEATING_CHOICES_SIZE + 1; i++) {


			/// ***  CHECK FOR VALID INPUT *** ///
			// If Input is Inside Valid Input Array ('SEATING_CHOICES_VAL_INPIT')
			if (toupper(userInput) == SEATING_CHOICES_VAL_INPUT[i]) {


				/// ***  CONFIRMING USER INPUT  *** ///
				// Calls ('confirmSelection') with ('userInput') to Validate Choice
				// ('T' -or- 'F')
				validInput = confirmSelection(toupper(userInput), i);


				/// ***  ASSIGNING RETURN SELECTION  *** ///
				// Assigns ('seatSelection') to array position ('i') for returning
				seatSelection = i;


			}//END CONFIRMATION CHECK


		} //END VALIDATION FOR LOOP


		/// ***  INVALID INPUT  *** ///
		// Invalid Input
		if (!validInput) {


			/// ***  REMINING USER OF VALID ENTRY  *** ///
			// Reminds User of Correct Input
			puts("#######################################################################");
			puts("   Incorrect entry... Please enter C, M, or U for valid selection!\n");
			printf("                               Entry: ");


		}// END INVALID CHECK


	} while (!validInput);// Do untill ('validInput') is Set to True


	/// *** RETURN STATEMENT -- SIZE_T  -- ('seatSelection')  *** ///
	// Returns :(SIZE_T): ('seatSelection') -- Postion of Selected Seat ('i')
	return seatSelection;


}// END SEAT_SELECTION



size_t ticketSelection(void) {


	/// ***  Initilizaiton  *** ///
	bool validInput = false;

	// User Input
	unsigned int userInput = 0;
	size_t userTicketSelection = 0;

	/// ***  INITIL TEXT PRITING  *** ///
	// Initial text
	puts("#######################################################################");
	puts(" ");
	puts("    Great! Now make a selection of how many tickets you'd like.");
	puts(" ");
	puts("#######################################################################");
	puts("#######################################################################");
	puts(" ");


	/// ***  FOR ALL ELEMENTS IN TICKET CHOICES  *** ///
	// Prints Out All Ticket Choices
	for (size_t i = 1; i < TICKET_CHOICES_SIZE + 1; i++) {


		// Priting of choices (Formated)
		printf("                      %llu. %s\n", i, *TICKET_CHOICES_PTR[i - 1]);


	} // END PRITNING OPTIONS FOR LOOP


	//Spacer
	puts(" ");

	//Filler Text
	printf("%s", "                            Entry: ");


	/// ***  DO-WHILE UNTILL VALID TICKET SELECTION FROM USER IS ENTERED  *** ///
	// Ticket Selection -- Untill Valid Selection Made
	do {


		/// ***  GETTING USER INPUT  *** //
		//User Input
		scanf("%i", &userInput);
		clearBuffer();

		//Buffer Text
		puts("#######################################################################");


		/// ***  VALIDATION FOR LOOP FOR ALL ELEMENTS IN ('TICKET_CHOICES_VAL_INPUT')  *** ///
		// Loops Through All Elements Using the ('TICKET_CHOICES_SIZE') Definition
		for (size_t i = 0; i < TICKET_CHOICES_SIZE; i++) {


			/// ***  CHECK FOR VALID INPUT *** ///
			// If Input is Inside Valid Input Array ('TICKET_CHOICES_VAL_INPIT')
			if (userInput == TICKET_CHOICES_VAL_INPUT[i]) {


				/// ***  CONFIRMING USER INPUT  *** ///
				// Calls ('confirmSelection') with ('userInput') to Validate Choice
				// ('T' -or- 'F')
				validInput = confirmSelection(toupper(userInput), i);

				userTicketSelection = i;

			}//END CONFIRMATION CHECK 


		} // END VALIDATION FOR LOOP


		/// ***  REPRINTING OPTIONS  *** ///
		// If Invalid Input Reinforms User of Correct Choices
		if (!validInput) {


			// Repritning of options
			puts("#######################################################################");
			puts("  Incorrect entry... Please enter 1, 2, 3, or 4 for valid selection!");
			puts(" ");
			printf("                               Entry: ");


		} // END REPRITNING OPTIONS


	} while (!validInput);// Loop Until ('validInput') is True


	/// ***  RETURN -- UNSIGNED INT -- ('userInput') *** //
	// Returns :(UNSIGNED INT): -- ('userInput') After Confirmed as Correct Selection
	return userTicketSelection;


}// END TICKET_SELECTION



double calculateTotal(const double* price, const size_t numberOfTickets) {


	/// ***  RETURN -- DOUBLE  -- ('return')  *** ///
	// Returns :(DOUBLE): -- DOUBLE ('price') Multiplied by INT ('numberOfTickets')
	return *price * numberOfTickets;


}// END CALCULATE_TOTAL



double giveToCharity(const double beforeCharity, const double charityPercentage) {


	// ***  RETURN -- DOUBLE -- ('return') *** //
	// Returns :(DOUBLE): -- DOUBLE ('beforeCharity') Multiplied by DOUBLE ('charityPercentage')
	return beforeCharity * charityPercentage;


}// END GIVE_TO_CHARITY



void updateTicketsSold(unsigned int* seatSaleArrayElement, const size_t seatSelection, const size_t numberOfTickets) {


	/// ***  NOTE  ** ///
	// Requires Manual Addition For All New Seating Options


	/// ***  SWITCH BASED OFF USER SELECTION  *** ///
	// Switch Based Off User's Selection of Seat -- Adds ('numberOfTickets') to ('seatSaleArrayElement')
	switch (seatSelection) {


	case 0: // Courtside Seating

		*seatSaleArrayElement += (unsigned int)numberOfTickets;

		break;// END C::0


	case 1: // Middle-Level Seating

		*seatSaleArrayElement += (unsigned int)numberOfTickets;

		//break;// END C::1


	case 2: // Upper-Level Seating

		*seatSaleArrayElement += (unsigned int)numberOfTickets;

		break;// END C::2


	default: // Default Case

		break;// END C:DEF


	} // END SWITCH FOR ('seatSelection')


} // END UPDATE_TICKETS_SOLD



void updateSeatSales(double* seatSaleArrayElement, const size_t seatSelection, const double amountAfterCharity) {


	/// ***  NOTE  ** ///
	// Requires Manual Addition For All New Seating Options


	/// ***  SWITCH BASED ON USER SELECTION OF SEAT *** //
	// Based Off User's Selection of Seat -- Adds ('amointAfterChartiy') to ('seatSalesArrayElement')
	switch (seatSelection) {


	case 0:// Courtside Seating

		*seatSaleArrayElement += amountAfterCharity;

		break;// END C::0


	case 1:// Middle-Level Seating

		*seatSaleArrayElement += amountAfterCharity;

		break;// END C::1


	case 2:// Upper-Level Seating

		*seatSaleArrayElement += amountAfterCharity;

		break;// END C::2


	default:// Default Case


		break;// END C::DEF


	} // END SWITCH FOR ('seatSelection')


}// END UPDATE_SEAT_SALES



void updateCharityTotals(double* charityArrayElement, const size_t seatSelection, const double givenToCharity) {


	/// ***  NOTE  ** ///
	// Requires Manual Addition For All New Seating Options


	/// ***  SWITCH BASED ON USER SELECTION OF SEAT *** //
	// Based Off User's Selection of Seat -- Adds ('amointAfterChartiy') to ('seatSalesArrayElement')
	switch (seatSelection) {


	case 0:// Courtside Seating

		*charityArrayElement += givenToCharity;

		break;// END C::0


	case 1:// Middle-Level Seating

		*charityArrayElement += givenToCharity;

		break;// END C::1


	case 2:// Upper-Level Seating

		*charityArrayElement += givenToCharity;

		break;// END C::2


	default:// Default Case


		break;// END C::DEF


	} // END SWITCH FOR ('seatSelection')


}// END UPDATE_SEAT_SALES