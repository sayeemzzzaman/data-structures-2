/*
n=0,1,2,3,4,5....are 1,1,2,5,14,42
C(n) = from i=0 to n-1 Sum[ C(i)*C(n-1-i) ] and C(0)=1
*/

#include<iostream>
using namespace std;

int catalanNumber(int n){
    if(n==0){
        return 1;
    }
    else{
        int sum=0;
        for(int i=0;i<n;i++){
            sum = sum + catalanNumber(i)*catalanNumber(n-1-i);
        }
        return sum;
    }

}

int main(){
    int n;
    cin >> n;
    cout << catalanNumber(n) << endl;
}