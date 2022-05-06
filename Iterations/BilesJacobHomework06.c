// Jacob Biles
// CS2060
// Homework 06
// The goal of this assignment is to create a mad libs program that takes in three files and 5 inputs of two differente categories
// It will then combine these inputs and then format them based on a random selection from each category. Finally printing it to 
// a file for reading.


#include <stdio.h>//Standard INPUT OUTPUT
#include <stdlib.h>//Standard Library
#include<string.h>//Standard STRING
#include<ctype.h>//C TYPE
#include<stdbool.h>//Standard BOOl

//Madlib Values
#define STRING_LENGTH 100
#define NUMBER_SENTENCES 5
#define NUMBER_WORDS 5
#define WORD_LENGTH 20
#define NOUN "noun"
#define ADJECTIVE "adjective"


//file names and path
const char* MADLIB_FILE = "madlib.txt";
const char* PREPOSITION_FILE = "prepositions.txt";
const char* ARTICLE_FILE = "articles.txt";
const char* VERB_FILE = "verbs.txt";
const char* DIRECTORY_PATH = "C:\\Users\\dacak\\CS2060\\";


/// *** Function ProtoTyping *** ///
void clearBuffer(void);

bool setWordArray(char*, char[][WORD_LENGTH], const char*);

void getFilePath(char*, const char*, const char*);

bool getWordsFromFile(const char*, char[][WORD_LENGTH], const int);

void getUserWords(const char*, char[][WORD_LENGTH], const int);

bool writeSentenceToFile(const char*, const char[][WORD_LENGTH],
	const char[][WORD_LENGTH],
	const char[][WORD_LENGTH],
	const char[][WORD_LENGTH],
	const char[][WORD_LENGTH],
	int, int);

void madLibs(void);


//// #### **  MAIN  ** #### ///
int main(void)
{

	madLibs();

	// For Prorper Return From Main
	return 0;


}  //  ## END ##  // #### **  MAIN  ** #### //


// Clear Buffer
/*Summary
* Clears the buffer by checking and applying for '\n' in the buffer
*/
void clearBuffer(void) {

	while (getchar() != '\n');


} // ## END ## // FUNCTION // Clear Buffer


// Set Word Array
/*Summary
* Finds the path of the file by calling 'getFilePath' to find the path then, assign it accordingly based on
* the 'fileType' parameter passed in. Calling 'getWordsFromFile' to assign the values to the passed array.
*/
/*Inputs
path,
assigned array,
name of the file being passed
*/
bool setWordArray(char* path, char arrayType[][WORD_LENGTH], const char* fileType) {

	getFilePath(path, DIRECTORY_PATH, fileType); // Getting Verb File Path

	//Was Able to ASsign Values
	if ((getWordsFromFile(path, arrayType, NUMBER_WORDS)) == true) {// Getting Words From File


		return true;
	}


	else {

		return false;
	}


} // ## END ## // FUNCTION // Set Word Array


// GET FILE PATH //
/*Summary
* Creats the file path of the determined file by combining the name and directory
*/
/*Inputs
path,
Directory,
Name of File
*/
void getFilePath(char* path, const char* directroy, const char* name) {

	strcpy(path, directroy); // Copy Director to Path
	strcat(path, name); // Copy name to end of Path


} // ## END ## // Function // GET_FILE_PATH


// Get Words From File //
/*Summary
* Assigns words from the file path given to the given words array paramater.
*/
/*Inputs
path,
Assinged Array,
Number of Words in FIle
*/
/*Outputs
* True/False -- Ability to open File
*/
bool getWordsFromFile(const char* path, char words[][WORD_LENGTH], const int numberWords) {

	// Initilization
	FILE* filePtr;
	char* arrayPtr;

	// Opening File for Reading
	filePtr = fopen(path, "r");


	if (filePtr == NULL) { // File Does Not exist

		puts("Error! File Does not Exists!");
		return false; // ## OUTPUT ## //

	}


	else { // *** IF_FILE EXISTS *** //

		// Initilization
		char tempLetter; // Holds input letter
		size_t letterSpot; // Second Array Index Element


		// For All number of words in a file
		for (size_t i = 0; i < numberWords; i++) {

			letterSpot = 0; // Set-or-Reset spot to 0 (First Element, Second Index)


			do { // Do untill a space ' ' character is read

				tempLetter = fgetc(filePtr); // Getting Character from file
				arrayPtr = &words[i][letterSpot]; // Setting Pointer


				// Space Check (' ')
				if (tempLetter != ' ' && tempLetter != EOF) {

					*arrayPtr = tempLetter; // Assinging Chr
					letterSpot++; // Incrementing Letter Spot

				}



				else { // Adding Null character in place of Space (' ')

					*arrayPtr = '\0';

				}


			} while (tempLetter != ' ' && tempLetter != EOF);


		} // ## END ## // FOR # of Words

		return true; // ## OUTPUT ## //


	} // ## END ## // IF_FIlE_EXISITS

	// Close File
	fclose(filePtr);


}// ## END ## // FUNCTION // GET_WORDS_FROM_FILE


