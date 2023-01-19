/*
need undirected weighted connected graph
*/
#include<bits/stdc++.h>
using namespace std;

struct edges{
    int u,v,w;
};
struct T{
    int u,v,w;
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

bool byWeight(edges e1, edges e2){
    return e1.w < e2.w;
}
vector<edges> kruskal(int v, vector<edges> e, int p[]){

    for(int i=0;i<v;i++)make_set(p,i);
    sort(e.begin(),e.end(), byWeight);

    vector<edges> selected;
    for(int i=0;i<e.size();i++){
        if(find_set(p,e[i].u) != find_set(p,e[i].v)){
            selected.push_back(e[i]);
            _union(p,e[i].u,e[i].v);
        }
    }
    return selected;
}

int main(){
    int v,e; cin>>v>>e;
    int p[v];

    vector <edges> vv;
    for(int i=0;i<e;i++){
        edges ee;
        cin >> ee.u >> ee.v >> ee.w;
        vv.push_back(ee);
    }

    vector<edges> selected = kruskal(v,vv,p);
    int weightSum=0;
    cout<<"MST"<<endl;
    for(auto i: selected){
        cout<<i.u<<"-"<<i.v<<endl;
        weightSum+=i.w;
    }
    cout<<"Weight: ";
    for(int i=0;i<selected.size();i++){
        cout<<selected[i].w;
        if(i!=selected.size()-1){
            cout<<"+";
        }
    }
    cout << " = " << weightSum<<endl;
    
}
/*
Sample Input
V
E
u v weight(u,v)
…
6
9
0 1 4
1 2 5
0 3 10
1 3 3
1 5 6
1 4 7
2 4 1
3 5 9
4 5 8

Output
MST
2 – 4
1 – 3
0 – 1
1 – 2
1 – 5
Weight: 1+3+4+5+6 = 19
*/
