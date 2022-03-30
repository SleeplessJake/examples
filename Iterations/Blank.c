// JACOB BILES
// ITERATION 01
// CS 2060
// DUE -- 3/31/2022





////##########################################////
////####                                  ####////
////####**#            TODO            #**####////
////####                                  ####////
////##########################################////

/* ADD PROGRAM DESC*/
/* CLEAN UP COMMENTING -- FUNCTIONS */



////##########################################////
////####                                  ####////
////####**#          LIBRARIES         #**####////
////####                                  ####////
////##########################################////


// Standard Input Output
#include <stdio.h>


// c Type
#include <ctype.h>


// Standard Bool
#include <stdbool.h>





////##########################################////
////####                                  ####////
////####**#  DEFINITIONS // CONSTANTS  #**####////
////####                                  ####////
////######          ADMIN_INFO          ######////
////####                                  ####////
////##########################################////



/// ### DEFINITION ### // ADMIN_PIN ///
/// Correct PIN Number for USER INPUT
#define ADMIN_PIN 4932



/// ### DEFINITION ### // MAX_LOGON_ATTEMPTS ///
//  Max Logon Attempts
//  For Use in ('dailyLogOn') ### FUNCTION ###
#define MAX_LOGON_ATTEMPTS 3



/// ### DEFINITION ### // LOGIN_QUIT_NUMBER ///
//  The Last Spot in ('SEATING_CHOICES_VAL_INPUT') ### DEFINITION ### //
//  For Use in ('isLoggedOn')
//  ('Q') Option
#define LOGIN_QUIT_NUMBER 3





///###########################################///
///####                                   ####///
///######          SEATING_INFO         ######///
///####                                   ####///
///###########################################///



///  ### DEFINITION ### // SEATING_CHOICES_SIZE ///
//   Number of Seating Choices
//   Excludes Quit Which is Represented With +1 in ('SEATING_CHOICES_VAL_INPUT') ARRAY
#define SEATING_CHOICES_SIZE 3



/// ### DEFINITION ### // SEATING_CHOICE_PRICE_RANGE ///
//  Range of Price Seats Can Be
//  [2] Slots for MIN/MAX
//  INPUT For ('changePrice') ### FUNCTION ###
const double SEATING_CHOICE_PRICE_RANGE[SEATING_CHOICES_SIZE][2] = {


	{200, 500} /* MIN - Courtside Seating - MAX */,
	{75, 200}  /* MIN - Mid-Level Seating - MAX */,
	{9.99, 75} /* MIN - Upper-Level Seating - MAX */,


}; ///  ## END ##  // ### DEFINITION ### // SEATING_CHOICE_PRICE_RANGE ///



/// ### DEFINITION ### // SEATING_CHOICES_VAL_INPUT ///
//  Valid CHAR INPUT from USER 
//  Each Slot is a Valid Entry
//  +1 For Inclusion of Quit Option -- 'Q'
const char SEATING_CHOICES_VAL_INPUT[SEATING_CHOICES_SIZE + 1] = {


	'C' /* Courtside Seating */,
	'M' /* Mid-Level Seating */,
	'U' /* Upper-Level Seating */,
	'Q' /* Quit */,


};///  ## END ##  // ### DEFINITION ### // SEATING_CHOICE_VAL_INPUT ///



/// ### DEFINITION ### // ***  TICKET_CHARACTER_ARRAY_POINTER  *** ///
//  Allows For Easier Printing of Name Options
//  Max Size For Each String is 32 Characters (Exclusive For ('\0') in [32])
const char* SEATING_CHOICES_PTR[SEATING_CHOICES_SIZE][32] = {


{"(C)Courtside Seats" } /* Courtside Seating */,
{"(M)Middle Level Seats"} /* Mid-Level Seating */,
{"(U)Upper Level Seats"} /* Mid-Level Seating */,


};///  ## END ##  // ### DEFINITION ### // SEATING_CHOICE_PTR ///





///##########################################///
///####                                  ####///
///####           CHARITY_INFO           ####///
///####                                  ####///
///##########################################///



/// ### DEFINITION ### // CHARITY_PERCENTAGE_RANGE ///
//  Range of Price Seats Can Be
//  [2] Slots for MIN/MAX
//  INPUT For ('changePrice') ### FUNCTION ###
const double CHARITY_PERCENTAGE_RANGE[2] = { 0.04, .25 };





///##########################################///
///####                                  ####///
///####           TICKET_INFO            ####///
///####                                  ####///
///##########################################///



/// ### DEFINITON ### // TICKET_CHOICES_SIZE ///
// Number of Ticket Options
// For ('TICKET_CHOICES_VAL_INPUT') and ('TICKET_CHOICES_PTR') ### DEFINITIONS ###
#define TICKET_CHOICES_SIZE 4



/// ### DEFINITION ### // TICKET_CHOICES_VAL_INPUT ///
//  Valid INT INPUT From USER 
//  Each Slot is a Valid Entry
const unsigned int TICKET_CHOICES_VAL_INPUT[TICKET_CHOICES_SIZE] = {


	1 /* 1 Tickets,[0] */,
	2 /* 2 Tickets,[1] */,
	3 /* 3 Tickets,[2] */,
	4 /* 4 Tickets,[3] */,


};//  ## END ##  // ### DEFINITION ### // TICKET_CHOICES_VAL_INPUT



