// Prof. Rigas,
//
// Please see the my-lib.h for any clarification on functions that are 
// used without being defined in this file. I did not want to clutter 
// the actual important function for the assignment which is the 
// compute_pay() with all the other functions I tried to write on my 
// own for extra practice. I tried to comment my-lib.c extensively (as
// mentioned in my note in the name.c file) so as to demonstrate I am 
// not merely copying from online as I used a lot of stuff we have not
// yet covered in class. 
//
// Best wishes, 
//
// Sophia W. 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/my-lib.h"

double compute_pay(double, double);

int main()
{
	double d_hours_worked;
	double d_hourly_rate;
	double final_pay;
	char* hours_worked;
	char* hourly_rate;

	char reloop = 0;
	do
	{
		if(reloop){ printf("Invalid entry.\n"); }
		printf("Please enter the hours worked: ");
		hours_worked = safely_get_input();
		reloop = 1; 
	}
	while(!verify_double(hours_worked, &d_hours_worked));

	reloop = 0;	
	do
	{
		if(reloop){ printf("Invalid entrty.\n"); }
		printf("Please enter the hourly rate: ");
		hourly_rate = safely_get_input();
		reloop = 1;
	}
	while(!verify_double(hourly_rate, &d_hourly_rate));
	
	printf("Pay: %.2lf\n", compute_pay(d_hours_worked, d_hourly_rate));
	
	bzero(hours_worked, str_len(hours_worked));
	free(hours_worked);
	hours_worked = NULL;

	bzero(hourly_rate, str_len(hourly_rate));
	free(hourly_rate);
	hourly_rate = NULL;

	return 0;
}

double compute_pay(double hours_worked, double hourly_rate)
{
	double overtime_rate = (hourly_rate + (hourly_rate/2));
	double overtime_hours = 0;

	if(hours_worked > 40){ overtime_hours = hours_worked - 40; hours_worked -= overtime_hours; }
	
	return ((hours_worked * hourly_rate) + (overtime_hours * overtime_rate));
}
