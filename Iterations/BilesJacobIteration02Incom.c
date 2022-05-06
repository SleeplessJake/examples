// LIBRARIES //
#include <stdio.h> // Standard Input Output
#include <stdbool.h> // Standard Bool
#include <ctype.h>	// C Type
#include <limits.h> //Limits of Standard Data Structures -- Int/Long/Char
#include <float.h> // Limits of Standard Data Structures -- Float/Double
#include <errno.h> // For System Interaction for Error Callig
#include <stdlib.h> // Standard Libraries
#include <string.h> // Strings


// CONSTANTS //
// General Constants
#define STRING_SIZE 80 // Max size a string can be
#define TICKET_CHOICES 4 // Number Of Tickts
const char WELCOME_MESSAGE[STRING_SIZE] = " Hello welcome to tonights big game!\n Please Select a seat!\n";
const char* TICKET_NAMES[TICKET_CHOICES] = { "Single Pack", "Couple Pack", "Triple Pack", "Family Pack" };

// Charity Percentage 
#define CHARITY_MAX 25
#define CHARITY_MIN 10

// Admin Constants 
#define ADMIN_PANEL_OPTIONS 6
const char* ADMIN_OPTIONS[ADMIN_PANEL_OPTIONS] = { "Add Seat", "Remove Seat", "Edit Seat", "See current Sales", "Continue Day" ,"End Day" }; // All Admin Option
const char QUIT_KEYWORD[5] = "Quit"; // Quit Keyword 
#define MAX_LOGON_ATTEMPTS 4 // Max Logon Attemps a User has
#define ADMIN_PIN 4932 // The Logon Pin to the 

// Console -or- Screen IO
#define INPUT_LOCATION stdin // User Input location
#define OUTPUT_LOCATION stdout // Standard Printed Info

// FIlE IO
#define FILE_INPUT_LOCATION stdin // File Input location
#define FILE_OUTPUT_LOCATION stdout // File to be written 

// Seat Parameters
#define NUMBER_OF_SEATS 3 // Number of Seats to be added
#define MIN_PRICE 10 // Minimum price of a seat 
#define MAX_PRICE 500 // Maximum price of a 


// STRUCTURES //
typedef struct SeatChoice {

	char name[STRING_SIZE];
	double price;
	double totalSales;
	unsigned int totalTickets;
	struct SeatChoice* nextSeat;

}SeatChain; // Seat Structure


// FUNCTION PROTOTYPES // 
void clearBuffer(void); // Clears Buffer
const bool confirmChoice(void); // Asks the user for confirmation before continuing
int stringCompare(const char[STRING_SIZE], const char[STRING_SIZE]); // compares two strings
const unsigned int validateUInt(void); // Gets Secure Valid Int
const double validateDouble(void); // Gets Secure Valid Double
void validateString(char*); // Takes in a string and updates it when validated
void logOn(bool*); // Logon Protocol -- Either Starts or Ends Day
bool adminPanel(SeatChain**, double); // All admin options 
bool isWithinRange(const double, const unsigned int, const unsigned int); // Determines if double is within given range
double getCharityPercentage(); // Gets the Charity Percentage for the day
SeatChain* findLastLink(SeatChain*); // Finds Last link In chain
SeatChain* getValidSeat(SeatChain*); // Gets users input and Outputs their selected seat
void createSeat(SeatChain**); // Adds Seat Choice to Link
void addSeatToChain(SeatChain**); // Sets up Initil Seat Choice Chain
void removeLink(SeatChain**); // Removes Link Based on Name
void printSeatChain(SeatChain*); // Prints a Seat 
SeatChain* getSeatSelection(SeatChain*); // Get Seat Selection From User
unsigned int getTicketSelection(SeatChain*); // Get Ticket Selection From User
unsigned int getZipCode(); // Get Zip Code From User
void bootUP(SeatChain**, double* charityPercentage); // Start of day, admin logs in, sets up seats and Percentage
void salesMode(SeatChain**, double charityPercantage); // Main Process of the Programm -- Sells Tickers


// MAIN //
int main(void) {

	double charityPerctange = 0;
	SeatChain* headChainPTR = malloc(sizeof(SeatChain));
	bootUP(&headChainPTR, &charityPerctange);

	free(headChainPTR);
	headChainPTR = NULL;

	return 0; // Return For Main

}// MAIN //


/// FUNCTION IMPLEMENTATION ///
// Clear Buffer
/* Desc
*  Clears the buffer by getting the next character of the buffer. If it is not the new line character
*  ('\n') it will continue to loop through the buffer untill it is.
*/
void clearBuffer(void) {

	while ((getchar()) != '\n');

} // FUNCTION // Clear Buffer //