/// ### DEFINITION ### // ***  TICKET_CHARACTER_ARRAY_POINTER  *** ///
// Allows For Easier Printing of Name Options
// Max Size For Each String is 32 Characters (Exclusive For ('\0') in [32])
const char* TICKET_CHOICES_PTR[TICKET_CHOICES_SIZE][32] = {


{"Single Pack (1 ticket)" } /* 1 Tickets,[0] */,
{"Double Pack (2 tickets)"} /* 2 Tickets,[1] */,
{"Triple Pack (3 tickets)"} /* 3 Tickets,[2] */,
{"Family Pack (4 tickets)"} /* 4 Tickets,[3] */,


};//  ## END ##  // ### DEFINITION ### // TICKET_CHOICES_PTR





///##########################################///
///####                                  ####///
///####**      FUNCTION_PROTOTYPES     **####///
///####                                  ####///
///##########################################///



/// ***  CLEAR_BUFFER  *** ///
//       ### DESC ###       //
/*  Clear Buffer -- Uses the getChar function to detect when the BUFFER is left with the new line character.
 *  If not it will continue to clear out the buffer leaving the new line character ('\n') ending the function.   */
void clearBuffer(void);



/// ***  ADMIN_LOG_ON  *** ///
//       ### DESC ###       //
/*  Admin Log On -- Gathers USER INPUT then compares it to ('ADMIN_PIN') ### Definition ###.
 *
 *  If the INPUT matches the PIN number -- OUTPUTS : TRUE
 *  Otherwise -- OUTPUTS : FALSE                                                          */
bool adminLogOn(void);



/// ***  DAILY_LOG_ON  *** ///
//       ### DESC ###       //
/*  Daily Log On - The inital start to the program.
 *
 *  It PROMPTS for input from the USER for the ('ADMINT_PIN') ### DEFINITION ### up to (<= 3) THREE times
 *
 *  After ONE failed attempt -- OUTPUTS : DIFFERENT PROMPT
 *  After the THIRD FAILED log on attempt -- OUTPUTS : FALSE
 *  If INPUT matches ('ADMIN_PIN') ### DEFINITION ### -- OUTPUTS : TRUE
 *
 *  Using the ('adminLogOn') ### FUNCTION ### to validate authenticity of INPUT                        */
bool dailyLogOn(void);



/// ***  CHANGE_PRICE  *** ///
//       ### DESC ###       //
/*  Change Price -- Takes INPUT from USER to set the price of the days tickets.
 *  It INPUTS a MIN/MAX alongside a slot from ('seatPrices[]') ARRAY.
 *  Continuing to reprompt the user untill a VALID entry is made then updating the ARRAY slot to this Value  */
void changePrice(const double, const double, double*);



/// ***  DAY_SET_UP  *** ///
//       ## NOTE ##       //
/*  ANY NEW SEATING OPTIOSN WILL BE REQUIRED TO BE SET UP HERE
 *  IF NOT SET UP PROPERLY THE RESULT WILL NOT HAVE A PRICE SET  */
 //     ### DESC ###      //
 /*  Day Set Up -- Uses a FOR LOOP to iterate through each slot in ('seatPrices') ARRAY
 *
 *   Determining if the MAX is GREATER('>') than ONE ('1')
 *   If it is then ('charityPercent') is set up instead
 *
 *   In Both Cases using the Iterator to dertermien which MIN / MAX range is applicable. */
void daySetUp(double[], double*);



/// ***  CONFIRM_SELECTION  *** ///
//          ### DESC ###         //
/*  Confirm Selection -- PROMPTS and INPUTS from USER to determine their entry is what they meant
 *
 *  If they Select No -- OUTPUTS FALSE
 *  If they Select Yes -- OUTPUTS TRUE
 *  If Neither -- OUTPUTS REPROMPT
 *
 *  Determines if INT or CHAR based on if value is GREATER ('>') than 31 based on special ASCII CHAR */
bool confirmSelection(const int, const size_t);



/// ***  SEAT_SELECTION  *** ///
//        ### DESC ###        //
/*  Seat Selection -- PROMPTS and INPUTS USER ('ticketSelection') based on
 *  the valid choices in ('TICKET_CHOICE_VAL_INPUT') ### DEFINITION ###
 *
 *  If they select a VALID selection -- OUTPUTS SIZE_T
 *  If INVALID selection -- REPROMPTS USER
 *
 *  OUTPUTS a SIZE_T representing the USER selection of seating          */
size_t seatSelection(const double[], const double);



/// ***  TICKET_SELECTION  *** ///
//         ### DESC ###         //
/*  Ticket Selection -- PROMPTS and INPUTS USER ('seatSelection') based on
 *  the valid choices in ('SEAT_CHOICE_VAL_INPUT') ### DEFINITION ###
 *
 *  If they select a VALID selection -- OUTPUTS SIZE_T
 *  If INVALID selection -- REPROMPTS USER
 *
 *  OUTPUTS a SIZE_T representing the USER selection of tickets          */
size_t ticketSelection(void);



/// ***  CALCULATE_TOTAL  *** ///
//         ### DESC ###        //
/*  Calculate Total -- Calculates the USERS total
 *  Takes USERS ('usersSeatingChoice') and MULTIPLIES (*) by USERS ('usersTicketSelection')
 *
 *  OUTPUTS a DOUBLE to represent the USERS total                                        */
