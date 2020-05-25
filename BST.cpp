#include <iostream>
#include <conio.h>
#include <queue>
using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node *left;
		Node *right;
		Node *parent;
		//constructor
		Node(T data
		){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
			this->parent = parent;
		}
		
};

template <class T>
class BinarySearchTree{
	Node<T> *root;
	public :
		
		//constructor
		BinarySearchTree(){
			root = NULL; 
		}
		
		//insert function
		void insert(T value){
			cout<<"\ninsert("<<value<<")";
			Node<T> *tmp = new Node<T>(value);
			if(root == NULL){
				root = tmp;
				return;				
			}
			Node<T> *i = root;
			while(root != NULL){
				if(value < i->data){
					if(i->left == NULL){
						tmp->parent = i;
						i->left = tmp;
						break;
					}
					else
					i = i->left;
				}else{
					if(i->right == NULL){
						tmp->parent = i;
						i->right = tmp;
						break;
					}
					else
					i = i->right;
					
				}
			}
		}
		
		//display function
		void display(){
			cout<<endl<<"level wise display ";
			queue < Node<T>* > q;
			q.push(root);
			while(!q.empty()){
				Node<T> *tmp = q.front();
				cout<<tmp->data<<" ";
				if(tmp->left)
				q.push(tmp->left);
				if(tmp->right)
				q.push(tmp->right);
				q.pop();
			}
			
		}
		
		//inorder traversal
		void inOrder(Node<T> *node = NULL){
			if(node == NULL)
			node = root;
			if(node->left == NULL && node->right == NULL){
			cout<<node->data<<" ";
			return;				
			}
			else{
				if(node->left)
				inOrder(node->left);
				cout<<node->data<<" ";
				if(node->right)
				inOrder(node->right);
			}
		}

		//preorder traversal
		void preOrder(Node<T> *node = NULL){
			if(node == NULL)
			node = root;
			if(node->left == NULL && node->right == NULL){
			cout<<node->data<<" ";
			return;				
			}
			else{
				cout<<node->data<<" ";
				if(node->left)
				preOrder(node->left);
				if(node->right)
				preOrder(node->right);
			}
		}
		
		//postOrder traversal
		void postOrder(Node<T> *node = NULL){
			if(node == NULL)
			node = root;
			if(node->left == NULL && node->right == NULL){
			cout<<node->data<<" ";
			return;				
			}
			else{
				if(node->left)
				postOrder(node->left);
				if(node->right)
				postOrder(node->right);
				cout<<node->data<<" ";
			}
		}

		//bst search
		Node<T>* search(T value){
			Node<T> *node = root;
			while(node!=NULL){
				if(value == node->data)
				return node;
				else if(value < node->data)
				node = node->left;
				else
				node=node->right;
			}
			return NULL;
		}
		
		//max
		Node<T>* maxNode(Node<T> *node = NULL){
			Node<T> *ptr = node;
			if(ptr==NULL)
			ptr = root;
			while(ptr->right!=NULL){
				ptr = ptr->right;
			}
			return ptr;
		}
		
		//min
		Node<T>* minNode(Node<T> *node = NULL){
			Node<T> *ptr = node;
			if(ptr==NULL)
			ptr = root;
			while(ptr->left!=NULL){
				ptr = ptr->left;
			}
			return ptr;
		}
		
		//delete function
		bool deleteNode(T value){
			cout<<"\ndelete("<<value<<")";
			Node<T> *node = search(value);
			if(node == NULL){
			cout<<"\nnode not present";				
			return false;
			}
			else{
				Node<T> *parent = node->parent;
				//node with no children
				if(node->right == NULL && node->left == NULL){
//					cout<<"\nno children";
					if(node == parent->left)
					parent->left = NULL;
					else 
					parent->right = NULL;
				}
				//node with one children
				else if(node->left==NULL && node->right != NULL){
//					cout<<"\nright children";
					if(node == parent->left){
						parent->left = node->right;
						node->right->parent = parent;					
					}else{
						parent->right = node->right;
						node->right->parent = parent;					
					}
				}
				else if(node->right == NULL && node->left != NULL){
//					cout<<"\nleft children";
					if(node == parent->left){
						parent->left = node->left;
						node->left->parent = parent;					
					}else{
						parent->right = node->left;
						node->left->parent = parent;					
					}
					
				}
				//node with two children
				else{
//					cout<<"\ntwo children";
					Node<T> *successor = minNode(node->right);
//					cout<<"\n"<<successor->data;
					T data = successor->data;
					deleteNode(data);
					node->data = data;
				}
				return true;	
			}
		}
};

int main(){
	cout<<"Binary Search Tree \n";
	BinarySearchTree<int> bst ;
	bst.insert(12);
	bst.display();
	bst.insert(5);
	bst.display();
	bst.insert(1);
	bst.display();
	bst.insert(8);
	bst.display();
	bst.insert(-1);
	bst.display();
	bst.insert(4);
	bst.display();
	bst.insert(24);
	bst.display();
	bst.insert(17);
	bst.display();
	bst.insert(14);
	bst.display();
	cout<<"\ninorder ";
	bst.inOrder();
	cout<<"\npreorder ";
	bst.preOrder();
	cout<<"\npostorder ";
	bst.postOrder();
//	cout<<endl<<bst.search(-1)->parent->data;
//	cout<<endl<<bst.maxNode(bst.search(12))->data;
	bst.deleteNode(1);
	bst.display();
	return 0;
}

