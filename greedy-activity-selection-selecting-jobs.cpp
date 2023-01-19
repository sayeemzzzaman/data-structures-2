#include<bits/stdc++.h>
using namespace std;

struct jobs{
    int id,start,duration,end,difficulty;
};

bool byEarliestEnd(jobs l1, jobs l2){
    return l1.end<l2.end;
}
void jobSelection(int eachJobPays, int rangeStart, int rangeEnd, vector<jobs> v){
    sort(v.begin(),v.end(),byEarliestEnd);
    // for(jobs i : v){
    //     cout << i.start << " " << i.end << endl;
    // }
    int chosen;
    vector<jobs> selected;
    for(int i=0;i<v.size();i++){
        if(v[i].start>=rangeStart){
            selected.push_back(v[i]);
            chosen = i;
            break;
        }
    }
    // for(jobs p : selected){
    //     cout << "job starts at " << p.start <<", ends at " << p.end << ", difficulty " << p.difficulty << endl;
    // }
    // cout << "-------------------" << endl;
    for(int i=1;i<v.size();i++){
        if(v[chosen].end<=v[i].start && v[i].end<= rangeEnd){
            selected.push_back(v[i]);
            chosen = i;
        }
    }
    cout << "Recommended jobs:" << endl;
    for(jobs p : selected){
        cout << "job" << p.id << " starts at " << p.start <<", ends at " << p.end << ", difficulty " << p.difficulty << endl;
    }
    cout << "expected earning " << eachJobPays*selected.size() << " dollars" << endl;
}

int main(){
    int n; cin >> n;
    vector<jobs> v;
    for(int i=0;i<n;i++){
        jobs jj;
        cin >> jj.start >> jj.duration >> jj.difficulty;
        jj.end = jj.start+jj.duration;
        jj.id = i+1;
        v.push_back(jj);
    }
    int eachJobPays,rangeStart,rangeEnd;
    cin >> eachJobPays >> rangeStart >> rangeEnd;

    jobSelection(eachJobPays,rangeStart,rangeEnd,v);
}
/*
6
5 4 4
13 1 1
4 8 4
11 2 3
10 2 5
16 1 2
20
10 14
*/