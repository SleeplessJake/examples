//Jacob Biles
//CS 2060 002
//HO04 -- 2/23/22

//Desc -- The goal of this assignment is to create a moque version of canvas in which takes in constant variables
//Such as the ones given in the very beggining, allow them for change in different cases (modulizing them) and eunsuring
//Different catergories, numbers of students, grades, etc can be assigned for the students. Within this -- it adds each 
//grade to the student and allows them to have a grade for each catergory (2D array) -- in which it will calculate 
//the grade of that catergory based on the weight of a constnat (pretend array) that is pased in. Finally displaying the
//Letter grade for the appropriate grade and calculating an average for the class.


#include <stdio.h>
#define STUDENTS 4
#define GRADE_CATEGORIES 5
#define CATEGORIES "1. Learning Activity 2. Homework 3. Project 4. Midterm 5. Final "
const double GRADE_CATEGORY_WEIGHT[] = { 0.1, 0.3, 0.3, 0.15, .15 };

//Prototyping
void clearBuffer();

void printHeader(int whichHeader);

//MAIN
int main(void)
{
	//2D Array Creation
	double arrayStudentsGrades[STUDENTS][GRADE_CATEGORIES];
	double arrayStudentFinalGrades[STUDENTS];

	//Array pointer
	double* studentGradePtr = 0;
	double gradeAverage = 0;
	double temp = 0;
	//Initilization loading screen -- Done once 
	printf("\t%s\n\t%s\n\t%s%s\t\n", "Loading....", "Welcome to JakeBook, lets begin.", "This gradebook has: ", CATEGORIES);
	printHeader(0);

	//User Input
	//#Students
	for (size_t i = 0; i < STUDENTS; i++) {

		printHeader(1);

		//#Categories
		for (size_t j = 0; j < GRADE_CATEGORIES; j++) {
			//#Print once if correct, goes over again if invalid entry.
			do {
				//
				studentGradePtr = &arrayStudentsGrades[i][j];
				printf("\t\nPlease Enter Student %llu's grade for category %llu: ", i + 1, j + 1);
				
				scanf("\t%lf", &temp);
				temp *= GRADE_CATEGORY_WEIGHT[j];

				arrayStudentsGrades[i][j] = temp;

				clearBuffer();

			} while (*studentGradePtr < 0 || * studentGradePtr > 100);

		}

	}//End INPUT

	//Print Summary
	for (size_t i = 0; i < STUDENTS; i++) {
		printf("\n Student %llu grades:", i);
		for (size_t j = 0; j < GRADE_CATEGORIES; j++) {
			studentGradePtr = &arrayStudentsGrades[i][j];
			printf("\t%.1f", *studentGradePtr / GRADE_CATEGORY_WEIGHT[j]);
		}
	}//End Summary

	for (size_t i = 0; i < STUDENTS; i++) {
		printf("\n Student %llu end grade:", i);
		temp = 0;
		for (size_t j = 0; j < GRADE_CATEGORIES; j++) {
			studentGradePtr = &arrayStudentsGrades[i][j];
			temp += *studentGradePtr;
		}
		
		temp / GRADE_CATEGORIES;
		arrayStudentFinalGrades[i] = temp;
		if (temp > 90) {
			printf("%.2f A", temp);
		}
		else if (temp > 80) {
			printf("%.2f B", temp);
		}
		else if (temp > 70) {
			printf("%.2f C", temp);
		}
		else if (temp > 60) {
			printf("%.2f D", temp);
		}
		else {
			printf("%.2f F", temp);
		}

		gradeAverage += temp;
	}// Final Grade printing

	//find average
	gradeAverage = gradeAverage / STUDENTS;

	//print average
	printf("\n\n The class average was %.2f", gradeAverage);
	return 0;
}//END MAIN


//Methods
void clearBuffer() {
	while (getchar() != '\n');
}//END clr Buffer

void printHeader(int whichHeader) {
	if (whichHeader == 0) {
		puts("");
		for (size_t i = 0; i < GRADE_CATEGORIES; i++) {
			printf("\tWith Category %llu having a scale of: %.2f\n", i, GRADE_CATEGORY_WEIGHT[i]);
		}
	}

	else {
		printf("\n%s", CATEGORIES);
	}
}//END print header