#include <iostream>
#include <string.h>
using namespace std;

int getstrlen(char*str)
{
    int n=0;
    while (str[n] != '\0')
    {
        n++;
    }
    return n;
}
int main(){
    FILE* file = fopen("reverse.txt", "r");
    if (file == NULL)
	{
		printf ("Error!");
		exit (1);
	}
     char strarray[256];
     fgets(strarray, 256, file);
     int a = getstrlen(strarray);
     for (int i = 0; i < a/2; i++)
     {
       char temp = strarray[i];
       strarray[i]=strarray[a-i-1];
       strarray[a-i-1]=temp;
     }
     printf("%s",strarray);
     fclose(file);

return 0;

}