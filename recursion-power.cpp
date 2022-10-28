#include<iostream>
using namespace std;

int powerFunction(int num, int power){
    if(power==1){
        return num;
    }
    else{
        int mypart = num;
        int restpart = powerFunction(num,power-1);
        // int myresult =  mypart*restpart;
        // return myresult;
        return mypart*restpart;
    }
}

int main(){
    int num,power;
    cin >> num >> power;
    cout << powerFunction(num,power) << endl;
}