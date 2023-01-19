/*
length of rod 1 2 3  4 5
price         5 7 9 21 23

rc(5) = 23+rc(5-5) = 23
        21+rc(5-4) = 21
        9 +rc(5-3) = 9
        7 +rc(5-2) = 7
        5 +rc(5-1) = 5
similar code of dpcoinchange

sample~
5
5 7 9 21 23

8
1 5 8 9 10 17 17 20

    0 | 1 | 2 | 3 | 4 | 5
r   0 | 5 |10 | 15| 21|26
sol x | 1 | 1 | 1 | 4 | 1
*/
#include<bits/stdc++.h>
using namespace std;
int rodCutting(int p[], int n){
    int r[n+1];
    r[0] = 0;
    // int solution[n+1];
    if(n==0)return 0;
    else{
        for(int m=1;m<=n;m++){
            int q = INT_MIN;
            for(int x=0;x<m;x++){
                // q = max(q,p[x]+r[m-x-1]);
                if(q<p[x]+r[m-x-1]){
                    q = p[x]+r[m-x-1];
                    // solution[m] = x+1;
                }
            }
            r[m] = q;
        }
    }
    // int currLength=n;
    // while(currLength!=0){
    //     cout << solution[currLength] << " ";
    //     currLength-=solution[currLength];
    // }
    // while(currLength!=0){
    //     int piece = solution[currLength];
    //     cout << piece << " pieces together " << p[piece-1] << " taka" << endl;
    //     currLength-=piece;
    // }
    return r[n];
}

int main(){
    int length;
    cin >> length;
    int price[length];
    for(int i=0;i<length;i++){
        cin >> price[i];
    }
    cout << rodCutting(price,length) << endl;
}