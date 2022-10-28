#include<iostream>
using namespace std;

struct Person {
    string name;
    int id;
    int salary;
};

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    struct Person data[n];
    struct Person sortedData[n];
    for(int i=0;i<n;i++){
        fflush(stdin);
        string name;
        getline(cin,name);
        data[i].name=name;
    }
    for(int i=0;i<n;i++){
        cin >> data[i].id;
    }
    for(int i=0;i<n;i++){
        cin >> data[i].salary;
    }
    // for(int i=0;i<n;i++){
    //     cout << data[i].name << " " << data[i].id << " " << data[i].salary << endl;
    // }

    int p=0;
    for(int i=0;i<n;i++){
        int min=INT16_MAX;
        int index=0;
        for(int j=0;j<n;j++){
            if(min>data[j].salary){
                min=data[j].salary;
                index=j;
            }    
        }
        for(int j=0;j<n;j++){
            if(index!=j && data[j].salary==data[index].salary){
                if(min>data[j].id){
                    min=data[j].id;
                    index=j;
                }
            }    
        }
        sortedData[p]=data[index];
        p++;
        data[index].salary=INT16_MAX;
    }

    for(int i=0;i<n;i++){
        cout << sortedData[i].name << " " << sortedData[i].salary << " " << sortedData[i].id << endl;
    }
}

/*
5
Mr. Kamal 
Ms. Zara 
Nitu Roy 
Rakib Hasan 
Samira Haque 
32 28 29 25 30
165 163 165 178 165

*/