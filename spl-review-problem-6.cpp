#include<iostream>
using namespace std;

void print_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

void reverse_array(int arr[], int n){
    int temp[n],j=0;
    for(int i=n-1;i>=0;i--){
        temp[i] = arr[j];
        j++;
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    reverse_array(arr,n);
    print_array(arr,n);
}

/*
7
4 256 2 4 3 3 5
*/