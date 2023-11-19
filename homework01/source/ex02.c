// ** NOTE: This program should be modified ot use my own strcmp function to reduce the
// size of imports. However, for now, using the string.h library is sufficent.
// (MEDIUM priority)

#include <stdio.h>
#include <string.h>

int retrieve_integer_from_user_with_validation();
float retrieve_float_from_user_with_validation();
void clear_input_buffer();


int main()
{
	int width;
	float height;

	width = retrieve_integer_from_user_with_validation();
	height = retrieve_float_from_user_with_validation();
	
	printf("\nThe result of %d/3 is %d and the type is of type int.\n", width, (width/3));
	printf("The result of %d/2.0 is %.2f and the type is of type float\n", width, (width/2.0));
	printf("The result of %.2f/2 is %.2f and the type is of type float\n\n", height, (height/2));
	
	return 0;
}

float retrieve_float_from_user_with_validation()
{
	// This function works exactly as does retrieve_integer_from_user_with_validation() which
	// is heavily documented below. Please see that function for clarification as to how this works.
	// This function will become obsolete once the modifications noted in the comment header in the
	// function mentioned are complete.
	float user_input;
	int status;
	char user_response[20];
	
	printf("Please enter a float: ");
	status = scanf("%f", &user_input);

	while(status != 1)
	{
		clear_input_buffer();
		printf("You did not enter a floating point number.\n");
		printf("Please enter a float: ");
		status = scanf("%f", &user_input);
	}
	clear_input_buffer();
	printf("Your input as a floating point number will be %.2f. Is this acceptable (y/n): ", user_input);
	scanf("%c", &user_response);
	clear_input_buffer();
	if(strcmp(user_response,"y")){ retrieve_float_from_user_with_validation(); }

	return user_input;
}

int retrieve_integer_from_user_with_validation()
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
	printf("Please enter an integer: ");
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
	printf("Your input as an integer will be %d. Is this acceptable (y/n): ", user_input);
	scanf("%c", &user_response);
	clear_input_buffer();
	// check if strings are equal. Will return 0 if equal and therefore
	// will no longer loop if the user entered 'y'. If the user entered
	// anything other than 'y' it will reloop and ask them for another 
	// integer.
	if(strcmp(user_response, "y")){ user_input = retrieve_integer_from_user_with_validation(); }
	
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
