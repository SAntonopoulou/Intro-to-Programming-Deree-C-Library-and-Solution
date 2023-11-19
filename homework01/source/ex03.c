// ** NOTE: This program should be modified ot use my own strcmp function to reduce the
// size of imports. However, for now, using the string.h library is sufficent.
// (MEDIUM priority)
//
// ** NOTE: Eventually this program should be modified to calculate the current year 
// programatically to check the user supplied date for the current year. However, for the
// moment it simply uses a definition of CURRENT_YEAR to handle this check. Not idea. 
// (HIGH priority)

#include <stdio.h>
#include <string.h>

// unused but will be used in the future until I am able to modify this to generate the 
// current year programatically - this is a stepping stone. I am just too lazy to have the
// current year be caculated by the program at the moment ;P 
#define CURRENT_YEAR 2023

int calculate_user_age(int current_year, int birth_year);
int retrieve_year_from_user_with_validation(char type_of_year[2]);
void clear_input_buffer();

int main()
{
	int current_year;
	int birth_year;
	int user_age;

	birth_year = retrieve_year_from_user_with_validation("b");
	current_year = retrieve_year_from_user_with_validation("c");

	user_age = calculate_user_age(current_year, birth_year);

	printf("You are %d years old, or %d years old.\n", user_age, (user_age - 1));
	
	return 0;
}

int calculate_user_age(int current_year, int birth_year)
{
	return (current_year - birth_year);
}

int retrieve_year_from_user_with_validation(char type_of_year[2])
{
	// ** NOTE: This ought to be modified in the future to use a long long instead of an
	// integer as at the moment entering a value that is lager than the maximum value that
	// can be held in an integer will result in unpredicatable behaviour. 
	// (HIGH priority)
	//
	// ** NOTE: This can be modified to allow the program to specify which type of input 
	// is expected and to handle all types (ex. float, double, character array, integer, etc.)
	// within this single function - however, for now, this is adequate.
	// (MEDIUM priority)

	// ** NOTE: This should be modified to allow user validation of the resulting integer
	// to be turned on or off with a parameter to allow for more use cases of this function.
	// (LOW priority)

	int user_input;
	int status;
	char user_response[20];
	
	// prompt the user for an integer
	if(type_of_year == "b")
	{
		printf("Please enter your birth year (xxxx): ");
	}
	else if(type_of_year == "c")
	{
		printf("Please enter the current year (xxxx): ");
	}
	else
	{
		printf("ERROR: Invalid request.");
		return 1;
	}
	status = scanf("%d", &user_input);
	
	while(status != 1){
		// clear the input buffer character by character
		clear_input_buffer();
		// prompt the user for another input
		printf("You did not enter an integer.\n");
		printf("Please enter an integer: ");
		// set the status again to validate user input
		// reloop until the user has supplied a valid 
		// integer value.
		status = scanf("%d", &user_input);
	}	
	clear_input_buffer();
	if(type_of_year == "b")
	{
		printf("Your birth year is %d. Is this correct (y/n): ", user_input);
	}
	else
	{
		printf("The current year is %d. Is this correct (y/n): ", user_input);
	}
	scanf("%c", &user_response);
	clear_input_buffer();
	// check if strings are equal. Will return 0 if equal and therefore
	// will no longer loop if the user entered 'y'. If the user entered
	// anything other than 'y' it will reloop and ask them for another 
	// integer.
	if(strcmp(user_response, "y")){ user_input = retrieve_year_from_user_with_validation(type_of_year); }
	
	// return the validated user input for further use in the program
	return user_input;
}

void clear_input_buffer()
{
	// this will hold the individual characters as it walks through the remaining input
	// until you reach the EOF or new line character to indicate the end of user input.
	// More or less clears input to allow for furter input by the user etc.	
	int temp;
	while((temp=getchar()) != EOF && temp != '\n');
}
