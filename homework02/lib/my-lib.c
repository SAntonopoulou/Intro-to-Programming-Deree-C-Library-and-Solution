#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my-lib.h"
#define TRUE 1
#define FALSE 0

double do_exponent(double number, int iterations)
{
	if(iterations == 0) { return 1; }
	else { return number * do_exponent(number, iterations -1); }
}

short is_space(char c)
{
	#define SPACE 32
	if(c == SPACE){ return (TRUE); }
	return (FALSE);
	#undef SPACE
}

short is_digit(char c)
{
	#define DIGIT_LOWER_BOUND 48
	#define DIGIT_UPPER_BOUND 57
	if(c >= DIGIT_LOWER_BOUND && c <= DIGIT_UPPER_BOUND){ return (TRUE); }
	return (FALSE);	
	#undef DIGIT_LOWER_BOUND
	#undef DIGIT_UPPER_BOUND
}

size_t str_len(char* string)
{
	size_t length = 0;
	for(; *string; ++string, ++length)
		;
	return (length);
}

short alpha_to_int(char c)
{
	#define MIN_DIGIT_VALUE 48
	return ((MIN_DIGIT_VALUE - (int)c) * -1);
}

double str_to_double(char* string, char** endpoint)
{
	double return_value = 0;
	// calculate length
	size_t BUFFER_SIZE = str_len(string);
	// create buffer of length
	char* before_buffer = calloc(BUFFER_SIZE+1, sizeof(char));
	char* after_buffer = calloc(BUFFER_SIZE+1, sizeof(char));
	// create string up to decimal
	size_t position = 0;
	while(*string && *string != '.')
	{
		before_buffer[position] = *string;
		++string;
		++position;
	}
	// add null terminator to make a proper string
	before_buffer[position] = '\0';
	// increment past decimal
	++string;
	// reset position for post decimal string
	position = 0;
	// create string after decimal
	while(*string)
	{
		after_buffer[position] = *string;	
		++string;
		++position;
	}
	after_buffer[position] = '\0';
	// convert before decimal to int
	unsigned long long int pre_value = str_to_int(before_buffer);
	unsigned long long int post_value = str_to_int(after_buffer);
	// convert after decimal to int
	double decimal_value = post_value/do_exponent(10, str_len(after_buffer));
	// add together
	return_value = (pre_value + decimal_value);

	bzero(before_buffer, str_len(before_buffer));
	free(before_buffer);
	before_buffer = NULL;
	bzero(after_buffer, str_len(after_buffer));
	free(after_buffer);
	after_buffer = NULL;

	return (return_value);
}

unsigned long long int str_to_int(char* string)
{
	#define ZERO 48
	size_t length = str_len(string);
	unsigned long long int return_value = 0;
	unsigned long long int place = 1;

	for(int position = 0; position < length; ++position)
	{
		if(position == 0){ return_value = alpha_to_int(string[(length - 1) - position]); }
		else if ((string[(length-1) - position]) == ZERO){ place *= 10; continue; }
		else { 
			return_value += alpha_to_int(string[(length - 1) - position]) * (10 * place); 
			place *= 10; 
		}
	}

	return (return_value);
	#undef ZERO
}

short verify_double(char* string, double* converted_double)
{
	#define MAX_BUFFER_SIZE 600
	#define MAX_VALID_DOUBLE 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000
	double MAX_DOUBLE = MAX_VALID_DOUBLE;
	
	size_t count = 0;
	size_t length = str_len(string);
	char string_buffer[MAX_BUFFER_SIZE];
	size_t buffer_count = 0;
	double supplied_double = 0;
	short decimal_count = 0;

	while(is_space(string[count])) { ++count; }
	if(count == length) { return (FALSE); }
	if(!is_digit(string[count])) { return (FALSE); }

	while(count < length && !is_space(string[count]))
	{
		if(!is_digit(string[count]) && string[count] != '.'){ return (FALSE); }
		if(string[count] == '.'){ ++decimal_count; }
		if(decimal_count > 1) { return (FALSE); }
		string_buffer[buffer_count] = string[count];
		++buffer_count;
		++count;
	}

	string_buffer[buffer_count] = '\0';
	supplied_double = str_to_double(string, NULL);

	if(supplied_double <= MAX_DOUBLE) { *converted_double = supplied_double; return (TRUE); }
	return (FALSE);

	#undef MAX_BUFFER_SIZE
	#undef MAX_VALID_DOUBLE	
}

short verify_integer(char* string, unsigned long long int* converted_integer)
{
	#define MAX_BUFFER_SIZE 488
	#define MAX_VALID_INTEGER 1844674407370955161
	unsigned long long int MAX_INTEGER = MAX_VALID_INTEGER;

	size_t count = 0;
	size_t length = str_len(string);
	char string_buffer[MAX_BUFFER_SIZE];
	size_t buffer_count = 0;
	unsigned long long int supplied_integer = 0;

	while(is_space(string[count])) { ++count; }
	if(count == length) { return (FALSE); }
	if(!is_digit(string[count])) { return (FALSE); }

	while(count < length && !is_space(string[count]))
	{
		if(!is_digit(string[count])) { return (FALSE); }
		string_buffer[buffer_count] = string[count];
		++buffer_count;
		++count;
	}

	string_buffer[buffer_count] = '\0';
	supplied_integer = str_to_int(string_buffer);	

	if(supplied_integer <= MAX_INTEGER) { *converted_integer = supplied_integer; return (TRUE); }
	return (FALSE);

	#undef MAX_BUFFER_SIZE
	#undef MAX_VALID_INTEGER
}

