#include<iostream>
using namespace std;
/*
[1,2,1,2,5,6,1,2,2,3]
    [3] [1,2,1,2,5,6,1,2,2]
        [2] [1,2,1,2,5,6,1,2]
            [2] [1,2,1,2,5,6,1]
                [1] [1,2,1,2,5,6]
                    [6] [1,2,1,2,5]
                        [5] [1,2,1,2]
                            [2] [1,2,1]
                                [1] [1,2] 
                                    [2] [1] 
                                        [1] len==1

*/



int freqFunction(int array[],int len, int num){
    if(len==1){
        if(array[0]==num)return 1;
        else return 0;
    }
    else{
        int mypart = array[len-1];
        int restpart = freqFunction(array,len-1,num);
        if(mypart == num)return restpart+1;
        else return restpart;
    }
}
int main(){
    int array[] = {1,2,1,2,5,6,1,2,2,3};
    int len = 10;
    cout << freqFunction(array,len,2) << endl;
}