// Confirm Choice
/* Desc
*  Asks the user for a yes or no selection. Where true and false are returned respectfully from this choice.
*  Maintains security by validating user entry.
*/
/* Output
*  O: Const Bool -- True (Yes)
*  O: Const Bool -- False (No)
*/
const bool confirmChoice(void) {

	// INITILIZATION //
	char userInput = '\0';


	// VALIDATE SELECTION //
	while (userInput != 'Y' && userInput != 'N') { // Comtimues Umtill Y or N entered

		fprintf(OUTPUT_LOCATION, " Entry (Y/N): "); // Prompt For yes or No
		userInput = toupper(fgetc(INPUT_LOCATION)); // Get and Capitilize Input
		clearBuffer(); // Clear Buffer

	} // Validate Input 

	// ## OUTPUT ## //
	if (userInput == 'Y') { return true; } // User Inputs Yes
	else { return false; } // User Inptus No

} // FUNCTION // Confirm Choice //


// String Compare
/* Desc
*  Compares two different strings by copying their values, capitilizng them, and then finally passing
*  a ranged value based on this comparison.
*/
/* Inputs
*  I: char Pointer -- First string to be compared
*  I: char Pointer -- Second string to be compared
*/
/* Outputs
*  O: int -- 1, First string value is larger than seconed
*  O: int -- 0, Both strings are equal
*  O: int -- -1, Second string is larger
*/
int stringCompare(const char stringOne[STRING_SIZE], const char stringTwo[STRING_SIZE]) {

	// INITILIZATION //
	size_t currentSpot = 0; // Incrementer of 
	char tempOne[STRING_SIZE] = "\0";
	char tempTwo[STRING_SIZE] = "\0";


	// CAPITILIZE STRING TWO //
	while (stringOne[currentSpot] != '\0') { // Continue Untill Null Character Reached

		tempOne[currentSpot] = toupper(stringOne[currentSpot]); // Capitilize each letter
		currentSpot++; // Increment To Next Letter

	}tempOne[currentSpot + 1] = '\0'; // Assigning Null to Last Location


	// Reset to First Posisition 
	currentSpot = 0;


	// CAPITILIZE STRING ONE //
	while (stringTwo[currentSpot] != '\0') { // Continues untill Null Specifier Found

		tempTwo[currentSpot] = toupper(stringTwo[currentSpot]); // Capitilize 
		currentSpot++; // Increment to Next Letter

	}tempTwo[currentSpot + 1] = '\0'; // Assigning Null to Last Location


	// COMPARISION //
	int returnValue = strcmp(tempOne, tempTwo); // Compares Capitilized Strings


	return returnValue; // Returns Comparison Value 

} // FUNCTION // String Compare 


// Validate Unsiged (U) Int
/* Desc
*  Asks the user for an input, maintins security by checking for all (known) possible errors -- and reasks
*  user if one of these errors are acheived.
*/
/*
*  O: const unsigned int -- User input (valid)
*/
const unsigned int validateUInt(void) {

	// INITILIZATION //
	char* slicedPortion; // Cut Portion
	errno = 0; // Error Marker
	char buffer[STRING_SIZE]; // Buffer Input
	unsigned long userInput = 0; // User Input
	int error = 0; // Error Code


	// GET USER CONFIRMATION //
	do { // Continue Untill User Confirmation //


		// GETTING AND FORMATING INPUT //
		fgets(buffer, STRING_SIZE - 1, INPUT_LOCATION); // Getting 
		userInput = strtoul(buffer, &slicedPortion, 10); // Cutting
		error = 0; // Reset Errors

		// ERROR HANDLING //
		if (slicedPortion == buffer) { error = -1; } // No Portion Taken
		else if (*slicedPortion != '\n') { error = -2; } // The End Is incorrect
		else if ((0 > userInput || ULONG_MAX == userInput) && ERANGE == errno) { error = -3; } // Long Range Exceeded
		else if ((userInput > UINT_MAX) || (userInput < 0)) { error = -4; } // Int Range Exceeded


		// ERROR PRINTING //
		if (error < 0) {

			fprintf(OUTPUT_LOCATION, "%s %d", " ERROR! Code: ", error);
			fputs(" \n ", OUTPUT_LOCATION); // Spacer
			fprintf(OUTPUT_LOCATION, "%s", " Re-Enter: ");
			userInput = -1;

		} // Error Printing

	} while (error != 0); // Confirm Valid Entry -- Restart if not


	 // ##OUTPUT## //
	return (unsigned int)userInput;

} // FUNCTION // Validate Unsiged (U) Int //


