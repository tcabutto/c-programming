/*
Program Name: phone.c
Programmer: Tyler Cabutto
Class: CS 3335 A
HW: 02
Problem 02
Date: 9/22/16
*/

#include <stdio.h>

int main()
{
	char number;
	int length = 10;
	int i;

	printf("Enter a phone number: ");



	for(i=0; i <= length; i++)
	{
//		if( (i==1) || (i==4) || (i==7)){printf("-");}

		scanf("%c", &number);
		switch(number)
		{
			case 'A':
			case 'B':
			case 'C':
				printf("2");
				break;
			case 'D':
			case 'E':
			case 'F':
				printf("3");
				break;
			case 'G':
			case 'H':
			case 'I':
				printf("4");
				break;
			case 'J':
			case 'K':
			case 'L':
				printf("5");
				break;
			case 'M':
			case 'N':
			case 'O':
				printf("6");
				break;
			case 'P':
			case 'R':
			case 'S':
				printf("7");
				break;
			case 'T':
			case 'U':
			case 'V':
				printf("8");
				break;
			case 'W':
			case 'X':
			case 'Y':
				printf("9");
				break;
			default:
				printf("%c", number);
				break;

		}
	}

	printf("\n");
	return 0;
}
