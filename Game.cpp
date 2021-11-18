#include <iostream>
#include <stdio.h>
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

void PlayerVision(int &x, int &y, char Array[256][256],int rows, int charsonrow)
{
	
	for(int i = -2; i < 3; i ++)
	{
		for (int j = -2; j < 3; j++)
		{
			const int mapY = y+i;
			const int mapX = x+j;
			if(mapY < 1 || mapY > rows-2)
			{
				Array[y+i][x+j] = ' ';
				printf("%c",Array[y+i][x+j]);
			}else if(mapX < 0 || mapX > charsonrow)
			{
				Array[y+i][x+j] = ' ';
				printf("%c",Array[y+i][x+j]);
			}else
			{
				printf("%c",Array[mapY][mapX]);
			}
		}
		printf("\n\r");
	}
}
// void PrintMap(char a[256][256], int rows, int charsonrow)
// {
// 	for(int i = 0; i < rows-1; i++)
// 	{
// 		for(int j = 0;j < charsonrow+1;j++)
// 		{
// 			printf("%c", a[i][j]);
// 		}
// 		printf("\n\r");
// 	}
// }
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
			}
			break;
		case 'S':
		case 's':
			if(Array[y+1][x] != '#')
			{
				y++;
			}
			break;
		case 'A':
		case 'a':
			if(Array[y][x-1] != '#')
			{
				x--;
			}
			break;
		case 'D':
		case 'd':
			if(Array[y][x+1] != '#')
			{
				x++;
			}
			break;
		}
		system("clear");
		Array[y][x] = player;
		PlayerVision(x,y,Array,rows,charsonrow);
		//PrintMap(Array,rows,charsonrow);
		Array[y][x] = ' ';
		
	}while( movechar != 'q' && movechar != 'Q');
	system ("/bin/stty cooked");
}