double calculateTotal(const double*, const size_t);



/// ***  GIVE_TO_CHARITY  *** ///
//         ### DESC ###        //
/*  Give To Charity -- Takes ('usersTotal') and MULTIPLES ('*') by the days charity percentage
 *
 *  OUTPUTING a DOUBLE to represent the share charity gets from the sale                    */
double giveToCharity(const double, const double);



/// ***  USER_PAYMENT  *** ///
//       ### DESC ###       //
/*  User Payment -- Ficticious User Payment
 *
 *  PROMPTS USER and INPUTS from USER their zipcode.
 *  Which must be GREATER than ('>') 9999 but LESS than ('<') 100000
 *
 *	If VALID -- PASS STEP
 *	If INVALID -- REPROMPT USER
 *
 *  Eventually a Credit/Debit payment will be done here           */
void userPayment();



/// ***  UPDATE_TICKETS_SOLD  *** ///
//           ### DESC ###          //
/*  Update Tickets Sold -- INPUTS ('userTicketSelection') and a slot from ('ticketsSold[]') ARRAY
 *
 *  Determining the slot based on ('userTicketSlection') upon call*/
void updateTicketsSold(unsigned int*, const size_t);



/// ***  UPDATE_TICKETS_SOLD  *** ///
//           ### DESC ###          //
/*  Update Seat Sales -- INPUTS ('actualProfit') -- (The ('usersTotal') - ('charityTake') ) -- and a slot from ('seatsSold[]') ARRAY
 *
 *  Determining the slot based on ('userTicketSlection') upon call*/
void updateSeatSales(double*, const double);



/// ***  UPDATE_CHARITY_TOTALS  *** ///
//       ### DESC ###       //
/*  Update Charity Totals -- INPUTS ('charityTake') from ('giveToCharity') ### FUNCTION -- and a slot from ('charityTotals[]') ARRAY
 *
 *  Determining the slot based on ('userTicketSlection') upon call                                                         */
void updateCharityTotals(double*, const double);



/// ***  PRINT_RECIEPT *** ///
//       ### DESC ###       //
/*  Print Receipt -- Starts off by PROMPTING USER and INPUTING if they want a reciept
 *
 * If YES (VALID) -- OUTPUT TRUE -- CONTINUE SALE
 * If NO (VALID) -- OUTPUT FALSE -- END SALE
 * Else INVALID -- REPROMPT USER
 *
 * If TRUE -- Takes all INPUTS and OUTPUTS Formatted Reciept-type-printout         */
void printRecipt(const double, const double, const size_t, const size_t, const unsigned int*);



bool dailySales(double[], double, unsigned int[], double[], double[]);



////##########################################////
////####                                  ####////
////####**              MAIN            **####////
////####                                  ####////
////##########################################////



//// ####**  MAIN  **#### ///
int main(void) {





	////##########################################////
	////####                                  ####////
	////######        INITIZILIZATION       ######////
	////####                                  ####////
	////##########################################////



	// Admin Initilization
	// Initilized to FALSE
	bool isLoggedOn = false; // Admin Logged On


	// Seats and Tickets Initilization
	// Initilized to NULL character ('\0') -- 0 INT
	double seatPrices[SEATING_CHOICES_SIZE] = { '\0', '\0', '\0' }; // Daily Seat Prices 
	unsigned int ticketsSold[SEATING_CHOICES_SIZE] = { '\0' , '\0', '\0' }; // Daily Total Tickets Sold
	double seatSales[SEATING_CHOICES_SIZE] = { '\0', '\0', '\0' }; // Daily Seats Sold


	// Charity Initilization
	// Initilized to NULL character ('\0') -- 0 INT
	double charityPercentage = '\0'; // Charity Percentage
	double charityTotals[SEATING_CHOICES_SIZE] = { '\0', '\0', '\0' }; // Daily Charity Totals

	// Filler Text
	// Border Text
	puts("#######################################################################");





	////##########################################////
	////####                                  ####////
	////######          ADMIN_LOGON         ######////
	////####                                  ####////
	////##########################################////


	// Calls ('dailyLogOn'); Function Getting PROMPTING USER for PIN
	// Calling ('adminLogon') to Determine ('T' -or- 'F') for PIN INPUT
	// 
	// Determining if They Can Log on Within 3 Attempts
	// 
	// If VALID ENTRY - OUTPUTS TRUE
	// If INVALID ENTRY - OUTPUTS FALSE
	isLoggedOn = dailyLogOn();





	////##########################################////
	////####                                  ####////
	////######       SUCESSFUL_LOGON        ######////
	////####                                  ####////
	////##########################################////

	/// ***  SUCESSFUL LOGON CHECK  *** ///
	// If the USER INPUTED ('ADMIN_PIN') ### DEFINITON ### for ('dailyLogOn') ### FUNCTION ###
	if (isLoggedOn) {


		dailySales(seatPrices, charityPercentage, ticketsSold, seatSales, charityTotals);


	}//  ## END ##  // SUCCESSFUL_LOGON_CHECK // isLoggedOn



	////##########################################////
	////####                                  ####////
	////######      UNSUCESSFUL_LOGON       ######////
	////####                                  ####////
	////##########################################////

	/// ***  Unsucessful Logon -- (FALSE -- Initial Login) --  *** ///
	// The User Maxed Out Attempts of the Admin Pin Authentication
	else {


		/// ***  PRITING OUT FAILED LOGON  *** ///
		// Shows User Failed Based on 'MAX_LOGON_ATTEMPTS' Condition
		printf("             Logon attempts exceded %u! Seek admin!  ", MAX_LOGON_ATTEMPTS);


	}// END UNSUCESSFUL LOGON CHECK





	////##########################################////
	////####                                  ####////
	////######      RETURN 0 FOR MAIN       ######////
	////####                                  ####////
	////##########################################////

	//Returns :(INT): -0- for Sake of Proper Return for Main
	return 0;


} /////  ## END ##  // ####**  MAIN  **#### /////



