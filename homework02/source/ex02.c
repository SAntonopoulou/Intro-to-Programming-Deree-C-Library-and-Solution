#include <stdio.h>

float retrieve_temperature_from_user();
float celsius_to_fahrenheit(float);
int main()
{
	float user_temperature;
	user_temperature = retrieve_temperature_from_user();
	printf("%.2f degrees Celsius is %.2f degrees in Fahrenheit.\n", user_temperature, celsius_to_fahrenheit(user_temperature));

	return 0;
}

float retrieve_temperature_from_user()
{
	float temperature = 2.0f;
	printf("Please enter the temperature in Celsius: ");
	scanf("%f", &temperature);
	return temperature;
}

float celsius_to_fahrenheit(float user_temperature)
{
	return ((user_temperature * 1.8) + 32.0);
}

