#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH 13

void validateInt(const char* buff);

int main(void) {
char inputStr[LENGTH];
fgets(inputStr, LENGTH, stdin);
validateInt(&inputStr[0]);
}

void validateInt(const char* buff)
{
	
	char* end;
	errno = 0;
	int validInt = 0;
	long intTest = strtol(buff, &end, 10);

	if (end == buff) {
		fprintf(stderr, "%s: not a decimal number\n", buff);
	}

	else if (*end != '\n') {
		fprintf(stderr, "%s: extra characters at end of input: %s\n", buff, end);
	}

	else if ((LONG_MIN == intTest || LONG_MAX == intTest) && ERANGE == errno){
		fprintf(stderr, "%s out of range of type long\n", buff);
	}

	else if (intTest > INT_MAX)	{
		fprintf(stderr, "%ld greater than INT_MAX\n", intTest);
	}

	else if (intTest < INT_MIN) {
		fprintf(stderr, "%ld less than INT_MIN\n", intTest);
	}

	else {			

		validInt = (int)intTest;
		printf("%ld is integer value ", intTest);	

	}

}
