#include<iostream>
using namespace std;

int sum(int n){
    if(n==1){
        cout<<n<<" ";
        return 1;
    }
    else{
        int c1 =  n+sum(n-1);
        cout << n << " ";
        return c1;
    }
}

int main(){
    int n;
    cin >> n;
    cout << endl << sum(n);
}