// Validate Double
/* Desc
*  Asks the user for an input, maintins security by checking for all (known) possible errors -- and reasks
*  user if one of these errors are acheived.
*/
/* Outputs
*  O: const double -- User input (valid)
*/
const double validateDouble(void) {

	// INITILIZATION //
	char* slicedPortion; // Sliced Portion
	errno = 0; // Error Handling
	char buffer[STRING_SIZE]; // Buffer Input
	double userInput = 0; // userInputed Double
	int error = 0; // Error Code
	bool isConfirmed = false; // Confirmation by User


	// INPUT ERROR HANDLING //
	do { // Continue Untill Confrimed by user 

		fprintf(OUTPUT_LOCATION, "%s", " Enter a double digit value: ");


		// GETTING AND FORMATING INPUT //
		fgets(buffer, STRING_SIZE - 1, INPUT_LOCATION); // Getting Input (One Less For Buffer)
		userInput = strtod(buffer, &slicedPortion); // Cutting Off Tail


		// ERROR HANDALING //
		if (slicedPortion == buffer) { error = -1; } // No Portion Taken
		else if (*slicedPortion != '\n') { error = -2; } // The End Is incorrect
		else if ((userInput > FLT_MAX) || (userInput < FLT_MIN)) { error = -3; } // Double Range Exceeded


		// CONFIRMING SELECTION //
		else { // No Errors -- Only Call to Confirm Choice

			fprintf(OUTPUT_LOCATION, "\n Entered: %.2f\n %s", userInput, "Is this what you meant ?\n");
			isConfirmed = confirmChoice(); // Confirms Selection With User

		} // Input Without Errors


		// ERROR PRINTING //
		if (error < 0) { fprintf(OUTPUT_LOCATION, "%s %d", " ERROR! Code: ", error); error = 0; clearBuffer(); }


	} while (!isConfirmed); // Error Handiling BREAKS -- User Confirms Choice

	// ##OUTPUT## //
	return userInput;

} // FUNCTION // Validate Double


// Validate String
/* Desc
*  Asks the user for an input, maintins security by asking user to confirm choice
*  reasks user if unhappy with selection.
*/
/* Inputs
*  I: char* -- Pointer to a character array
*/
void validateString(char* someString) {

	// INITILIZATION //
	bool isConfirmed = false;


	// CONFIRMATION CHECK //
	do { // Continues Untill User Quits

		fprintf(OUTPUT_LOCATION, "%s", " Enter a name: ");


		// GETTING AND FORMATING USER INPUT //
		fgets(someString, STRING_SIZE, FILE_INPUT_LOCATION); // Get User Name Entry


		// CONFIRMING SELECTION //
		fprintf(OUTPUT_LOCATION, "\n Entered: %s %s", someString, "Is this what you meant ? (Y/N)\n"); // Prompt
		isConfirmed = confirmChoice(); // Get user Input Y/N


		// ASSIGNING STRING //
		if (isConfirmed) { someString = strtok(someString, "\n"); } // Confirmed Selection, Removes New Line Character

	} while (!isConfirmed); // Confirmation Check -- BREAK: User Confirms Choice

} // Function // Validate String //


// Log On
/* Desc
*  Takes in the current logged on status and switches it if user can correctly enter pin.
*  If user can't within certin amount of tries, alerts user and breaks.
*/
/* Input-Output
*  IO: bool -- Current logon status
*/
void logOn(bool* isLoggedOn) {

	// INITILIZATION //
	int attempts = 0; // Number of Attempts
	bool currentStatus = *isLoggedOn; // Dereference Value


	// DAY NOT STARTED //
	if (!currentStatus) { // Check If Day is Ongoing


		// CHECK ENTRY AND ATTEMPTS //
		while (!currentStatus && attempts < MAX_LOGON_ATTEMPTS) { // BREAKS: Pin Mathced, or, Login Attempts Exceeded

			fprintf(OUTPUT_LOCATION, "%s", " Enter PIN: ");


			// SUCESSFUL ENTRY //
			if (validateUInt() == ADMIN_PIN) { // Matches PIN

				currentStatus = true; // Set Day Status to True
				fprintf(OUTPUT_LOCATION, "%s\n", " Sucessful logon!");
				attempts++; // Increment Attempts

			} // PASS


			// FAILED ENTRY //
			else { // Entry Doesn't Match PIN //

				attempts++; // Incremenet Attempts
				fprintf(OUTPUT_LOCATION, "\n%s (%d/%d)\n", " Incorrect Pin! Attempt", attempts, MAX_LOGON_ATTEMPTS);

			} // FAIL


			// MAX ATTEMPTS REACHED //
			if (attempts == MAX_LOGON_ATTEMPTS) { fputs(" FAILED TO LOG IN! SEEK ADMIN!", OUTPUT_LOCATION); }

		} // PIN Check Loo

	}// Day Isn't Started


	// DAY IS ONGOING //
	else { if (validateUInt() == ADMIN_PIN) { currentStatus = false; } }


	// UPDATE ORIGINAL STATUS //
	*isLoggedOn = currentStatus;

} // FUNCTION // Log On //


