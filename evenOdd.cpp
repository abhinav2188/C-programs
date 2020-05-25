#include <iostream>
using namespace std;

void evenOdd(int arr[],int n, int index){
	if(index>=n)
	return;
	if(arr[index]%2 == 0)
	cout<<arr[index]<<" ";
	evenOdd(arr,n,index+1);
	if(arr[index]%2 !=0)
	cout<<arr[index]<<" ";
}

int main(){
	int a[]= {1,2,3,4,5,6,7,8,9,10};
	evenOdd(a,10,0);
	return 0;
}
