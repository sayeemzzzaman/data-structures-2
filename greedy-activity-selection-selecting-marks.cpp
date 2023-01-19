#include<bits/stdc++.h>
using namespace std;

struct questions{
    int id,marks,time,percentage;
};

bool byMarkDivideTime(questions l1, questions l2){
    return (l1.marks/l1.time)>(l2.marks/l2.time);
}
void selectedQuestions(int totalMark, int totalTime, vector<questions> v){
    sort(v.begin(),v.end(),byMarkDivideTime);
    // for(questions pp : v) cout << pp.marks << " " << pp.time << endl;
    int currTime = 0;
    vector<questions> selected;
    // selected.push_back(v[0]);
    
    for(int i=0;i<v.size();i++){
        if((currTime+v[i].time)<=totalTime){
            v[i].percentage = 100;
            selected.push_back(v[i]);
            currTime+=v[i].time;
            // cout << " curr " << currTime;
        }
        else if(currTime<totalTime){
            int remains = totalTime-currTime;
            questions pp;
            pp.marks = remains*(v[i].marks/v[i].time);
            pp.percentage = remains*10;
            pp.id = v[i].id;
            selected.push_back(pp);
            currTime=totalTime;
        }
    }
    for(questions pp : selected) cout <<"ques " << pp.id << " " <<pp.percentage <<"% done---" << pp.marks << endl;
}
int main(){
    int totalMark,totalTime,queToAns;
    cin >> totalMark >> totalTime >> queToAns;
    vector<questions> v;

    for(int i=0;i<queToAns;i++){
        questions qq;
        cin >> qq.marks >> qq.time;
        qq.id = i+1;
        v.push_back(qq);
    }
    selectedQuestions(totalMark,totalTime,v);
}

/*
120 20 5
20 10
20 5
30 5
30 6
20 40


*/