// Admin Panel
bool adminPanel(SeatChain** headSeatPTR, double charityPercentage) {

	// INITILIZATION //
	bool isLoggedOn = true;
	unsigned int userInput = 0;
	SeatChain* localHeadPTR = *headSeatPTR;

	fprintf(OUTPUT_LOCATION, "\n%s", " Enter PIN: ");
	logOn(&isLoggedOn); // Checks to See if Admin
	fprintf(OUTPUT_LOCATION, "%s", "\n");


	// FAILED LOG ON -- CONTIUE DAY // 
	if (isLoggedOn == true) { return true; }


	// Sucessful LOGON 
	else {


		// GETTING ADMIN SELECTION // 
		do { // Quit Options Selected

			fprintf(OUTPUT_LOCATION, "\n %s\n", "--Admin Settings--");
			for (size_t i = 0; i < ADMIN_PANEL_OPTIONS; i++) { fprintf(OUTPUT_LOCATION, " %llu.%s\n", i + 1, ADMIN_OPTIONS[i]); }


			// VALIDATING USER INPUT
			do { // Continues Untill Valid Range

				fprintf(OUTPUT_LOCATION, "\n%s", " Select Option: ");
				userInput = validateUInt(); // Getting User Input

			} while (!isWithinRange(userInput, ADMIN_PANEL_OPTIONS, 1));


			// QUIT OR CONTINUE SELECTED //
			if (userInput == ADMIN_PANEL_OPTIONS - 1 || userInput == ADMIN_PANEL_OPTIONS) {


				// END DAY //
				if (userInput == ADMIN_PANEL_OPTIONS) { isLoggedOn = false; }


				// CONTINUE DAY //
				else { isLoggedOn = true; }

			} // Quit or Continue Selected


			// OTHER ADMIN OPTION SELECTED //
			else { // Continue Making Edits


				// Admin options 
				switch (userInput)
				{
				case 1: // Add Seat

					fprintf(OUTPUT_LOCATION, "%s", " New Seat To Add!");
					addSeatToChain(headSeatPTR);
					break;

				case 2: // Remove Seat
					fprintf(OUTPUT_LOCATION, "%s", " Remove a Seat!");
					removeLink(headSeatPTR);
					break;

				case 3: // Edit Seat
					fprintf(OUTPUT_LOCATION, "%s", " Not Implemented!");
					break;

				case 4: // See current sales 

					while (localHeadPTR != NULL) {

						fprintf(OUTPUT_LOCATION, "\n %s has sold $%.2f, where $%.2f goes to chairty.\n", localHeadPTR->name, localHeadPTR->totalSales, localHeadPTR->totalSales * charityPercentage);
						fprintf(OUTPUT_LOCATION, " %s$%.2f\n\n", "Our Take: ", (localHeadPTR->totalSales - (localHeadPTR->totalSales * charityPercentage)));
						localHeadPTR = localHeadPTR->nextSeat;
					}

					localHeadPTR = *headSeatPTR;

					break;

				default:
					break;

				} // Admin Option Switch

			} // Non Quit Option

		} while (userInput != ADMIN_PANEL_OPTIONS - 1 && userInput != ADMIN_PANEL_OPTIONS); // Quit/Continue Option

	} // Sucesfful Logon


	// #OUTPUT## //
	return isLoggedOn; // Either Continue Or End Day

} // FUNCTION // Admin Panel


// Is In range
/* Desc
*  Determines if the inputed numbed is within the range of the input max and min
*/
/* Input
*  I: double -- checkNum (Number to be checked)
*  I: unsigned int -- Max
*  I: unsigned int -- Min
*/
/* Output
*  O: Bool -- True, Within range
*  O: Bool -- False, Out of range
*/
bool isWithinRange(const double checkedNum, const unsigned int max, const unsigned int min) {

	if (checkedNum > max || checkedNum < min) { return false; } // Out Of range
	else { return true; } // In Range

} // FUNCTION // Is Within Range


// Get Charity Percentage
/* Desc
*  Gets and returns a double value that represents a charity percentage.
*/
/* Output
*  O: Double -- The Charity Percentage
*/
double getCharityPercentage() {

	// INITILIZATION //
	double userInput = 0;


	// GETTING PERCENTAGE WITHIN RANGE //
	do {

		fprintf(OUTPUT_LOCATION, "\n%s %%%u-%%%u\n", " Please enter a Charity Percentage from", CHARITY_MAX, CHARITY_MIN);
		userInput = validateDouble();

	} while (!isWithinRange(userInput, CHARITY_MAX, CHARITY_MIN));

	// ##OUTPUT## //
	return userInput / 100;

} // FUNCTION // Get Charity Percentage


