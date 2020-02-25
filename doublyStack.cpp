//implementing two stacks using array in C++

#include <iostream>

using namespace std;

class DoublyStack{
    int size;
    int *arr;
    int sp1;
    int sp2;
    
    public :
    DoublyStack(int s){
        cout<<"constructor";
        size = s;
        arr  = new int[s];
        sp1 = -1;
        sp2 = size;
    }
    void display(){
        cout<<"\nStack1 ";
        for(int i=sp1;i>=0;i--)
        cout<<arr[i]<<" ";
        cout<<"\nStack2 ";
        for(int i=sp2;i<=size-1;i++)
        cout<<arr[i]<<" ";
    }
    bool isFull(){
        return sp1==sp2-1;
    }
    bool isEmpty(){
        return (sp1==0 && sp2==size-1);
    }
    void push1(int el){
        if(!isFull()){
        arr[++sp1] = el;
            cout<<"\npushed to stack1 "<<el;
        }
        else
        cout<<"\nStack Overflow";
    }
    void push2(int el){
        if(!isFull()){
            arr[--sp2] = el;
            cout<<"\npushed to stack2 "<<el;
        }
        else
        cout<<"\nStack Overflow";
    }
    int pop1(){
        if(!isEmpty()){
        return arr[sp1--]; 
        }else{
         cout<<"\nStack empty";
         return 0;
        }
    }
    int pop2(){
        if(!isEmpty()){
        return arr[sp2++];
        }else{
         cout<<"\nStack empty";
         return 0;
        }
    }
};

int main()
{
   DoublyStack ds(10);
   ds.push1(12);
   ds.push1(34);
   ds.push2(111);
   ds.push1(34);
   ds.push1(98);
   ds.push2(11);
   ds.push1(100);
   ds.push1(341);
   ds.push1(1232);
   ds.push1(34111);
   ds.push2(111);
   ds.push2(1112);   
   cout<<endl<<ds.pop1();
   cout<<endl<<ds.pop2();
   cout<<endl<<ds.pop1();
   ds.push2(2);
   ds.isFull();
   ds.display();
   
   return 0;
}
