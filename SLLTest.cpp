#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	
	SingleLinkedList<float> sll;

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