// Find Last Link
/* Desc
*  Finds the last link within a chain and then returns it
*/
/* Input
*  I: SeatChain Pointer -- The chain to loop through
*/
/* Output
*  O: SeatChain Pointer -- The last link of the Inputed Chain
*/
SeatChain* findLastLink(SeatChain* seatHeadPTR) {

	// INITILIZATION //
	SeatChain* currentSeatPTR = seatHeadPTR; // Iterator
	SeatChain* previousChain = currentSeatPTR;


	// FINDING LAST LINK //
	while (currentSeatPTR != NULL) { // Continue Untill Null (empty) spot is reached

		previousChain = currentSeatPTR;
		currentSeatPTR = currentSeatPTR->nextSeat;

	} // Find Last Link


	// ## OUTPUT ## //
	return previousChain;

} // FUNCTION // Find Last Element


// Get Valid Seat Selection
/* Desc
*  Gets a valid seat from the user based on a character entered -- very crude
*/
/* INPUT
*  SeatChain Pointer -- A Seat Chain
*/
/* OUTPUT
*  SeatChain Pointer -- The Selected Seat
*/
SeatChain* getValidSeat(SeatChain* seatPTR) {

	// INITILIZATION //
	char userInput;
	unsigned int size = 0;
	SeatChain* localHeadPTR = seatPTR;
	SeatChain* seatIterator = seatPTR;


	// FIND SIZE OF CHAIN //
	while (seatIterator != NULL) {
		size++;
		seatIterator = seatIterator->nextSeat;
	}


	// GET USER INPUT //
	userInput = toupper(fgetc(INPUT_LOCATION));
	clearBuffer();


	// QUIT OPTION SELECETED //
	if (userInput == 'Q') { seatIterator = NULL; }


	else { // Quit Option Not Selected

		do {

			// SEAT CHECK //
			for (size_t i = 0; i < size; i++) {	// Loops all Names						// Crude -- Only checks first Letter

				if (userInput == localHeadPTR->name[0]) { seatIterator = localHeadPTR; } // If First Letter Matches
				else { localHeadPTR = localHeadPTR->nextSeat; } // Else Iterate

			} // All names looped


			// ENTRY NOT IN CHAIN //
			if (seatIterator == NULL) { // Seat Not Found

				fprintf(OUTPUT_LOCATION, " %s\n%s", "Seat not found!", "Name:");
				userInput = toupper(fgetc(INPUT_LOCATION)); // Getting User Input
				clearBuffer();
				localHeadPTR = seatPTR; // Reset Link

			} // Seat Not Found

		} while (seatIterator == NULL); // Continue Untill A Seat Is found

	} // Real Selection


	// ## OUTPUT ## //
	return seatIterator;

} // FUNCTION // Get Valid Seat


// Create Seat
/* Desc
*  Takes an empty seat adress, creates a seat, and places it within this adress.
*/
/* Input-Output
*  IO: SeatChain Adress Pointer -- The seat pointer to be updated
*/
void createSeat(SeatChain** emptyChainLink) {

	// INITILIZAION //
	SeatChain* seatToAdd = *emptyChainLink; // Assign Pointer For incomming Pointer Adress
	bool inRange = false;


	// CREATING OF NEW LINK //
	validateString(seatToAdd->name); // Assigining Name
	seatToAdd->name[0] = toupper(seatToAdd->name[0]);
	do { // Continues Untill Entered Price is Within Range


		// QUIT OPTION //
		if ((stringCompare(seatToAdd->name, "Quit") == 0)) { // Didn't mean to add new Seat

			fprintf(OUTPUT_LOCATION, "%s", " Quit option selected, seat not Created\n");
			inRange = true; // Set Range to True, Breaks 

		} // Quit Option Check


		// PROPER NAME //
		else { // Name Isn't Quit -- Continue 


			// PRICE ASSIGNING  //
			fprintf(OUTPUT_LOCATION, "%s $%d-$%d %s", "\n Enter a price between", MIN_PRICE, MAX_PRICE, "for the seat!\n");
			seatToAdd->price = validateDouble(); // Assining Price 
			inRange = isWithinRange(seatToAdd->price, MAX_PRICE, MIN_PRICE); // Checking Range


			// OUT OF DETERMINED RANGE //
			if (!inRange) { fprintf(OUTPUT_LOCATION, " $%3.2f is out of range. Please enter between $%u-$%u\n", seatToAdd->price, MIN_PRICE, MAX_PRICE); }


			// WITHIN DETERMINED RANGE //
			else { // Other Initilized Variables

				seatToAdd->nextSeat = NULL;
				seatToAdd->totalSales = 0;
				seatToAdd->totalTickets = 0;

			}


		} // Proper Name Entered 


	} while (!inRange); // Create New Animal -- BREAK When Price is Within Range Or Quit Selected


} // FUNCTION // Add Seat Choice //


