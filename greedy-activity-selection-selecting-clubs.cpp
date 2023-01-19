#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
optimal = earliest finish time
*/

struct club{
    char id;
    int start,duration,end;
};

bool byEarliestEndTime(club i1, club i2){
    return i1.end < i2.end;
}

void activitySelect(int cleaningTime, vector<club> v){
    sort(v.begin(),v.end(), byEarliestEndTime);
    for(club v : v){
        cout << v.id << " " << v.start << " " << v.duration << " " << v.end << endl;
    }
    int chosen = 0;
    vector <club> selected;
    selected.push_back(v[0]);

    for(int i=1;i<v.size();i++){
        if(v[i].start >= (v[chosen].end+cleaningTime)){
            chosen = i;
            selected.push_back(v[i]);
        }
    }
    cout << "Chosen clubs: " << endl;
    for(club v : selected){
        cout << v.id << endl;
    }
}
int main(){
    int n;cin>>n;
    vector<club> v;
    for(int i=0;i<n;i++){
        club c;
        cin >> c.id >> c.start >> c.duration;
        c.end = c.duration+c.start;
        v.push_back(c);
    }
    int cleaningTime;
    cin >> cleaningTime;

    activitySelect(cleaningTime,v);
}
/*
4
a 2 8
b 3 4
d 8 1
c 7 1
0
*/
/*
activitySelect(acts,n)
    sort acts by earliest finish time
    chosen = 1
    selected = {acts[1]}
    for i=2 to n:
        if acts[i].start >= acts[chosen].finish
            chosen = i;
            selected.add(acts[i])
*/