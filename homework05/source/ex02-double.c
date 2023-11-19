// Dr. Rigas,
//
// This is more or less the same as ex02.c with the only exception that it operates with
// floating point numbers. It also had me reaslise that I did not account for negative
// floating point numbers in my library so that has been adjusted, as well as I was unable
// to process floating point numbers without a leading zero. That has also now been adjusted
// so values such as .42 are now accepted as valid input. 
//
// Thank you again for assigning these exercises. It's really helping me to push myself to 
// become a better developer with the C language, and I'm starting to appreciate the control 
// it gives more and more each time. Of course, I miss being able to overload functions etc 
// (for instance in C++ I would have merely used the ability to overload a new_node function 
// with different parameter types whereas in C we have to define them as totally separate 
// methods), but other than that I'm really enjoying the fact that this class is helping me 
// to develop a bit more control over a language I would have most likely otherwise 
// overlooked. 
//
// Best wishes, 
//
// Sophia W. 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/my-lib.h"

int count_doubles(Double_Node*);
double sum_doubles(Double_Node*);
void get_user_input(Double_Node**);
void present_data(Double_Node*);

int main()
{
	Double_Node* double_list = NULL;
	get_user_input(&double_list);
	print_double_list(double_list);
	present_data(double_list);
	free_double_list(double_list);
	return 0;
}

void present_data(Double_Node* double_list)
{
	printf("Number of Numbers: %d\n", count_doubles(double_list));
	printf("Sum of Numbers: %lf\n", sum_doubles(double_list));
}

void get_user_input(Double_Node** double_list)
{
	double double_value;
	do
	{
		double_value = safely_get_signed_double("Please enter a number (0 to quit): ");
		if(double_value > 0)
		{
			new_double_node(double_list, double_value);
		}
		else if(double_value < 0)
		{
			printf("Negative number. Skipping.\n");
		}
	}while(double_value != 0);
}

double sum_doubles(Double_Node* list_head)
{
	double return_value = 0;
	while(list_head != NULL)
	{
		return_value += list_head->double_value;
		list_head = list_head->next_link;
	}
	return (return_value);
}
int count_doubles(Double_Node* list_head)
{
	int return_value = 0;
	while(list_head != NULL)
	{
		++return_value;
		list_head = list_head->next_link;
	}
	return (return_value);
}
