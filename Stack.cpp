//implementing stack using array in C++

#include <iostream>

using namespace std;

template <class T>
class Stack{
    int size;
    T *arr;
    int top;
    
    public :
	Stack(int s){
        cout<<"Stack created with size "<<s<<endl;
        size = s;
        arr  = new T[s];
        top = -1;
    }
    void display(){
        if(isEmpty()){
            cout<<"\nEmpty Stack\n";
            return;
        }
        cout<<"\nStack ";
        for(int i=top;i>=0;i--)
        cout<<arr[i]<<" ";
        cout<<endl;
     }
    bool isFull(){
    	return top==size-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(T el){
        if(!isFull()){
        arr[++top] = el;
            cout<<el<<" pushed to stack\n";
        }
        else
        cout<<"Stack Overflow\n";
    }
    void pop(){
        if(!isEmpty()){
            T el = arr[top];
            cout<<el<<" popped from stack\n";
            top--; 
        }else{
         cout<<"Stack empty\n";
        }
    }
    int getTop(){
        return arr[top];
    }
};

int main()
{
	Stack<int> s(10);
   	s.push(12);
   s.push(34);
   s.push(111);
   s.push(34);
   s.push(98);
   s.push(11);
   s.push(100);
   s.push(341);
   s.push(1232);
   s.push(34111);
   s.push(111);
   s.push(1112);   
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.pop();
   s.push(2);
   s.pop();
   s.pop();
   s.pop();
   cout<<s.isFull();
   s.display();
   
   return 0;
}
