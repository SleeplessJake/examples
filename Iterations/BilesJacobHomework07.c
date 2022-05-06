
// ###  LIBRARIES  ### //
#include <stdio.h>// STD Input Output
#include <stdlib.h>// STD Libraries
#include <stdbool.h>// STD Boolean
#include <ctype.h>// C Type
#include <string.h> // String



// ###  CONSTANTS  ### ///
#define STRING_SIZE 60
#define INPUT_LOCATION stdin
#define OUTPUT_LOCATION stdout



// ###  STRUCTURES  ### ///
typedef struct Pet { // Pet Facade

	char name[STRING_SIZE];
	unsigned int age;
	struct Pet* nextPTR;


}Pet;



// ###  FUNCTION PROTOTYPES  ### ///
void clearBuffer(void); // Clears Buffer from insecure FXNS
bool confirmChoice(void); // Gets User Validation 
unsigned int getNumberOfPets(void); // Gets Number of Pets to Create
void setPetAge(Pet*); // Assigns A PetPTR's Age
void setPetName(Pet*); // Assigns A PetPTR's Name
Pet* createPet(void); // Creates A Pet from Strut
void addPet(Pet*); // Create Linked Pet List
void sortPetList(Pet*, const unsigned int); // Sorts Linked List Alphabetically
void deleteAnimal(Pet*); // Deletes specified Animal

// ###  MAIN  ### //
int main(void) {

	unsigned int numberOfPets = getNumberOfPets();

	Pet* somePet = createPet();

	for (unsigned int i = 0; i < numberOfPets - 1; i++) {
		addPet(somePet);
	}

	sortPetList(somePet, numberOfPets);

	return 0; // ## OUTPUT ## //

} //  ## END ##  // ###  MAIN  ### //


// ###  FUNCTION IMPLEMENTATION  ### //
void clearBuffer(void) {



	while ((getchar()) != '\n');


} // FUNCTION // Clear Buffer //


bool confirmChoice(void) {


	fprintf(OUTPUT_LOCATION, "%s", "Entry (Y/N): "); // Prompt
	char tempChar = toupper(fgetc(INPUT_LOCATION)); // ##  INPUT  ## //
	clearBuffer(); // Clear Buffer


	// ##  OUTPUT  ## //
	if (tempChar == 'Y') { return true; } // Yes -- True
	else { return false; } // No -- False


} // FUNCTION // Confirm Choice //


unsigned int getNumberOfPets(void) {

	//Initilization
	unsigned int tempNum;

	do { // Untill Correct Selection

		puts("#######ENTER NUMBER OF PETS#######"); // Header
		fprintf(OUTPUT_LOCATION, "%s", "Entry: "); // Prompt

		fscanf(INPUT_LOCATION, "%d", &tempNum); // ##  INPUT  ## //
		clearBuffer(); // Clearing Buffer

		fprintf(OUTPUT_LOCATION, "\nYou entered: %d\n", tempNum); // Re-Prompt
		fputs("Is this what you meant?\n", OUTPUT_LOCATION); // Header

	} while (!confirmChoice()); // Continue Untill Confirmed ('Y') Entered

	return tempNum; // ##  OUTPUT  ## //


} // FUNCTION // Get Number Of Pets //


void setPetAge(Pet* somePet) {

	//Initilization
	int tempAge;


	do { // Do Untill Selection Is Validated


		fputs("\n##########ENTER PET AGE ##########\n", OUTPUT_LOCATION); // Header
		fprintf(OUTPUT_LOCATION, "%s", "Entry: "); // Prompt

		fscanf(INPUT_LOCATION, "%d", &tempAge); // ##  INPUT  ## //
		clearBuffer(); // Clearing Buffer

		fprintf(OUTPUT_LOCATION, "\nYou entered: %d\n", tempAge); // Re-Prompt
		fputs("Is this what you meant?\n", OUTPUT_LOCATION); // Header

	} while (!confirmChoice()); // Continue Untill Confirmed ('Y') Entered


	somePet->age = tempAge; // Assigning Pets Age


} // FUNCTION // Set Pet Age //


void setPetName(Pet* somePet) {

	//Initilization
	char tempName[STRING_SIZE];
	char* stringPTR = tempName;


	do { // Do Untill User Selects Is Valid


		fputs("\n#######ENTER A NAME#######\n", OUTPUT_LOCATION); // Header
		fprintf(OUTPUT_LOCATION, "%s", "Entry: "); // Prompt

		fgets(stringPTR, STRING_SIZE, INPUT_LOCATION); // ##  INPUT  ## //

		fprintf(OUTPUT_LOCATION, "\nYou entered: %s", tempName); // Re-Prompt
		fputs("Is this what you meant?\n", OUTPUT_LOCATION); // Header

	} while (!confirmChoice());


	strcpy(somePet->name, strtok(tempName, " \0"));


} // FUNCTION // Set Pet Name //


Pet* createPet(void) {

	//Initilization 
	Pet* petPTR = malloc(sizeof(Pet)); // Allocating Pointer
	setPetAge(petPTR); // Assinging Age to Pointer
	setPetName(petPTR); // Assigning Name to Pointer
	petPTR->nextPTR = NULL;
	return petPTR;

} // FUNCTION // Create Pet

