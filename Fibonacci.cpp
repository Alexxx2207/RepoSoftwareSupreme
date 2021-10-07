#include <iostream>
using namespace std;

int main(void) {
 int n, First=0, Second=1, NextRotation=0;
 cout<<" N=?";

      cin>>n;

     for (int i=0; i<=n;i++){

     if (i==0)
     {

     cout<<First<<", ";
     continue;
     }

     if (i==2)
     {
     cout<<Second<<", ";
     continue;
     }
     NextRotation=First+Second;
     First=Second;
     Second=NextRotation;
     cout<<NextRotation<<", ";

 }
 
     return(0);

}
