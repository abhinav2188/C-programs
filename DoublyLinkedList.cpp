#include <iostream>
#include <conio.h>
using namespace std;

template <class T>
class Node{
	public:
	T data;
	Node<T> *next;
	Node<T> *prev;
	Node( T value, Node *ptr1 = NULL, Node *ptr2=NULL){
		data = value;
		next = ptr1;
		prev = ptr2;
	}
};

template <class T>
class DoubleLinkedList {
	Node<T> *head;
	Node<T> *tail;
	int size;
	public:
		//constructor
		DoubleLinkedList(){
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
				tmp->prev=tail;
				tail = tmp;
			}
			size++;
		}
		void insertAtFront(T value){
			Node<T> *tmp = new Node<T>(value);
			if(head == NULL){
				head = tail = tmp;
			}else{
				tmp->next = head;
				tmp->prev = NULL;
				head->prev = tmp;
				head = tmp;
			}
			size++;
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
				tmp->prev = ptr;
				ptr->next->prev = tmp;
				ptr->next = tmp;
			size++;
			}
		}
		//deletion
		void deleteFromLast(){
			if(tail == NULL){
				cout<<"no nodes left";
				return;
			}else{
				Node<T> *ptr;
				for(ptr=head;ptr->next!=tail;ptr=ptr->next);
				ptr->next->prev = NULL;
				ptr->next=NULL;
				tail=ptr;
				size--;
			}
		}
		void deleteFromFront(){
			if(head==NULL){
				cout<<"no nodes left";
				return;
			}else{
				head->next->prev = NULL;
				head = head->next;
				size--;
			}
		}
		void deleteFromIndex(int index){
			if(head==NULL){
				cout<<"no nodes left";
				return;
			}else if(index==0){
				deleteFromFront();
			}else if(index==size-1){
				deleteFromLast();
			}
			else{
				Node<T> *tmp = head;
				for(int i=0; i<=index-2 ;i++){
					tmp = tmp->next;
				}
				tmp->next->next->prev = tmp;
				tmp->next = tmp->next->next;
				size--;
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
		void displayFromEnd(){
			for(Node<T> *ptr = tail; ptr!=NULL; ptr=ptr->prev){
				cout<<ptr->data<<" -> ";
			}
			cout<<endl;
		}
		
		//function to reverse elements of linked list
		void reverse(){
			if(head->next==NULL)
				return;
			for(Node<T> *ptr=tail;ptr!=NULL;ptr=ptr->prev){
				ptr->next = ptr->prev;
			}
			head = tail;
			head->prev = NULL;
			Node<T> *tmp;
			for(Node<T> *tmp=head; tmp->next!=NULL; tmp=tmp->next)
			tmp->next->prev = tmp;
			tail = tmp;
		}
		
}; 

int main(){

	DoubleLinkedList<int> dll;
	
	dll.insertAtLast(133); dll.insertAtLast(13); dll.insertAtLast(167);	dll.insertAtLast(87);
	dll.display();
	dll.insertAtFront(21); dll.insertAtFront(76); dll.insertAtFront(90);
	dll.display();
	dll.insertAtIndex(89,6);dll.insertAtIndex(34,1);dll.insertAtIndex(99,9);
	dll.display();
	cout<<"reverse ";
	dll.reverse();
	dll.display();
	dll.displayFromEnd();
//	dll.deleteFromFront();
//	dll.display();
//	dll.displayFromEnd();
//	dll.deleteFromLast();
//	dll.display();
//	dll.displayFromEnd();
//	dll.deleteFromIndex(4);
//	dll.display();
//	dll.displayFromEnd();
	
	
	return 0;
}