//// #****#  FUNCTIONS  #****# ////

/// ****  CLEAR BUFFER  **** ///
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


/// ****  ADMIN LOGON  **** ///
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
	unsigned int userLogon = '\0';


	/// *** GETTING USER INPUT -- UNSGINED INT -- userLogon*** ///
	scanf("%ui", &userLogon);
	clearBuffer();
	puts(" ");


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



bool dailyLogOn(void) {

	unsigned int attempts = '\0';
	bool isLoggedOn = false;

	/// ***  DO WHILE UNTILL ADMIN LOGGED IN OR FAILED AUTHENTICATE  *** ///
	// Continues Untill
	// User Enters ('ADMIN_PIN') Deefition -- TRUE
	// Attemps Exceed 3
	do {



		/// ***  USER FAILED ENTRY CHECK  *** ///
		// If User Has Failed To Log In at Least Once
		if (attempts >= 1) {



			/// ***  REPROMPT TO USER  *** ///
			// Shows User Number of Attempts
			printf("#####################  Attempt (Attempts (%u/%u)  #######################\n", attempts + 1, MAX_LOGON_ATTEMPTS);
			puts("#######################################################################");
			puts(" ");
			printf("%s", "           Error! Please enter the admin loging PIN #: "); // Entry Line



			/// ***  CHECKING USER INPUT CALLING ('adminLogOn')  *** ///
			isLoggedOn = adminLogOn();
			puts("#######################################################################");


		}//  ## END ##  // ## IF ## // *** REPROMPT_TO_USER  *** //



		/// ***  INITIL_PROMPT_TO_USER  *** ///
		//The First Time the USer is Asked For the PIN Number
		else {


			/// ***  INITIL PROMPT TO USER  *** ///
			puts("#######################################################################");
			puts(" ");
			printf("%s", "              Please enter the admin loging PIN #: ");// Entry Line 



			/// ***  CHECKING USER INPUT CALLING ('adminLogOn')  *** ///
			isLoggedOn = adminLogOn();
			puts("#######################################################################");


		}//  ## END ##  // ## ELSE ## // ***  INITIL PROMPT CHECK  *** //


		/// ***  INCREMENTATION OF ATTEMPTS  *** ///
		// Increaments Attempts
		attempts++;


	} while ((!isLoggedOn) && (attempts < MAX_LOGON_ATTEMPTS)); /*  Do untill('validInput') is Set to True && ('attempts') is below('MAX_LOGON_ATTEMPTS') Definition  */


	// ## OUTPUT ## //
	// ##  Bool  ## //
	/* TRUE: Sucessful Log On
	 * Attempts Less Than 3 AND ('userInput') is the Admin PIN Number

	 * FALSE: Failed Log On
	 * Attempts Greater Than 3 */
	return isLoggedOn;

}


/// ****  CHANGE PRICE **** ///
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
	// User Input
	double userInput = '\0';

	bool validChoice = false;


	/// ***  CHECK FOR PRICE  *** ///
	// Intil Prompt of Price -- Before Error is Made
	// If ('max') Greater Than 1 -- Ensuring a Percentage
	if (max > 1) {


		/// ***  INITIL PROMPTING OF USER FOR PRICE OR PERCENTAGE  *** ///
		// For Price Range
		puts("#######################################################################");
		puts(" ");
		printf("             Please enter a price above $%.2lf to $%.2lf\n", min, max);
		printf("                     Enter Between Range: $");


	}// END PRICE CHECK


	/// ***  CHECK FOR PRICE  *** ///
	// Intil Prompt of Price -- Before Error is Made
	// If ('max') less Than 1 -- Ensuring a Percentage
	else {


		/// ***  INITIL PROMPTING OF USER FOR PRICE OR PERCENTAGE  *** ///
		// For Percentage Range
		puts("#######################################################################");
		puts(" ");
		printf("             Please enter a percentage above %.2lf%% to %.2lf%%\n", min, max);
		printf("                     Enter Between Range: ");


	}// END PERCENTAGE CHECK


	/// ***  DO-WHILE UNTILL A VALID ENTRY IS GIVEN  *** ///
	// Continues Untill a Valid Price or Percentage is 
	// Given From the Admin That is Within the Given
	// ('min') and ('max') Range
	do {


		/// ***  GETTING USER INPUT  *** ///
		//Get Price From Admin Input
		scanf("%lf", &userInput);
		clearBuffer();
		puts(" ");
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
			if (max >= 1) {


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


			///  *** PRICE PRITNING  *** ///
			// Check to see If Price or Percentage
			if (max > 1) {


				/// ***  REPRINTING OF OPTIONS  *** ///
				// Reprints the Correct Options for the User
				puts("#######################################################################");
				puts(" ");
				printf("  Error $%.2lf is out of range! The range is above $%.2lf to $%.2lf\n", userInput, min, max);
				printf("                      Enter between Range: ");


			}// END REPRINTING PRICE OPTIONS


			///  *** PRICE PRITNING  *** ///
			// Check to see If Price or Percentage
			else {


				/// ***  REPRINTING OF OPTIONS  *** ///
				// Reprints the Correct Options for the User
				puts("#######################################################################");
				puts(" ");
				printf("  Error %.2lf%% is out of range! The range is above %.2lf%% to %.2lf%%\n", userInput, min, max);
				printf("                     Enter between Range: ");



			}


		} // END INVALID INPUT CHECK


	} while (!validChoice);// Do untill ('validInput') is Set to True


	/// ***  ASSINGING VALUES  *** //
	// Assigns ('userInput') to Deference of ('*price')
	*price = userInput;


}// END CHANGE_PRICE


