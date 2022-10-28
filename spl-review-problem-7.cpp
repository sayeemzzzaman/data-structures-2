#include<iostream>
using namespace std;

string remove_ws(string sen){
    char temp[sen.size()];
    int p=0;
    for(int i=0;i<sen.size();i++){
        if(sen[i]!=' '){
            temp[p] = sen[i];
            p++;
        }
    }
    temp[p] = '\0';
    sen=temp;

    return sen;
}

string conv_to_lower(string sentence){
    for(int i=0;i<sentence.size();i++){
        if(sentence[i]>='A' && sentence[i]<='Z'){
            sentence[i] = sentence[i]+32;
        }
    }
    return sentence;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    string sentence;
    getline(cin,sentence);
    sentence = conv_to_lower(sentence);
    //cout << sentence << endl;
    sentence = remove_ws(sentence);
    cout << sentence << endl;

}

/*
Do you have 2 Markers? Can you spare one for me?
*/