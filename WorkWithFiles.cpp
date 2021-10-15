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
        float sum;
        float Avg;
        float num;
  
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
               fscanf(file,"%f",&num);
               sum+=num;

             }
             Avg=sum/firstn;
             sum=0;
               cout<<"Average of line "<<"["<<i+1<<"] is : "<<("%.2f",Avg)<<endl;
               
         }
         
         
        
   fclose(file);
   delete[]array;
   return 0;
}