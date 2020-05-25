#include <iostream>
using namespace std;

void evenOdd(string str,int n,int index){
	if(index>=n)
	return;
	evenOdd(str,n,index+1);
	cout<<str[index];
}

int main(){
	string s = "abhinav rastogi";
	evenOdd(s,s.length(),0);
	return 0;
}
