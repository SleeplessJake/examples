// JACOB BILES
// ITERATION 01
// CS 2060
// DUE -- 3/31/2022





////##########################################////
////####                                  ####////
////####**#            DESC            #**####////
////####                                  ####////
////##########################################////


//DESC
/*  The Goal Of this Assignment is to be a project
*   that we continue to update untill the end of
*   the semester. The Program is a modularized
*   POS System where the admin will be initilly
*   needed to log on. After this the POS System
*   will make sales to whatever USER aproaches it.
*   It Will Continue to do this untill the admin
*   is able to log out -- Selecting a secret
*   option to quit. After this is is done the EOD
*   TOTALS are printed and the program ends.  */





////##########################################////
////####                                  ####////
////####**#            TODO            #**####////
////####                                  ####////
////##########################################////


/*  CLEAN UP COMMENTING -- FUNCTIONS  */
/*  REASSESS FUNCTION VIABILITY AND FUNCTIONALITY  */



////##########################################////
////####                                  ####////
////####**#          LIBRARIES         #**####////
////####                                  ####////
////##########################################////


// STANDARD INPUT OUTPUT
#include <stdio.h>


// C TYPE
#include <ctype.h>


// STANDARD BOOL
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
void userPayment(void);



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
 *  If YES (VALID) -- OUTPUT TRUE -- CONTINUE SALE
 *  If NO (VALID) -- OUTPUT FALSE -- END SALE
 *  Else INVALID -- REPROMPT USER
 *
 *  If TRUE -- Takes all INPUTS and OUTPUTS Formatted Reciept-type-printout         */
void printRecipt(const double, const double, const size_t, const size_t, const unsigned int*);


/// ***  DAILY_SALES *** ///
//       ### DESC ###       //
/*  DAILY_SALES -- The main bulk of the program. Calls other functions, and proceedes on with the day.
 *
 *  If VALID -- OUTPUT TRUE -- END SALES
 *  If INVALID -- OUTPUT FALSE -- CONTINUE SALES       */
bool dailySales(double[], double, unsigned int[], double[], double[]);



////##########################################////
////####                                  ####////
////####**              MAIN            **####////
////####                                  ####////
////##########################################////



//// #### **  MAIN  ** #### ///
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



	/// ** LOGGING ON ** //
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



	}// ## END ## // ***  UNSUCESSFUL LOGON CHECK  *** //





	////##########################################////
	////####                                  ####////
	////######      RETURN 0 FOR MAIN       ######////
	////####                                  ####////
	////##########################################////


	//Returns :(INT): -0- for Sake of Proper Return for Main
	return 0;



} /////  ## END ##  // #### **  MAIN  ** #### /////





	////##########################################////
	////####                                  ####////
	////####**          FUNCTIONS           **####////
	////####                                  ####////
	////##########################################////



/// ***  CLEAR_BUFFER  *** ///
//  Clears Buffer
void clearBuffer(void) {



	/// ***  CLEARING BUFFER  *** ///
	// If the return of )'getchar'_ is Not ('\n')
	// Then Will Continue to call ('getchar') 
	// Untill it is ('\n')
	while (getchar() != '\n');



}// ## END ## // ##FUNCTION // ***  CLEAR_BUFFER  *** //



/// ***  ADMIN_LOG_ON  *** ///
//  Validates USERS ENTRY
/// ## REQUIREMENTS ## ///
/*  R: ('clearBuffer') ### FUNCTION ###
 *  R: ('ADMIN_PIN') ### DEFINITION ###
*/
/// ## OUTPUTS ##
/*  O: BOOL TRUE -- VALID ENTRY
 *  O: BOOL FALSE -- INVALID ENTRY */
bool adminLogOn(void) {



	/// **  INITILIZATION  ** ///
	unsigned int userLogon = '\0';// USER INPUT



	/// ##  GETTING USER INPUT  ## ///
	//  Get UNSINGED INT ('userLogon') from USER INPUT
	//  Clears Buffer After
	scanf("%ui", &userLogon);
	clearBuffer();
	puts(" ");



	/// **  TRUE_VALIDITY_CHECK  ** ///
	// User Input Matches ('ADMINT_PIN') Definition
	if (userLogon == ADMIN_PIN) {



		/// ## OUTPUT ## //
		// BOOL
		// OUTPUTS TRUE -- Matches the ('ADMIN_PIN') ### Definition ###
		return true;



	}// ## END ## // ## IF ## // **  TRUE_VALIDITY_CHECK  ** ///



	/// ** FALSE_VALIDITY_CHECK  ** ///
	// User Input Doesn't Match ('ADMINT_PIN') Definition
	else {



		/// ## OUTPUT ## //
		// BOOL
		// OUTPUTS FALSE -- Doesn't Match the ('ADMIN_PIN') ### Definition ###
		return false;



	}// ## END ## // ## ELSE ## // **  FALSE_VALIDITY_CHECK  ** ///



}// ### END ### // ### FUNCTION ### // *** ADMIN_LOGON  *** //