/// ****  DAY SET UP  **** ///
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
			changePrice(SEATING_CHOICE_PRICE_RANGE[i][0], SEATING_CHOICE_PRICE_RANGE[i][1], ticketPTR);

			break; // END C::0


		case 1:// Mid-Level Seating

			// MIN(E): 75      MAX(I): 200
			changePrice(SEATING_CHOICE_PRICE_RANGE[i][0], SEATING_CHOICE_PRICE_RANGE[i][1], ticketPTR);

			break; //END C::1


		case 2:// Upper-Level Seating

			// MIN(E): 10       MAX(I):75
			changePrice(SEATING_CHOICE_PRICE_RANGE[i][0], SEATING_CHOICE_PRICE_RANGE[i][1], ticketPTR);

			break;//END C::2


		default:// Default Case

			break;//END C::DEF


		} // END SWITCH FOR EACH ELEMENT IN ('seatArray[]')


	}// END TICKET SETUP LOOP FOR EACH ELEMENT IN ('seatArray[]')


	/// ***  PRICE CHANGE  *** ///
	// Calls ('changePrice') With a Predetermined
	// Range and Passes Adress or Pointer
	changePrice(CHARITY_PERCENTAGE_RANGE[0], CHARITY_PERCENTAGE_RANGE[1], charityPercent);


}//END DAY_SETUP


/// ****  CONFIRM SELECTION  **** ///
//Short DESC:: Prompts the user with their input and confirms selection. For Characters
// 
//Prints: Prompts user (includes carried data), reprompts on error
// 
//Requires:: VOID
// 
//Input:: const int input(selective)
//Output:: BOOL -- T :: Yes -- F :: NO
bool confirmSelection(const int input, const size_t nameLocation) {

	/// ***  INITILIZATION *** ///
	bool validInput = false;

	// User Input
	int userInput = '\0';
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
			puts(" ");
			printf("   You entered (%c)--%s, Is this what you meant? (Y/N)\n", input, *SEATING_CHOICES_PTR[nameLocation]);
			printf("%s", "                             Entry: ");


		}// END SALE CHECK


		/// ***  PROMPTING USER FOR INPUT -- Quting System *** //
		//Checks Less Often Case -- If ('Q')
		else {


			/// ***  PROMPTING USER FOR INPUT -- ('Y' -or- 'N')  *** ///
			//Filler Text
			puts("#######################################################################");
			puts(" ");
			printf("         You entered (%c)--Quit, Is this what you meant? (Y/N)\n", input);
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
		puts(" ");
		printf(" You entered (%i)--%s, Is this what you meant? (Y/N)\n", input, *TICKET_CHOICES_PTR[nameLocation]);
		printf("%s", "                             Entry: ");


	}// END INT CHECK


	/// ***  DO-WHILE LOOP FOR CHECKING VALID INPUT -- ('Y') -or- ('N') --  *** ///
	// Continues Untill a Valid Choice of Yes('Y') or No('N') is Made 
	do {


		/// ***  GETTING USER INPUT -- CHARACTER -- ('userInput')  *** ///
		// Gets the Users input
		userInput = getchar();
		clearBuffer();
		puts(" ");

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
			puts(" ");
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


/// ****  SEAT SELECTION  **** ///
//Short DESC:: Prompts User for Their Choice of Seat -- Validates Correct Entry and Confirms Selection
// 
//Prints: Prompts user (includes carried data), reprompts on error
// 
//Requires:: function ('confirmSelection'), function ('clearBuffer'), ('SEATING_CHOICES_SIZE') Definition, ('SEATING_CHOICES_VAL_INPUT') Definition
// 
//Input:: const double seatingArray[] ('seatPrices'), const double charityPercent ('charityPercentage')
//Output: SIZE_T -- Postion of Selected Seat in ('SEATING_CHOICES_VAL_INPUT') which position matches ('SEATING_CHOICES_POINTER') for Pritning Selection
size_t seatSelection(const double seatingArray[], const double charityPercent) {


	/// ***  INITILIZATION  *** ///
	bool validInput = false;

	// User Input
	int userInput = '\0';

	// Returned Info
	size_t seatSelection = '\0';


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
		printf("                     %s at $%.2lf\n", *SEATING_CHOICES_PTR[i], seatingArray[i]);


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
		"                      Fund Against Yoga!\n"
		"\n"
		"                               Entry: ", charityPercent
	);// END CHARITY PERCENTAGE PRINT


	/// ***  DO-WHILE UNTILL USER SEAT SELECTION IS VALID  *** /
	// Seat Selection -- Untill a Valid Input is Given
	do {


		/// ***  GETTING USER INPUT  *** ///
		// User Input
		userInput = getchar();
		clearBuffer();
		puts(" ");
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
			puts(" ");
			puts("   Incorrect entry... Please enter C, M, or U for valid selection!\n");
			printf("                               Entry: ");


		}// END INVALID CHECK


	} while (!validInput);// Do untill ('validInput') is Set to True


	/// *** RETURN STATEMENT -- SIZE_T  -- ('seatSelection')  *** ///
	// Returns :(SIZE_T): ('seatSelection') -- Postion of Selected Seat ('i')
	return seatSelection;


}// END SEAT_SELECTION


