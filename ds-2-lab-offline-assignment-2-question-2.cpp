#include<iostream>
using namespace std;

int main(){
    int distance,fullFuelGoes,numberOfGs,destinationRemains;
    cin >> distance >> fullFuelGoes >> numberOfGs;
    int gasStations[numberOfGs];
    for(int i=0;i<numberOfGs;i++){
        cin >> gasStations[i];
    }
    destinationRemains = distance;
    for(int i=0;i<numberOfGs;i++){
        if(gasStations[i]>fullFuelGoes){
            fullFuelGoes += gasStations[i-1];
            cout << "stop at gas station " << i << " ( " << gasStations[i-1] << " miles)" << endl;
            destinationRemains -= fullFuelGoes; 
        }
    }
    if(destinationRemains>0)cout << "couldn't reach the destination" << endl;
}

/*
20
10
8
2 4 5 8 12 14 16 19
-------
25
10
5
2 4 5 8 12
*/