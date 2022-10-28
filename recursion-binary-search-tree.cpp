#include<iostream>
using namespace std;

bool binarySearchTree(int arr[],int size, int index, int key){
	if(index>=size)return false;
	else{
		if(key==arr[index])return true;
		int leftChildIndex = 2*index;
		int rightChildIndex = 2*index+1;
		if(arr[index]>key){
			binarySearchTree(arr,size,leftChildIndex,key);
		}
		else{
			binarySearchTree(arr,size,rightChildIndex,key);
		}
	}
}

int main(){
	int bst[] = {-1,100,50,190,48,55,-1,215,-1,-1,53,-1,-1,-1,210,-1};
	int size = sizeof(bst)/sizeof(int);
	int key = 210;
	if(binarySearchTree(bst,size,1,key)){
		cout << "Found!" << endl;
	}
	else{
		cout << "Not Found" << endl;
	}
}