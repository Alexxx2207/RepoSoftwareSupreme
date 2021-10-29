#include <iostream>
using namespace std;
int main()
{
	int redove, num = 1;
	printf("Enter number of rows: ");
	scanf("%d", &redove);

	for(int i = 0; i < redove; i++)
	{
	for(int spacing = 0; spacing <= redove-i; spacing++ )
		printf("  ");
		for(int j = 0; j <= i; j++)
		{
			if (j == 0 || i == 0)
			{
				num = 1;
			}else
			{
				num = num*(i-j+1)/j;
			}
			printf("%3d ", num);
		}
		printf("\n");
	}

	return 0;
}