// Create Seat Link 
/* Desc
*  Creates a seat from user input, doing so while maintiainig the range of a seat price, and validating user choice.
*  Continues untill user quits the loop.
*/
/* Input-Output
*  IO: SeatChoice Adress Pointer -- Seat chain head
*/
void addSeatToChain(SeatChain** seatHeadPTR) {

	// INITILIZATION //
	SeatChain* localHeadPTR; // Head
	SeatChain* previousLink; // Previous Link
	SeatChain* emptyLink; // Added Link
	bool hasMoreToAdd = true;


	// ADDING NEW SEAT LINK TO CHAIN //
	do { // Continues Untill User Selects Quit

		localHeadPTR = *seatHeadPTR; // Assign Head
		previousLink = findLastLink(localHeadPTR); // Find Last Link Of Head
		emptyLink = malloc(sizeof(SeatChain)); // Allocate Memory for New Link
		createSeat(&emptyLink); // Create a New Seat Link



		// QUIT ENTERED -- BREAK, DONT ADD //
		if ((stringCompare("QUIT", emptyLink->name)) == 0) {

			hasMoreToAdd = false; // Stop Adding
			previousLink->nextSeat = NULL; // Deassociate Next Spot
			free(emptyLink); // Free Memory
			emptyLink = NULL; // Deassociate PTR Address

		}

		// ADD LINK TO CHAIN //
		else {
			previousLink->nextSeat = emptyLink; // Assign the Last Link of Head to New 
			fprintf(OUTPUT_LOCATION, "%s", "\n Would you like to create another Seat?");
			hasMoreToAdd = confirmChoice(); // Gets User Confirmation
		} // Add Link


	} while (hasMoreToAdd); // Adding New Seat to Link -- BREAKS: User Selectes Quit

}// Function // Create Seat Chain


// Remove Link
/* Desc
*  Removes a specified link from the chain based on an Prompted Token which Removes that Specific Element
*/
/* Input-Output
*  IO: SeatChain Address Pointer -- The Pointer to Be Updated
*/
void removeLink(SeatChain** headSeatPTR) {

	// INITILIZATION //
	char userInput[STRING_SIZE]; // User Input String Temp Array
	validateString(userInput); // Getting Deletion Token
	SeatChain* localheadPTR = *headSeatPTR; // Holder of Next Element
	SeatChain* seatIterator = localheadPTR; // Iterator For List
	SeatChain* previousSeat = seatIterator; // Holds the Adress TO be added onto
	SeatChain* seatToDelete; // Holds The Seat Marked For Deleteion
	bool hasToken = false;
	bool isHead = false;
	bool isConfirmned = false;


	// HEAD IS DELETED TOKEN //
	if ((stringCompare(seatIterator->name, userInput)) == 0) { // Head Comparison

		hasToken = true;
		isHead = true;
		seatToDelete = seatIterator; // Set Deletion Seat to Head
	} // Name Matches


	// HEAD IS NOT DELETE TOKEN //
	else { previousSeat = seatIterator; seatIterator = seatIterator->nextSeat; } // Iterates Past Head


	// CHECK TOKEN MATHCES ANY TOKEN //
	while (seatIterator != NULL && !hasToken) { // Continues Untill Either Not Found or Confimred Within


		// NAME MATHCES DELETION TOKEN //
		if ((stringCompare(seatIterator->name, userInput)) == 0) { // Current Name Comparison

			seatToDelete = seatIterator; // Set Deleted Marker to The Current 
			hasToken = true;

		} // Name Matches


		// NAME DOESNT MATCH //
		else { // Different Name

			previousSeat = seatIterator; // Hold Onto Link
			seatIterator = seatIterator->nextSeat; // Goes To Next Link
		}

	} // Name Matches or Not in List

	//Iterate to next Spot
	if (seatIterator != NULL) { seatIterator = seatIterator->nextSeat; }

	//TOKEN EXISTS
	if (hasToken) { // Token is within Chain


		// CONFIRMING DELETION //
		fprintf(OUTPUT_LOCATION, " %s selected, delete this seat?", seatToDelete->name);
		isConfirmned = confirmChoice(); // Gets User's Confirmation


		// USER CONFIRMS DELETION //
		if (isConfirmned == true) { // Yes is entered

			if (isHead) { // Head Pointer


				// HEAD WAS LAST LINK //
				if (seatIterator == NULL) { // The Next Seat Is Not 

					fprintf(OUTPUT_LOCATION, "%s", " Cant Delete, Last Link Available!"); // Alert User

				}// No More Elemenets


				// MULTIPLE LINKS //
				else { // Can Replace Head 

					*localheadPTR = *seatIterator; // Assign Next Spot To Head
					seatToDelete = NULL; // Deassociate Address From PTR

				} // Multiple Link


			} // Head Marked For Deletion


			else { // Regualr Link

				// LAST ELEMENT DELETED //
				if (seatIterator == NULL) { // Next Spot is Empty

					previousSeat->nextSeat = NULL;
					free(seatToDelete); // Free Memory
					seatToDelete = NULL; // Deassocitate Adress From PTR

				} // Last Element Deleted


				// LINK CAN BE REPALCED //
				else { // Next Spot has a Link

					previousSeat->nextSeat = seatIterator; // Reassign The next Link
					free(seatToDelete); // Free Deleted Memory
					seatToDelete = NULL; // Deassociate Pointer

				} // Link Can Be Replaced 

			} // Regular Link

		} // User Confirms Deletion

	}// Token is Within the Chain


	// TOKEN DOESNT MATCH //
	else { fprintf(OUTPUT_LOCATION, "%s\n", " Token not found"); }

} // FUNCTION // Remove Link 


