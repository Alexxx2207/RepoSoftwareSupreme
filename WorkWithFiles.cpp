#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{   
   FILE *file;

	file = fopen("newprogram.txt","r");
	int FirstNum;
	int sum=0;
	if (file == NULL)
	{
		printf ("Error!");
		exit (1);
	}

	char array[256];
	fscanf (file,"%d\n",&FirstNum);
	
	for (int i=0;i<FirstNum;i++)
	{
		fgets (array, 256, file);
		
			for (int j = 0; j < 256; j++)
			{
				
				
					const char ch = array[j];
					int FirstInLine;

					sscanf(array,"%d",&FirstInLine);

                    
						if (ch == '\0')
						{
							printf("\n");
							break;
						}
						else if (ch != ' ' && ch != '\n')
						{
							int num = 0;
							sscanf(&array[j], "%d", &num);
							//printf("%d %d ", num, j);
							sum += num;
						}
					
			}
			printf("%d", sum);
			sum = 0;
		       
	}
	        
        
   fclose(file);
   return 0;
}