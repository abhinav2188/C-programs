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
class CircularLinkedList {
	Node<T> *head;
	Node<T> *tail;
	int size;
	public:
		//constructor
		CircularLinkedList(){
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
				head->prev = tmp;
				tail->next = tmp;
				tmp->prev=tail;
				tmp->next = head;
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
				tmp->prev = tail;
				head->prev = tmp;
				tail->next = tmp;
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
				ptr->next = head;
				head->prev = ptr;
				tail = ptr;
				size--;
			}
		}
		void deleteFromFront(){
			if(head==NULL){
				cout<<"no nodes left";
				return;
			}else{
				head->next->prev = tail;
				tail->next = head->next;
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
			for(Node<T> *ptr = head ; ptr!=tail ; ptr=ptr->next){
				cout<<ptr->data<<" -> ";
			}
			cout<<tail->data;
			cout<<endl;
		}
		void displayFromEnd(){
			for(Node<T> *ptr = tail; ptr!=head ; ptr=ptr->prev){
				cout<<ptr->data<<" -> ";
			}
			cout<<head->data;
			cout<<endl;
		}
		//functions to return head and tail nodes
		Node<T>* front(){
			return head;
		}
		Node<T>* rear(){
			return tail;
		}
		
		
}; 

int main(){

	CircularLinkedList<int> dll;
	
	dll.insertAtLast(133); dll.insertAtLast(13); dll.insertAtLast(167);	dll.insertAtLast(87);
	dll.display();
	dll.insertAtFront(21); dll.insertAtFront(76); dll.insertAtFront(90);
	dll.display();
	dll.insertAtIndex(89,6);dll.insertAtIndex(34,1);dll.insertAtIndex(99,9);
	dll.display();
	dll.displayFromEnd();
	dll.display();
	dll.deleteFromFront();
	dll.display();
	dll.displayFromEnd();
	dll.deleteFromLast();
	dll.display();
	dll.displayFromEnd();
	dll.deleteFromIndex(4);
	dll.display();
	dll.displayFromEnd();
	Node<int> *f = dll.front();
	cout<<"front "<<f->data<<endl;
	Node<int> *l = dll.rear();
	cout<<"rear "<<l->data<<endl;
	
	return 0;
}
