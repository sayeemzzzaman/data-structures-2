#include<iostream>
using namespace std;

//8 9 6     1 0 8 
// 1 0
void merge(int arr[], int startInd, int mid, int endInd){
    int leftArrSize = mid - startInd + 1;
    int rightArraySize = endInd - (mid+1) + 1;
    // int n1 = mid-startInd+1;
    // int n2 = endInd-(mid+1)+1;
    int leftArr[leftArrSize];
    for(int i=0;i<leftArrSize;i++){//storing left side of the main array
        leftArr[i] = arr[startInd+i];
    }

    int rightArr[rightArraySize];
    for(int i=0;i<rightArraySize;i++){//storing right side of the main array
        rightArr[i] = arr[mid+1+i];
    }

    int leftIndex=0;
    int rightIndex=0;
    for(int i=startInd;i<=endInd;i++){
        if(leftIndex==leftArrSize){
            //all the left array elements are copied
            //so only need to copy the right elements
            arr[i] = rightArr[rightIndex];
            rightIndex++;
        }
        else if(rightIndex==rightArraySize){
            //all the right elements copied
            //need only copy the left elements
            arr[i] = leftArr[leftIndex];
            leftIndex++;
        }
        else if(leftArr[leftIndex]<=rightArr[rightIndex]){
            arr[i] = leftArr[leftIndex];
            leftIndex++;
        }
        else{
            arr[i] = rightArr[rightIndex];
            rightIndex++;
        }
    }

}
void mergeSort(int arr[], int startInd, int endInd){
    //startIndex > endIndex then array is empty
    if(startInd<endInd){
        int mid = (startInd+endInd)/2;
        mergeSort(arr,startInd,mid);
        mergeSort(arr,mid+1,endInd);
        merge(arr,startInd,mid,endInd);
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
