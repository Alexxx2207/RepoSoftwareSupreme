#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{

   
   FILE *file;
  
   file = fopen("newprogram.txt","r");
        int First=0;
        int sum=0;
  
    if(file == NULL)
         {
            printf("Error!");
            exit(1);
         }
         fscanf(file,"%d",&First);
         int *array = new int[First];
         for (int i = 0; i < First; i++)
         {
             fscanf(file,"%d",&array[i]);
             sum+=array[i];
               
         }
         cout<<sum;
         
        
   fclose(file);
   delete[]array;
   return 0;
}