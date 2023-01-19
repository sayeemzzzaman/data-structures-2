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
//Short method
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
/*
{1,5,3,2,6,7}
-1,5,3,2,6  7/6
    -1,5,3,2  6/6
        -1,5,3  2/6
            -1,5  3/6
                -1  5/6
                    -1/6
    
*/
//average
double average(int arr[],int size, int n){
    if(size==1){
        return (double)arr[size-1]/n;
    }
    else{
        double myvalue = (double)arr[size-1]/n;
        double colresult = (double)average(arr,size-1,n);
        return ((double)myvalue+colresult);
        // return ((double)(average(arr,size-1,n)*(size-1) + arr[size-1])/size); //this also works
    }
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
//print Even Numbers
void printEven(int arr[], int size){
    if(size==0){
        if(arr[0]%2==0)cout<<arr[0]<<" ";
        return;
    }
    else{
        printEven(arr,size-1);
        if(arr[size]%2==0)cout<<arr[size]<<" ";
    }
}
//print Odd Numbers
void printOdd(int arr[], int size){
    if(size==0){
        if(arr[0]%2!=0)cout<<arr[0]<<" ";
        return;
    }
    else{
        printOdd(arr,size-1);
        if(arr[size]%2!=0)cout<<arr[size]<<" ";
    }
}
//count even numbers
int countEven(int arr[], int size){
    if(size==0){
        if(arr[0]%2==0)return 1;
        return 0;
    }
    else{
        int c2 = countEven(arr,size-1);
        int c1=0;
        if(arr[size]%2==0){
            c1=1;
        }
        return c1+c2;
    }
}
//count odd numbers
int countOdd(int arr[], int size){
    if(size==0){
        if(arr[0]%2!=0)return 1;
        return 0;
    }
    else{
        int c2 = countOdd(arr,size-1);
        int c1=0;
        if(arr[size]%2!=0){
            c1=1;
        }
        return c1+c2;
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
    cout << "Max: " << maximum(arr,n)<<endl<<"Min: "<<minimum(arr,n)<<endl<<"Sum: "<<sum(arr,n)<<endl<<"Multiplication: "<<multi(arr,n)<<endl << "Average: " << average(arr,n,n)<<endl;
    printArray(arr,n-1);
    cout <<endl<<"-------"<<endl<<"Even: ";
    printEven(arr,n-1);
    cout<<endl<<"Odd: ";
    printOdd(arr,n-1);
    cout<<endl<<"Counted Even Numbers: "<<endl<<countEven(arr,n-1)<<endl;
    cout<<"Counted Odd Numbers: "<<endl<<countOdd(arr,n-1)<<endl;

    

}