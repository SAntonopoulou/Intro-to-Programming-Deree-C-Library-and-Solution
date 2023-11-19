#include <stdio.h>

int main()
{
	int width;
	float height;

	width = 10;
	height = 13.0;

	printf("\nThe result of %d/3 is %d and the type is of type int.\n", width, (width/3));
	printf("The result of %d/2.0 is %.2f and the type is of type float\n", width, (width/2.0));
	printf("The result of %.2f/2 is %.2f and the type is of type float\n\n", height, (height/2));
	
	return 0;
}
