#include <iostream>
using namespace std;


void fibonacci(){
	int n=0;
	int First=0;
	int Second=1;
	int NextRotation=0;

	cin >> n;
	for (int i=0; i<=n;i++){
		NextRotation=First+Second;
		First=Second;
		Second=NextRotation;
	}
	cout<<NextRotation<<endl;
}
int main() {
	cout<<" N=?";
	fibonacci();
	return(0);
}

