/*
0 1 1 2 3 5 8 13 21
myself(n-th)
-   int prev1 = colleague(n-1)
    int prev2 = colleague(n-2)
    return prev1+prev2

*/
#include<iostream>
using namespace std;
int fibonacci(int n){
    if(n==0)return 0;
    else if(n==1)return 1;
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }

}

int main(){
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}