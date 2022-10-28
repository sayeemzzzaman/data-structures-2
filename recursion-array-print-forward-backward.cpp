#include<iostream>
using namespace std;

int forward(int array[], int len){
    if(len==1)cout << array[0] << " ";
    else{
        forward(array,len-1);
        int mypart = array[len-1];
        cout << mypart << " ";
    }
}
int backward(int array[], int len){
    if(len==1)cout << array[0] << " ";
    else{
        int mypart = array[len-1];
        cout << mypart << " ";
        backward(array,len-1);
    }
}
int main(){
    int array[] = {1,2,7,8,4};
    int len = 5;
    forward(array,len);
    cout << endl;
    backward(array,len);
}