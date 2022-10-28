/*
5! = 5x4x3x2x1
- 5, coll(4)
    -4, coll(3)
        -3, coll(2)
            -2 coll(1)
                -1 coll(0)
                    -return 1
*/
#include<iostream>
using namespace std;
int factorial(int num){
    if(num==0)return 1;
    else{
        // int mypart=num;
        // int colresult=factorial(num-1);
        // return colresult*mypart;
        return num*factorial(num-1);
    }
}

int main(){
    int num;
    cin >> num;
    cout << factorial(num) << endl;
}