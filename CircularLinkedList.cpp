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
			cout<<"element inserted \n";
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
			cout<<"element inserted \n";
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
			cout<<"element inserted \n";
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
				cout<<"element deleted \n";
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
				cout<<"element deleted \n";
			}
		}
		void deleteFromIndex(int index){
			if(index >= size){
				cout<<"index out of range \n";
				return;
			}
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
				cout<<"element deleted \n";
			}
		}
		//function to return size of the linked list
		int getSize(){
			return size;
		}
		//function to display linked list
		void display(){
			cout<<"displaying list : ";
			for(Node<T> *ptr = head ; ptr!=tail ; ptr=ptr->next){
				cout<<ptr->data<<" -> ";
			}
			cout<<tail->data;
			cout<<endl;
		}
		void displayFromEnd(){
			cout<<"displaying list from end : ";
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

	int choice;
	do{
		
		cout<<"Select an option for circular linked list \n";
		cout<<"1 : insert"<<endl;
		cout<<"2 : display"<<endl;
		cout<<"3 : delete"<<endl;
		cout<<"4 : size"<<endl;
		cout<<"5 : display front element"<<endl;
		cout<<"6 : display rear element"<<endl;
		cout<<"7 : display reverse "<<endl;
		cout<<"8 : END"<<endl;
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
						dll.insertAtFront(el);
						break;
					}
					case 2:{
						dll.insertAtLast(el);
						break;
					}
					case 3:{
						int index;
						cout<<"Enter the index position (index starts at 0) : ";
						cin>>index;
						dll.insertAtIndex(el,index);
						break;
					}
				}
				break;
			}
			case 2 : {
				dll.display();
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
						dll.deleteFromFront();
						break;
					}
					case 2:{
						dll.deleteFromLast();
						break;
					}
					case 3:{
						int index;
						cout<<"Enter the index position (index starts at 0) : ";
						cin>>index;
						dll.deleteFromIndex(index);
						break;
					}
				}
				break;
			}
			case 4:{
				cout<<"Size of the linked list is "<<dll.getSize()<<endl;
				break;
			}
			case 5 : {
				cout<<"List first element is "<<dll.front()->data<<endl;
				break;
			}
			case 6 :{
				cout<<"List last element is "<<dll.rear()->data<<endl;
				break;
			}
			case 7:{
				dll.displayFromEnd();
				break;
			}
			default :
				cout<<"specify correct option \n";
			
		}
		
	}while(choice != 8);
	
	return 0;
}