void str_copy(char* origin, char* destination)
{
	int position  = 0;
	while(*origin)
	{
		destination[position] = *origin;
		++origin;
		++position;
	}
}

char* safely_get_input()
{
	#define BUFFER_SIZE 600
	char* memory_error_message = "MEMORY ALLOCATION ERROR! STOPPING EXECUTION!";
	size_t length;

	// use malloc (for speed?) or better to initalise with values (calloc)?
	// (do more research)
	// I realise sizeof(char) is perhaps redundant, but why not be extra 
	// cautious when we can do so
	char* buffer = calloc(BUFFER_SIZE, sizeof(char));
	// check that memory was allocated without any issues, and if there are
	// any issues exit the program with the error exit code
	if(buffer == NULL) { printf("%s\n", memory_error_message); exit(EXIT_FAILURE); }

	// I chose to use fgets to avoid any buffer overflow potential as
	// we are taking input from the user
	fgets(buffer, BUFFER_SIZE, stdin);
	length = str_len(buffer);
	// remove the \n that is read from stdin with fgets()
	buffer[length-1] = '\0';

	// This is created to be specifically the length of the input from
	// the user +1 to account for the null character.
	// Again, not sure if malloc would be better or if initalising to a value
	// straight away is better considering that it is used almost immediately
	char* name = calloc(length+1, sizeof(char));
	if(name == NULL) { printf("%s\n", memory_error_message); exit(EXIT_FAILURE); }

	// used my own str_copy function from this library as it just makes more sense to
	// me in my mind to reverse the values. Sort of why I also prefer AT&T syntax for 
	// assembly over Intel syntax. Plus I wanted to write my own version for practice.
	str_copy(buffer, name);

	// NOTE TO SELF( write bzero() and memset for my-lib)
	// I chose to use bzero to practice good security. Perhaps it is overkill, but this
	// could potentially be used to gather sensitive data such as passwords, etc. so I 
	// felt that the extra tradeoff in speed was worth the added security as this will
	// remove completely any potential traces of data left in memory after the programs
	// execution. (totally overkill for a project like this, but I am trying to practice
	// ...well...good practices ;) 
	//
	// I will likely write another version of this that forgoes bzero most likely at 
	// some point.
	bzero(buffer, str_len(buffer));
	free(buffer);
	buffer = NULL;
	// NOTE TO SELF( consider writing a secure_free() function that does all three of
	// these operations as I am getting tired of writing them over and over again... )
	
	return (name);
}

void strip_leading_whitespace(char* string, char* new_string)
{
	// This function will remove leading whitespace from a supplied string. It will not
	// remove whitespace between characters and therefore preserves space formatting in
	// a string if you nedd it. However, it does also leave the trailing whitespace as well. 
	size_t length = str_len(string);
	size_t first_character_found = 0;
	
	for(size_t i = 0, c = 0; i <= length; ++i)
	{
		if(string[i] != ' ' && string[i] != '\t' && string[i] != '\n' && !first_character_found)
		{
			// the first character has been found in the string
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

char* strip_whitespace_allow_one_internal(char* string)
{
	// This function will remove the trailing whitespace from a supplied string.
	// it will also strip any whitespace in the middle of a string as well so be
	// careful if you need to keep space formatting as this function will NOT 
	// meet your needs.
	//
	// NOTE: THIS IS A WORK IN PROGRESS. IT ALMOST WORKS PERFECTLY BUT IT'S DRIVING
	// ME INSANE THAT IT LEAVES AN EXTRA TRAILING WHITESPACE IF SOMEONE ENTERS THREE
	// ITEMS WITH SPACES BETWEEN THEM :0
	size_t length = str_len(string);
	size_t first_character_found = 0;
	size_t position = 0;
	short skipping = 0;
	char* new_string = calloc(str_len(string), sizeof(char));
	int back_fill = 0;

	for(size_t i = 0, c = 0; i <= length; ++i)
	{
		printf("%c: ", string[i]);
		if((string[i] != ' ' && string[i] != '\t') && i != length && !first_character_found)
		{ /* First Character Found */
			printf("First Character Found!\n");
			first_character_found = 1;
			new_string[position] = string[i];
			++position;
		}
		else if((string[i] != ' ' && string[i] != '\t') && i != length)
		{ /* Character Found */
			printf("Middle Character Found!\n");
			skipping = 0;
			new_string[position] = string[i];
			++position;
		}
		else if((string[i] == ' ' || string[i] == '\t') && !first_character_found)
		{ /* Leading White Space */ 
			printf("Leading White!\n");
		}
		else if((string[i] == ' ' || string[i] == '\t') && (first_character_found && i != length))
		{ /* Middle White Space */ 
			printf("Middle White");
			if(!skipping){ printf(" : Will Print White\n"); new_string[position] = ' '; ++position; skipping =1;}
			else { printf(" : Will NOT Print White\n");}
			//skipping = 1;
		}
		else if((string[i] == '\0') && (first_character_found && i == length))
		{ /* Last Character White Space */
			string[i] = '\0';
			int count = 0;
			while(
				string[i-count] == 32 ||
			       	string[i-count] == ' ' ||	
				string[i-count] == '\t' ||
				string[i-count] == '\0' || 
				string[i-count] == '\n')
			{
				++back_fill;
				++count;
			}
		}
	}
	printf("%d\n", str_len(new_string));
	printf("%d\n", back_fill);
	new_string[length-(back_fill-1)]= '\0';
	return (new_string);
}

