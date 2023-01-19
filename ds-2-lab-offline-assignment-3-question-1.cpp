/*
similar to 01 knapsack
A = {2,4,5,6,8} N = 15 -> True {4,5,6}

think the elements of A as items, N as knapsack Capacity

ss(i,n) = A[i] used -> ss(i-1,n-A[i])
          A[i] not used -> ss(i-1,n)
    base case -> ss(i,0) = True
                 ss(0,1...n) = False

*/

#include<bits/stdc++.h>
using namespace std;


bool subsetSumRecursion(int A[],int n,int X)
{
    if(n==0)return false;
    if(X==0)return true;
    if(X<A[n-1])return subsetSumRecursion(A,n-1,X);
    else{
        return subsetSumRecursion(A,n-1,X) || subsetSumRecursion(A,n-1,X-A[n-1]);
    } 
}


void subsetSumDP(int A[],int n,int X)
{
    bool p[n+1][X+1];
    for(int i=0; i<=n; i++)p[i][0]=true;
    for(int j=1; j<=X; j++)p[0][j]=false;
        
    for(int i=1; i<=n; i++){
        for(int j=1; j<=X; j++){
            if(j<A[i-1]) p[i][j] = p[i-1][j];
            else p[i][j] = (p[i-1][j-A[i-1]]) || (p[i-1][j]);
        }
    }
    if(p[n][X]==true){
        int sums[n+1];
        int k=0;
        int i=n,j=X;
        while(p[i][j]!=false){
            if(i==0 && j==0)break;
            else{
                if(p[i][j]!=p[i-1][j]){
                    sums[k]=A[i-1]; k++;
                    j=j-A[i-1];
                    i--;
                }
                else i--;
            }
        }

        cout<<X<<" is a subset sum"<<endl;
        for(int i=0;i<k;i++){
            cout<<sums[i]<<" ";
            if(i!=k-1)cout<<"+ ";
        }
        cout<<"= " << X << endl;
    }
    else
        cout<<X<<" is not a subset sum"<<endl;

}

int main()
{
    int n;cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int X;cin>>X;

    cout<<"======Solved B======"<<endl;
    if(subsetSumRecursion(A,n,X))
        cout<<X<<" is a subset sum(NaiveRecursion) "<<endl;
    else
        cout<<X<<" is not a subset sum (NaiveRecursion)"<<endl;

    cout<<endl<<"======Solved C======"<<endl;
    subsetSumDP(A,n,X);

    
    return 0;
}
/*
5
2 4 6 5 8
15
*/