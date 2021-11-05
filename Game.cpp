#include <iostream>
#include <stdio.h>

void SetupGround(char player, char PrintArray[256][256],int n,int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		{
			if(i == 0 || i == (n-1))
			{
				PrintArray[i][j] = '#';
			}else if(j == 0 || j == (m-1))
			{
				PrintArray[i][j] = '#';
			}else
			{
				PrintArray[i][j] = ' ';
			}
		}
	}
	
}
void PrintMap(char a[256][256], int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;j < m;j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n\r");
	}
}
int main()
{
	char Array[256][256];
	int n,m;
	scanf("%d %d", &n, &m);
	char player = '@';
	int y = n/2;
	int x = m/2;
	char movechar;
	do{
		system ("/bin/stty raw");
		movechar = getchar();
		switch (movechar)
		{
		case 'w':
		case 'W':
			if(y > 1)
			{
				y--;
			}
			break;
		case 'S':
		case 's':
			if(y < (n-2))
			{
				y++;
			}
			break;
		case 'A':
		case 'a':
			if ( x > 1)
			{
				x--;
			}
			break;
		case 'D':
		case 'd':
			if(x < (m-2))
			{
				x++;
			}
			break;
		}
		system("clear");
		SetupGround(player, Array, n, m);
		Array[y][x] = player;
		PrintMap(Array, n, m);
		
	}while( movechar != 'q' && movechar != 'Q');
	system ("/bin/stty cooked");
}


