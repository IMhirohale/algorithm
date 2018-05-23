#include <iostream>
#include <cstdio>
using namespace std;

int * shellSort(int *A, int n){
	int gap = n / 2;
	while(gap > 0){
	
		for(int i = 0; i < n; i++){

			for(int j = i; j >= gap; j -= gap){
				
				if(A[j] < A[j-gap]){
					swap(A[j],A[j-gap]);
				}
				
			}
		}
		gap /= 2;
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
	shellSort(arr,n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

