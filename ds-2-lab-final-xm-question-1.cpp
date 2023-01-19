#include<bits/stdc++.h>
using namespace std;

int dpCoinChange(int M,int boxes[],int d){
    int bnc[M+1];
    bnc[0] = 0;
    int takenBoxes[M+1];
    if(M==0)return 0;
    else{
        for(int m=1;m<=M;m++){
            bnc[m] = INT16_MAX;
            for(int i=0;i<d;i++){
                if(boxes[i]<=m){
                    int min = bnc[m-boxes[i]] + 1;
                    if(min<bnc[m]){
                        bnc[m] = min;
                        takenBoxes[m] = boxes[i];
                    }
                }
            }
        }
    }
    if(bnc[M]>d || bnc[M]<0)cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        // cout<<bnc[M]<<endl;
        int total = M;
        while(total!=0){
            cout<<takenBoxes[total]<<" ";
            total = total-takenBoxes[total];
        }
    }
    // cout<<bnc[M]<<endl;               
}
int main(){
    int M,n;cin>>M>>n;
    int boxes[n];
    for(int i=0;i<n;i++)cin>>boxes[i];
    dpCoinChange(M,boxes,n);
}







