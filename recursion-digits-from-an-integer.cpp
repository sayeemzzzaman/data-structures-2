#include<iostream>
using namespace std;

int sumOfDigits(int n){
    if(n<=9)return n;
    else{
        int rest = sumOfDigits(n/10);
        int lastdigit = n%10;
        return rest+lastdigit;
    }
        
}
int digitCalc(int n){
    if(n<=9)cout << n << " ";
    else{
        digitCalc(n/10);
        int lastdigit = n%10;
        cout << lastdigit << " ";
    }
}
int main(){
    int n;
    //cin >> n;
    digitCalc(923);
    cout << endl << "Sum: " << sumOfDigits(923);
}