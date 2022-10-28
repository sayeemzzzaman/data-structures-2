#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        cout << "Case " << i+1 << ": ";
        for(int j=1;j<=n;j++){
            if(n%j==0)cout << j << " ";
        }
        cout << endl;
    }
}