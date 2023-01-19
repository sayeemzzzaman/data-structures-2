#include<bits/stdc++.h>
using namespace std;

int cakeCutting(int length,int prices[]){
    int r[length+1];
    r[0]=0;
    int solution[length+1];
    for(int j=1;j<=length;j++){
        int q = INT32_MIN;
        for(int i=0;i<j;i++){
            if(q<prices[i]+r[j-i-1]){
                q = prices[i]+r[j-i-1];
                solution[j] = i+1;
            }
        }
        r[j]=q;
    }
    cout<<"income: " << r[length]<< " taka" << endl;
    
    int currLength=length;
    // while(currLength!=0){
    //     cout << solution[currLength] << " ";
    //     currLength-=solution[currLength];
    // }
    while(currLength!=0){
        int piece = solution[currLength];
        cout << piece << " pieces together " << prices[piece-1] << " taka" << endl;
        currLength-=piece;
    }
    return r[length];
}
int main(){
    int length;cin>>length;
    int prices[length];
    for(int i=0;i<length;cin>>prices[i],i++);
    
    cakeCutting(length,prices);
}
/*
5
2 6 9 10 12
*/