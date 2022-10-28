#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        int check=arr[i];
        int count=0;
        for(int k=i+1;k<n;k++){
            if(arr[i]==arr[k])count++;
        }
        if(count==0){
            for(int k=0;k<n;k++){
                if(arr[i]==arr[k])count++;
            }
            cout << arr[i] << " Occurs " << count << " times" << endl;
        }
    }
}
//7
//4 256 2 4 3 3 5