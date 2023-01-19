#include<iostream>
using namespace std;

int gcd(int x, int y){
    if(y==0)return x;
    else if(x==0)return y;
    else{
        if(x>y){
            gcd(y,x%y);
        }
        else{
            gcd(x,y%x);
        }
    }
}

int main(){
    int x,y;
    cin >> x >> y;
    cout << gcd(x,y) << endl;
}