#include <iostream>
#include <conio.h>
using namespace std;

template <class T>
class Node{
	public:
	T data;
	Node<T> *next;
	Node( T value, Node *ptr = NULL){
		data = value;
		next = ptr;
	}
};

template <class T>
class SingleLinkedList {
	Node<T> *head;
	Node<T> *tail;
	int size;
	public:
		//constructor
		SingleLinkedList(){
			cout<<"constructor linked list\n";
			head = NULL;
			size=0;
			tail= NULL;
		}
		//insertion
		void insertAtLast(T value){
			Node<T> *tmp = new Node<T>(value);
			if(head == NULL){
				tail = head = tmp;
			}else{
				tail->next = tmp;
				tail = tmp;
			}
			size++;
			cout<<"Element inserted \n";
		}
		void insertAtFront(T value){
			Node<T> *tmp = new Node<T>(value);
			if(head == NULL){
				head = tail = tmp;
			}else{
				tmp->next = head;
				head = tmp;
			}
			size++;
			cout<<"Element inserted \n";
		}
		void insertAtIndex(T value, int index){
			if(index >size){
				cout<<"index out of range \n";
				return;
			}
			if(index == 0){
				insertAtFront(value);
			}else if(index == size){
				insertAtLast(value);
			}else{
				Node<T> *tmp = new Node<T>(value);
				Node<T> *ptr = head;
				int i = 0;
				while(i != index-1){
					ptr = ptr->next;
					i++;
				}
				tmp->next = ptr->next;
				ptr->next = tmp;
			size++;
			cout<<"Element inserted \n";
			}
		}
		//deletion
		void deleteFromLast(){
			if(tail == NULL){
				cout<<"no nodes left \n";
				return;
			}else{
				if(head == tail)
				head = tail = NULL;
				Node<T> *ptr;
				for(ptr=head;ptr->next!=tail;ptr=ptr->next);
				ptr->next=NULL;
				tail=ptr;
				size--;
				cout<<"Element deleted \n";
			}
		}
		void deleteFromFront(){
			if(head==NULL){
				cout<<"no nodes left\n";
				return;
			}else{
				if(head == tail)
				head = tail = NULL;
				head = head->next;
				size--;
				cout<<"Element deleted \n";
			}
		}
		void deleteFromIndex(int index){
			if(index >= size){
				cout<<"index out of range \n";
				return;
			}
			if(head==NULL){
				cout<<"no nodes left\n";
				return;
			}else if(index==0){
				deleteFromFront();
			}else if(index==size-1){
				deleteFromLast();
			}
			else{
				if(head == tail)
				head = tail = NULL;
				Node<T> *tmp = head;
				for(int i=0; i<=index-2 ;i++){
					tmp = tmp->next;
				}
				tmp->next = tmp->next->next;
				size--;
				cout<<"Element deleted \n";
			}
		}
		//function to return size of the linked list
		int getSize(){
			return size;
		}
		//function to display linked list
		void display(){
			for(Node<T> *ptr = head ; ptr!=NULL ; ptr=ptr->next){
				cout<<ptr->data<<" -> ";
			}
			cout<<endl;
		}
		//function to reverse elements of linked list
		void reverse(){
			if(head->next==NULL)
				return;
			Node<T> *tmp;
			Node<T> *slast;
			bool flag = true;
			for(slast=head;slast->next!=tail;slast=slast->next);
			
			while(slast!=NULL){
				tail->next = slast;
				if(flag){
					tmp = tail;
					flag = false;
				}
				slast->next=NULL;
				tail=slast;
				if(head==tail)
				break;
				for(slast=head;slast->next!=tail;slast=slast->next);
			
			}
			head = tmp;
		}
		
		//function to search and swap a element with its previous node
		void searchAndSwap(T el){
			Node<T> *prev ;
			bool flag = false;
			if(head->data == el){
				cout<<"Head element can't be swapped \n";
			}
			for(Node<T> *ptr = head; ptr!=tail; ptr=ptr->next){
				prev = ptr;
				if(prev->next->data == el){
					flag = true;
					break;
				}
			}
			if(flag){
				T tmp = prev->data;
				prev->data = prev->next->data;
				prev->next->data = tmp;
				cout<<"Element swapped \n";
			}else{
				cout<<"Element not found \n";
			}
		}
		
		void swapAtIndex(int index){
			if(index>=size||index<1){
				cout<<"invalid index for swapping with previous element \n";
				return;
			}else{
				Node<T> *prev = head;
				for(int i=1;i<index;i++){
					prev = prev->next;
				}
				T tmp = prev->next->data;
				prev->next->data = prev->data;
				prev->data = tmp;
			}
		}	
		
}; 

int main(){
	SingleLinkedList<int> sll;

	int choice;
	do{
		
		cout<<"\nSelect an option for single linked list \n";
		cout<<"1 : insert"<<endl;
		cout<<"2 : display"<<endl;
		cout<<"3 : delete"<<endl;
		cout<<"4 : size"<<endl;
		cout<<"5 : reverse list"<<endl;
		cout<<"6 : search and swap with previous node"<<endl;
		cout<<"7 : END"<<endl;
		cin>>choice;
		
		switch(choice){
			
			case 1:{
				
				int el;
				cout<<"Enter a number : ";
				cin>>el;
			
				int pos;
				cout<<"Select position to insert : \n";
				cout<<"1 : beginning\n";
				cout<<"2 : end\n";
				cout<<"3 : at a specified index\n";
				cin>>pos;
				
				switch(pos){
					case 1:{
						sll.insertAtFront(el);
						break;
					}
					case 2:{
						sll.insertAtLast(el);
						break;
					}
					case 3:{
						int index;
						cout<<"Enter the index position (index starts at 0) : ";
						cin>>index;
						sll.insertAtIndex(el,index);
						break;
					}
				}
				break;
			}
			case 2 : {
				cout<<"Displaying current linked list : ";
				sll.display();
				break;
			}
			case 3: {
				int pos;
				cout<<"Select position to delete : \n";
				cout<<"1 : beginning\n";
				cout<<"2 : end\n";
				cout<<"3 : at a specified index\n";
				cin>>pos;
				
				switch(pos){
					case 1:{
						sll.deleteFromFront();
						break;
					}
					case 2:{
						sll.deleteFromLast();
						break;
					}
					case 3:{
						int index;
						cout<<"Enter the index position (index starts at 0) : ";
						cin>>index;
						sll.deleteFromIndex(index);
						break;
					}
				}
				break;
			}
			case 4:{
				cout<<"Size of the linked list is "<<sll.getSize()<<endl;
				break;
			}
			case 5:{
				sll.reverse();
				cout<<"linked list is successfully reversed"<<endl;
				break;
			}
			case 6 :{
				int el;
				cout<<"Enter element : ";
				cin>>el;
				sll.searchAndSwap(el);
				break;
			}
			default :
				cout<<"specify correct option \n";
				
		}
		
	}while(choice != 7);
	
	return 0;
}	

