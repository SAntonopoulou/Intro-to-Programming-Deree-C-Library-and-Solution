#include <stdio.h>
int pop_digit(int*);
void push_digit(int, int*);

int main()
{
	int number = 1234;
	int reverse;

	printf("NUM ORIG: %d\n", number);

	while(number > 0)
	{
		push_digit(pop_digit(&number), &reverse);
	}

	printf("NUM REV: %d\n", reverse);
	
	return (0);
}

void push_digit(int digit, int* reverse)
{
	*reverse *= 10;
	*reverse += digit;
}

int pop_digit(int* supplied_digit)
{
	int digit = 0;
	digit = *supplied_digit%10;
	*supplied_digit = *supplied_digit/10;
	return(digit);
}
