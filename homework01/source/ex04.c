#include <stdio.h>

size_t get_string_length(char *string);
size_t has_suffix(char *string, char *suffix);
size_t string_compare(char *string1, char *string2);
void create_substring(char *string, char* new_string, size_t number_of_characters, size_t direction);

int main()
{
	char string[] = "Testsuffix";
	char suffix[] = "suffix"; 
	if(!has_suffix(string, suffix)){ printf("String contains the suffix.\n"); }
	else { printf("String does not contain the suffix.\n"); }	
}

size_t has_suffix(char *string, char *suffix)
{
	// This function checks if a string contains a supplied suffix by first
	// creating the substring from the provided string to be checked and then comparing that
	// with the supplied suffix using the string_compare function. 
	//
	// Could also be used to compare a prefix. 
	size_t length = get_string_length(string);
	char sub_string[get_string_length(suffix)+1];
	create_substring(string, sub_string, (get_string_length(suffix)), 0);

	if(string_compare(sub_string, suffix)){ return 1; }

	return 0;

}

void create_substring(char *string, char* new_string, size_t number_of_characters, size_t direction)
{
	// This function will create a substring from another string. It requires the destination
	// string to already be in existance prior to calling this function and to be of adequate size
	// to hold the transfered substring. 
	//
	// It also accepts the number of requested characters for the substring and the direction in 
	// which you would like the substring to be comleted. 0 will result taking the characters from
	// the end of the string, and 1 will result in taking the characters from the front of the string.
	//
	// This function will also add the null terminator at the end of the newly created substring to avoid
	// any errors when using the substring.
	size_t length = get_string_length(string);
	if(direction)
	{
		// forward
		for(size_t i = 0; i <= number_of_characters; ++i)
		{
			new_string[i] = string[i];
			if(i == number_of_characters){ new_string[number_of_characters+1] = '\0'; }
		}	
	}
	else 
	{
		// reverse
		for(size_t i = 0; i <= number_of_characters; ++i)
		{
			new_string[number_of_characters - i] = string[length - i];
			if(i == number_of_characters) { new_string[number_of_characters+1] = '\0'; }
		}
	}

}

size_t string_compare(char *string1, char *string2)
{
	// This function will compare two strings to see if they are of
	// equal value. 
	//
	// First, it will confirm that they are the same length - as if they are
	// not of the same length they are not the same strings. Next, it will step
	// through each of the strings character by character and compare the values. 
	// This will exit at the first occurance of any difference between the characters
	// which are being compared.
	size_t length1 = get_string_length(string1);
	size_t length2 = get_string_length(string2);
	if(length1 != length2){ return 1; }
	for(size_t i = 0; i <= length1; ++i)
	{
		if(string1[i] != string2[i]){ return 1; }
	}

	return 0;
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
