#include<iostream>
using namespace std;

int main(){
    string arr;
    getline(cin,arr);
    for(int i=0;i<arr.size();i++){
        if(arr[i]>='A' && arr[i]<='Z'){
            arr[i] = arr[i]+32;
        }
        else if(arr[i]>='a' && arr[i]<='z'){
            arr[i] = arr[i]-32;
        }
    }
    cout << arr << endl;
}