#include<iostream>
using namespace std;

int deciToBinary(int num){
    if(num==0){

    }
    else{
        int mypart = num%2;
        int restpart = deciToBinary(num/2);
        cout << mypart << " ";
    }
}
//for octal just divide by 8

int main(){
    deciToBinary(14);
}