/// ***  DAILY_LOG_ON  *** ///
//  OUTPUTS if Sucessful log on or failed
/// ## REQUIREMENTS ## ///
/*  R: ('amdinLogOn') ### FUNCTION ###
 *  R: ('MAX_LOGON_ATTEMPTS') ### DEFINITION ###  */
 /// ## OUTPUTS ##
 /*  O: BOOL TRUE -- VALID ENTRY
  *  O: BOOL FALSE -- INVALID ENTRY */
bool dailyLogOn(void) {



	/// ***  INITILIZATION  *** ///
	// Number of Attempts
	unsigned int attempts = '\0';

	// Logged On Check
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
	/* TRUE: Sucessful Log On
	 * Attempts Less Than 3 AND ('userInput') is the Admin PIN Number

	 * FALSE: Failed Log On
	 * Attempts Greater Than 3 */
	return isLoggedOn;


}// ## END ## // ### FUNCTION ### // DAILY_LOG_ON


/// ***  DAILY_LOG_ON  *** ///
//  Updates a Price Within a Range
/// ## REQUIREMENTS ## ///
/*  R: ('clearBuffer') ### FUNCTION ###
*/
/// ## INPUTS ##
/*  I: CONST DOUBLE ('min'), the Min in the Range
 *  I: CONST DOUBLE ('max'), the Max of the Range
 *  I: DOUBLE POINTER ('price'), the Price Being Updated  */
void changePrice(const double min, const double max, double* price) {




	/// ***  Initilization  *** ///
	double userInput = '\0';	/// User Input
	bool isValidChoice = false; /// Validity Check





	///#########################///
	///######INITIL PROMPT######///
	///#########################///



	/// ***  CHECK_FOR_PRICE  *** ///
	//  Check to see If Price
	//  If ('max') is GREATER THAN ('>') 1, Thus ENTRY is Price
	if (max > 1) {



		puts("#######################################################################");
		puts(" ");
		printf("             Please enter a price above $%.2lf to $%.2lf\n", min, max); // Displaying Line
		printf("                     Enter Between Range: $");// Entry Line



	}/// ## END ## // ## IF ## // **  CHECK_IF_PRICE  ** ///



	/// **  CHECK_FOR_PERCENTAGE  ** ///
	//  Check to see If Percentage
	//  If ('max') is LESS THAN ('<') 1, Thus ENTRY is Percentage
	else {



		puts("#######################################################################");
		puts("                                                                       ");
		printf("             Please enter a percentage above %.2lf%% to %.2lf%%\n", min, max); // Display Line
		printf("                     Enter Between Range: "); // Entry Line



	}/// ## END ## // ## IF ## // **  CHECK_IF_PERCENTAGE  ** ///





	///#########################///
	///##### VALIDITY_LOOP #####///
	///#########################///



	/// ***  DO-WHILE UNTILL IS_VALID_ENTRY *** ///
	// Continues Untill a Valid Price or Percentage is 
	// Given From the Admin That is Within the Given
	// ('min') and ('max') Range
	do {



		/// ##  GETTING USER INPUT  ## ///
		//  Get DOUBLE ('price') from USER INPUT
		//  Clears Buffer After
		scanf("%lf", &userInput);
		clearBuffer();
		puts("                                                                       ");
		puts("#######################################################################");





		///#############################///
		///##### VALID_INPUT_CHECK #####///
		///#############################///



		/// **  VALID_INPUT_CHECK  ** ///
		//  Within Range ('min')/('max')
		//  Shows User Accepted INPUT
		if (max >= userInput && userInput > min) {



			/// **  CONFIRMING VALIDITY  ** ///
			//  The Input is Within Range
			//  Breaks This Loop
			isValidChoice = true;



			/// **  PRICE_CHECK  ** ///
			//  Check to see If Price
			//  If ('max') is GREATER THAN ('>') 1, Thus ENTRY is Price
			if (max > 1) {



				/// ** PRINTING ACCEPTED PRICE  ** ///
				//  Displays accepted INPUT
				//  For Visual Confirmation
				puts("#######################################################################");
				puts("                                                                       ");
				printf("######################  Accepted at: $%.2lf  #########################\n", userInput); // ACCEPTED INPUT
				puts("                                                                       ");
				puts("#######################################################################");



			}// ## END ## // ## NESTED-IF ## // **  PRICE_CHECK  ** //



			/// **  PERCENTAGE CHECK  ** ///
			//  Check to see If Percentage
			//  If ('max') is LESS THAN ('<') 1, Thus ENTRY is Percentage
			else {



				/// *** PRINTING ACCEPTED PERCENTAGE  *** ///
				//  Displays accepted INPUT
				//  For Visual Confirmation
				puts("#######################################################################");
				puts("                                                                       ");
				printf("########################  Accepted at: %.2lf%%  #######################\n", userInput);// ACCEPTED INPUT
				puts("                                                                       ");
				puts("#######################################################################");



			}// ## END ## // ## NESTED-ELSE ## // **  PERCENTAGE_CHECK  ** //



		}// ## END ## // ## IF ## // **  IS_VALID_ENTRY  ** //





		///###############################///
		///##### INVALID_INPUT_CHECK #####///
		///###############################///



		/// **  INVALID ENTRY  ** ///
		//  Out Of Range
		//  Reprints Correct Range For User
		//  REPROMPTS USER
		else {



			///  ** PRICE_CHECK  ** ///
			//   Check to see If Price
			//   If ('max') is GREATER THAN ('>') 1, Thus ENTRY is Price
			if (max > 1) {



				/// **  REPRINTING OF OPTIONS  ** ///
				//  REPROMPT USER
				//  Reprints the Correct Options for the User
				puts("#######################################################################");
				puts("                                                                       ");
				printf("  Error $%.2lf is out of range! The range is above $%.2lf to $%.2lf\n", userInput, min, max);// REPROMPT USER
				printf("                      Enter between Range: ");// ENTRY LINE



			}// ## END ## // ## NESTED-IF ## // **  PRICE_CHECK  **//



			///  ** PRICE_PRITNING_CHECK  ** ///
			//   Check to see If Price or Percentage
			//   If ('max') is LESS THAN ('<') 1, Thus ENTRY is Percentage
			else {



				/// **  REPRINTING OF OPTIONS  ** ///
				//  REPROMPT USER
				//  Reprints the Correct Options for the User
				puts("#######################################################################");
				puts("                                                                       ");
				printf("  Error %.2lf%% is out of range! The range is above %.2lf%% to %.2lf%%\n", userInput, min, max);// PROMPT USER
				printf("                     Enter between Range: ");// ENTRY LINE



			}// ## END ## // ## NESTED-ELSE ## // **  PRICE_PRINTING_CHECK  ** ///



		}// ## END ## // ## ELSE ## // **  INVALID INPUT CHECK  ** //



	} while (!isValidChoice);/// **  DO UNTILL ('validInput') is Set to TRUE  ** ///



	/// ***  ASSINGING VALUES  *** //
	//  Updates INPUT ('*price')
	//  Assigns ('userInput') to Deference of ('*price')
	*price = userInput;




}/// ## END## // ### FUNCTION ### // ***  CHANGE_PRICE   *** ///



