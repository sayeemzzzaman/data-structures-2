#include<iostream>
using namespace std;

int sum(int n){
    if(n==1){
        cout<<n<<" ";
        return 1;
    }
    else{
        int c = (n*n) + sum(n-1);
        // return c+sum(n-1);
        cout << n*n << " ";
        return c;
    }
}

int main(){
    int n;
    cin >> n;
    cout << endl << sum(n);
}