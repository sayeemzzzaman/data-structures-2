#include<iostream>
using namespace std;
/*
!sumOfDigits
923
-92, 3
-9, 2

!palindrome
92329
923329
reverse the number and check with input
reverse = reverse*10
reverse = reverse + (input%10)
input = input/10
base case ~ input==0
*/
int sumOfDigits(int n){
    if(n<=9)return n;
    else{
        int rest = sumOfDigits(n/10);
        int lastdigit = n%10;
        return rest+lastdigit;
    }
        
}
int digitCalc(int n){
    if(n<=9)cout << n << " ";
    else{
        digitCalc(n/10);
        int lastdigit = n%10;
        cout << lastdigit << " ";
    }
}
//count the digits
int countDigits(int n){
    if(n<=9)return 1;
    else{
        int count = countDigits(n/10);
        return count+1;  
    }
}
//palindrome check
int reverseNum(int input,int reverse){
    if(input==0){
        return reverse;
    }
    else{
        reverse = reverse*10;
        reverse = reverse + (input%10);
        input = input/10;
        return reverseNum(input,reverse);
    }
}
int main(){
    int n;
    cin >> n;
    digitCalc(n);
    cout<<endl;
    cout << "Total Digits: " << countDigits(n)<<endl;
    cout << "Sum: " << sumOfDigits(n)<<endl;

    if(n==reverseNum(n,0)){
        cout<<n<<" is Palindrome!"<<endl;
    }
    else{
        cout<<n<<" is not Palindrome!"<<endl;
    }
}