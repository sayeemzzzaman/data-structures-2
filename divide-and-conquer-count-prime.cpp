#include<iostream>
using namespace std;

bool isPrime(int x){
    if (x <= 1)
        return false;
    for (int i = 2; i <= x/2; i++)
        if (x % i == 0)
            return false;
 
    return true;
}
int countPrime(int arr[],int i, int j){
    if(i==j){
        if(isPrime(arr[i])){
            // cout<<arr[i]<<" ";
            return 1;
        }
        else return 0;
    }
    else{
        int mid = (i + j) / 2;
        int c1 = countPrime(arr, i, mid);     // solution to the first half
        int c2 = countPrime(arr, mid + 1, j); // solution to the second half
        return c1+c2;
    }
}

int main(){
    int arr[]= {1,2,3,4,5,6,7,8,9};
    cout << countPrime(arr,0,8) << endl;
}