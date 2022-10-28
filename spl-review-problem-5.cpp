#include<iostream>
using namespace std;

int calc_factorial(int n){
    if(n==0)return 1;
    else{
        return n*calc_factorial(n-1);
    }
}

int main(){
    int number1,number2;
    cin >> number1 >> number2;
    
    for(int i=number1;i<=number2;i++){
        int fact = calc_factorial(i);
        cout << i << "! = ";
        for(int j=i;j>0;j--){
            cout << j;
            if(j!=1)cout << " x ";
        }
        cout << " = " << fact << endl;
    }
}