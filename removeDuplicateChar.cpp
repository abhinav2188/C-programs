#include <iostream>
#include <conio.h>
using namespace std;

string removeDuplicates(string str){
	string res = "";
	for(int i=0;i<str.length();i++){
		bool contains = false;
		for(int j=0;j<res.length();j++){
			if(res[j]==str[i]){
				contains = true;
				break;
			}
		}
		if(!contains)
		res = res + str[i];
	}
	return res;
}
int main(){
	string str;
	cout<<"Enter a string ";
	cin>>str;
//	cout<<str;
//	str = "missisippi";
	string updateStr = removeDuplicates(str);
	cout<<"After removing duplicate characters "<<updateStr;
	return 0;
}
