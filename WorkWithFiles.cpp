#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{

   
   FILE *file;
  
   file = fopen("newprogram.txt","r");
        int First=0;
        int firstn;
        int sum;
        int Avg;
        int num;
  
    if(file == NULL)
         {
            printf("Error!");
            exit(1);
         }
         fscanf(file,"%d",&First);
         int *array = new int[First];
         
         for (int i = 0; i < First; i++)
         {
            
             fscanf(file,"%d",&firstn);
             for(int i=0;i<firstn;i++)
             {
               fscanf(file,"%d",&num);
               sum+=num;

             }
             Avg=sum/firstn;
             sum=0;
               cout<<"Average of line "<<"["<<i+1<<"] is : "<<Avg<<endl;
               
         }
         
         
        
   fclose(file);
   delete[]array;
   return 0;
}