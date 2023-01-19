#include<iostream>
using namespace std;

long long merge(int arr[], int startInd, int mid, int endInd){
    long long inv = 0;
    int leftArrSize = mid - startInd + 1;
    int n1 = mid-startInd+1;
    int n2 = endInd-(mid-1)+1;
    int leftArr[n1];
    for(int i=0;i<leftArrSize;i++){//storing left side of the main array
        leftArr[i] = arr[startInd+i];
    }

    int rightArraySize = endInd - (mid+1) + 1;
    int rightArr[n2];
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
            inv += n1-i;
            rightIndex++;
        }
    }
    return inv;

}
long long mergeSort(int arr[], int startInd, int endInd){
    //startIndex > endIndex then array is empty
    long long inv=0;
    if(startInd<endInd){
        int mid = (startInd+endInd)/2;
        inv += mergeSort(arr,startInd,mid);
        inv += mergeSort(arr,mid+1,endInd);
        inv += merge(arr,startInd,mid,endInd);
    }
    return inv;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << mergeSort(arr,0,n-1)<<endl;

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
}
