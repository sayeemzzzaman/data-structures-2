/*
465
465/200 = 2
465%200 = 65

65/50 = 1
65%50 = 15

15/10 = 1
15%10 = 5

5/5
5%5 = 0
take the notes in an array~descending?
*/
#include<bits/stdc++.h>
using namespace std;

struct coin{
    int cn,taken=0;
};
bool byBigNotes(coin l1, coin l2){
    return l1.cn>l2.cn;
}
void coinChange(int total, int n, vector<coin> v){
    sort(v.begin(),v.end(),byBigNotes);
    // for(int i=0;i<n;i++){
    //     cout << v[i].cn << " ";
    // }
    int i=0;
    while(total!=0){
        if(v[i].cn<=total){
            v[i].taken = total/v[i].cn;
            total = total%v[i].cn;
        }
        i++;
    }
    for(int i=0;i<n;i++){
        if(v[i].taken!=0)
        cout << v[i].cn << " cents --- " << v[i].taken << endl;
    }
}
int main(){
    int N;
    int numberOfCoins;
    cin >> N >> numberOfCoins;
    vector<coin> v;
    for(int i=0;i<numberOfCoins;i++){
        coin cc;
        cin >> cc.cn;
        v.push_back(cc);
    }
    coinChange(N,numberOfCoins,v);
}
/*
173
4
10 1 25 5
*/