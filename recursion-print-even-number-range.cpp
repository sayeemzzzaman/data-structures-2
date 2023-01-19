#include<iostream>
using namespace std;
/*
3->7
-3, 4-7
    -4, 5-7
        -5, 6-7
            -6, 7-7

*/
void printEven(int a, int b){
    if(a==b){
        if(b%2==0)cout<<b<<" ";
    }
    else{
        if(a%2==0)cout<<a<<" ";
        printEven(a+1,b);
    }
}
int main(){
    int a,b;
    cin >> a >> b;
    printEven(a,b);
}