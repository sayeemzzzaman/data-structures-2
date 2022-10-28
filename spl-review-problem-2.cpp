/*
Write a program that will run and show keyboard inputs until the user types an ’A’ at the keyboard.
*/
#include<iostream>
using namespace std;

int main(){
    char c;
    do{
        cin >> c;
        cout << c << endl;
    }while(c!='A');
}