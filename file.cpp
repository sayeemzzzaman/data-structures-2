#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream myFile;
    myFile.open("file.txt", ios::out | ios::app);

    if(myFile.is_open()){   //file write
        myFile << "Line 1" << endl;
        myFile << "Line 2" << endl;
        myFile << "Line 3" << endl;
    }
    else{
        cout << "File can't be opened" << endl;
    }

    //file read
    ifstream file;
    file.open("file.txt");
    if(file.is_open()){
        string line;
        while(getline(file,line)){ //getline(source,variable)
            cout << line << endl;
        }
        cout << "-----End of File-----" << endl;
    }
    else{
        cout << "Unable to open file" << endl;
    }
}