/// ****  TICKET SELECTION  **** ///
//Short DESC:: Prompts User for Their Choice of Seat -- Validates Correct Entry and Confirms Selection
// 
//Prints: Prompts user (includes carried data), reprompts on error
// 
//Requires:: function ('confirmSelection'), function ('clearBuffer'), ('TICKET_CHOICES_SIZE') Definition, ('TICKET_CHOICES_VAL_INPUT') Definition
// 
//Input:: VOID
//Output: SIZE_T -- Postion of Selected Seat in ('TICKET_CHOICES_VAL_INPUT') which position matches ('TICKET_CHOICES_POINTER') for Pritning Selection
size_t ticketSelection(void) {


	/// ***  Initilizaiton  *** ///
	bool validInput = false;

	// User Input
	unsigned int userInput = '\0';
	size_t userTicketSelection = '\0';

	/// ***  INITIL TEXT PRITING  *** ///
	// Initial text
	puts("#######################################################################");
	puts("                                                                       ");
	puts("    Great! Now make a selection of how many tickets you'd like.        ");
	puts("                                                                       ");
	puts("#######################################################################");
	puts("#######################################################################");
	puts("                                                                       ");


	/// ***  FOR ALL ELEMENTS IN TICKET CHOICES  *** ///
	// Prints Out All Ticket Choices
	for (size_t i = 1; i < TICKET_CHOICES_SIZE + 1; i++) {


		// Priting of choices (Formated)
		printf("                      %llu. %s\n", i, *TICKET_CHOICES_PTR[i - 1]);


	} // END PRITNING OPTIONS FOR LOOP


	//Filler Text
	puts(" ");
	printf("%s", "                             Entry: ");


	/// ***  DO-WHILE UNTILL VALID TICKET SELECTION FROM USER IS ENTERED  *** ///
	// Ticket Selection -- Untill Valid Selection Made
	do {


		/// ***  GETTING USER INPUT  *** //
		//User Input
		scanf("%i", &userInput);
		clearBuffer();
		puts(" ");

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

				userTicketSelection = i + 1;

			}//END CONFIRMATION CHECK 


		} // END VALIDATION FOR LOOP


		/// ***  REPRINTING OPTIONS  *** ///
		// If Invalid Input Reinforms User of Correct Choices
		if (!validInput) {


			// Repritning of options
			puts("#######################################################################");
			puts(" ");
			puts("  Incorrect entry... Please enter 1, 2, 3, or 4 for valid selection!");
			printf("                            Entry: ");


		} // END REPRITNING OPTIONS


	} while (!validInput);// Loop Until ('validInput') is True


	/// ***  RETURN -- UNSIGNED INT -- ('userInput') *** //
	// Returns :(UNSIGNED INT): -- ('userInput') After Confirmed as Correct Selection
	return userTicketSelection;


}// END TICKET_SELECTION


/// ****  CALCULATE TOTAL  **** ///
//Short DESC:: Calculates the User's Total Based on Seat Selection and # of Tickets
// 
//Prints:: VOID
// 
//Requires:: VOID
// 
//Input:: const double* price ('seatPrices[('userSeatSelection')]'), const size_t numberOfTickets('userTicketSelection')
//Output: DOUBLE -- The total Cost of the Transaction (Before Charity's Take)
double calculateTotal(const double* price, const size_t numberOfTickets) {


	/// ***  RETURN -- DOUBLE  -- ('return')  *** ///
	// Returns :(DOUBLE): -- DOUBLE ('price') Multiplied by INT ('numberOfTickets')
	return *price * numberOfTickets;


}// END CALCULATE_TOTAL


/// ****  GIVE TO CHARITY  **** ///
//Short DESC:: Calculates the Charity's Share From the Sale
// 
//Prints:: VOID
// 
//Requires:: VOID
// 
//Input:: const double* beforeCharity ('usersTotal'), const double charityPercentage ('charityPercentage')
//Output: DOUBLE -- The Total Amount the Charity Will Recieve 
double giveToCharity(const double beforeCharity, const double charityPercentage) {


	// ***  RETURN -- DOUBLE -- ('return') *** //
	// Returns :(DOUBLE): -- DOUBLE ('beforeCharity') Multiplied by DOUBLE ('charityPercentage')
	return beforeCharity * charityPercentage;


}// END GIVE_TO_CHARITY



