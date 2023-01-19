#include <iostream>
using namespace std;

int countEven(int arr[], int i, int j)
{
    if (i == j)
    { // array size 1
        if (arr[i] % 2 == 0) return 1;
         else return 0;
        
    }
    else
    {
        int mid = (i + j) / 2;
        int c1 = countEven(arr, i, mid);     // solution to the first half
        int c2 = countEven(arr, mid + 1, j); // solution to the second half
        return c1 + c2;
    }
}

void printOdd(int arr[],int i, int j){
    if(i==j){
        if(arr[i]%2!=0){
            cout<<arr[i]<<" ";
        }
        return;
    }
    else{
        int mid=(i+j)/2;
        printOdd(arr,i,mid);
        printOdd(arr,mid+1,j);
    }
}

int calcSum(int arr[], int i, int j){
    if(i==j)return arr[i];
    else{
        int mid=(i+j)/2;
        int c1 = calcSum(arr,i,mid);
        int c2 = calcSum(arr,mid+1,j);
        return c1+c2;
    }
}

int calcEvenSum(int arr[], int i, int j)
{
    if (i == j){
        if (arr[i] % 2 == 0){
            return arr[i];
        }
        else{
            return 0;
        } 
    }
    else{
        int mid = (i + j) / 2;
        int c1 = calcEvenSum(arr, i, mid);
        int c2 = calcEvenSum(arr, mid + 1, j);
        return c1 + c2;
    }
} 

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    cout << "Even Numbers: " << countEven(arr,0,7)<<endl;
    printOdd(arr,0,7);
    cout<<endl<<"Sum of the Array: " << calcSum(arr,0,7)<<endl;

    cout << "Even Numbers Sum: " << calcEvenSum(arr,0,7) << endl;
}
