/*
            p[i-1,w] ;w < wi
P[i,w] =    
            max{Vi + P[i-1,w-wi],
                P[i-1,w]}

item    weight  Value
1       2       12
2       1       10
3       3       20
4       2       15
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


int dpKnapsack(int capacity, int n, int value[], int weight[]){

    int P[n+1][capacity+1];
    // for(int v=0; v<=capacity;v++) P[0][v] = 0;
    // for(int v=0; v<=n;v++) P[v][0] = 0;

    for(int i=0;i<=n;i++){
        for(int w=0;w<=capacity;w++){

            if(i==0 || w==0) P[i][w] = 0;
            else if(weight[i] <= w){
                if(value[i]+P[i-1][w-weight[i]] > P[i-1][w]){
                    P[i][w] = value[i] + P[i-1][w-weight[i]];
                }
                else{
                    P[i][w] = P[i-1][w];
                }
            }
            else{
                P[i][w] = P[i-1][w];
            }
        }

    }
    cout << "Profit: " << P[n][capacity] << endl;

    int result=P[n][capacity];
    int w=capacity;
    cout<<"By taking: "<<endl;
    for(int i=n; i>0 && result>0; i--){
        if(result == P[i-1][w]) continue;
        else{
            cout<<value[i] << " " << weight[i]<<endl;
            result -= value[i];
            w = w-weight[i];
        }
    }
}
int main(){
    int n;cin>>n;
    int value[n],weight[n];

    for(int i=0;i<n;i++){
        cin >> value[i] >> weight[i];
    }
    int capacity;
    cin >> capacity;

    dpKnapsack(capacity,n,value,weight);
}
/*
4
16 4
9 3
18 3
16 2
5

*/
