#include <iostream>
using namespace std;
void FirstLine(int redove)
{
	for(int spacing = 0; spacing < redove-1; spacing++ )
	{
		printf(" ");
	}

	for(int i=0; i < redove; i++)
	{
		printf(" ");
		printf("*");
	}
}
void LastLine(int redove)
{
	
	for(int i=0; i < (redove*2)-1; i++)
	{
		printf(" ");
		printf("*");
	}
}
void MidLines(int redove)
{
	for(int i = 0; i < redove - 2; i++)
	{
		for(int spacing = 1; spacing < redove-i; spacing++ )
		{
			printf(" ");
		}
			printf("* ");
			for(int SpaceInside = 1; SpaceInside <= i*2; SpaceInside++)
			{
					printf(" ");
			}
			printf("*");
			for(int spacing = 3; spacing < redove-i; spacing++ )
		{
			printf(" ");
		}
		for(int spacing = 2; spacing < redove-i; spacing++ )
		{
			printf(" ");
		}
		printf("* ");
			for(int SpaceInside = 1; SpaceInside <= i*2; SpaceInside++)
			{
					printf(" ");
			}
			printf("*");
			printf("\n");
	}
}

int main()
{
	int redove;
	printf("Enter number of rows: ");
	scanf("%d", &redove);

	FirstLine(redove);
	printf("\n");
	MidLines(redove);
	LastLine(redove);
	printf("\n");

	return 0;
}