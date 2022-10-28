/*
binary tree = contains max 2 child

parent node index = n'th cell store
leftnode index= 2*n'th cell
rightnode index= 2*n+1'th cell

------------------------------------------------
-1|100|300|50|120|200|30|-1|-1|20|80|150|-1|99
------------------------------------------------
0	1   2  3   4   5  6  7  8  9  10  11 12  13

*/
#include<iostream>
using namespace std;

//preorder ~ root left right
void preorder(int binTree[], int size, int index){
	if(index>=size || binTree[index]==-1)return;
	else{
		cout << binTree[index] << " "; //root
		int leftChildIndex = 2*index;
		int rightChildIndex = 2*index+1;

		preorder(binTree, size, leftChildIndex);//left
		preorder(binTree, size, rightChildIndex);//right
	}
}

//postorder left right root
void postorder(int binTree[], int size, int index){
	if(index>=size || binTree[index]==-1)return;
	else{
		int leftChildIndex = 2*index;
		int rightChildIndex = 2*index+1;

		postorder(binTree, size, leftChildIndex);//left
		postorder(binTree, size, rightChildIndex);//right
		cout << binTree[index] << " "; //root
	}
}
//inorder left root right
void inorder(int binTree[], int size, int index){
	if(index>=size || binTree[index]==-1)return;
	else{
		int leftChildIndex = 2*index;
		int rightChildIndex = 2*index+1;

		inorder(binTree, size, leftChildIndex);//left
		cout << binTree[index] << " "; //root
		inorder(binTree, size, rightChildIndex);//right
	}
}
int main(){
	int binTree[]={-1,100,300,50,120,200,30,-1,-1,20,80,150,-1,99};
	int size = sizeof(binTree)/sizeof(int);

	preorder(binTree,size,1);
	cout<<endl<<"--------------------------------------"<<endl;
	postorder(binTree,size,1);
	cout<<endl<<"--------------------------------------"<<endl;
	inorder(binTree,size,1);
}