// Print Seat Chain
/* Desc
*  Takes a seat chain and prints all the links within it.
*/
/* Input
*  I: Seat Chain Pointer -- Pointer to Head, Loops through for Printing
*/
void printSeatChain(SeatChain* seatHeadPTR) {

	// INITILIZATION //
	SeatChain* seatIterator = seatHeadPTR; // Iterator / Counter Role


	// PRINTING OF ALL LINKS // 
	while (seatIterator != NULL) { // Printing of All Links { // Continues Untill Last Link is Reached

		fprintf(OUTPUT_LOCATION, " %s\t\t$%.2f\n", seatIterator->name, seatIterator->price);
		seatIterator = seatIterator->nextSeat; // Iterate to Next Seat

	}


} // FUNCTION // Print Search Chain


// Get Seat Selection
/* Desc
*  Confirms the Users Seat Selection Unless They Have selected Quit
*/
/* INPUT
*  I: SeatChain Pointer -- Local Reference to the Head
*/
/* OUTPUT
*  O: SeatChain Pointer -- Pointer To Selected Seat
*/
SeatChain* getSeatSelection(SeatChain* seatPTR) {

	// INTIILIZATION //
	SeatChain* seatSelection;
	bool isConfirmed = false;


	// GETTING SEAT SELECTED //
	do { // Confirmed Choice


		// USER INPUT //
		fprintf(OUTPUT_LOCATION, "%s", " Entry: ");
		seatSelection = getValidSeat(seatPTR); // Getting User Selection


		// SEAT NOT FOUND //
		if (seatSelection == NULL) { return seatSelection; }


		// QUIT OPTION //
		else if (seatSelection->price == 0) { isConfirmed = true; }


		// CONFIRMING SELECTION //
		else { // Seat Found

			fprintf(OUTPUT_LOCATION, "\n %s %s %s", "You entered,", seatSelection->name, "is that what you meant?\n");
			isConfirmed = confirmChoice(); // Gets Users Entry

		} // Seat Found

		fputs("\n", OUTPUT_LOCATION); // Spacer


	} while (!isConfirmed); // Gets Users Choice of Seat and Ensures Its what they Meant


	// ## OUTPUT ## //
	return seatSelection;

} // FUNCTION // Get Seat Selection


// Get Ticket Selection //
/* Desc
*  Gets Ticket Selection From User By validating range and entry
*/
/* INPUT
*  I: SeatChain Pointer - Head Pointer for Printing
*/
/* OUTPUT
*  O: unsigned int -- Number of Tickets Selected
*/
unsigned int getTicketSelection(SeatChain* seatChoice) {

	// INITILIZATION //
	unsigned int userInput = 0;

	// PRINTING TICKET OPTIONS //
	fprintf(OUTPUT_LOCATION, "%s", " Select a ticket Pack!\n");
	for (size_t i = 1; i < TICKET_CHOICES + 1; i++) { fprintf(OUTPUT_LOCATION, " %llu. %s\t\t$%.2f\n", i, TICKET_NAMES[i - 1], seatChoice->price * i); }


	// GETTING TICKET SELECTION //
	do { // Confirming Chouce
		do { // Confirming range

			fprintf(OUTPUT_LOCATION, "%s 1-%d: ", " Enter a number", TICKET_CHOICES);
			userInput = validateUInt();

		} while (!isWithinRange(userInput, TICKET_CHOICES, 1)); // Range Check


		fprintf(OUTPUT_LOCATION, "\n %s%u:%s \n%s", "You entered ", userInput, TICKET_NAMES[userInput - 1], " Is that what you meant?\n");

	} while (!confirmChoice()); // User Confirmation

	// ## OUTPUT ## //
	return userInput;

} // FUNCTION // getTicketSelection


