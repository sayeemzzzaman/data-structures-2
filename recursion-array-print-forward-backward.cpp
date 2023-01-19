#include<iostream>
using namespace std;
/*
{1,2,7,8,4}
-1, 2,7,8,4
    -2, 7,8,4
        -7, 8,4
            -8, 4
                -4
*/
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
    // int array[] = {1,2,7,8,4};
    // int len = 5;
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++){
        cin >> array[i];
    }
    forward(array,n);
    cout << endl;
    backward(array,n);
}