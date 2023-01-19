#include<bits/stdc++.h>
using namespace std;

struct job{
    int id,start,duration,end,difficulty;
};

bool byEarliestEnd(job l1, job l2){
    return l1.end<l2.end;
}
void selectionJobs(int eachJobPays, int startRange, int endRange, vector<job> v){
    sort(v.begin(),v.end(),byEarliestEnd);
    for(job j : v){
        cout << j.start << " " << j.end << endl;
    }
    int chosen;
    vector<job> selected;
    for(int i=0;i<v.size();i++){
        if(v[i].start>=startRange){
            chosen = i;
            selected.push_back(v[i]);
            break;
        }
    }

    for(int i=1;i<v.size();i++){
        if((v[i].start >= v[chosen].end) && (v[i].end<=endRange)){
            chosen = i;
            selected.push_back(v[i]);
        }
    }
    cout << "Recommended jobs:" << endl;
    for(job j : selected){
        cout << "job" << j.id <<" starts at " << j.start << ", ends at " << j.end << ", difficulty " << j.difficulty << endl;
    }
    cout << "expected earning " << eachJobPays*selected.size() << " dollars" << endl;
}
int main(){
    int N; cin >> N;
    vector<job> v;

    for(int i=0;i<N;i++){
        job jj;
        cin >> jj.start >> jj.duration >> jj.difficulty;
        jj.end = jj.start+jj.duration;
        jj.id = i+1;
        v.push_back(jj);
    }
    int eachJobPays,startRange,endRange;
    cin >> eachJobPays >> startRange >> endRange;
    selectionJobs(eachJobPays,startRange,endRange,v);
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