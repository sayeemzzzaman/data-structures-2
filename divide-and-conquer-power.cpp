#include<iostream>
using namespace std;

int power(int x, int y){
    if(y==0)return 1;
    else{
        // int val;
        if(y%2==0){ //(9,2) = 9*9
            int val = power(x,y/2);
            return val*val;
        }
        else{ //(9,3) = 9*9*9
            int val = power(x,y/2);
            return val*val*x;
        }
        return 0;
    }
}

int main(){
    cout << power(9,7) << endl;
}