#include<bits/stdc++.h> 
using namespace std;  
  
int postIndex = 0; 
  
int search(int in[], int data,int n) 
{ 
    int i = 0; 
    for (i = 0; i < n; i++) 
        if (in[i] == data) 
            return i; 
    return i; 
} 
  
void buildPreOrder(int in[], int post[], int inStrt, 
            int inEnd, stack<int> &s,int n) 
{ 
    if (inStrt > inEnd) 
        return; 
  
    int val = post[postIndex]; 
    int inIndex = search(in, val, n); 
    postIndex--; 
  
    // traverse right tree 
    buildPreOrder(in, post, inIndex + 1, inEnd, s, n); 
  
    // traverse left tree 
    buildPreOrder(in, post, inStrt, inIndex - 1, s, n); 
  
    s.push(val); 
} 
  
void printPreMain(int in[], int post[],int n) 
{ 
    int len = n; 
    postIndex = len - 1; 
    stack<int> s ; 
    buildPreOrder(in, post, 0, len - 1, s, n); 
    while (s.size() > 0) 
    { 
        cout << s.top() << " "; 
        s.pop(); 
    } 
} 
  
int main() 
{ 
	cout<<"preorder given postorder and inorder traversals \n\n";
    int in[] = { 4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90 }; 
    int post[] = { 4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25 }; 
    int n=sizeof(in)/sizeof(int); 
    printPreMain(in, post,n); 
} 
