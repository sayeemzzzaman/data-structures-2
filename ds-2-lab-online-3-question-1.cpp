#include <bits/stdc++.h>
using namespace std;

int box(int length[], int numberOfBoxes, int capacity){
    int bnx[capacity+1];
    int boxCount[capacity+1];

    bnx[0] = 0;
    if(capacity==0)return 0;
    else{
        for(int m=1;m<=capacity;m++){
            bnx[m] = INT16_MAX;
            for(int i=0;i<numberOfBoxes;i++){
                if(length[i]<=m){
                    if(1+bnx[m-length[i]] < bnx[m]){
                        bnx[m] = 1+bnx[m-length[i]];
                        boxCount[m] = length[i];
                    }
                }
            }
        }
        cout << "minimum "<< bnx[capacity] << " boxes." << endl;
    }

    int cargoLength = capacity;
    while(cargoLength!=0){
        cout << boxCount[cargoLength] << " meter" << endl;
        cargoLength -= boxCount[cargoLength];
    }

}

int main(){
    int numberOfBoxes; cin>>numberOfBoxes;
    int length[numberOfBoxes];

    for(int i=0;i<numberOfBoxes;i++){
        cin>>length[i];
    }

    int capacity; cin>>capacity;

    box(length,numberOfBoxes,capacity);

    return 0;
}
/*
5
1 23 25 12 10
46
*/