/// ***  DAY_SET_UP  *** ///
//  Setup For All Days Totals And Percentage
/// ## REQUIREMENTS ## ///
/*  R: ('clearBuffer') ### FUNCTION ###
*/
/// ## INPUTS ##
/*  I: CONST DOUBLE ('min'), the Min in the Range
 *  I: CONST DOUBLE ('max'), the Max of the Range
 *  I: DOUBLE POINTER ('price'), the Price Being Updated  */
void daySetUp(double seatArray[], double* charityPercent) {



	/// **  INITILIZATION  ** ///
	//  Pointer Intilization
	//  Initilized to NULL
	double* ticketPTR = NULL;



	/// **  FOR ALL ELEMENTS IN ('SEATING_CHOICES_SIZE') DEFINITION  ** ///
	//  For All Seating Choices Set Up the Price for Them Appropriatley
	//  Based on the Predetermined Min (EXCLUSIVE (E)) and Max (INCLUSIVE (I)) Range Given.
	for (size_t i = 0; i < SEATING_CHOICES_SIZE; i++) {



		/// **  POINTER ASSIGNING  ** ///
		//  Assins Pointer to Incremential Spots in the ('seatArray[]')
		//  Uses ('seatPrices[]')
		ticketPTR = &seatArray[i];


		// Courtside Seating 
		changePrice(SEATING_CHOICE_PRICE_RANGE[i][0], SEATING_CHOICE_PRICE_RANGE[i][1], ticketPTR);



	}/// ## END ## // ## FOR LOOP ## // **  ALL_ELEMENTS_IN ('SEATING_CHOICES_SIZE')  ** ///



	/// **  PERCENTAGE_UPDATING  ** ///
	//  Calls ('changePrice') With a Predetermined
	//  Based on the Predetermined Min (EXCLUSIVE) and Max (INCLUSIVE) Range Given.
	changePrice(CHARITY_PERCENTAGE_RANGE[0], CHARITY_PERCENTAGE_RANGE[1], charityPercent);




}// ##  END  ## // ### FUNCTION ### // ***  DAY_SETUP  *** ///



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



void updateTicketsSold(unsigned int* ticketsSoldArrayElement, const size_t numberOfTickets) {

	//Updating Slot (+=) to Amount
	*ticketsSoldArrayElement += (unsigned int)numberOfTickets;


} // END UPDATE_TICKETS_SOLD



void updateSeatSales(double* seatSaleArrayElement, const double amountAfterCharity) {


	//Updating Slot (+=) to Amount
	*seatSaleArrayElement += amountAfterCharity;


}// END UPDATE_SEAT_SALES



void updateCharityTotals(double* charityTotalsSpot, const double givenToCharity) {


	//Updates Position within ('charityTotals[]
	*charityTotalsSpot += givenToCharity;


}//  ## END ## // ### FUNCTION ### // ***  UPDATE_CHARITY_TOTALS  *** //



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