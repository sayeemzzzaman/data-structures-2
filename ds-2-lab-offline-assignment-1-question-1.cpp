#include<iostream>
using namespace std;

bool isPrime(int x){
    if(x<=1)return false;
    for(int i=2;i<=x/2;i++){
        if(x%i==0)return false;
    }
    return true;
}

void printPrime(int arr[],int n){
    if(n==0){
        if(isPrime(arr[n]))cout<<arr[n]<<" ";
        return;
    }
    else{
        printPrime(arr,n-1);
        if(isPrime(arr[n]))cout<<arr[n]<<" ";
    }
}

int countPrime(int arr[],int n){
    if(n==0){
        if(isPrime(arr[n]))return 1;
        return 0;
    }
    else{
        int c1 = isPrime(arr[n]);
        int c2 = countPrime(arr,n-1);
        return c1+c2;
    }
}

int main(){
    int n;
    cin>>n;

    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    printPrime(A,n-1);
    cout << endl << "#primes=" << countPrime(A,n-1) << endl;
}