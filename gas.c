/*
Program Name: gas.c
Programmer: Tyler Cabutto
Class: CS 3335 A
HW: 01
Problem: 01
Date: 9/8/2016
*/

#include <stdio.h>

int main()
{
	char input;

	printf("Please enter the color of the cylinder: ");
	scanf("%c", &input);

	switch (input)
	{
		case 'o':
		case 'O':
				printf("Ammonia\n");
				break;
		case 'b':
		case 'B':
				printf("Carbon monoxide\n");
				break;
		case 'y':
		case 'Y':
				printf("Hydrogen\n");
				break;
		case 'g':
		case 'G':
				printf("Oxygen\n");
				break;
			default:
				printf("Contents unknown\n");
				break;
	}

	return 0;

}

