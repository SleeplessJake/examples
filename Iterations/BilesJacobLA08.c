




////##########################################////
////####                                  ####////
////####**#          LIBRARIES         #**####////
////####                                  ####////
////##########################################////


//Standard INPUT OUTPUT
#include <stdio.h>

//Standard Library
#include <stdlib.h>

//Standard STRING
#include<string.h>

//C TYPE
#include<ctype.h>




////##########################################////
////####                                  ####////
////####**#  DEFINITIONS // CONSTANTS  #**####////
////####                                  ####////
////##########################################////



/// ### DEFINITION ### // MAX_NUM_SUITS ///
//  Set to the 4 For Suits of a Deck
//  USED IN ('*SUIT_POINTER') ARRAY
#define MAX_NUM_SUITS 4



/// ### DEFINITION ### // MAX_PATH_SIZE ///
//  Set to 80 For Worst-Case Scenerio 
//  USED IN ('FILE_filePath[]') #### INITILIZATION  ####
#define POSSIBLE_PATH_SIZE 80

/// ### DEFINITION ### // MAX_PATH_SIZE ///
//  How Many Times the Program Should Print
//  Set to 20 for Assignment Case
#define NUM_PRINTS 20




/// ### DEFINITION ### // SUIT_POINTER ///
//  Holds Names of Suits
//  TAKES IN ('MAX_NUM_SUITS') ### DEFINITION ###
const char* SUIT_NAME_POINTER[MAX_NUM_SUITS][32] =
{


	{"hearts"} /* Heart Suit [0] */,
	{"diamond"} /* Diamond Suit [1] */,
	{"spades"} /* Spade Suit [2] */,
	{"clubs"} /* Club Suit [3] */,


};//  ## END ##  // ### DEFINITION ### /// SUIT_POINTER //

//  TAKES IN ('MAX_NUM_SUITS') ### DEFINITION ###
char SUIT_NAMES[MAX_NUM_SUITS][32] =
{


	{"hearts\0"} /* Heart Suit [0] */,
	{"diamond\0"} /* Diamond Suit [1] */,
	{"spades\0"} /* Spade Suit [2] */,
	{"clubs\0"} /* Club Suit [3] */,


};//  ## END ##  // ### DEFINITION ### /// SUIT_POINTER //




///##########################################///
///####                                  ####///
///####**      FUNCTION_PROTOTYPES     **####///
///####                                  ####///
///##########################################///





////##########################################////
////####                                  ####////
////####**              MAIN            **####////
////####                                  ####////
////##########################################////



//// #### **  MAIN  ** #### ///
int main(void)
{


	// Assigning Random Seed
	// Assigns the Seed for srand()
	unsigned int randSeed = 10271999;
	srand(randSeed);





	////##########################################////
	////####                                  ####////
	////######        INITIZILIZATION       ######////
	////####                                  ####////
	////##########################################////



	// ### FILE ### // ### INITILIZATION ### //
	char FILE_fileName[] = "suits.txt";// ### FILE ### Name (What it's called)
	char FILE_fileDirectory[] = "C:\\CS2060\\";// ### FILE ### Directory (Which Foulder)
	char FILE_filePath[POSSIBLE_PATH_SIZE]; // ### FILE #### Path (Where it's Located)



	// ### FILE ### // PATH_DETERMINATION
	/* Takes ONE (Solt / Memory Location / Reference) Over
	 * Subtract Original Reference
	 * Since Each Element in an ARRAY adds +1 to the ARRAY Reference
	 *
	 * Ex (00FFFF00, 00FFFF01, 00FFFF02) -- For a SIZE THREE ARRAY
	 * Ex (00FFFF00)+1 == (00FFFF03) -- For a SIZE THREE ARRAY
	 * Ex (00FFFF00) - (00FFFF03) == 3 -- For a SIZE THREE ARRAY
	 *
	 * Tried to Make A ### FUNCTION ### Adress Copying Hard
	 *
	 * OUTPUT SIZE_T -- What Remains (The Difference in Locations     */
	size_t arrayLength = *(&FILE_fileName + 1) - FILE_fileName;


	//Copy Start of Path ('FILE_fileDirectory')
	strcpy(FILE_filePath, FILE_fileDirectory);


	//Copy End of Path ('FILE_fileName') APPEND to ('path')
	strncat(FILE_filePath, FILE_fileName, arrayLength);



	// ### FILE ### // INITILIZATION_OF_POINTER //
	FILE* FILE_filePTR;



	// ### FILE ### // OPENING_FILE //
	FILE_filePTR = fopen(FILE_fileName, "w");



	// ***  CHECK IF CORRUPT // NON-EXISTENT  *** //
	// Checks to See if File is NULL on Open
	if (FILE_filePTR == NULL) {


		// Lets USer Know Corruption // Lack of Creation //
		puts("File is either Corrupted or Non-Existenet");

	} // ## END ## // ***  CHECK IF CORRUPT // NON-EXISTENT  *** //



	// ***  FILE EXISTS *** //
	// Checks to See if File is Openable
	else {

		unsigned int randValue = rand() % (3 - 0) + 0;

		/// ***  FOR ALL ELEMENTS IN MAX_NUM_SUITS *** ///
		// Loops For determined amount of Times
		for (size_t i = 0; i < MAX_NUM_SUITS; i++) {

			SUIT_NAMES[i][0] = toupper(SUIT_NAMES[i][0]);

			switch (randValue){


			case 0: // Heart

				fputs(SUIT_NAMES[i], FILE_filePTR);

				break;


			case 1: // Diamond

				fputs(SUIT_NAMES[i], FILE_filePTR);

				break;


			case 2: // Spade

				fputs(SUIT_NAMES[i], FILE_filePTR);

				break;


			case 3: // Club

				fputs(SUIT_NAMES[i], FILE_filePTR);

				break;


			default: // Default Case

				break;

			} //

			
		} //

		printf("Your File can be found at: %s", FILE_filePath);

	}  // ## END ## // ***  OPENABLE  *** //


	//Close File For Writing
	fclose(FILE_filePTR);

	
	////##########################################////
	////####                                  ####////
	////######      RETURN 0 FOR MAIN       ######////
	////####                                  ####////
	////##########################################////


	// OUTPUTS -- INT ('0')
	// For Prorper Return From Main
	return 0;




}/////  ## END ##  // #### **  MAIN  ** #### /////





	////##########################################////
	////####                                  ####////
	////####**          FUNCTIONS           **####////
	////####                                  ####////
	////##########################################////

