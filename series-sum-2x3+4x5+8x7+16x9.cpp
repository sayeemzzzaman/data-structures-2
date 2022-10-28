#include<iostream>
using namespace std;

int series(int first, int second, int n){
	if(n==1)return first*second;
	else{
		cout << first << " " << second << endl;
		return first*second+series(first*2,second+2,n-1);
	}
}

int main(){
	int n;
	cin >> n;
	cout << series(2,3,n) << endl;
}