// Get Zip Code 
/* Desc
*  Gets a user input for their zip code and returns it.
*/
/* OUTPUTS
*  O: Unsinged Int -- User's Entry for Zipcode
*/
unsigned int getZipCode() {

	// INITILIZATION //
	unsigned int userInput = 0;


	// GETTING ZIP CODE //
	do {
		do {

			fprintf(OUTPUT_LOCATION, "\n%s", " Enter your 5 digit Zip Code");
			userInput = validateUInt(); // Gets User Input;

		} while (!isWithinRange(userInput, 99999, 9999)); // Continues untill in range

		fprintf(OUTPUT_LOCATION, "\n%s%u%s\n", " You entered ", userInput, " is this what you meant?");

	} while (!confirmChoice()); // Continues Untill In Rnage and User Confirms Choice


	// ## OUTPUT ## //
	return userInput;

} // FUNCTION // Get Zip Code


// Boot UP
/* Desc
*  Starts the day by having admin set up charity percentage, and seats if the user is able to log on, afterwards it proceeds to sales mode where
*  it will process the days operations. After that finishes prints all reqested info to a file.
*/
/* INPUT
*  I: SeatChain Adress Pointer -- The Main Seat Chain
*  I: double Pointer -- Charity Percentage of the Day
*/
void bootUP(SeatChain** mainSeatPTR, double* charityPercentage) {

	// INTILIZATION //
	bool isLoggedOn = false;
	SeatChain* nullPTR;
	logOn(&isLoggedOn);


	// SUCCESSFUL LOG ON //
	if (isLoggedOn) {


		// CREATING INITIL SEAT
		fprintf(OUTPUT_LOCATION, "%s", "\n Create the Seats for the Days Game!\n");
		do { // Continues Untill Initil Seat is Made

			createSeat(mainSeatPTR); // Create Head Seat
			nullPTR = *mainSeatPTR; // nullPTR for Checking

			if (nullPTR->nextSeat != NULL) {

				fprintf(OUTPUT_LOCATION, "%s", "ERROR AT LEAST ONE SEAT MUST BE MADE!");

			}

		} while (nullPTR->nextSeat != NULL); //While First Seat Isnt Null


		// MULTIPLE SEATS //
		fprintf(OUTPUT_LOCATION, "%s", "\n Would you like to create another seat?");
		if (confirmChoice()) { addSeatToChain(mainSeatPTR); }


		// CHARITY PERCENTAGE //
		*charityPercentage = getCharityPercentage();


		// SALES MODE // 
		salesMode(mainSeatPTR, *charityPercentage);

	} // Sucessful Log On



} // FUNCTION // Day Start


// Sales Mode
/* Desc
*  The sales mode of the program, takes in the percentage and chain for editing and ticket slecting from admin. However, for user processes
*  sales and continues on untill the admin shuts down the system.
*/
/* INPUT
*  I: SeatChain Adress Pointer -- The Main Seat Chain
*  I: Double -- Chairty Percentage of the day
*/
void salesMode(SeatChain** mainSeatPTR, double charityPercentage) {

	// INITILIZATION //
	SeatChain* seatSelection;
	unsigned int ticketSelection = 0;
	bool isLoggedOn = true;


	// ERROR HANDLING //
	if (mainSeatPTR == NULL) { fprintf(OUTPUT_LOCATION, "\n%s", "ERROR NO SEATS CREATED!"); }


	// SALES MODE //
	else { // At least One Entry


		// TICKET SALES //
		do { // While Logged On Keep performing Sale;


			// GETTING SEAT SELECETION //
			fprintf(OUTPUT_LOCATION, "\n%s", WELCOME_MESSAGE);
			printSeatChain(*mainSeatPTR); // Printing Seating Options
			seatSelection = getSeatSelection(*mainSeatPTR); // Gets the Seat Selection


			// QUIT OPTION //
			if (seatSelection == NULL) {

				isLoggedOn = adminPanel(mainSeatPTR, charityPercentage);

			} // Quit Option


			// TICKET SELECTION //
			else { // Real Seat Selected

				ticketSelection = getTicketSelection(seatSelection); // Gets the Ticket Selection 
				getZipCode(); // Get Zip Code From user
				seatSelection->totalSales += ticketSelection * seatSelection->price; // Updating Total Sales
				seatSelection->totalTickets += ticketSelection; // Updating Total Tickets Sold 

			} // Ticket Selection


		} while (isLoggedOn); // Continue Untill Sucessfully logged off


	} // Sales Mode

} // FUNCTION // Sales Mode