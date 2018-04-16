/*
Program Name: plane.c
Programmer: Tyler Cabutto
Class: CS3335 A
HW: 01
Problem: 02
Date: 9/8/16
*/

#include <stdio.h>

int main()
{
	float x, y;

	printf("Enter x coordinate: ");
	scanf("%f", &x);

	printf("Enter y coordinate: ");
	scanf("%f", &y);

	if(x == 0)
	{
		if(y == 0)
		{
			printf("(%.1f, %.1f) is on the origin\n", x, y);
		}
		else
		  printf("(%.1f, %.1f) is on the y axis\n", x, y);
	}
	else if(x < 0)
	{
		if(y == 0)
		{
			printf("(%.1f, %.1f) is on the x axis\n", x, y);

		}
		else if(y > 0)
		{
			printf("(%.1f, %.1f) is in quadrant II\n", x, y);

		}
		else if(y < 0)
		{
			printf("(%.1f, %.1f) is in quadrant III\n", x, y);

		}
	}
	else if(x > 0)
	{
		if(y == 0)
		{
			printf("(%.1f, %.1f) is on the x axis\n", x, y);
		}
		else if(y > 0)
		{
			printf("(%.1f, %.1f) is in quadrant I\n", x, y);
		}
		else if(y < 0)
		{
			printf("(%.1f, %.1f) is in quadrant IV\n", x, y);
		}
	}

	return 0;
}
