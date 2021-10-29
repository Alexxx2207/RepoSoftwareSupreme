#include <iostream>
#include <cmath>
using namespace std;
 void Menu()
 {
	printf("\nChoose one of the options\n");
	printf("1. If you want to check day\n");
	printf("2. If you want to check day + 1\n");
	printf("3. Exit");
 }
 int DayOfWeekCalculation( int day, int month , int year)
 {
int M=0;
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
	return W;
 }
 const char* GetNameDay (int dayOfWeek)
 {
	 switch (dayOfWeek)
	{
	case 0 :
		return "Saturday";
	case 1 :
		return "Sunday";
	case 2 :
		return "Monday";
	case 3 :
		return "Tuesday";
	case 4 :
		return "Wednesday";
	case 5 :
		return "Thursday";
	case 6 :
		return "Friday";
	}
 }
int main()
{ 
	bool check = false;
	do{
	Menu();
	int day=0;
	int month=0;
	int year=0;
	int choise=0;
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
			scanf("%d", &month);
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
	int dayOfWeek = DayOfWeekCalculation(day, month, year);
	printf("%s", GetNameDay(dayOfWeek));
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
	int dayOfWeek = DayOfWeekCalculation(day, month, year);
	printf("%s", GetNameDay(dayOfWeek));
}
		break;
	case 2: 
	printf("Enter year: ");
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		do{
			printf("Enter a valid month: ");
			scanf("%d", &month);
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
	int dayOfWeek= DayOfWeekCalculation(day, month, year);
	int maxdays=0;
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		maxdays= 31;
		break;
	case 2:
		maxdays= 29;
		break;
	case 4: case 6: case 9: case 11:
		maxdays= 30;
		break;
	}
	if(day+1>maxdays)
	{
		day=1;
		month++;
	}
	if(month>12)
	{
		month=1;
		year++;
	}
	int newday= day+1;
	printf("The date is : %d %d %d ", newday, month, year);
	dayOfWeek++;
	if(dayOfWeek>6)
	{
		dayOfWeek=0;
	}
	printf("%s", GetNameDay(dayOfWeek));
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
	int dayOfWeek= DayOfWeekCalculation(day, month, year);
	int maxdays;
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		maxdays= 31;
		break;
	case 2:
		maxdays= 28;
		break;
	case 4: case 6: case 9: case 11:
		maxdays= 30;
		break;
	}
	if(day+1>maxdays)
	{
		day=1;
		month++;
	}
	if(month>12)
	{
		month=1;
		year++;
	}
	int newday= day+1;
	printf("The date is : %d %d %d ", newday, month, year);
	dayOfWeek++;
	if(dayOfWeek>6)
	{
		dayOfWeek=0;
	}
	printf("%s", GetNameDay(dayOfWeek));

}
		break;
	case 3: 
	check = true;
	return 0;
	} 
	}while(check != true);
}
