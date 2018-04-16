/*
Program Name: wordLength.c
Programmer: Tyler Cabutto
Class: CS3335 A
HW: 02
Problem: 03
Date: 9/22/16
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
	char input = ' ';
	int wordLength = 0;
	int count = 0;
	double avg = 0.0;

	bool space = false;

	printf("Enter a sentence: ");


		while((input = getchar()) != EOF && input != '\n');
		{
			if(input == ' ')
			{
				space = true;

			}
			else
				if(!space)
				{

					wordLength++;
				}
				avg = avg + (double)wordLength;
				space = false;
				count++;
		}

	if (count > 0)
	{
		avg = avg/(double)count;
		printf("Average word length: %f\n", avg);
	}
	else
		printf("No words found\n");
	return 0;
}
