#include<bits/stdc++.h>
using namespace std;

int cakeCuttingRecursion(int prices[], int length){
    if(length==0) return 0;
    int q = INT16_MIN;
    for(int i=0;i<length;i++){
        q = max(q,prices[i]+cakeCuttingRecursion(prices,length-i-1));
    }
    return q;
}
int cakeCuttingDP(int length,int prices[]){
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
    
    cout<<"===Solved B==="<<endl;
    cout<<"income(recursive): " << cakeCuttingRecursion(prices,length)<< " taka"<<endl;
    cout<<endl<<"===Solved C==="<<endl;
    cakeCuttingDP(length,prices);
}
/*
5
2 6 9 10 12
*/