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
		void searchAndSwap(int index){
			if(index>=size||index<1){
				cout<<"invalid index for swapping with previous element \n";
				return;
			}else{
				Node<T> *prev = head;
				for(int i=1;i<index;i++){
					prev = prev->next;
				}
				int tmp = prev->next->data;
				prev->next->data = prev->data;
				prev->data = tmp;
			}
		}	
		
}; 

int main(){
	SingleLinkedList<int> sll;

	sll.insertAtLast(12);
	sll.display();
	cout<<"reverse : ";
	sll.reverse();
	sll.display();
	sll.insertAtLast(23);
	sll.display();
	cout<<"reverse : ";
	sll.reverse();
	sll.display();
	sll.insertAtLast(112);
	sll.display();
	sll.insertAtIndex(2,2);
	sll.display();
	sll.insertAtIndex(0,0);
	sll.display();
	sll.insertAtIndex(78,5);
	sll.display();
	cout<<"\n";
	cout<<"reverse : ";
	sll.reverse();
	sll.display();

	sll.insertAtFront(90);
	sll.display();
	cout<<"swap ";
	sll.searchAndSwap(3);
	sll.display();
	sll.deleteFromIndex(3);
	sll.display();
	cout<<"swap ";
	sll.searchAndSwap(6);
	sll.display();
	sll.deleteFromLast();
	sll.display();
	sll.deleteFromLast();
	sll.display();
	sll.deleteFromFront();
	sll.display();
	sll.deleteFromLast();
	sll.display();
	sll.deleteFromFront();
	sll.display();
	sll.insertAtFront(9);
	sll.display();
	sll.deleteFromIndex(1);
	sll.display();
	
	
	return 0;
}
