
#include <stdio.h>
void clearBuffer();

//MAIN
int main(void)
{
	int userAge = 0;
	puts("Enter your age!");
	scanf("%d", &userAge);
	int *numberPtr =  &userAge;
	clearBuffer();

	if (*numberPtr >= 18) {
		printf("%d, can vote.\n", *numberPtr);
	}
	else{
		printf("%d, can't vote.\n",*numberPtr);
	}

	*numberPtr += 5;
	printf("In 5 years you will be %d\n", *numberPtr);



	return 0;
}//END MAIN


void clearBuffer() {
	while (getchar() != '\n');
}//END clr Buffer
