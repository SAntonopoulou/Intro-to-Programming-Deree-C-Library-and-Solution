// Dr. Rigas,
//
// I really apprciate this exercise! It made me realise that my safely_get_int method
// did not account for negative numbers! That was a massive oversight on my part, but
// now I have included a method safely_get_signed_int as well as safely_get_signed_double
// in the library that allows for signed integers and doubles to be accepted safely as 
// well as verified as valid along with the original that works for unsigned integers
// and doubles.
//
// I was not entirely sure if you wanted just integers or if you also wanted floating
// point numbers in your description so I have created two version so of this exercise.
// This one - that handles only integer values - and ex02-double.c that handles floating
// point numbers. 
//
// For both of these exercises I have chosen to use a linked list to store the values
// because - well mostly to practice with data structures - but also becasue I wanted
// the user to be able to enter as many values as they pleased and to separate the
// calculation from the actual loop of taking input. The methods for the nodes and 
// their structures are included in the my-lib.c file and the my-lib.h file if you 
// are curious to see how they work. Otherwise, I have left them out of this file
// so that it is easier to focus on the solution to the exercises provided without
// cluttering it up with all the extra stuff. 
//
// Best wishes, 
//
// Sophia W. 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/my-lib.h"

long long int count_integers(Int_Node*);
long long int sum_integers(Int_Node*);
void get_user_input(Int_Node**);
void present_data(Int_Node*);


int main()
{
	Int_Node* integer_list = NULL;
	get_user_input(&integer_list);
	present_data(integer_list);
	free_int_list(integer_list);
	return 0;
}

void present_data(Int_Node* integer_list)
{
	printf("Number of Integers: %lld\n", count_integers(integer_list));
	printf("Sum of Integers: %lld\n", sum_integers(integer_list));
}

void get_user_input(Int_Node** integer_list)
{
	long long int integer;
	do
	{
		integer = safely_get_signed_int("Please enter an integer (0 to quit): ");
		if(integer > 0)
		{
			new_int_node(integer_list, integer);
		}
		else if(integer < 0)
		{
			printf("Negative number. Skipping.\n");
		}
	}while(integer != 0);
}

long long int sum_integers(Int_Node* list_head)
{
	long long int return_value = 0;
	while(list_head != NULL)
	{
		return_value += list_head->integer;
		list_head = list_head->next_link;
	}
	return (return_value);
}

long long int count_integers(Int_Node* list_head)
{
	long long int return_value = 0;
	while(list_head != NULL)
	{
		++return_value;
		list_head = list_head->next_link;
	}
	return (return_value);
}
