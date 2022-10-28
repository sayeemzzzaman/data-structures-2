#include<iostream>
using namespace std;
//max
int maximum(int arr[],int size){
    if(size==1){
        return arr[0];
    }
    else{
        int myvalue = arr[size-1];
        int colresult = maximum(arr,size-1);
        if(myvalue>colresult){
            return myvalue;
        }
        else{
            return colresult;
        }
    }
}

// int findMax(int a[], int n){
//     if(n==0)return a[n];
//     else{
//         return max(findMax(a,n-1), a[n]);
//     }
// }

//min
int minimum(int arr[],int size){
    if(size==1){
        return arr[0];
    }
    else{
        int myvalue = arr[size-1];
        int colresult = minimum(arr,size-1);
        if(myvalue<colresult){
            return myvalue;
        }
        else{
            return colresult;
        }
    }
}
//sum
int sum(int arr[],int size){
    if(size==1){
        return arr[0];
    }
    else{
        int myvalue = arr[size-1];
        int colresult = sum(arr,size-1);
        return myvalue+colresult;
    }
}
//average
int average(int arr[],int size){

}
//multiplication
int multi(int arr[],int size){
    if(size==1){
        return arr[0];
    }
    else{
        int myvalue = arr[size-1];
        int colresult = multi(arr,size-1);
        return myvalue*colresult;
    }
}
//printArray
int printArray(int arr[], int size){
    if(size==0){
        cout << arr[size] << " ";
        return arr[0];
    }
    else{
        printArray(arr,size-1);
        cout << arr[size] << " ";
    }
}
int main(){
    // int arr[]={1,1,10,5,10};
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    // cout << findMax(arr,n-1) << endl;
    cout << "Max: " << maximum(arr,n)<<endl<<"Min: "<<minimum(arr,n)<<endl<<"Sum: "<<sum(arr,n)<<endl<<"Multiplication: "<<multi(arr,n)<<endl;
    printArray(arr,n-1);

}