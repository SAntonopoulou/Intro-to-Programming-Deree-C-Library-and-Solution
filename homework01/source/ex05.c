#include <stdio.h>

size_t is_decimal(char *string);
size_t is_digit(char c);
size_t get_string_length(char *string);

int main()
{
	char s0[20] = "1234567890a";
	char s1[20] = "1234567890";
	if(!is_decimal(s0)) { printf("All decimal\n"); }
	else { printf("Not all decimal\n"); }

	if(!is_decimal(s1)) { printf("All decimal\n"); }
	else { printf("Not all decimal\n"); }
	
	return 0;
}

size_t is_decimal(char *string)
{
	// This function will check if a string contains only digits [0-9]
	// by checking each individual character one by one until it either
	// happens upon a non-digit character (in which case it will return 1)
	// or until it reaches the end of the string/file (in which case it will
	// return 0)
	
	size_t string_length = get_string_length(string);
	for(size_t i = 0; i <= string_length; ++i)
	{
		if(string[i] == EOF || string[i] == '\0')
		{ break; }
		if(is_digit(string[i]))
		{ return 1; }
	}

	return 0;
	
}

size_t is_digit(char c)
{
	// This function will check if the supplied character is
	// a digit by checking that it exists within the range of
	// ASCII characters for digits [0-9]
	
	#define DIGIT_START 48
	#define DIGIT_END 57

	size_t return_value;

	if(c >= DIGIT_START && c <= DIGIT_END)
	{
		return_value = 0;
	}
	else 
	{
		return_value = 1;
	}

	return (return_value);
}

size_t get_string_length(char *string)
{
	// This function will loop through all the characters in
	// the string until it reaches the null terminator indicating
	// the end of the string. It will then return the length of the
	// string (--string_length);
	
	size_t string_length = 0;
	for(size_t i = 0; string[i] != '\0'; ++i)
	{
		++string_length;
	}

	return (--string_length);
}
