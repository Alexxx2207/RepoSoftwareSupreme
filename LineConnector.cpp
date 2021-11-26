#include <iostream>
using namespace std;
	
	void bresenham(int radius, int size, char Array[7][7], int yFinish, int xFinish)
	{
		int x1 = radius;
		int y1 = radius;
		int yfinal = yFinish;
		int xfinal = xFinish;
		float m =(yfinal - y1)/float(xfinal - x1);
		float newerror = 0;
		for (int x = x1, y = y1; x >= xfinal; x--)
		{
			cout << "(" << x << "," << y << ")\n";
			Array[x][y] = '#';
			newerror += m;

			if (newerror > 0.5)
			{
				y++;
				newerror -= 1;
			}
			
		}
	}
	
	int main()
	{
	int radius = 3;
	int size = (radius*2)+1;
	char Array[7][7];
	int xFinish = 0;
	int yFinish = 0;
	do{
		scanf("%d", &xFinish);
		scanf("%d", &yFinish);
	
	for(int i =0; i < size; i++){
		for (int j = 0; j < size; j++)
		{
			Array[i][j] = '*';
			
		}
		printf("\n");
	}
	bresenham(radius, size, Array, yFinish ,xFinish);
	for(int i =0; i < size; i++){
		for (int j = 0; j < size; j++)
		{
			printf("%c ", Array[i][j]);
			
		}
		printf("\n");
		
	}
	}while(xFinish != 9);
	return 0;
	}