#include <iostream>
#include <stdio.h>
int CustomGetLine(FILE* file ,char Array[256][256])
{
	char temp[256];
	int i = 0;
	for (; feof(file) == 0; i++)
	{	
		fgets(temp, 256, file);
		for (int j=0;temp[j] != '\0'; j++)
		{	
				if(temp[j] == '\n') {
					temp[j] = '\0';
					
				}
				Array[i][j]=temp[j];
		}
	}
	return i;
}
// int CharsOnRow(FILE* file, char Array[256][256])
// {
// 	int charsonrow = 0;
// 	char temp[256];
// 	fgets(temp, 256, file);
// 		for (int j=0;temp[j] != '\0'; j++)
// 		{	
// 				charsonrow++;
// 		}
// 		return charsonrow;
// }
//}
void PlayerVision(int &x, int &y, char Array[256][256],int player)
{
	for(int i = -2; i < 3; i ++)
	{
		for (int j = -2; j < 3; j++)
		{
			printf("%c",Array[y+i][x+j]);
			
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
	int y = 1;
	int x = 1;
	char movechar;
	// int charsonrow = CharsOnRow(file,Array);
	int rows = CustomGetLine(file,Array);
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
		PlayerVision(x,y,Array,player);
		//PrintMap(Array,rows);
		Array[y][x] = ' ';
		
	}while( movechar != 'q' && movechar != 'Q');
	system ("/bin/stty cooked");
}


