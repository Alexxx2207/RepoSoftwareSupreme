#include <iostream>
using namespace std;
void FirstLine(int rows)
{
	for(int spacing = 0; spacing < rows-1; spacing++ )
	{
		printf(" ");
	}

	for(int i=0; i < rows; i++)
	{
		printf(" ");
		printf("*");
	}
}
void LastLine(int rows)
{
	
	for(int i=0; i < (rows*2)-1; i++)
	{
		printf(" ");
		printf("*");
	}
}
void MidLines(int rows)
{
	for(int i = 0; i < rows - 2; i++)
	{
		for(int spacing = 1; spacing < rows-i; spacing++ )
		{
			printf(" ");
		}
			printf("* ");
		for(int SpaceInside = 1; SpaceInside <= i*2; SpaceInside++)
		{
			printf(" ");
		}
			printf("*");
		for(int spacing = 3; spacing < rows-i; spacing++ )
		{
			printf(" ");
		}
		for(int spacing = 2; spacing < rows-i; spacing++ )
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
	int rows;
	printf("Enter number of rows: ");
	scanf("%d", &rows);

	FirstLine(rows);
	printf("\n");
	MidLines(rows);
	LastLine(rows);
	printf("\n");

	return 0;
}