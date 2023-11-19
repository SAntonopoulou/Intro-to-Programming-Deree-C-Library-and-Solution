// Dr. Rigas,
//
// You can find the is_digit and str_len methods in the my-lib.c file.
//
// Best wishes, 
//
// Sophia W. 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/my-lib.h"

short two_digits(char*);

int main()
{
	int value;
        value = two_digits("8*9+6/2");
	printf("Result: %d\n", value);
	value = two_digits("Catch-22");
	printf("Result: %d\n", value);
	return 0;
}

short two_digits(char* string)
{
	int digit = 0;
	int length = str_len(string);
	for(int count = 0; count < length; ++count)
	{
		if(is_digit(string[count]) && digit == 1){ return (1); }
		else if(is_digit(string[count]) && digit == 0) { ++digit; }
		else { digit = 0; }
	}
	return (0);
}
