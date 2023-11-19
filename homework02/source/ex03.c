#include <stdio.h>

double get_hourly_rate();
double get_hours_worked();
double calculate_pay(double, double);

int main()
{
	printf("Pay: %.2lf\n", calculate_pay(get_hours_worked(), get_hourly_rate()));
	return 0;
}

double get_hourly_rate()
{
	double user_value;
	printf("Enter hourly rate: ");
	scanf("%lf", &user_value);
	return (user_value);
}

double get_hours_worked()
{
	double user_value;
	printf("Enter hours worked: ");
	scanf("%lf", &user_value);
	return (user_value);
}

double calculate_pay(double hours_worked, double hourly_rate)
{
	return (hours_worked * hourly_rate);
}
