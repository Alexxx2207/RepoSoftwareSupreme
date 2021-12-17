#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <math.h>

using namespace std;
	
	void bresenham(int radius, int size, char Array[100][100], int yFinish, int xFinish, int &ObjectX,int &ObjectY, bool &IsSeen, bool &ShouldDelete)
	{
		int x1 = radius;
		int y1 = radius;
		int yfinal = yFinish;
		int xfinal = xFinish;
		float UpDown =float(yfinal - (y1))/(xfinal - (x1));
		float LeftRight = float(xfinal - (x1))/(yfinal - (y1));
		float newerror = 0;
		if(xfinal < x1 && yfinal < size - 1 && yfinal > 0){
		for (int x = x1, y = y1;(x-x1)*(x-x1) +(y-y1)*(y-y1) < radius*radius && x >= xfinal; x--)
		{
			Array[x][y] = '#';
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
			if(x==ObjectX && y==ObjectY){
					if(ShouldDelete == true){
						IsSeen=false;
					}else{
						IsSeen = true;
					}

				} 
		}
		} else if (xfinal > x1 && yfinal < size - 1 && yfinal > 0)
		{
			for (int x = x1, y = y1;(x-x1)*(x-x1) +(y-y1)*(y-y1) < radius*radius && x <= xfinal; x++)
			{
				Array[x][y] = '#';
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
				if(x==ObjectX && y==ObjectY){
					if(ShouldDelete == true){
						IsSeen=false;
					}else{
						IsSeen = true;
					}

				} 
				
			}	
		} else if(yfinal < y1)
		{
			for (int x = x1, y = y1;(x-x1)*(x-x1) +(y-y1)*(y-y1) < radius*radius && y >= yfinal; y--)
			{
				Array[x][y] = '#';
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
				if(x==ObjectX && y==ObjectY){
					if(ShouldDelete == true){
						IsSeen=false;
					}else{
						IsSeen = true;
					}

				} 
				
		
			}
		}else if(yfinal > y1)
		{
			for (int x = x1, y = y1;(x-x1)*(x-x1) +(y-y1)*(y-y1) < radius*radius && y <= yfinal; y++)
			{
				Array[x][y] = '#';
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
				if(x==ObjectX && y==ObjectY){
					if(ShouldDelete == true){
						IsSeen=false;
					}else{
						IsSeen = true;
					}

				} 
			}
		}
	}
	void Filler(char Array[100][100], int &size)
	{
		
		for(int i =0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				Array[i][j] = '.';
			}
			printf("\n");
			}
		} 
	
	// void AddObjects(char Array[100][100],int &ObjectX,int &ObjectY)
	// {
	// 	printf("Enter the cordinates of the object");
	// 	scanf("%d",&ObjectX);
	// 	scanf("%d",&ObjectY);
	// } 
	// void SeekAndDestroy(char Array[100][100], int ObjectX, int ObjectY)
	// {

	// }
	void DoThatThing (char Array[100][100],int &ObjectX,int &ObjectY, int &Move, bool &ShouldDelete)
	{
		int delx,dely;
		system ("/bin/stty raw");
		printf("enter command: " "\n\r");
		char Action = getchar();
		switch (Action)
		{
			case 'a':
				scanf(" %d %d", &ObjectX, &ObjectY);
				ShouldDelete = false;
				break;
			case 's': 
				scanf(" %d", &Move);
				break;
			case 'd':
				ShouldDelete = true;
				break;
		}
	}

	
	void PrintEverything(int radius, char Array[100][100], int size){
		for(int i = 0;i < size; i++)
		{
			for(int j = 0;j < size;j++)
			{
				if(pow((radius-i),2)+ pow((radius-j),2)> (radius*radius)-1){
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
	int radius = 6;
	int size = (radius*2)+1;
	char Array[100][100];
	int xFinish = 0;
	int yFinish = radius;
	int ObjectX;
	int ObjectY;
	bool IsSeen = false;
	bool ShouldDelete = false;
	int Move = 0;
	while(true){
		do{
			while (Move != 0 && yFinish != size)
			{
				Move--;
				Filler(Array, size);
			bresenham(radius, size, Array, yFinish ,xFinish,ObjectX,ObjectY,IsSeen,ShouldDelete);
			if(true == IsSeen)
			{
				Array[ObjectX][ObjectY] = '$';				
			}
			PrintEverything(radius,Array,size);
			yFinish++;
			usleep(100000);
			}
			if(Move == 0){
			DoThatThing(Array,ObjectX,ObjectY,Move,ShouldDelete);
		}
		}while(yFinish != size);
		do{
			while (Move != 0 && xFinish != size)
			{
				Move--;
				Filler(Array, size);
			bresenham(radius, size, Array, yFinish ,xFinish,ObjectX,ObjectY,IsSeen,ShouldDelete);
			if(true == IsSeen)
			{
				Array[ObjectX][ObjectY] = '$';				
			}
			PrintEverything(radius,Array,size);
			xFinish++;
			usleep(100000);
			}
			if(Move == 0){
				DoThatThing(Array,ObjectX,ObjectY,Move,ShouldDelete);
			}
		}while(xFinish != size);
		do{
			while (Move != 0 && yFinish != 0)
			{
				Move--;
				Filler(Array, size);
			bresenham(radius, size, Array, yFinish ,xFinish,ObjectX,ObjectY,IsSeen,ShouldDelete);
			if(true == IsSeen)
			{
				Array[ObjectX][ObjectY] = '$';				
			}
			PrintEverything(radius,Array,size);
			yFinish--;
			usleep(100000);
			}
				if(Move == 0){
				DoThatThing(Array,ObjectX,ObjectY,Move,ShouldDelete);
			}
		}while(yFinish != 0);
		do{
			while (Move != 0 && xFinish != 0)
			{
				Move--;
				Filler(Array, size);
			bresenham(radius, size, Array, yFinish ,xFinish,ObjectX,ObjectY,IsSeen,ShouldDelete);
			if(true == IsSeen)
			{
				Array[ObjectX][ObjectY] = '$';				
			}
			PrintEverything(radius,Array,size);
			xFinish--;
			usleep(100000);
			}
			if(Move == 0){
				DoThatThing(Array,ObjectX,ObjectY,Move,ShouldDelete);
			}
		}while(xFinish != 0);
		IsSeen=false;	
	}
	return 0;
	}