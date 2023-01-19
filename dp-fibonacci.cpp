//tabulation method ~ DP with for loop
//memoization method ~ DP with recursive

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    long long F[n+1];
    F[0]=0;
    F[1]=1;
    for(long long i=2;i<=n;i++){
        F[i] = F[i-1] + F[i-2];
    }
    cout << F[n] << endl;
}
//0 1 1 2 3 5 8