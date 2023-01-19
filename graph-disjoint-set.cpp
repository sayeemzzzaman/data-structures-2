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

int main(){


    int n;cin>>n;

    /// create the parent array for a disjoint set of n elements
    int p[n];
    for (int i=0;i<n;i++){
        makeSet(p, i);
    }

    while(1){
        /// take an integer "option" as input.
        int option;
        cout << "Choose option: ";
        cin >> option;

        /// if "option" is 1, take another integer x as input,
        /// check if x is an element of the disjoint set or not, and
        /// if it is then print the root/representative-element of x
        if (option==1){
            int x;cin>>x;
            int flag=0;
            for(int i=0;i<n;i++){
                if(p[i]==x){
                    flag=1;break;
                }
            }
            if(flag)cout<<findSet(p,x)<<" is the representative element of " << x << endl;
            else cout<<"It's not an element of the disjoint set."<<endl;
        }

        /// if "option" is 2, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are check if they belong to the same set or not
        else if (option==2){
            int x,y; cin>>x>>y;
            int flagX=0,flagY=0;
            for(int i=0;i<n;i++){
                if(p[i]==x){
                    flagX=1;
                }
                if(p[i]==y){
                    flagY=1;
                }
            }
            if(flagX==1 && flagY==1){
                cout<<x<<" and "<<y<<" are elements of the disjoint set.";
                if(findSet(p,x)==findSet(p,y))cout<<" They belong to the same set."<<endl;
                else cout<<"But they don't belong to the same set."<<endl;
            }
            else cout<<"They are not the elements of the disjoint set."<<endl;
        }

        /// if "option" is 3, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are then union them
        else if (option==3){
            int x,y; cin>>x>>y;
            int flagX=0,flagY=0;
            for(int i=0;i<n;i++){
                if(p[i]==x){
                    flagX=1;
                }
                if(p[i]==y){
                    flagY=1;
                }
            }
            if(flagX==1 && flagY==1){
                cout<<"Uniting them..."<<endl;
                Union(p,x,y);
            }
            else cout<<"They are not the elements of the disjoint set."<<endl;

        }

        else {
            return 0;
        }
    }

}