// Get User Words // 
/*Summary
* Gets input from user mainting a dertermined size.
*/
/*Inputs
Word Type,
Assinged Array,
Number of Words in FIle
*/
void getUserWords(const char* wordType, char word[][WORD_LENGTH], const int numberWords) {

	char userInput[WORD_LENGTH];
	char* arrayPtr;
	size_t letterSpot;
	printf("Hello please enter 5 %s's\n\n", wordType);


	// For All words to be added
	for (size_t i = 0; i < numberWords; i++) {

		letterSpot = -1;
		fgets(userInput, WORD_LENGTH, stdin); // Getting User INput
		puts(" ");


		do { // Do Untill user input is the New line character


			letterSpot++; // Increments Index 2 of the Array

			arrayPtr = &word[i][letterSpot]; // Assaigns Pointers

			//If New line character
			if (userInput[letterSpot] == '\n') {

				*arrayPtr = '\0'; // Assigns as Null

			}

			// Okay Case
			else {

				*arrayPtr = userInput[letterSpot];

			}


		} while (userInput[letterSpot] != '\n');


	}// ## END ## // FOR LOOP


}


// Get Words From File //
/*Summary
* Takes all arrays that have been assigned either from user or Files and then creates a formated
* string to output to the file. Then it proceds to output it to said file.
*/
/*Inputs
path of file
article array
verb array
prepositions array
noun array
adjectivive array
number of words in each array
number of sentances to be printed
*/
/*Outputs
* True/False -- Ability to open File
*/
bool writeSentenceToFile(const char* path, const char article[][WORD_LENGTH],
	const char verb[][WORD_LENGTH],
	const char preposition[][WORD_LENGTH],
	const char noun[][WORD_LENGTH],
	const char adjective[][WORD_LENGTH],
	int numberWords, int numberSentences) {

	//Rand num gen
	srand(102799); // Seeding

	FILE* filePtr; // File PTR Initilization

	filePtr = fopen(path, "w"); // File Opening


	//File Not found
	if (filePtr == NULL) {

		puts("ERROR! File Could Not Be Opened.");
		return false; // ## OUTPUT ## //

	}


	//Valid File
	else {

		//Write 5 Sentances
		for (int i = 0; i < numberSentences; i++) {

			char sentace[STRING_LENGTH];

			//Writing Sentance
			int randNum = (rand() % 4);

			// Captilize First letter
			char firstLetter = toupper(article[randNum][0]);

			// Sets up first word (excludes first letter)
			const char* firstWord = &article[randNum][1];

			//Creating Output Sentance
			sprintf(sentace, "%c%s %s %s %s %s %s %s %s.\n", firstLetter, firstWord, adjective[(rand() % 4)],
				noun[(rand() % 4)], verb[(rand() % 4)], preposition[(rand() % 4)],
				article[(rand() % 4)], adjective[(rand() % 4)], noun[(rand() % 4)]);

			//Pritining TO file
			fputs(sentace, filePtr);


		} // For All sentances

		fclose(filePtr);//Close File
		return true; // ## OUTPUT ## //


	} // ## END ## // Valid File


} // ## END ## // Function // WRITE_SENTANCE_TO_FILE


//Mad Libs
/*Summary
* The Main call, Initilizes all variables, and calls all appropriate functions. Nests all said functions wihtin if-else checks
* to ensure each step completes correctly. If not, ending the program within that step.
*/
void madLibs(void) {

	//Initilization
	char verbWords[NUMBER_WORDS][WORD_LENGTH]; // File Read
	char prepositionsWords[NUMBER_WORDS][WORD_LENGTH]; // File Read
	char articleWords[NUMBER_WORDS][WORD_LENGTH]; // File Read
	char path[STRING_LENGTH];
	char nounWords[NUMBER_WORDS][WORD_LENGTH];
	char adjectiveWords[NUMBER_WORDS][WORD_LENGTH];


	// Assgining Words To arrays -- Nested To stop if one is an error
	// All else Statments are to follow up the "Faile to open File" message
	// To Let user know which file is the error
	if ((setWordArray(path, verbWords, VERB_FILE)) == true) {
		if ((setWordArray(path, prepositionsWords, PREPOSITION_FILE)) == true) {

			if ((setWordArray(path, articleWords, ARTICLE_FILE)) == true) {

				//Assigning User Input To Arrays
				getUserWords(NOUN, nounWords, NUMBER_WORDS);
				getUserWords(ADJECTIVE, adjectiveWords, NUMBER_WORDS);

				//Getting FIle Path for Written-to-file
				getFilePath(path, DIRECTORY_PATH, "madLibs.txt");

				//Writing Sentance
				if ((writeSentenceToFile(path, articleWords, verbWords, prepositionsWords, nounWords, adjectiveWords, NUMBER_WORDS, NUMBER_SENTENCES)) == true) {}
				else { puts("Writing to MadLib File"); }

			}
			else { puts("Article File"); }

		}
		else { puts("Preposition File"); }

	}
	else { puts("Verb File"); }




} // ## END // FUNCTION // MADLIBS
