#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits> 

using namespace std;


//判断字符串的合法性
bool isValid(char chas[]){

	if(chas[0] != '-' && (chas[0] < '0' || chas[0] > '9')){

		return false;	
	}

	if(chas[0] == '-' && (strlen(chas) == 1 || chas[1] == '0')){

		return false;
	}

	if(chas[0] == '0' && strlen(chas) > 1){

		return false;
	}

	for(int i = 1; i < strlen(chas); i++){

		if(chas[i] < '0' || chas[i] > '9'){

			return false;
		}
	}

	return true;

}

//将整数字符串转化成整数值
int strToInt(string str){

	if(str == "" || str.size() == 0)
		return 0;

	char chas[12]; //至少需要12位，这里需要注意一下 -2147483648(12) 2147483647(10)
	strncpy(chas,str.c_str(),str.size());
	
	if(!isValid(chas)){ //不合法则返回0
		return 0;
	}

	bool posi = chas[0] == '-' ? false : true;
	int MININT = numeric_limits<int>::min();
	int minq = MININT / 10;
	int minr = MININT % 10;

	int res = 0;
	int cur = 0;

	for(int i = posi ? 0 :1; i < strlen(chas); i++){

		cur = '0' - chas[i];

		if(res < minq || (res == minq && cur < minr)){
			return 0;
		}

		res = res * 10 + cur;

	}

	if(posi && res == MININT){
		return 0;
	}

	return posi ? -res : res; //都是以负数存储的，所以，这里最后需要加-
 	
}


int main(){

	string str;
	getline(cin,str);
	cout << strToInt(str) << endl;
	return 0;
}
