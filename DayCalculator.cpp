#include <iostream>
#include <cmath>
using namespace std;
 void Menu()
 {
	printf("Press 1 or 2\n");
	printf("1. If you want to check day\n");
	printf("2. If you want to check day + 1\n");
 }
int main()
{
	Menu();
	int day;
	int month;
	int year;
	int choise;
	scanf("%d", &choise);
	switch (choise)
	{
	case 1 : 
	printf("Enter year: ");
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		do{
			printf("Enter a valid month: ");
			scanf("%d",&month);
		}while(month > 12);
		if (month == 2)
		{
			do{
			printf("Enter a valid day: ");
			scanf("%d", &day);
			}while(day > 29);

		}else{
		do{
			printf("Enter a valid day: ");
			scanf("%d", &day);
		}while(day > 31);
	}
int M;
	if (month>2)
	{
		M=month;
	} else
	{
 		M=month+12;
 		year--;
	}
	int Y= year % 100;
	int C= year / 100;
	int W= (day + floor((13*(M+1)) / 5) + Y + floor(Y/4) + floor(C/4) + C*5);
	W = W % 7;
	switch (W)
	{
	case 0 :
		printf("Saturday");
		break;
	case 1 :
		printf("Sunday");
		break;
	case 2 :
		printf("Monday");
		break;
	case 3 :
		printf("Tuesday");
		break;
	case 4 :
		printf("Wednesday");
		break;
	case 5 :
		printf("Thursday");
		break;
	case 6 :
		printf("Friday");
		break;
	}
	}else
	{
	do{
		printf("Enter month: ");
		scanf("%d",&month);
	}while(month > 12);
	if (month == 2)
	{
		do{
			printf("Enter a valid day: ");
			scanf("%d",&day);
		}while(day > 28);

	}else{

		do{
			printf("Enter a valid day: ");
			scanf("%d",&day);
		}while(day > 31);
	}


	int M;
	if (month>2)
	{
		M=month;
	}else 
	{
 		M=month+12;
 		year--;
	}
	int Y= year % 100;
	int C= year / 100;
	int W= (day + floor((13*(M+1)) / 5) + Y + floor(Y/4) + floor(C/4) + C*5);
	W = W % 7;
	switch (W)
	{
	case 0 :
		printf("Saturday");
		break;
	case 1 :
		printf("Sunday");
		break;
	case 2 :
		printf("Monday");
		break;
	case 3 :
		printf("Tuesday");
		break;
	case 4 :
		printf("Wednesday");
		break;
	case 5 :
		printf("Thursday");
		break;
	case 6 :
		printf("Friday");
		break;
	}

}
		break;
	
	 

	
	} 
}
