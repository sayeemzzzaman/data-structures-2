//#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Person{
    string name;
    int height;
    int age;
};

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int n;
    cin >> n;
    struct Person person[n];
    struct Person sortedPerson[n];
    getchar();
    for(int i=0;i<n;i++){
        fflush(stdin);
        string name;
        int height;
        int age;
        getline(cin,name);
        cin >> height >> age;
        person[i].name=name;
        person[i].height=height;
        person[i].age=age;
    }
    int p=0;
    for(int i=0;i<n;i++){
        int max=INT16_MIN;
        int index=0;
        for(int j=0;j<n;j++){
            if(max<person[j].height){
                max=person[j].height;
                index=j;
            }    
        }
        for(int j=0;j<n;j++){
            if(index!=j && person[j].height==person[index].height){
                if(max<person[j].age){
                    max=person[j].age;
                    index=j;
                }
            }    
        }
        sortedPerson[p]=person[index];
        p++;
        person[index].height=INT16_MIN;
    }

    for(int i=0;i<n;i++){
        cout << sortedPerson[i].name << " " << sortedPerson[i].height << " " << sortedPerson[i].age << endl;
    }
}
/*
5
Mr. Kamal 
165 32
Ms. Zara
163 28
Nitu Roy 
165 28
Rakib Hasan 
178 25
Samira Haque 
165 28
*/

/*
5
Mr. Kamal
162 32
Ms. Zara
163 28
Nitu Roy
165 28
Rakib Hasan
178 25
Samira Haque
166 28
*/