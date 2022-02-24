//Jacob Biles
//CS 2060 MW
//WINDOWS
//HW03 PT 2
//Due 2/14/22

/*DESC
* The Goal of this assignment is to make a simple POS system where the user can enter any value (0-10] hours
* and it will calculate the total for the user of the sale. Within this POS it will keep track of the number
* of board sold, the total hours, and sales. While also printing infomation about the current sale. If the value 
* -1 is entered then the program will print these end values.

*/
#include <stdio.h>

//Quit Number
const int QUIT_NUM = -1;
//Cost Per Hour
const double HOURLY_RATE = 10;

//Function Prototyping
double calculateTotal(double numHours);
void clearBuffer();

//MAIN
int main(void)
{
	//initilization 
	double saleHours = 0;
	double saleTotal = 0;
	double dayTotalHours = 0;
	double dayTotalSales = 0;
	unsigned int boardCount = 0;


	//Main Loop not equal -1
	while (saleHours != QUIT_NUM) {

		saleHours = 0;

		//Getting Input
		puts("Please enter 1-10 hours");
		scanf("%lf", &saleHours);
		puts("");
		clearBuffer();

		//Ensuring valid input 1-10 or -1
		while (saleHours != -1 && (saleHours <= 0 || saleHours > 10)) {
			puts("(human) Error! enter 1-10 hours");
			scanf("%lf", &saleHours);
			puts("");
			clearBuffer();
		}

		//Printing of sale (unless quiting)
		if (saleHours != -1) {
			saleTotal = calculateTotal(saleHours);
			dayTotalSales += saleTotal;
			dayTotalHours += saleHours;
			boardCount++;
			puts("Board\t\tHours\t\tCost");
			printf("%d\t\t%.2f\t\t%.2f\n\n", boardCount, saleHours, saleTotal);
		}

	}

	//Printing EOD Sales
	printf("Total Boards: %d\nTotal Sales: $%.2f\nTotal Hours: %.2f\n", boardCount, dayTotalSales, dayTotalHours);


	return 0;
}//END MAIN

//Function Clear Buffer -- Clears Buffer
void clearBuffer() {
	while (getchar() != '\n');
}//END clr Buffer

//Function Calculate Total -- TotalHours*HOURLY_RATE = Int (returned)
double calculateTotal(double hours) {
	double temp = 0;
	if (hours > 2) {
		temp = ((hours - 2) * HOURLY_RATE) + 35;
	}
	else {
		temp = 35;
	}

	return temp;
}//END calculateTotal
