#include <iostream>
using namespace std;
int main()
{
	int redove;
	printf("Enter number of rows: ");
	scanf("%d", &redove);

	for(int i = 0; i < redove; i++)
	{
	for(int spacing = 0; spacing <= redove-i; spacing++ )
		printf(" ");
		for(int j = 0; j <= i; j++)
		{
			printf("#");
		}
		printf(" ");
		for(int j = 0; j <= i; j++)
		{
			printf("#");
		}
		printf("\n");
	}
	
	return 0;
}