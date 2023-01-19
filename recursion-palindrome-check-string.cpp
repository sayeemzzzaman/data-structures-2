// #include<iostream>
// using namespace std;
// /*
//     a b c b a
//     a b c c b a
//     -         -
//       -     -
//         - -
// */
// bool palindromeCheck(string arr, int tracker){

//     int firstIndex = tracker;
//     int lastIndex = arr.size()-1-tracker;
//     if(firstIndex>=lastIndex){
//         return true;
//     }
//     else{
//         int firstChar = arr[firstIndex];
//         int lastChar = arr[lastIndex];

//         bool colResult = palindromeCheck(arr,tracker+1);
//         if(firstChar==lastChar && colResult==true)return true;
//         else return false;
//     }
// }

// int main(){
//     string mystr;
//     cin >> mystr;

//     bool result = palindromeCheck(mystr,0);
//     if(result==true){
//         cout << "Palindrome" << endl;
//     }
//     else{
//         cout << "Not a Palindrome" << endl;
//     }
// }


//ignoring whitespace and case sensitivity

/*
Evil olive
E         e
 v      v
  i    i
    l l
     o

*/


#include<iostream>
#include<algorithm>

using namespace std;

string ignoreWhiteSpace(string arr){
    int j=0;
    string temp = arr;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=' '){
            temp[j]=arr[i];
            j++;
        }
    }
    temp[j]='\0';
    return temp;
}
bool palindrome(string arr, int track){
    int firstIndex = track;
    int lastIndex = arr.size()-1-track;
    if(firstIndex>=lastIndex){
        return true;
    }
    else{
        char firstChar=tolower(arr[firstIndex]);
        char lastChar=tolower(arr[lastIndex]);
        if(firstChar==lastChar){
            return palindrome(arr,track+1);
        }
        else return false;
    }
}
int main(){
    string arr;
    getline(cin,arr);
    arr.erase(remove(arr.begin(),arr.end(), ' '),arr.end()); //use char arr[] and pointer if don't want to use arr.erase
    //arr = ignoreWhiteSpace(arr);

    if(palindrome(arr,0))
        cout << "True" << endl;
    else cout<<"False"<<endl;
}

