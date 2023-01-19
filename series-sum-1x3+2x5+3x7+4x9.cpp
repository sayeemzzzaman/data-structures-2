#include<iostream>
using namespace std;

int seriesSum(int f1, int f2, int n){
    if(n==1)return f1*f2;
    else{
        return f1*f2 + seriesSum(f1+1,f2+2,n-1);
    }
}
int main(){
    int n;cin >> n;
    cout << seriesSum(1,3,n);
}