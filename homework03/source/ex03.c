#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/my-lib.h"

int extract_score(char* );

int main()
{
	char* string = "Points won: 83 out of 100";
	int score = extract_score(string);
	printf("The score was %d out of 100\n", score);
	return 0;
}

int extract_score(char* string)
{
	// create the character buffer to hold characters prior to them
	// being convereted to an integer with the str_to_int library function
	size_t BUFFER_SIZE = str_len(string);
	char* digit_string = calloc(BUFFER_SIZE+1, sizeof(char));
	long long int return_value;

	// Check each character up to the first non-digit character following
	// the final digit of the first integer.
	int first_number = 0;
	int position = 0;
	while(*string)
	{
		if(is_digit(*string))
		{
			digit_string[position] = *string;
			first_number = 1;
			++position;
		}
		// We have the first number and are now starting to
		// intake the last part of the string. Therefore, break
		// instead of processing the whole string
		if(first_number && !is_digit(*string)){ digit_string[position] = '\0'; break; }
		++string;
	}

	return_value = str_to_int(digit_string);

	bzero(digit_string, str_len(digit_string));
	free(digit_string);
	digit_string = NULL;

	return (return_value);
}

