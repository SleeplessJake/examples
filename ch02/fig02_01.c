// Fig. 2.1: fig02_01.c
// A first program in C 
#include <stdio.h>

int width = 0;
int height = 0;
int area = 0;

//main
int main( void )
{
   printf( "Hello lets solve some equations! Enter a width please: " );
   getInput(width);
   printf("Awesome! Now please enter a height: ");
   getInput(height);
   area = width * height;

   printf("\nWidth: %d\n Height: %d\n Area: %d", width, height, area);


   return 0;

} // end function main 

//scanf input from console -- INT
int getInput(int input) {
	scanf("d", &input);
}


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
