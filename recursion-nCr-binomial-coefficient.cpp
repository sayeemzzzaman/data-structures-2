/*
nCr = (n-1)Cr + (n-1)C(r-1)
C(n,r) = C(n-1,r) + C(n-1, r-1)  ;n>=r

base condition:
                n!           n!
C(n,0) = 1 = ----------- = ------- = 1
              r! (n-r)!      n!

                n!           n!
C(n,n) = 1 = ----------- = ------- = 1
              n! (n-n)!      n! 0!
       5!          120
5C3 = --------  = ------- = 10
      3! (5-3)!    12
*/
#include<iostream>
using namespace std;

int ncr(int n, int r){
    if(r==0)return 1;
    else if(n==r)return 1;
    else{
        return ncr(n-1,r)+ncr(n-1,r-1);
    }
}

int main(){
    int n,r;
    cin >> n >> r;
    cout << ncr(n,r) << endl;
}