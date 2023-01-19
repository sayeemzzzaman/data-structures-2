#include<bits/stdc++.h>
using namespace std;


void make_set(int p[], int x){
    p[x] = x;
    cout << "making a one-element set of "<<x<< endl;
}

int find_set(int p[], int x){
    if (x!=p[x])
        return find_set(p, p[x]);
    return p[x];
}

void Union(int p[], int x, int y){
    int a = find_set(p, x);
    int b = find_set(p, y);
    p[a] = b;
    cout << "union "<<a << " and "<<b<< endl;
}

struct Edge{
    int u, v;
};


void connected_components(int p[], int V, vector<Edge> edges){
    for(int i=0;i<V;i++){
        make_set(p,i);
    }
    for(int i=0;i<edges.size();i++){
        if(find_set(p,edges[i].u)!=find_set(p,edges[i].v)){
            Union(p,edges[i].u,edges[i].v);
        }
    }
}

bool same_component(int p[], int u, int v){
    if(find_set(p,u)==find_set(p,v)) return true;
    else return false;
}

int main(){
    /// This code is for an undirected graph

    int V, E;
    /// take the number of vertices V and
    /// the number of edges E as input from user
    cin>>V>>E;

    /// take the E edges as input from the user
    vector<Edge> edges;
    for (int i=0;i<E;i++){
        Edge e;
        cin>>e.u>>e.v;
        edges.push_back(e);
    }

    /// create the parent array for a disjoint set of V elements
    int p[V];

    /// call the function connected_components
    connected_components(p, V, edges);

    // int n;cin>>n;
    // for(int i=0;i<n;i++){
    //     int a,b;cin>>a>>b;
    //     if(same_component(p,a,b))cout<<a<<" and "<<b<<" are in the same component"<<endl;
    //     else cout<<a<<" and "<<b<<" are not in the same component"<<endl;
    // }

    while(1){
        /// take an integer "option" as input.
        int option;
        cin>>option;

        /// if "option" is 1, take another integer x as input,
        /// check if x is an element of the disjoint set or not, and
        /// if it is then print the root/representative-element of x
        if (option==1){
            int x;cin>>x;
            int flag=0;
            for(int i=0;i<V;i++){
                if(p[i]==x){
                    flag=1;break;
                }
            }
            if(flag)cout<<find_set(p,x)<<" is the representative element of " << x << endl;
            else cout<<x<<" is not an element of the disjoint set."<<endl;
        }

        /// if "option" is 2, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are, print whether they belong to the
        /// same connected component or not
        else if (option==2){
            int x,y; cin>>x>>y;
            // int flagX=0,flagY=0;
            // for(int i=0;i<V;i++){
            //     if(p[i]==x){
            //         flagX=1;
            //     }
            //     if(p[i]==y){
            //         flagY=1;
            //     }
            // }
            // if(flagX==1 && flagY==1){
            //     cout<<x<<" and "<<y<<" are elements of the disjoint set.";
            //     if(find_set(p,x)==find_set(p,y))cout<<" They belong to the same set."<<endl;
            //     else cout<<"But they don't belong to the same set."<<endl;
            // }
            // else cout<<"They are not the elements of the disjoint set."<<endl;

            if(same_component(p,x,y))cout<<x<<" and "<<y<<" are in the same component"<<endl;
            else cout<<x<<" and "<<y<<" are not in the same component"<<endl;

        }

        /// if "option" is 3, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are, print if there is a path from x to y or not.
        else if (option==3){
            int x,y; cin>>x>>y;
            // int flagX=0,flagY=0;
            // for(int i=0;i<V;i++){
            //     if(p[i]==x){
            //         flagX=1;
            //     }
            //     if(p[i]==y){
            //         flagY=1;
            //     }
            // }
            //path exist or not?
            if(find_set(p,x)!=find_set(p,y))cout<<"there is no path between "<<x<<" and "<<y<<endl;
            else cout<<"there exists a path between "<<x<<" and "<<y<<endl;
        }

        /// if "option" is 4, print all the roots of this disjoint set
        else if (option==4){
            cout<<"Printing all the roots: "<<endl;
            for(int i=0;i<V;i++){
                if(p[i]==i){
                    cout<<i<<" ";
                }
            }
            cout<<endl;
        }

        /// if "option" is 5, print the vertices of each connected components
        /// in each line
        else if (option==5){
            // int copyP[V];
            // for(int i=0;i<V;i++)copyP[i]=p[i];

            // for(int i=0;i<V;i++){
            //     if(copyP[i]==i){
                    
            //     }
            // }
            vector<int> v[V];
            for(int i=0;i<V;i++){
                int c = find_set(p,i);
                v[c].push_back(i);
            }
            for(int i=0;i<V;i++){
                if(v[i].size()>0){
                    for(auto m: v[i])cout<<m<<" ";
                    cout<<endl;
                }
            }
            /// 0 1 5
            /// 2 3
            /// 4
        }

        else {
            return 0;
        }
    }

}
/*
8
5
0 1
1 2
0 3
1 3
4 5

5 <-option
1
8
1
7
2
0 4
3
0 4
4
6 
*/