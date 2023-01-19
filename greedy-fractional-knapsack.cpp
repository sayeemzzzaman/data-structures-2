#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
/*
Capacity = 25kg
item - weight - value   v/w
1       10      60      6
2       20      100     5
3       30      120     4

//optimal
take 10kg of 1  60tk
take 15kg of 2  15*5=75tk
                total = 135tk

*/

struct item{
    double weight,value;
    int id;
};

bool byValuePerWeight(item i1, item i2){
    return (double)i1.value/i1.weight > (double)i2.value/i2.weight;
}
int fracKnapsack(int capacity, vector<item> itm){
    sort(itm.begin(),itm.end(), byValuePerWeight);

    // for(item v : itm){
    //     cout << v.value << " " << v.weight << " " << (double) v.value/v.weight << endl;
    // }

    int currCapacity = capacity;
    int profit=0;
    int i=0;
    while(currCapacity>0 && i<itm.size()){
        if(currCapacity>=itm[i].weight){
            profit = profit + itm[i].value;
            currCapacity = currCapacity - itm[i].weight;
            cout << fixed << setprecision(1) << "item " << itm[i].id << ": " << itm[i].weight << " kg " << itm[i].value << " taka" << endl;
        }
        else{
            // profit = (profit+itm[i].value) * (currCapacity/itm[i].weight);
            profit = (itm[i].value/itm[i].weight)*currCapacity + profit;
            currCapacity=0;
            cout << fixed << setprecision(1) << "item " << itm[i].id << ": " << itm[i].weight << " kg " << itm[i].value << " taka" << endl;
        }
        i++;
    }
    cout << "Profit: " << profit << endl;
}
int main(){
    int n;cin>>n;
    vector<item> itm;

    for(int i=0;i<n;i++){
        item it;
        cin >> it.weight >> it.value;
        it.id = i+1;
        itm.push_back(it);
    }
    int capacity;
    cin >> capacity;

    fracKnapsack(capacity,itm);
}
/*
4
4 16
3 9
3 18
2 16
5

*/

/*
//Pseudocode
fracKnapsack(w,items[],n)
sort items by v/w descending
currCapacity = w
i=1
while currCapacity>0 && i<=n
    if(items[i].w <= currCapacity)
        profit = items[i].v;
        currCapacity -= items[i].w
    else{
        profit += currCapacity*(items[i].v/items[i].w)
        currCapacity = 0;
    }
    i++;
*/