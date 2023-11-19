#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/my-lib.h"

short get_vehicle_type();
short has_day_pass();
double calculate_cost(short, short, double);
void print_cost(short, double);

int main()
{
	short vehicle_type;
	double duration_of_stay;
	short day_pass;
	double total_cost;
	
	vehicle_type = get_vehicle_type();	
	duration_of_stay = safely_get_double("How many hours: ");	
	day_pass = has_day_pass();
	total_cost = calculate_cost(vehicle_type, day_pass, duration_of_stay);

	print_cost(0, total_cost);
	//printf("Total cost: %.2lf€\n", total_cost);

	
	return (0);
}

void print_cost(short currency, double total_cost)
{
	#define EURO 0
	#define DOLLAR 1

	char* currency_sign;
	
	// if/else if/else chosen to allow for different currencies
	if(currency == EURO) { currency_sign = "€"; }
	else if (currency == DOLLAR) { currency_sign = "$"; }

	printf("Total cost: %.2lf%s\n", total_cost, currency_sign);

	#undef EURO
	#undef DOLLAR	
}

double calculate_cost(short vehicle_type, short day_pass, double duration_of_stay)
{
	// (I know macros are to be avoided...but it's a  bad habit that 
	// is going to die hard...I'll work on it...;) )
	#define CAR 1

	#define CAR_DAY_PASS 24
	#define CAR_FIRST_THREE 4
	#define CAR_SECOND_THREE 2
	#define CAR_EXTRA_HOURS 1
	
	#define MOTORBIKE_DAY_PASS 15
	#define MOTORBIKE_FIRST_THREE 3
	#define MOTORBIKE_SECOND_THREE 1
	#define MOTORBIKE_EXTRA_HOURS 0.5

	#define FIRST_CHARGE_TOP 3
	#define SECOND_CHARGE_TOP 6
	// set this to determine when rollover to regular hours begins with
	// day pass
	#define LENGTH_OF_BUSINESS_DAY 24

	double total_cost = 0;
	if(day_pass == 1)
	{
		if(vehicle_type == CAR){ total_cost += CAR_DAY_PASS; }
		else { total_cost += MOTORBIKE_DAY_PASS; }
		duration_of_stay -= LENGTH_OF_BUSINESS_DAY;
	}
	
	for(int i = 1; duration_of_stay > 0; ++i, --duration_of_stay)
	{
		if(i > 0 && i <= FIRST_CHARGE_TOP)
		{
			if(vehicle_type == CAR){ total_cost += CAR_FIRST_THREE; }
			else { total_cost += MOTORBIKE_FIRST_THREE; }
		}
		else if(i >= FIRST_CHARGE_TOP && i <= SECOND_CHARGE_TOP)
		{
			if(vehicle_type == CAR){ total_cost += CAR_SECOND_THREE; }
			else { total_cost += MOTORBIKE_SECOND_THREE; }
		}
		else if(i > SECOND_CHARGE_TOP)
		{
			if(vehicle_type == CAR){ total_cost += CAR_EXTRA_HOURS; }
			else { total_cost += MOTORBIKE_EXTRA_HOURS; }
		}		
	}

	return (total_cost);
		
	#undef CAR
	#undef MOTORBIKE
	#undef CAR_DAY_PASS
	#undef CAR_FIRST_THREE
	#undef CAR_SECOND_THREE
	#undef CAR_EXTRA_HOURS
	#undef MOTORBIKE_DAY_PASS
	#undef MOTORBIKE_FIRST_THREE
	#undef MOTORBIKE_SECOND_THREE
	#undef MOTORBIKE_EXTRA_HOURS
	#undef FIRST_CHARGE_TOP
	#undef SECOND_CHARGE_TOP
	#undef LENGTH_OF_BUSINESS_DAY
}

short has_day_pass()
{
	short return_value;
	short reloop;

	printf("Would you like a day pass?\n");
	printf("1. Yes\n");
	printf("2. No\n");
	printf("Note: Time stayed after 24 hourse will be calculated at normal rates.\n");
	do
	{
		reloop = 0;
		return_value = safely_get_int("Enter your selection [1 or 2]:");
		if(return_value != 1 && return_value != 2)
		{
			printf("Invalid entry.\n");
			reloop = 1;
		}
	}while(reloop);

	return (return_value);
}

short get_vehicle_type()
{
	int return_value;
	int reloop;
	printf("Please select your vehicle type:\n");
	printf("1. Car\n");
	printf("2. Motorbike\n");
	do
	{
		reloop = 0;
		return_value = safely_get_int("Enter selection [1 or 2]: ");
		if(return_value != 1 && return_value != 2)
		{
			printf("Invalid entry.\n");
			reloop = 1;
		}
	}while(reloop);


	return (return_value);
}
