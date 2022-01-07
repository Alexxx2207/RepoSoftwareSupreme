#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <math.h>

using namespace std;
	
	struct Element{
		int x;
		int y;
		int num;
		bool seen;
		bool del;
	};

	Element elem[50];

	void shouldDraw( int AddNum,int x, int y)
	{
		for(int i = 0; i < AddNum; i++)
		{
			if(x == elem[i].x && y == elem[i].y)
			{
				elem[i].seen = elem[i].del == false;
			}
		}
	}
	void SecondToFirst(int yIn, int xIn, int xOut, int yOut)
	{
		xIn = yOut;
	}
	void draw(int radius, int size, char Array[100][100], int yFinish, int xFinish , bool &ShouldDelete, int &AddNum)
	{
		int x1 = radius;
		int y1 = radius;
		int yfinal = yFinish;
		int xfinal = xFinish;
		float UpDown = float(yfinal - (y1))/(xfinal - (x1));
		float LeftRight = float(xfinal - (x1))/(yfinal - (y1));
		float newerror = 0;
		int x = x1, y = y1;
		if(xfinal < x1 && yfinal < size - 1 && yfinal > 0){
			for (;(x-x1)*(x-x1) +(y-y1)*(y-y1) < radius*radius && x >= xfinal; x--)
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
				shouldDraw(AddNum,x,y);  
			}
		} else if (xfinal > x1 && yfinal < size - 1 && yfinal > 0)
		{
			x = x1, y = y1
			FirstToSecond(yfinal,xfinal,x,y);
			for (;(x-x1)*(x-x1) +(y-y1)*(y-y1) < radius*radius && x <= xfinal; x++)
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
				shouldDraw(AddNum,x,y);    
				
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
				shouldDraw(AddNum,x,y);     
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
			shouldDraw(AddNum,x,y);   
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
	
	void DoThatThing (char Array[100][100], int &Move, bool &ShouldDelete,int &AddNum)
	{
		system ("/bin/stty raw");
		printf("enter command: " "\n\r");
		char Action = getchar();
		int delObj;
		switch (Action)
		{
			case 'a':
				scanf("%d %d", &elem[AddNum].x, &elem[AddNum].y);
				elem[AddNum].num = AddNum;
				AddNum++;
				break;
			case 's': 
				scanf(" %d", &Move);
				break;
			case 'd':
				scanf("%d", &delObj);
				elem[delObj].del=true;
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
	int yFinish = 0;
	bool ShouldDelete = false;
	int Move = 0;
	int AddNum = 0;
	while(true){
		do{
			while (Move != 0 && yFinish != size)
			{
				Move--;
				Filler(Array, size);
			draw(radius, size, Array, yFinish ,xFinish,ShouldDelete,AddNum);
			for(int i = 0; i < AddNum;i++){
				if(true == elem[i].seen)
				{
					Array[elem[i].x][elem[i].y] = '0' + elem[i].num;
									
				}
			}
			
			PrintEverything(radius,Array,size);
			yFinish++;
			usleep(100000);
			}
			if(Move == 0){
			DoThatThing(Array,Move,ShouldDelete,AddNum);
		}

		}while(yFinish != size);
		do{
			while (Move != 0 && xFinish != size)
			{
				Move--;
				Filler(Array, size);
			draw(radius, size, Array, yFinish ,xFinish,ShouldDelete,AddNum);
			for(int i = 0; i < AddNum;i++){
				if(true == elem[i].seen)
				{
				Array[elem[i].x][elem[i].y] = '0' + elem[i].num;
										
				}
			}
			PrintEverything(radius,Array,size);
			xFinish++;
			usleep(100000);
			}
			if(Move == 0){
				DoThatThing(Array,Move,ShouldDelete,AddNum);
			}
		}while(xFinish != size);
		do{
			while (Move != 0 && yFinish != 0)
			{
				Move--;
				Filler(Array, size);
			draw(radius, size, Array, yFinish ,xFinish,ShouldDelete,AddNum);
			for(int i = 0; i < AddNum;i++){
				if(true == elem[i].seen)
				{
					Array[elem[i].x][elem[i].y] = '0' + elem[i].num;
										
				}
			}
			
			PrintEverything(radius,Array,size);
			yFinish--;
			usleep(100000);
			}
				if(Move == 0){
				DoThatThing(Array,Move,ShouldDelete,AddNum);
			}
		}while(yFinish != 0);
		do{
			while (Move != 0 && xFinish != 0)
			{
				Move--;
				Filler(Array, size);
			draw(radius, size, Array, yFinish ,xFinish,ShouldDelete,AddNum);
			for(int i = 0; i < AddNum;i++){
				if(true == elem[i].seen)
				{
				Array[elem[i].x][elem[i].y] = '0' + elem[i].num;
								
				}
			}
			
			PrintEverything(radius,Array,size);
			xFinish--;
			usleep(100000);
			}
			if(Move == 0){
				DoThatThing(Array,Move,ShouldDelete,AddNum);
			}
		}while(xFinish != 0);
	}
	return 0;
	}