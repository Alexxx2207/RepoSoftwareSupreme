#include <iostream>
#include <math.h>
using namespace std;
	
	void bresenham(int radius, int size, char Array[100][100], int yFinish, int xFinish)
	{
		int x1 = radius;
		int y1 = radius;
		int yfinal = yFinish;
		int xfinal = xFinish;
		float UpDown =float(yfinal - (y1))/(xfinal - (x1));
		float LeftRight = float(xfinal - (x1))/(yfinal - (y1));
		float newerror = 0;
		if(xfinal < x1 && yfinal < size - 1 && yfinal > 0){
		for (int x = x1, y = y1; x >= xfinal; x--)
		{
			Array[x][y] = '#';
			cout << "(" << x << "," << y <<","<< newerror << ")\n";
			newerror += UpDown;
			
			if (newerror > 0.5)
			{
				y--;
				newerror -= 1;
			}
			if (newerror < -0.5)
			{
				y++;
				newerror += 1;
			}
			
		}
		} else if (xfinal > x1 && yfinal < size - 1 && yfinal > 0)
		{
			for (int x = x1, y = y1; x <= xfinal; x++)
			{
				Array[x][y] = '#';
				cout << "(" << x << "," << y <<","<< newerror << ")\n";
				newerror += UpDown;
				
				if (newerror > 0.5)
				{
					y++;
					newerror -= 1;
				}
				if (newerror < -0.5)
				{
					y--;
					newerror += 1;
				}
				
			}	
		} else if(yfinal < y1)
		{
			for (int x = x1, y = y1; y >= yfinal; y--)
			{
				Array[x][y] = '#';
				cout << "(" << x << "," << y <<","<< newerror << ")\n";
				newerror += LeftRight;
				
				if (newerror > 0.5)
				{
					x--;
					newerror -= 1;
				}
				if (newerror < -0.5)
				{
					x++;
					newerror += 1;
				}
				
			}
		}else if(yfinal > y1)
		{
			for (int x = x1, y = y1; y <= yfinal; y++)
			{
				Array[x][y] = '#';
				cout << "(" << x << "," << y <<","<< newerror << ")\n";
				newerror += LeftRight;
				
				if (newerror > 0.5)
				{
					x++;
					newerror -= 1;
				}
				if (newerror < -0.5)
				{
					x--;
					newerror += 1;
				}
				
			}
		}
	}
	void Filler(int &radius, char Array[100][100], int &size, int &yFinish, int &xFinish)
	{
		for(int i =0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				Array[i][j] = '.';
			}
			printf("\n");
			}
		bresenham(radius, size, Array, yFinish ,xFinish);
		for(int i = 0;i < size; i++)
		{
			for(int j = 0;j < size;j++)
			{
				if(pow((radius-i),2)+ pow((radius-j),2)> radius*radius){
					printf("X ");
				}else{
					printf("%c ",Array[i][j]);
				}
			}
			printf("\n\r");
		} 
	}

	int main()
	{
	int radius = 10;
	int size = (radius*2)+1;
	char Array[100][100];
	int xFinish = 0;
	int yFinish = radius;
	do{
		scanf("%d", &xFinish);
		scanf("%d", &yFinish);
		Filler(radius, Array, size, yFinish,xFinish);
		// for (; yFinish < size * 2; yFinish++)
		// {
		// 	if(yFinish == size - 1)
		// 	do{
		// 		xFinish++;
		// 	}while(xFinish == size - 1)
		// }
		
	}while(true);
	return 0;
	}