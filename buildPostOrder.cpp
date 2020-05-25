#include <iostream>
#include <conio.h>
#include <queue>
using namespace std;  

int preIndex = 0;
int searchIndex(int in[], int value, int n){
	for(int i=0;i<n;i++)
	if(in[i] == value)
	return i;
}

void buildPostOrder(int in[], int pre[], int inStart, int inEnd, queue<int> &que,int n){
	if(inStart>inEnd)
	return;
	int root = pre[preIndex];
	int rootIndex = searchIndex(in,root,n);
	preIndex++;
	buildPostOrder(in,pre,inStart,rootIndex-1,que,n);
	buildPostOrder(in,pre,rootIndex+1,inEnd,que,n);
	que.push(root);
} 


int main(){
	cout<<"building postorder given preorder and inorder traversals\n\n ";
	int inorder[] = {4,2,5,1,3,6};
	int preorder[] = {1,2,4,5,3,6};
	int n=6;
	queue<int> q;
	buildPostOrder(inorder,preorder,0,n-1,q,n);
	while(q.size()>0){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}
