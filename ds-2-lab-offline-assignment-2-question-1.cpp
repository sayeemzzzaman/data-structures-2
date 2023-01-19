#include<bits/stdc++.h>
using namespace std;

struct item{
    double weight,value,vW;
    string itemName;
};

bool byValuePerWeight(item i1, item i2){
    return (double)i1.value/i1.weight > (double)i2.value/i2.weight;
}
int fracKnapsack(int thiefCapacity[], int thiefNumber, vector<item> itm){
    sort(itm.begin(),itm.end(), byValuePerWeight);
    int thiefCount=0;

    for(int j=0;j<thiefNumber;j++){
        double currCapacity = thiefCapacity[j];
        double profit=0;
        int i=0;
        while(currCapacity>0 && i<itm.size()){
            if((currCapacity>=itm[i].weight) && ((itm[i].value!=0) || (itm[i].weight!=0))){
                profit = profit + itm[i].vW*itm[i].weight;
                currCapacity = currCapacity - itm[i].weight;
                itm[i].value = itm[i].vW*itm[i].weight;
                //if(itm[i].value!=0 || itm[i].weight!=0)
                cout << fixed << setprecision(1) << "Taking " << itm[i].itemName << ":  " << itm[i].weight << " kg " << itm[i].value << " taka" << endl;
                itm[i].value=0;
                itm[i].weight=0;
            }
            else if((itm[i].value!=0) || (itm[i].weight!=0)){
                profit = itm[i].vW*currCapacity + profit;
                // cout << currCapacity << endl;
                double takenValue = currCapacity*itm[i].vW;
                itm[i].weight -= currCapacity;
                double takenWeight = currCapacity;
                cout << fixed << setprecision(1) << "Taking " << itm[i].itemName << ": " << takenWeight << " kg " << takenValue << " taka" << endl;
                currCapacity=0;
            }
            i++;
        }
        if(profit!=0){
            thiefCount++;
            cout << "Thief " << j+1 << " profit: " << profit << " taka" << endl << endl;
        }       
    }
    cout << "Total " << thiefCount << " thieves stole from the warehouse." << endl;
    int flag=1;
    for(int i=0;i<itm.size();i++){
        if(itm[i].weight!=0){
            if(flag){
                cout<<"Still following items are left" << endl;
                flag=0;
            }
            cout << "\t" << itm[i].itemName << "\t" << itm[i].weight << " kg " << itm[i].weight*itm[i].vW << " taka" << endl;
        }
    }
    
}
int main(){
    int n;cin>>n;
    vector<item> itm;

    for(int i=0;i<n;i++){
        item it;
        string line;
        cin >> line;
        it.itemName = line;
        cin >> it.value >> it.weight;
        it.vW = it.value/it.weight;
        itm.push_back(it);
    }
    int thiefNumber;
    cin >> thiefNumber;
    int thiefCapacity[thiefNumber];
    for(int i=0;i<thiefNumber;i++){
        cin >> thiefCapacity[i];
    }
    fracKnapsack(thiefCapacity,thiefNumber,itm);
}

/*
4
silver-dust 300 4
gold-dust 2000 8
salt 80 10
sugar 89 10
2
15 15
----
4
silver-dust 300 4
gold-dust 2000 8
salt 80 10
sugar 89 10
4
8 10 6 10
*/