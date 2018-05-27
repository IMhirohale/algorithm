#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//非递归实现
int binarySearch(int *arr, int x,int n){
	
	if(n == 0)
		return -1;

	if(n == 1)
		return arr[0];

	int left = 0;
	int right = n - 1;
	int mid;

	while(left <= right){

		mid = left + (right - left) / 2;

		if(arr[mid] == x){

			return mid;

		}else if(arr[mid] < x){

			left = mid + 1;

		}else{
			right = mid - 1;
		}
	}
	
	return -1;
}


//递归实现
int binarySearchRecursive(int *arr, int left, int right, int val){

	if(left > right)
		return -1;

	int mid = left + (right - left) / 2;

	if(arr[mid] == val){
		return mid;
	}

	if(arr[mid] > val){
		return binarySearchRecursive(arr,left,mid-1,val);
	}
	
	if(arr[mid] < val){
		return binarySearchRecursive(arr,mid+1,right,val);
	}
	
	return -1;
}

//二分的简单运用
//假定最小值在是数组最后一个元素
int getMin(int *arr, int n){

	if(n == 0) return -1;

	if(n == 1) return arr[0];

	int left = 0;
	int right = n - 1;
	int mid;

	while(left < right){
		
		mid = left + (right - left) / 2;

		if(arr[mid] >= arr[right])
			left = mid + 1;
		else
			right = mid;
	}

	return arr[right];
	
}

//使用二分记住一点：必须有序。
int main(){

	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x;
	cout << "请输入要查找的x的值：" << endl;
	scanf("%d",&x);
	cout << "要查找x值的下标为：" << endl;
	cout << binarySearch(arr,x,n) << endl;
	cout << binarySearchRecursive(arr,0,n-1,x) << endl;
	cout << getMin(arr,n) << endl;

	return 0;
}
