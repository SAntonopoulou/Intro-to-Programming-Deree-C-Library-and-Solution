#include <stdio.h>

size_t get_string_length(char *string);
void strip_leading_whitespace(char* string, char* new_string);
void strip_all_whitespace(char* string, char* new_string);
void strip_trailing_whitespace(char* string, char* new_string);

int main()
{
	char string[] = "     TestString    "; 
	char new_string[get_string_length(string) + 1];
	char new_string2[get_string_length(string) + 1];
	char new_string3[get_string_length(string) + 1];
	strip_leading_whitespace(string, new_string);
	strip_all_whitespace(string, new_string2);
	strip_trailing_whitespace(string, new_string3);
	printf("String with suffix: |%s|\n", string);
	printf("String without leading whitespace: |%s|\n", new_string);
	printf("String without any whitespace: |%s|\n", new_string2);
	printf("string without trailing whitespace: |%s|\n", new_string3);	
}

void strip_trailing_whitespace(char* string, char* new_string)
{
	// This function will remove the trailing whitespace from a supplied string. It will
	// also strip any whitespace in the middle of a string as well so be careful if you 
	// need to keep space formatting. This function will not meet your needs. 
	size_t length = get_string_length(string);
	size_t first_character_found = 0;
	for(size_t i = 0, c = 0; i <= length; ++i)
	{
		if(first_character_found && string[i] != ' ' && string[i] != '\t' && string[i] != '\n')
		{
			// first character has been found so remove whitespace going forward
			// from the end of the string
			new_string[c] = string[i];
			++c;
		}
		else if(!first_character_found)
		{
			// first character has just been identified so set the first_character_found to 1
			// add add it to the new string
			new_string[c] = string[i];
			++c;
			if(string[i] != ' ' && string[i] != '\t' && string[i] != '\n'){ first_character_found = 1; }
		}
	}	
}

void strip_all_whitespace(char* string, char* new_string)
{
	// This function will remove all whitespace from a given string including whitespace in
	// the middle of the string. If you need to maintain space formatting with a string this may
	// not be suitable for your needs.
	size_t length = get_string_length(string);
	for(size_t i = 0, c = 0; i <= length; ++i)
	{
		if(string[i] != ' ' && string[i] != '\t' && string[i] != '\n')
		{
			// only add non-whitespace characters to the new string
			new_string[c] = string[i];
			++c;
		}
	}
	
}

void strip_leading_whitespace(char* string, char* new_string)
{
	// This function will remove leading whitespace from a supplied string. It will not
	// remove whitespace between characters and therefore preserves space formatting in
	// a string if you need it. However, it does leave trailing whitespace as well. Best to
	// split a string using the substring function (found in other programs until I make the
	// library itself - mini project :) ) and then remove whitespace with the correct function.
	// It's tedious for the moment. I should address this eventually. 
	size_t length = get_string_length(string);
	size_t first_character_found = 0;
	for(size_t i = 0, c = 0; i <= length; ++i)
	{
		if(string[i] != ' ' && string[i] != '\t' && string[i] != '\n' & !first_character_found)
		{
			new_string[c] = string[i];
			++c;
			first_character_found = 1;
		}
		else if(first_character_found)
		{
			new_string[c] = string[i];
			++c;
		}
	}
}

size_t get_string_length(char *string)
{
	// This function gets the length of a string by stepping through
	// each of the characters and incrementing the string_length variable
	// by one as long as it is has not yet reached the null terminator.
	//
	// The length of the string returned does not include the null terminator.
	size_t string_length = 0;
	for(size_t i = 0; string[i] != '\0'; ++i)
	{
		++string_length;
	}

	return (string_length);
}
