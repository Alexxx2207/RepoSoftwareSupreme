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
		{
			printf(" ");
		}
			printf("/");
			for(int SpaceInside = 1; SpaceInside <= i*2; SpaceInside++)
			{
				if(i + 1 == redove)
				{
					printf("_");
				}else
				{
					printf(" ");
				}
			}
			printf("\\");
//			for(int spacing = 0; spacing <= redove-i; spacing++ )
//		{
//			printf("#");
//		}
			printf("\n");
	}
	
	return 0;
}