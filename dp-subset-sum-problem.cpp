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

//Naive recursion
bool sumofsubsetNaiveREC(int A[],int n,int sum)
{
    if(n==0)return false;
    if(sum==0)return true;
    if(A[n-1]>sum)
        return sumofsubsetNaiveREC(A,n-1,sum);
    else
        return sumofsubsetNaiveREC(A,n-1,sum) || sumofsubsetNaiveREC(A,n-1,sum-A[n-1]);
}

//DP
void sumofsubset(int A[],int n,int sum)
{
    bool p[n+1][sum+1];
    for(int i=0; i<=n; i++)
        p[i][0]=true;
    for(int j=1; j<=sum; j++)
        p[0][j]=false;
        
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j<A[i-1]) p[i][j]=p[i-1][j];
            else p[i][j] = p[i-1][j] || p[i-1][j-A[i-1]];
        }
    }
    if(p[n][sum])
    {
        cout<<sum<<" is the subset "<<endl;
        vector<int>v;
        int i=n,j=sum;
        while(p[i][j]!=false)
        {
            if(i==0 && j==0)break;
            else
            {
                if(p[i][j]!=p[i-1][j])
                {
                    v.push_back(A[i-1]);
                    j=j-A[i-1];
                    i--;
                }
                else
                    i--;
            }
        }
        int n=v.size();
        for(i=0; i<v.size(); i++)
        {
            if(i==n-1)cout<<v[i];
            else cout<<v[i]<<"+";
        }
        cout<<"="<<sum<<endl;
    }
    else
        cout<<sum<<" is not the subset"<<endl;

}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    int N;
    cin>>N;//Target

    //function call for DP
    sumofsubset(A,n,N);

    //function call for naive recursion
    if(sumofsubsetNaiveREC(A,n,N))
        cout<<N<<" is the subset(NaiveRecursion) "<<endl;
    else
        cout<<N<<" is not the subset(NaiveRecursion)"<<endl;
    return 0;
}
/*
5
2 4 6 5 8
15
*/