void userPayment() {


	/// ***  INITILIZATION  *** //
	// User Input
	unsigned int userInput = '\0';
	bool isValidInput = false;


	/// ***  INITIL PROMPT TO USER  *** ///
	// Promp User for ZIPCODE
	puts("#######################################################################");
	puts("");
	puts("                   Please Enter your 5 Digit Zipcode");
	printf("%s", "                             Entry: ");

	/// ***  DO-WHILE UNTIL VALID ENTRY IS ENTERED -- code larger than 4 digits  *** ///
	// Continues Untill a Code Greater Than 4 Digits is Entered
	do {


		/// *** GETTING USER INPUT -- UNSIGNED INT ('userInput')  *** ///
		// Get User's Input for ZIPCODE
		scanf("%ui", &userInput);
		clearBuffer();

		//Filler Text
		puts("");
		puts("#######################################################################");


		///  *** VALID ZIPCODE ENTRY CHECK *** ///
		if (userInput > 9999 && userInput < 100000) {


			/// *** LOOP BREAK  *** //
			//Sets Validation to True (VALID ZIPCODE)
			isValidInput = true;


		}// END VALID ZIPCDE CHECK


		/// ***  INVALID ZIPCODE ENTRY CHECK  *** ///
		// Anything Besides UNSIGNED INT Greater Than 5 Digits Fails
		else {


			/// *** REPROMPTING USER OF ACCEPTABLE ENTRY  *** //
			//Filler Text
			puts("#######################################################################");
			puts("                                                                       ");
			puts("                    Error! Enter your 5 Digit Zipcode                  ");
			printf("%s", "                             Entry: ");


		}// END INVALID ZIPCODE CHECK


	} while (!isValidInput);// Continue untill ('isValidInput') is TRUE


}//END USER_PAYMENT


/// ****  UPDATE TICKETS SOLD  **** ///
// Short DESC:: Updates Position in ('ticketsSold') Based off Number of Seats Sold
// 
// NOTE:: Requires Manual Addition For All New Seating Options
// 
// Prints:: VOID
// 
// Requires:: VOID
// 
// Input:: unsigned int* seatSaleArrayElement ('ticketsSold'), const size_t seatSelection ('userSeatSelection'), const size_t numberOfTickets ('userTicketSelection')
// Output: VOID
void updateTicketsSold(unsigned int* ticketsSoldArrayElement, const size_t numberOfTickets) {

	//Updating Slot (+=) to Amount
	*ticketsSoldArrayElement += (unsigned int)numberOfTickets;


} // END UPDATE_TICKETS_SOLD


/// ****  UPDATE SEAT SALES  **** ///
// Short DESC:: Updates Position in ('seatSales') Based off Profit from Sale
// 
// NOTE:: Requires Manual Addition For All New Seating Options
// 
// Prints:: VOID
// 
// Requires:: VOID
// 
// Input:: unsigned int* seatSaleArrayElement ('actualProfit'), const size_t seatSelection ('userSeatSelection'), const size_t numberOfTickets ('userTicketSelection')
// Output: VOID
void updateSeatSales(double* seatSaleArrayElement, const double amountAfterCharity) {


	//Updating Slot (+=) to Amount
	*seatSaleArrayElement += amountAfterCharity;


}// END UPDATE_SEAT_SALES


/// ***  UPDATE_CHARITY_TOTALS  *** ///
//  ## DESC ##
/*  Updates a Postion Within the ('charityTotals[]') Array by Taking the
 *  ('userSeatSelection')
*/
//  ## NOTE ##
/*  Requires Manual Addition For All New Seating Options  */
//  ## INPUT ## 
/*  I: DOUBLE* ('CharityArrayElement ('actualProfit')'), Spot in Array ('charityTotals') Holding Charity Totals Based on Seat
 *  I: CONST SIZE_T ('seatSelection'), The User's Choice of Seat
 *  I: CONST DOUBLE ('giveToCharity'), The Amount To be Added to the Array Element  */
void updateCharityTotals(double* charityTotalsSpot, const double givenToCharity) {


	//Updates Position within ('charityTotals[]
	*charityTotalsSpot += givenToCharity;


}//  ## END ## // ### FUNCTION ### // ***  UPDATE_CHARITY_TOTALS  *** //



