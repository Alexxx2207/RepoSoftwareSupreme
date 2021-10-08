#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   int NumbersInFile;
   int sum=0;
   FILE *file;
  
   file = fopen("newprogram.txt","w");

  
    if(file == NULL)
         {
            printf("Error!");
            exit(1);
         }
    do{

        printf("Enter num higher than 0: ");
        scanf("%d",&num);

    }while (num<=0);

        fprintf(file,"%d\n",num);
        printf("Now lets fill the file with numbers\n");
     
    for (int i = 0; i < num; i++)
     {
         
        scanf("%d",&NumbersInFile);
        sum+=NumbersInFile;
        fprintf(file,"%d\n",NumbersInFile);
     
     }
    fprintf(file,"%d\n",sum);

   fclose(file);

   return 0;
}