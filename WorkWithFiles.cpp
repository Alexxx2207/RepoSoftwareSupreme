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
        int SumPerLine=0;
        int firstn;
        int secondn;
  
    if(file == NULL)
         {
            printf("Error!");
            exit(1);
         }
         fscanf(file,"%d",&First);
         int *array = new int[First];
         
         for (int i = 0; i < First; i++)
         {
            
             fscanf(file,"%d %d",&firstn,&secondn);
             sum=firstn+secondn;
             SumPerLine+=sum;

           
             cout<<"The sum for line: "<<"["<<i+1<<"] is "<<SumPerLine<<endl;
             SumPerLine=0;
               
         }
         
         
        
   fclose(file);
   delete[]array;
   return 0;
}