#include <iostream>
#include <stdio.h>
#include <math.h>
// bool CheckIfVisible(int x1, int y1, int x2, int y2, char Array[256][256])
// {
// 	float m =(y2 - y1)/float(x2 - x1);
// 	float newerror = 0;
// 	for (int x = x1, y = y1; x <= x2; x++)
// 	{
// 		cout << "(" << x << "," << y << ")\n";
// 		newerror += m;

// 		if (newerror > 0.5)
// 		{
// 			y++;
// 			newerror -= 1;
// 		}
		
// 	}
// }
int CustomGetLine(FILE* file ,char Array[256][256], int &charsonrow)
{
	char temp[256];
	int i = 0;
	for (; feof(file) == 0; i++)
	{	
		fgets(temp, 256, file);
		for (int j=0;temp[j] != '\0'; j++)
		{	
				if(temp[j] == '\n') {
					break;
				}
				Array[i][j]=temp[j];
				charsonrow = j;
		}
	}
	return i;
}
int calculatevision(int x, int y)
{
	return pow((x-y),2);
}
void ChangeVision(char Array[256][256], int &x, int &y, int &radius)
{
	if(Array[y][x] == 'L')
	{
		radius++;
	}else if(Array[y][x] == 'l')
	{
		radius--;
	}
}
void PrintMap(char Array[256][256], int rows, int charsonrow,int &x, int &y, int &radius)
{
	for(int i = 0;i < rows+1; i++)
	{
		for(int j = 0;j < charsonrow+1;j++)
		{
			if(calculatevision(y,i) + calculatevision(x,j) > radius*radius){
				printf(" ");
			}else{
				printf("%c",Array[i][j]);
			}
		}
		printf("\n\r");
	} 
}
int main(){

	FILE * file;
	file = fopen("MazeGame.txt","r");
	
	if (file == NULL)
	{
		printf ("Error!");
		exit (1);
	}
	char Array[256][256];
	
	const char player = '@';
	int y;
	int x;
	int radius = 3;
	char movechar;
	int charsonrow;
	int rows = CustomGetLine(file,Array,charsonrow);
	sscanf(Array[0], "%d %d", &x, &y);
	if(Array[x][y] == '#')
	{
		printf("Invalid spawn point");
		return 0;
	}
	do{
		
		system ("/bin/stty raw");
		movechar = getchar();
		switch (movechar)
		{
		case 'w':
		case 'W':
			if(Array[y-1][x] != '#')
			{
				y--;
				ChangeVision(Array,x,y,radius);
			}
			break;
		case 'S':
		case 's':
			if(Array[y+1][x] != '#')
			{
				y++;
				ChangeVision(Array,x,y,radius);
			}
			break;
		case 'A':
		case 'a':
			if(Array[y][x-1] != '#')
			{
				x--;
				ChangeVision(Array,x,y,radius);
			}
			break;
		case 'D':
		case 'd':
			if(Array[y][x+1] != '#')
			{
				x++;
				ChangeVision(Array,x,y,radius);
			}
			break;
		}
		system("clear");
		Array[y][x] = player;
		PrintMap(Array,rows,charsonrow,x,y,radius);
		Array[y][x] = ' ';
		
	}while( movechar != 'q' && movechar != 'Q');
	system ("/bin/stty cooked");
}


