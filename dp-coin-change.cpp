/*    c1 c2 c3...cd
coins 1 3 5
     M
mnc(10):         M-c1
        1 + mnc(10-1) ;c1<=M
                 M-c2
 min    1 + mnc(10-3) ;c2<=M
        1 + mnc(10-5) ;c3<=M
        .........
        1+ mnc(M-cd) ;cd<=M

26
3
1 4 9
----
46 3 1 23 30
                0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20||
mnc             0|1|2|3|1|2|3|4|2|1|2|||||||||||||||||||||||||||
chosen coin     x|1|1|1|4|1|1|1|4|9|1||||||||||||||||||||||||||||


*/

#include<bits/stdc++.h>
using namespace std;

int dpCoinChange(int M, int coins[], int numberOfCoinType){
        int mnc[M+1];
        mnc[0] = 0;
        int cc[M+1];
        if(M==0)return 0;
        else{
                for(int m=1;m<=M;m++){
                        mnc[m] = INT16_MAX;
                        for(int i=0;i<numberOfCoinType;i++){
                                if(coins[i]<=m){
                                        int min = 1+mnc[m-coins[i]];
                                        if(min<mnc[m]){
                                                // cout << min << " ";
                                                mnc[m] = min;
                                                cc[m] = coins[i];
                                        }
                                }
                        }
                }
        }

        cout << endl << "DP: " << mnc[M];
        cout<<endl;
        int count = M;

        cout << "Using coins: ";
        while(count!=0){

                cout << cc[count] << " ";
                count-=cc[count];

        }
}
int coinChangeNormalRecursive(int M, int coins[], int numberOfCoinType){
        int min = INT32_MAX;
        if(M==0)return 0;
        else{
                for(int i=0;i<numberOfCoinType;i++){
                        if(coins[i]<=M){
                                int numberOfCoins = coinChangeNormalRecursive(M-coins[i],coins,numberOfCoinType);
                                if(min>numberOfCoins+1){
                                        min = numberOfCoins+1;
                                }
                        }
                }
        }
        return min;
}
int main(){
        int M,numberOfCoinType;
        cin >> M >> numberOfCoinType;
        int coins[numberOfCoinType];
        for(int i=0;i<numberOfCoinType;i++){
                cin >> coins[i];
        }
        cout << coinChangeNormalRecursive(M,coins,numberOfCoinType);
        dpCoinChange(M,coins,numberOfCoinType);
}

/*
26
3
1 4 9
output = 4
*/