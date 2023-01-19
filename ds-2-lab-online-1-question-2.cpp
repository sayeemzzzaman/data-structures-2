#include<iostream>
using namespace std;

bool check(int x){
    if(x%11==0)return true;
    else return false;
}
int sumOfGoodNumbers(int arr[],int start, int n){
    if(start==n){
        if(check(arr[n])){
            cout << arr[n] << " ";
            return arr[n];
        }
        else return 0;
    }
    else{
        int mid = (start+n)/2;
        int c1 = sumOfGoodNumbers(arr,start,mid);
        int c2 = sumOfGoodNumbers(arr,mid+1,n);

        return c1+c2;
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int output = sumOfGoodNumbers(arr,0,n);
    cout << endl << output << endl;
}

/*
5
11 0 1 5 22
*/