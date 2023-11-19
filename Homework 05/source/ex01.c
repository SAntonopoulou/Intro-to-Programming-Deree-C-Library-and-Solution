// Dr. Rigas,
// 
// As usual, I have included my library to help make input etc a bit easier for me, but have 
// included all the actual code relevant to the exercise directly in this file. If there are
// any concerns as to how any of the methods in my library work please do not hesitate to 
// let me know and I'll be sure to clarify.
// 
// Best wishes, 
// 
// Sophia W. 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/my-lib.h"

int sum_positive_integers(int);

int main()
{
	int maximum_integer;
	maximum_integer = safely_get_int("Please enter a positive integer: ");
	printf("Sum of even numbers until %d: %d\n", maximum_integer, sum_positive_integers(maximum_integer));
	return 0;
}

int sum_positive_integers(int maximum_integer)
{
// This method sums the positive integers in reverse order
// from maximum_integer until zero.
	int return_value = 0;
	while(maximum_integer)
	{
		if(!(maximum_integer%2))
		{
			return_value += maximum_integer;
		}
		--maximum_integer;
	}
	return (return_value);
}