void addPet(Pet* somePet) {

	//Initilization
	Pet* nextPet;


	if ((somePet->nextPTR) == NULL) { // Only One Pet

		somePet->nextPTR = createPet(); // Add Next Pet

	}

	else { // Multiple Pets

		nextPet = somePet;

		do {

			nextPet = nextPet->nextPTR;

		} while (nextPet->nextPTR != NULL);

		nextPet->nextPTR = createPet();

	} // Multiple Pets


}

void sortPetList(Pet* somePet, unsigned int numberPets) {


	if (somePet->nextPTR == NULL) { // Only One Pet Error Check

		fprintf(OUTPUT_LOCATION, "%s", "Only one Pet in list");

	}


	else { // Multiple Elements

		//Initilization
		Pet tempPet;
		Pet* firstPet = somePet;
		Pet* nextPet = somePet;
		Pet* returnedPet = somePet;

		unsigned int secondPetNameValue;
		unsigned int initilPetNameValue;



		do { // Do Untill End of List Reached

			nextPet = nextPet->nextPTR; // One spot Over

			secondPetNameValue = (toupper(nextPet->name[0])); // Secondary Spot
			initilPetNameValue = (toupper(firstPet->name[0])); // First Location


			// Order Check -- Checks up to 3 spaces
			if (secondPetNameValue < initilPetNameValue || secondPetNameValue == initilPetNameValue) {


				// First Characters Equivalent
				if (secondPetNameValue == initilPetNameValue) {

					secondPetNameValue = (toupper(nextPet->name[1]));
					initilPetNameValue = (toupper(firstPet->name[1]));


					// Second Character Check
					if (secondPetNameValue < initilPetNameValue || secondPetNameValue == initilPetNameValue) {


						// Second Characters Equal
						if (secondPetNameValue == initilPetNameValue) {

							secondPetNameValue = (toupper(nextPet->name[2]));
							initilPetNameValue = (toupper(firstPet->name[2]));


							// Third Characters Check
							if (secondPetNameValue < initilPetNameValue || secondPetNameValue == initilPetNameValue) {


								// Third Inequality
								if (secondPetNameValue != initilPetNameValue) {

									firstPet = nextPet;
									returnedPet = firstPet;

								}// Third Inequality
							} // Third Check 
						} // Second Equivalent 


						else { // Second Inequality

							tempPet = *nextPet;
							firstPet = nextPet;
							returnedPet = firstPet;


						} // Second Inequality
					} // Second Check 
				} // First Equivalent


				else { // First Inequality

					tempPet = *firstPet; // Copy First Location

					firstPet = nextPet; // Replace First Location With Second

					nextPet = &tempPet; // Replace Second Location With First

					if (firstPet->nextPTR != NULL) {

						nextPet->nextPTR = firstPet->nextPTR;

					}

					else {

						tempPet.nextPTR = NULL;

					}

					firstPet->nextPTR = nextPet;;

				} // First Inequality
			} // Order Check

			returnedPet = firstPet;

		} while (nextPet->nextPTR != NULL); // End Replacing

		*somePet = *returnedPet;

	} // More than one Element

}// FUNCTION // Sort Pet List //

void deleteAnimal(Pet* somePet) {

	//Initilization
	Pet* deletedLocation;
	Pet* nextPet;
	Pet* previousPet;
	char name[STRING_SIZE];
	char petName[STRING_SIZE];


	fputs("Would you like to delete an Animal?\n", OUTPUT_LOCATION); // Prompt
	while (confirmChoice()) { // Ask untill No entered

		fputs("\n##########ENTER PET NAME##########\n", OUTPUT_LOCATION); // Header
		fprintf(OUTPUT_LOCATION, "%s", "Entry: "); // Prompt

		fgets(name, STRING_SIZE, INPUT_LOCATION); // Gets Name
		clearBuffer();

		//strcpy(petName, somePet->name);
		clearBuffer();


		//First Entry Check -- Loops Incase of Multiple 
		while (somePet != NULL && strcmp(name, petName) == 0) {

			deletedLocation = somePet->nextPTR; // Saving Link
			free(somePet); // Deallocation
			somePet = deletedLocation; // Resassignation of Head

		}


		if (somePet != NULL && somePet->nextPTR != NULL) { // If there are still other elements

			previousPet = somePet; // Head
			nextPet = somePet; // Incrementor

			do { // Do untill all Elements looped

				// Incremeant if Possible
				nextPet = nextPet->nextPTR;


				if (strcmp(nextPet->name, name) == 0) { // Mathces

					deletedLocation = nextPet->nextPTR; // Saving Link
					free(nextPet); // Deallocation
					previousPet->nextPTR = deletedLocation; // Re Linking
					nextPet = previousPet; // Reassignition

				}


			} while (nextPet->nextPTR != NULL); // Untill Last ELement Checked

		} // Still More than One Element


		fputs("Would you like to delete another Animal? (Y/N)\n", OUTPUT_LOCATION); // Prompt

	} // More Than One Element



} // FUNCTIOM // Delete Animal