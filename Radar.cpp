#include <iostream>
using namespace std;
	
	void bresenham(int radius, int size, char Array[7][7], int yFinish, int xFinish)
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
			Array[i][j] = '.';
			
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