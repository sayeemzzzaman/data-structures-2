#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;

    double sum=0;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        sum=sum+temp;
    }
    cout << fixed << setprecision(2) << sum/n << endl;
}

/*

7
4 256 2 4 3 3 5

*/