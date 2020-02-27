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
		SingleLinkedList(){
			cout<<"constructor linked list\n";
			head = NULL;
			size=0;
			tail= NULL;
		}
		void insertAtLast(T value){
			Node<T> *tmp = new Node<T>(value);
			if(head == NULL){
				cout<<"first insert\n";
				tail = head = tmp;
			}else{
				tail->next = tmp;
				tail = tmp;
				cout<<"insert\n";
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
				cout<<"index out of range";
				return;
			}
			Node<T> *tmp = new Node<T>(value);
			if(index == 0){
				head = tail = tmp;
			}else if(index == size){
				tail->next = tmp;
				tail = tmp;
			}else{
				Node<T> *ptr = head;
				int i = 0;
				while(i != index-1){
					ptr = ptr->next;
					i++;
				}
				tmp->next = ptr->next;
				ptr->next = tmp;
			}
			size++;
		}
		int getSize(){
			return size;
		}
		void display(){
			cout<<"Linked list data : \n";
			for(Node<T> *ptr = head ; ptr!=NULL ; ptr=ptr->next){
				cout<<ptr->data<<" -> ";
			}
			cout<<endl;
		}
}; 

int main(){
	SingleLinkedList<int> sll;
	sll.insertAtLast(12);
	sll.display();
	sll.insertAtLast(23);
	sll.display();
	sll.insertAtLast(112);
	sll.display();
	sll.insertAtLast(45);
	sll.display();
	cout<<"size = "<<sll.getSize()<<endl;
	sll.insertAtIndex(2,2);
	sll.display();
	cout<<"size = "<<sll.getSize()<<endl;
	sll.insertAtFront(90);
	sll.display();
	cout<<"size = "<<sll.getSize()<<endl;
	return 0;
}
