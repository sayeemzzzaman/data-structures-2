#include<bits/stdc++.h>
using namespace std;

struct edges{
    int u,v;
};
void make_set(int p[], int x){
    p[x] = x;
    // cout << "making a one-element set of "<<x<< endl;
}

int find_set(int p[], int x){
    if (x!=p[x])
        return find_set(p, p[x]);
    return p[x];
}

void _union(int p[], int x, int y){
    int a = find_set(p, x);
    int b = find_set(p, y);
    p[a] = b;
    // cout << "union "<<a << " and "<<b<< endl;
}

void connectedComponents(int p[], int v, vector<edges> edges){
    for(int i=0;i<v;i++)make_set(p,i);

    for(int i=0;i<edges.size();i++){
        if(find_set(p,edges[i].u)!=find_set(p,edges[i].v)){
            _union(p,edges[i].u,edges[i].v);
        }
    }
}

bool sameComponent(int p[],int u, int v){
    if(find_set(p,p[u])==find_set(p,p[v])) return true;
    else return false;
}

int main(){
    int v,e; cin>>v>>e;
    int p[v];

    vector <edges> vv;
    for(int i=0;i<e;i++){
        edges ee;
        cin >> ee.u >> ee.v;
        vv.push_back(ee);
    }

    connectedComponents(p,v,vv);

    int verticePair;cin>>verticePair;
    for(int i=0;i<verticePair;i++){
        int a,b;cin>>a>>b;
        if(sameComponent(p,a,b)){
            cout<<a<<" and "<<b<<" are in the same component"<<endl;
        }
        else cout<<a<<" and "<<b<<" are not in the same component"<<endl;
    }
    
}
