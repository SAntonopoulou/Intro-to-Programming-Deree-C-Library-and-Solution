// Dr. Rigas, 
//
// I have continued to use and develop my library for this project. You can see all the fuctions used in the
// lib/my-lib.c file - which I have included with this assignment. The function safely_get_double is more or
// less the verification do/while loop from the last assignment put into a function of it's own so that one
// merely has to submit the prompt they would like to show the user and then it retreives input, verifies
// that it is a valid double value, converts the string to a double, and then returns that to the program
// for further processing. If the user enters invalid input the function will warn them that they have done 
// so and continue to prompt them until they have entered a valid input as a double. I'll also be adding one
// that does the same for integers, but did not do it yet for this assignemnt.
//
// Whlie all of this is extra I have not included it in this file so that it is easier for you to check the
// actual code relevant to the assignment (the get_grade_category function) without being distracted by all
// my other code. I hope this is okay. 
//
// Best wishes, 
//
// Sophia W. 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/my-lib.h"

char* get_grade_category(double);

int main()
{
	printf("Mark: %s\n", get_grade_category(safely_get_double("Enter grade: ")));

	return (0);
}

char* get_grade_category(double grade)
{
	// The return value from this function will be a string set to the
	// sentence/category specified for each range of grade point average.
	char* return_value;

	if(grade < 40.0) { return_value = "FAILED"; }
	else if(grade >= 40 && grade <= 54) { return_value = "FAIR"; }
	else if(grade >= 55 && grade <= 64) { return_value = "GOOD"; }
	else if(grade >= 65 && grade <= 74) { return_value = "VERY GOOD"; }
	else { return_value = "EXCELLENT"; }
	
	return (return_value);		
}
