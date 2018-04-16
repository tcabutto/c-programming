/*
Program Name: battleship.c
Programmer: Tyler Cabutto
Class: CS 3335 A
HW: 04
Problem: 01
Date: 10/27/16
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int human[SIZE] = {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'};
int computer[SIZE] = {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'};


void setBoard(int *);
void setComputerBoard(int *);
int playGame(int *, int *);

int main(void)
{

	int *hptr = &human[0];
	int *cptr = &computer[0];

	setComputerBoard(cptr);
	setBoard(hptr);
	int result;
	result = playGame(hptr, cptr);
	if(result == 0)
	{
		printf("Computer wins!\n");
	}
	else if(result == 1)
	{
		printf("Human wins!\n");
	}

	return 0;
}

void setBoard(int *x)
{
	int pos1, pos2;
	printf("Enter 1st position: ");
	scanf("%d", &pos1);
	while( (pos1 < 0) || (pos1 > 9) )
	{
		printf("Valid slots are in the range from 0 to 9. Try again.\n");
		printf("Enter 1st position: ");
		scanf("%d", &pos1);
	}

	printf("Enter 2nd position: ");
	scanf("%d", &pos2);
	while(pos2 == pos1)
	{
		printf("Already placed ship in this slot. Try again.\n");
		printf("Enter 2nd position: ");
		scanf("%d", pos2);
	}
	while( (pos2 < 0) || (pos2 > 9) )
	{
		printf("Valid slots are in the range from 0 to 9. Try again.\n");
		printf("Enter 2nd position: ");
		scanf("%d", &pos2);
	}

	while( (pos2 > (pos1+1) ) || (pos2 < (pos1 - 1) ) )
	{
		printf("Ships have to be in consectuive slots. Try again.\n");
		printf("Enter 2nd position: ");
		scanf("%d", &pos2);
	}

	*(pos1 + x) = 'S';
	*(pos2 + x) = 'S';


}

void setComputerBoard(int *x)
{
	int pos1, pos2;

	pos1 = rand() % 10;
	pos2 = rand() % 10;

	while(pos2 == pos1)
	{
		pos2 = rand() % 10;
		while( (pos2 > (pos1+1) ) || (pos2 < (pos1-1) ) )
		{
			pos2 = rand() % 10;
		}
	}

	x = &computer[pos1];
	*x = 'S';
	x = &computer[pos2];
	*x = 'S';

}

int playGame(int *h1, int *c1)
{
	int comCount, humanCount, guess = 0;
	int i;
	while( (comCount < 2) || (humanCount < 2) )
	{
		guess = rand() % 10;
		printf("Computer guesses %d\n\n", guess);
		c1 = &human[guess];
		if(*c1 == 'S')
		{
			printf("HIT!\n\n");
			*c1 = 'H';
			comCount++;
		}
		else
		{
			printf("MISS!\n\n");
			*c1 = 'M';
		}

		printf("0 1 2 3 4 5 6 7 8 9\n\n");
		printf("Human Board: \n\n");
		for(i = 0; i< SIZE; i++)
		{
			printf("%c ", human[i]);
		}
		printf("\n");
		printf("Computer Board: \n\n");
		printf("0 1 2 3 4 5 6 7 8 9\n\n");


		for(i = 0; i< SIZE; i++)
		{
			printf("%c ", computer[i]);
		}

		printf("\n\n");

		printf("Enter guess: ");
		scanf("%d", guess);
		c1 = &computer[guess];

		if(*h1 == 'S')
		{
			printf("HIT!\n\n");
			*h1 = 'H';
			humanCount++;
		}
		else
		{
			printf("MISS!\n\n");
			*h1 = 'M';
		}
		printf("0 1 2 3 4 5 6 7 8 9\n\n");
		printf("Human Board: \n\n");
		for(i = 0; i< SIZE; i++)
		{
			printf("%c ", human[i]);
		}
		printf("\n\n");
		printf("Computer Board: \n\n");
		printf("0 1 2 3 4 5 6 7 8 9\n\n");

		for(i = 0; i< SIZE; i++)
		{
			printf("%c ", computer[i]);
		}
			printf("\n\n");
	}

	if(comCount > humanCount)
		return 0;
	else
		return 1;
}