/// ***  PRINT_RECIPT  *** ///
//  ## DESC ##
/*  Updates Position in ('charityTotals[]') (+=) Based off Profit ('givenToCharity')  */
//  ## NOTE ##
/*  Requires Manual Addition For All New Seating Options  */
//  ## INPUT ## 
void printRecipt(const double userTotal, const double charityTake, const size_t userSeatSelection, const size_t userTicketSelection, const unsigned int* ticketsSoldArrayElement) {


	/// ***  INITILIZATION  *** ///
	bool isValidInput = false;

	//User Selects
	//Yes -- TRUE
	//NO -- FALSE
	bool isYesOrNo = '\0';

	// User Input
	int userInput = '\0';


	/// ***  INITIL PROMPT TO USER  *** ///
	//Prompts User
	puts("#######################################################################");
	puts("                       Would you like a Recipt?");
	printf("%s", "                             Entry: ");


	/// *** DO-WHILE UNTILL VALID ENTRY (YES OR NO IS GIVEN)  *** ///
	//Continues Untill User Enters ('Y' -or- 'N')
	do {


		/// *** GETTING USER INPUT *** ///		
		//Getting User Input
		userInput = getchar();
		clearBuffer();
		puts("#######################################################################");


		/// ***  YES SELECTION CHECK  *** ///
		// User Selects ('Y')
		if (toupper(userInput) == 'Y') {


			isValidInput = true;
			isYesOrNo = true; // Since Yes is a Valid Selection


		}// END YES SELECTION CHECK


		/// ***  NO SELECTION CHECK  *** ///
		//User Selects ('N')
		else if (toupper(userInput) == 'N') {


			isValidInput = true;
			isYesOrNo = false; //Since No is a Valid Selection


		}/// END NO SELECTION CHECK


		/// ***  INVALID ENTRY SELECTION  *** ///
		//User Enterd Something Invalid
		else {

			puts("#######################################################################");
			puts("                   Error ('Y' -or- 'N') Entry. Recipt?");
			puts(" ");
			printf("%s", "                             Entry: ");

		}

	} while (!isValidInput);// Continue Untill ('isValidInput') is TRUE 


	if (isYesOrNo) {
		unsigned int lastSeat = *ticketsSoldArrayElement;
		size_t ticketSelection = userTicketSelection - 1;
		unsigned int firstSeat = lastSeat - (unsigned int)ticketSelection;

		printf(
			" ##### Biles Big Game -- Proof Of Purchase Receipt #####\n"
			" #####             Section: %s \n"
			" #####             Seats %u - %u \n"
			" #####             Total: %.2lf \n"
			" #####             Charity Amount: %.2lf \n"
			" ######################################################\n"
			" ######## THANK YOU! ENJOY THE GAME! GO BUCKS! ########\n", *SEATING_CHOICES_PTR[userSeatSelection], firstSeat, lastSeat, userTotal, charityTake
		);
	}

}// END PRINT_RECEIPT



bool dailySales(double seatPrices[], double charityPercentage, unsigned int ticketsSold[], double seatSales[], double charityTotals[]) {
	/// ***  Initilizaing  **** ///
	//Logged On
	bool isLoggedOn = true;

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
	puts(" ");
	puts("                            Sucessful Logon  ");
	puts(" ");
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
			actualProfit = userTotal - charityTake;


			/// *** VALIDATION OF PAYMENT *** ///
			// Gathering Zip Code and (CreditCard(TBI))
			userPayment();


			/// ***  UPDATING TOTALS  *** //
			// Tickets Sold Updated
			updateTicketsSold(&ticketsSold[userSeatSelection], userTicketSelection);

			// Seats Sold Updated
			updateSeatSales(&seatSales[userSeatSelection], actualProfit);

			// Charity Totals Updated
			updateCharityTotals(&charityTotals[userSeatSelection], charityTake);


			/// ***  PROMPTING FOR RECEPIT  *** ///
			//First Asks if User Wants Receipt
			//PRINTS TOTAL / CHARITY TOTAL -- ('Y')
			//RESETS TRANSACTION -- ('N')
			printRecipt(userTotal, charityTake, userSeatSelection, userTicketSelection, &ticketsSold[userSeatSelection]);


		}// END QUIT CHARACTER CHECK


		/// ***  QUIT OPTION SELECTED  **** ///
		// If Quit Option is Selected and Confirmed
		else {


			/// ***  PROMPT USER  *** ///  
			//Filler Text
			puts("#######################################################################");
			puts("");
			printf("%s", "                         Enter PIN : ");


			/// ***  VALIDATION OF PIN #  *** ///
			// Calls ('adminLogOn') -- Returns Opposite Result
			isLoggedOn = !adminLogOn();


			/// *** SUCESSFUL LOG OUT CHECK  *** ///
			// Prints if Sucesfully Logged Out
			if (!isLoggedOn) {

				//Filler Text
				puts("");
				puts("#######################################################################");
				puts("#######################################################################");
				puts("");
				puts("                            Sucessful Logout  ");
				puts("");
				puts("#######################################################################");


				/// ***  FOR EACH ELEMENT IN ('SEATING_CHOICES_SIZE') LIST OUT THE SALES  *** ///
				//Prints All Sales of the Day
				for (size_t i = 0; i < SEATING_CHOICES_SIZE; i++) {

					//Filler Text
					puts("#######################################################################");
					puts("");

					//Printing of Days Totals
					printf(" %s sold %u tickets at: $%.2lf. Giving $%.2lf to charity \n", *SEATING_CHOICES_PTR[i], ticketsSold[i], seatSales[i], charityTotals[i]);

					//Filler Text
					puts("");
					puts("#######################################################################");


				}// END DAY SALES PRITNING


			}// END LOGGED OUT CHECK


			/// ***  UNSUCESSFUL LOG OUT CHECK  *** ///
			// Prints if Failled to Log Out
			else {

				//Filler Text
				puts("#######################################################################");
				puts("#######################################################################");
				puts("");
				puts("                               Seek Admin   ");
				puts("");
				puts("#######################################################################");


			}// END UNSUCESSFUL LOGG OUT CHECK


		}// END QUIT OPTION SELECTED


	} while (isLoggedOn); // Continue While ('loggedOn') is TRUE'

	return isLoggedOn;
}