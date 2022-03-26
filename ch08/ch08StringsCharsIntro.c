// Chars Arrays Strings Pointers Exploration
// Read section 6.5 and 7.10
// Add comments to code to explain or ask questions

//I tried %i %u %lu, %llu and %zu for size_t
// and I get warnings for each one 


#include <stdio.h>
#include <stdlib.h>


// prototype
void introStringChar(void);
void arrayPointerString(void);

int main(void)
{
	//arrayStringPointer();
	//introStringChar();
	arrayPointerString(); 

	return 0;
}

//Understanding chacters and array of characters (strings)
void introStringChar(void)
{
	
	// add comment 
	// initilizing the character myCharacter to m
	// initilizing the integer myCharacter2 to ASCII value of m
	char myCharacter = 'm';
	int myCharacter2 = 'm';
	
	// add comment 
	// Printing the character myCharacter ('m') as an int (its ASCII value)
	// Printing the scharacter myCharaceter('m') as an char 
	puts("What is happening?");
	printf ("myCharacter = %d\n", myCharacter);
	printf ("myCharacter = %c\n", myCharacter);


	// add comment 
	// Printing the character myCharacter ('m') as an int (its ASCII value)
	// Printing the scharacter myCharaceter('m') as an char 
	printf ("myCharacter = %d\n", myCharacter2);
	printf ("myCharacter = %c\n", myCharacter2);

 
	// add comments
    puts("\nWhat do you notice about the following?\n");
	char myString[] = "String in C";
    printf ("myString[] = %s\n", myString);
    
	char *myStringPtr = "String in C";
    printf ("*myStringPtr = %s\n", myStringPtr);
        
	//char stringArray[3] = "String in C";
    //printf ("stringArray[3] = %s\n", stringArray);
    
	puts("\nA string in C is a");
	puts("Sequence of characters that end with FILL IN");
	puts("No special type for strings in C so define with FILL IN ");
	puts("String is accessed using FILL IN which is pointer to FILL IN");
				
	// add comments
	puts("\nWhat do you notice about the following?");
	printf ("myString[] sizeof    = %llu\n", sizeof(myString));
	printf ("*testPtr sizeof    = %llu\n", sizeof(*myStringPtr));

		
	// add comments
    // Why doesn't this line of code work? myString[] = "new string";
	char string1[10];
    char string2[10];
    
	// add comment 	
	puts("\nWhat do you notice about how you use scanf when reading a string?");
	// add comment 	
	printf("%s", "Enter a string longer than 10 characters: ");
	// add comment 	
	scanf("%10s", string1);

	// add comment
	printf("string1 is: %s\n", string1);
    printf("%s", "Enter a string longer than 10 characters: ");
    
    scanf("%s", string2);
	printf("string2 is: %s\n", string2);

	puts("");

}

//Understanding Array of pointers to array of characters
void arrayPointerString(void)
{
	// add comment 
	char suitArray[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *suitPtr[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};	
	
	// add comment 
	puts("\n\nWhy use array of pointers rather than 2d array?");
	printf ("*suitPtr size_of    = %llu\n", sizeof(*suitPtr));
	printf ("suitArray[4][9] sizeof    = %zu\n", sizeof(suitArray));

	puts("\nHow do you access an array of pointers?");
	
	// add comment 
	puts("\nWhat is this doing?");
	printf ("&suitPtr[0] = %p\n", &suitPtr[0]);
	printf ("&suitPtr[1] = %p\n", &suitPtr[1]);
	printf ("&suitPtr[2] = %p\n", &suitPtr[2]);
	printf ("&suitPtr[3] = %p\n", &suitPtr[3]);

	// add comment
	puts("\nWhat is this doing?");
	printf ("suitPtr[0] = %p\n", suitPtr[0]);
	printf ("suitPtr[1] = %p\n", suitPtr[1]);
	printf ("suitPtr[2] = %p\n", suitPtr[2]);
	printf ("suitPtr[3] = %p\n", suitPtr[3]);

	// add comment
	puts("\nWhat is this doing?");
	printf ("suitPtr[0] = %s\n", suitPtr[0]);
	printf ("suitPtr[1] = %s\n", suitPtr[1]);
	printf ("suitPtr[2] = %s\n", suitPtr[2]);
	printf ("suitPtr[3] = %s\n", suitPtr[3]);

	// add comment
	puts("\nWhat is this doing?");
	printf ("*suitPtr[0] = %c\n", *suitPtr[0]);
	printf ("*suitPtr[1] = %c\n", *suitPtr[1]);
	printf ("*suitPtr[2] = %c\n", *suitPtr[2]);
	printf ("*suitPtr[3] = %c\n", *suitPtr[3]);

	// add comment
	puts("\nWhat is this doing?");
	printf ("suitPtr[0][0] = %c\n", suitPtr[0][0]);
	printf ("suitPtr[0][1] = %c\n", suitPtr[0][1]);
	printf ("suitPtr[0][2] = %c\n", suitPtr[0][2]);
	printf ("suitPtr[0][3] = %c\n", suitPtr[0][3]);
	printf ("suitPtr[0][4] = %c\n", suitPtr[0][4]);
	printf ("suitPtr[0][5] = %c\n", suitPtr[0][5]);

	
	
}

 



