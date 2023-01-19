#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;

bool is_palindrome(string arr, int track){
    int firstIndex = track;
    int lastIndex = arr.size()-1-track;
    if(firstIndex>=lastIndex){
        return true;
    }
    else{
        char firstChar=arr[firstIndex];
        char lastChar=arr[lastIndex];
        if(firstChar==lastChar){
            return is_palindrome(arr,track+1);
        }
        else return false;
    }
}

int sum_palindrome(int palindromes[], int n){
    if(n==0)return palindromes[0];
    else{
        return palindromes[n] + sum_palindrome(palindromes,n-1);
    }
}
int main(){
    int X,Y;
    cin >> X >> Y;
    int palindromes[Y-X+1];
    int k=0;
    for(int i=X;i<=Y;i++){
        string temp = to_string(i);

        if(is_palindrome(temp,0)){
            stringstream ss(temp);
            ss >> palindromes[k];
            cout << palindromes[k] << " ";
            k++;
        }
    }
    cout << endl << "sum " << sum_palindrome(palindromes,k-1) << endl;;
}