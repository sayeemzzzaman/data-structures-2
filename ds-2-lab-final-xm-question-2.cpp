#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;cin>>N>>M;
    int array[N];
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    sort(array,array+N,greater<int>());
    // for(int i=0;i<N;i++){
    //     cout<<array[i]<<" ";
    // }
    int j=1;
    while(M!=0){
        array[0]+=array[j];
        M--;j++;
    }
    cout<<array[0]<<endl;
}