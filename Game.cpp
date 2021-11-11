#include <iostream>
#include <stdio.h>

int CustomGetLine(FILE* file ,char Array[256][256])
{
	char temp[256];
	for (int i=0; i< 10; i++)
	{
		fgets(temp, 256, file);
		for (int j=0;temp[j] != '\0'; j++){
				if(temp[j] == '\n') {
					temp[j] = '\0';
				}
				Array[i][j]=temp[j];
		}
	}
}
void PrintMap(char Array[256][256])
{
		for(int j = 0;j < 10;j++)
		{
			printf("%s\n\r", &Array[j]);
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
	CustomGetLine(file,Array);
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
		PrintMap(Array);
		Array[y][x] = ' ';
		
	}while( movechar != 'q' && movechar != 'Q');
	system ("/bin/stty cooked");
}


