// COMPILATION NOTE: if compiling with gcc you MUST add the -lm flag to the compliation in order to 
// not encounter a linker error from the sqrt function in the math.h header.

#include <stdio.h>
#include <math.h>

void get_points_from_user(double points[]);
double calculate_euclidean_distance(double points[]);

int main()
{
	double points[4];
	get_points_from_user(points);
	printf("Euclidian Distance: %lf\n",calculate_euclidean_distance(points));
	return 0;
}

void get_points_from_user(double points[])
{
	// This function will prompt the user for the points in series and set them
	// to the respective position within the referenced points array.
	printf("Enter value for x1: ");
	scanf("%lf", &points[0]);
	printf("Enter value for y1: ");
	scanf("%lf", &points[1]);
	printf("Enter value for x2: ");
	scanf("%lf", &points[2]);
	printf("Enter value for y2: ");
	scanf("%lf", &points[3]);
}

double calculate_euclidean_distance(double points[])
{
	// This function will calculate the Euclidean distance from the points provided in the
	// referenced points array
	//
	// NOTE:
	// points[0] == x1
	// points[1] == y1
	// points[2] == x2
	// points[3] == y3
	return sqrt((((points[0] - points[2])*(points[0] - points[2])) + ((points[1] - points[3])*(points[1] - points[3]))));
}
