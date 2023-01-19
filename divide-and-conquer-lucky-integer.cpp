/*
an integer is lucky if its last digit is 8
*/
#include <iostream>
using namespace std;
bool check(int x){
    if(x<=9 && x==8)return true;
    else if(x%10==8)return true;
    return false;
}

int luckyInteger(int arr[], int i, int j){
    if(i==j){
        if(check(arr[i]))return 1;
        return 0;
    }
    else{
        int mid = (i+j)/2;
        int c1 = luckyInteger(arr,i,mid);
        int c2 = luckyInteger(arr,mid+1,j);

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
    cout << luckyInteger(arr,0,n-1);
}