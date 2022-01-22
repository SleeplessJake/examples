// Fig. 2.1: fig02_01.c
// A first program in C 
#include <stdio.h>

/*
	Jacob Biles
	Homework 01 - 1/27/22
	1/22/2022

	The goal of this assignment is to learn and get comfortable with our IDE and figure out some basics of c.
	*/


//Main paramaters int to zero;
int width = 0;
int height = 0;
int area = 0;
int dividedValues = 0;

//bool for requring int
int isAnInt = 0;

//main
int main(void)
{

	printf("Hello lets solve some equations! Enter a width please: ");
	scanf("%d", &width);
	printf("Awesome! Now please enter a height: ");
	scanf("%d", &height);
	area = width * height;

	printf("\nWidth: %d\nHeight: %d\nArea: %d\n", width, height, area);

	dividedValues = height / width;


	return 0;

} // end function main 

//scanf input from console -- INT -- REMOVED FUNCTION (need to learn about pointers)
													// * Learning now for methods need
													// * pointers -- (* , >>) these symbols
													// * what do they mean??



/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
