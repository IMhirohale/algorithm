#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool isRotation(string str1, string str2){

	
	if(str1 == "" || str2 == "" || str1.size() != str2.size()){

		return false;
	}
	
	string str;
	str = str2 + str2;

	if(str.find(str1) == str.npos){

		return false;
	}

	return true;	
}

int main(){

	string str1;
	string str2;
	getline(cin, str1);  
	getline(cin, str2);  

	bool res = isRotation(str1,str2) ? 1: 0;

	cout << res << endl;


	return 0;
}
