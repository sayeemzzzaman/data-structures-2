#include<iostream>
using namespace std;

void swap(int arr[],int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int startInd, int lastInd){
    int pivot = arr[lastInd];
    int i = startInd-1;
    for(int j=startInd;j<lastInd;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,lastInd);
    return i+1;
}
void quickSort(int arr[], int startInd, int lastInd){
    if(startInd<lastInd){
        int parts = partition(arr,startInd,lastInd);
        quickSort(arr,startInd,parts-1);
        quickSort(arr,parts+1,lastInd);
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}