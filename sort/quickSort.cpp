#include <iostream>
#include <cstdio>
using namespace std;

int partion(int * A, int low, int high){
	int k = low;
	for(int i = low; i < high; i++){
		if(A[i] < A[high]){
			swap(A[i],A[k]);
			k++;
		}
	}
	swap(A[k],A[high]);
	return k;
}

//递归调用快速排序
void sort(int *A, int low, int high){
	if(low < high){
		int t = partion(A,low,high);
		sort(A,low,t-1);
		sort(A,t+1,high);
	}
}


//Fcuntion quick sort
int * quickSort(int *A ,int n){
	sort(A,0,n-1);
	return A;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main(){

	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, n);
	quickSort(arr,n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

