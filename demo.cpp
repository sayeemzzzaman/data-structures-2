/*
Functions of Disjoint Set~
(1)Makeset(x)
    {x}
(2)Find(x) -> representative of the set where x belongs //returns the representative of a set
(3)Union(x,y) -> merges two whole sets

implementation -> rooted tree

a,b,c,d,e,f,g
{a,b,c} {d} {e,f} {g} //there are no commons...total are called disjoint set

n=6 sets will be 0,1,2,3,4,5,6
parent 0 1 2 3 4 5
     |0|1|2|3|4|5|
*/


#include<bits/stdc++.h>
using namespace std;


/// Final task: implement path compression and union by rank
void makeSet(int p[], int x){
    p[x] = x;
    cout << "making a one-element set of "<<x<< endl;
}

int findSet(int p[], int x){
    if(x!=p[x]) return findSet(p, p[x]);
    return p[x];
}

void Union(int p[], int x, int y){
    int a = findSet(p,x);
    int b = findSet(p,y);
    cout<<a<<" "<<b<<endl;
    p[a] = b;
}

void connectedComponents(int p[], int g, int v[], pair<int,int> edge){
    for(int i=0;i<g;i++) makeSet(v,v[i]);
    for(int i=0;i<g;i++){
        if(findSet(p,edge.first)!=findSet(p,edge.second)){
            Union(p,edge.first,edge.second);
        }
    }
}

int main(){

    int nl

}