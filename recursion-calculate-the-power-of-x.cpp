//x^y
/*

2^3
2*2*2
power(2,3)
-2, power(2,2)
	-2, power(2,1)
		- 2 power(2,0)
*/
#include<iostream>
using namespace std;

int powerValue(int x, int y){
	if(y==0)return 1;
	//else if(y==1)return x;
	else{
		return x*powerValue(x,y-1);
	}
}

int main(){
	int x,y;
	cin >> x >> y;
	cout << powerValue(x,y) << endl;
}