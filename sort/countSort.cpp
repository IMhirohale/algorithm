#include <iostream>
#include <cstdio>
using namespace std;

int * countSort(int *A, int n){

	int *bucket = new int[100];	
	int temp = 0;
	
	//初始化桶
	for(int i = 0; i < 100; i++){
		bucket[i] = 0;
	}
	
	//装桶
	for(int i = 0; i < n; i++){
		bucket[A[i]]++;
	}
	
	//倒桶
	for(int i = 0; i < 100; i++){
		if(bucket[i] != 0){
			for(int j = 0; j < bucket[i]; j++){
				A[temp++] = i;
			}
		}	
	}

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
	countSort(arr,n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

