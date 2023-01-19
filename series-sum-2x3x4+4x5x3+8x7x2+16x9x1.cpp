#include<iostream>
using namespace std;

int seriesSum(int f1, int f2, int f3, int n){
    if(n==1)return f1*f2*f3;
    else{
        return f1*f2*f3 + seriesSum(f1*2,f2+2,f3-1,n-1);
    }
}
int main(){
    int n;cin >> n;
    cout << seriesSum(2,3,4,n);
}