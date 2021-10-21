#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{   
   FILE *file;

	file = fopen("newprogram.txt","r");
	
	
	if (file == NULL)
	{
		printf ("Error!");
		exit (1);
	}

	char array[256];	
	do{
		int avg=0;
		int sum=0;
		int FirstInLine=0;
		fgets (array, 256, file);
		sscanf(array,"%d\n",&FirstInLine);
		int check=0;
		
		for (int j = 0; j < 256; j++)
		{
			
			if (check>=FirstInLine)
			{	
				break;
			}
			const char ch = array[j];

			if (ch == '\0')
			{
				printf("\n");
				break;
			}
			else if (ch != ' ' && ch != '\n')
			{
				if(ch>0 && array[j-1] == ' ')
				{
					int num = 0;
					sscanf(&array[j], "%d", &num);
					//printf("%d %d ", num, j);
					sum += num;
					check++;
				}
			}
				
		}
		avg=sum/FirstInLine;
		printf("%s%d\n","The avg on line is :", avg);
		
	}while (feof(file) == 0 );
	
	        
        
   fclose(file);
   return 0;
}