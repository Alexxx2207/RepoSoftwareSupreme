#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int day;
int month;
int year;
cout<<"Enter year: ";
cin>>year;
if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
{
	do{
	cout<<"Enter a valid month: ";
	cin>>month;
	}while(month > 12);
	if (month = 2)
	{
		do{
		cout<<"Enter a valid day: ";
		cin>>day;
		}while(day > 29);

	}else{

		do{
		cout<<"Enter a valid day: ";
		cin>>day;
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
	cout<<"Saturday";
	break;
case 1 :
	cout<<"Sunday";
	break;
case 2 :
	cout<<"Monday";
	break;
case 3 :
	cout<<"Tuesday";
	break;
case 4 :
	cout<<"Wednesday";
	break;
case 5 :
	cout<<"Thursday";
	break;
case 6 :
	cout<<"Friday";
	break;
}
}else
{
	do{
	cout<<"Enter month: ";
	cin>>month;
	}while(month > 12);
	if (month = 2)
	{
		do{
		cout<<"Enter a valid day: ";
		cin>>day;
		}while(day > 28);

	}else{

		do{
		cout<<"Enter a valid day: ";
		cin>>day;
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
	cout<<"Saturday";
	break;
case 1 :
	cout<<"Sunday";
	break;
case 2 :
	cout<<"Monday";
	break;
case 3 :
	cout<<"Tuesday";
	break;
case 4 :
	cout<<"Wednesday";
	break;
case 5 :
	cout<<"Thursday";
	break;
case 6 :
	cout<<"Friday";
	break;
}

}
}