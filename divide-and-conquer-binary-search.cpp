#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

/*
    random1, seed-1 - 100,200
    random2, seed-2 - 110,1000
    random3, seed-1 - 100,200 //if seed same it generates same value
*/
int randomInd(int s, int e){
    //initializing the seed value
    srand(time(NULL));
    int randNum = s+rand()%(e-s+1);

    return randNum;
}
bool binarySearch(int arr[], int startInd, int lastInd, int key){
    if(startInd>lastInd)return false;
    else{
        // int mid = (startInd+lastInd)/2;
        int mid = randomInd(startInd, lastInd);
        if(arr[mid] == key) return true;
        else if(key < arr[mid]){
            binarySearch(arr,startInd,mid-1,key);
        }
        else{
            binarySearch(arr,mid+1,lastInd,key);
        }
    }
}
int main(){
    int arr[] = {2,5,9,50,100,150,200};
    if(binarySearch(arr,0,6,100)){
        cout << "Found" << endl;
    }
    else cout << "Not Found" << endl;
}