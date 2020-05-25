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
		int height;
		//constructor
		Node(T data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->height = 1;
		}
		
};

template <class T>
class AVLTree{
	Node<T> *root;
	public :
		
		//constructor
		AVLTree(){
			root = NULL; 
		}
		
		int height(Node<T> *node){
			if (node==NULL)
			return 0;
			else
			return node->height;
		}
		int balance(Node<T> *node){
			int b = height(node->left) - height(node->right);
			return b;
		}	
		void propagateHeight(Node<T> *node){
//			cout<<"\npropagate("<<node->data<<")";
			while(node!= NULL){
				int ht = 1+ max(height(node->left),height(node->right));
				node->height = ht;
				int bal = balance(node);
//				cout<<" node balance = "<<bal;
				if(bal > 1 ){
					int innerBal = balance(node->left);
//					cout<<" inner balance = "<<innerBal;
					if(innerBal>=0){
						RRRotation(node);
					}
					else if(innerBal<0){
						LLRotation(node->left);
					}
				}
				if(bal < -1){
					int innerBal = balance(node->right);
//					cout<<" inner balance = "<<innerBal;
					if(innerBal<=0){
						LLRotation(node);
					}
					else if(innerBal>0){
						RRRotation(node->right);
					}
				}
				node=node->parent;
			}
		}
		//rotations 
		void RRRotation(Node<T> *z){
			cout<<"\nRightRotate("<<z->data<<")";
			Node<T> *y = z->left;
			if(y==NULL){
				cout<<"\nLLRotation not possible node doesn't have left child";
				return;
			}
			if(y->right){
				Node<T> *T3 = y->right;
				z->left = T3;
				T3->parent = z;
			}else
			z->left=NULL;
			if(z->parent){
				if(z == z->parent->left)
				z->parent->left = y;
				else
				z->parent->right = y;
				y->parent = z->parent;
			}
			else{
				root = y;
				y->parent = NULL;
			}
			y->right = z;
			z->parent = y;
			propagateHeight(z);
			
		}

		void LLRotation(Node<T> *z){
			cout<<"\nLeftRotate("<<z->data<<")";
			Node<T> *y = z->right;
			if(y==NULL){
				cout<<"\nLLRotation not possible node doesn't have right child";
				return;
			}
			
			if(y->left){
				Node<T> *T3 = y->left;
				z->right = T3;
				T3->parent = z;
			}else
			z->right=NULL;

			if(z->parent){
				if(z == z->parent->left)
				z->parent->left = y;
				else
				z->parent->right = y;
				y->parent = z->parent;
			}
			else{
				root = y;
				y->parent = NULL;
			}

			y->left = z;
			z->parent = y;
			propagateHeight(z);
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
						tmp->parent=i;
						i->left = tmp;
						propagateHeight(tmp);
						break;
					}
					else
					i = i->left;
				}else{
					if(i->right == NULL){
						tmp->parent = i;
						i->right = tmp;
						propagateHeight(tmp);
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
		
		//display height
		void displayHeight(){
			cout<<endl<<"heights ";
			queue < Node<T>* > q;
			q.push(root);
			while(!q.empty()){
				Node<T> *tmp = q.front();
				cout<<tmp->height<<" ";
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
				bool twoChild = false;
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
					twoChild = true;
					Node<T> *successor = minNode(node->right);
//					cout<<"\n"<<successor->data;
					T data = successor->data;
					deleteNode(data);
					node->data = data;
				}
				if(twoChild){
					propagateHeight(node);
				}else{
					propagateHeight(parent);
				}
				return true;
					
			}
		}
		

};

int main(){
	cout<<"AVL Tree \n";
	AVLTree<int> avl ;
	avl.insert(12);
	avl.display();
	avl.insert(5);
	avl.display();
	avl.insert(1);
	avl.display();
	avl.insert(8);
	avl.display();
	avl.insert(-1);
	avl.display();
	avl.insert(4);
	avl.display();
	avl.insert(24);
	avl.display();
	avl.insert(217);
	avl.display();
	avl.insert(214);
	avl.display();
	avl.displayHeight();
	cout<<"\ninorder ";
	avl.inOrder();
	avl.deleteNode(1);
	avl.display();
	avl.deleteNode(-1);
	avl.display();
	avl.displayHeight();
	avl.deleteNode(12);
	avl.display();
	avl.displayHeight();
	avl.deleteNode(214);
	avl.display();
	avl.displayHeight();
	avl.deleteNode(217);
	avl.display();
	avl.displayHeight();
//	cout<<"\npreorder ";
//	avl.preOrder();
//	cout<<"\npostorder ";
//	avl.postOrder();
//	cout<<endl<<avl.search(-1)->parent->data;
//	cout<<endl<<avl.maxNode(avl.search(12))->data;
//	avl.deleteNode(1);
//	avl.display();
	return 0;
}

