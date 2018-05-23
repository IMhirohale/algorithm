#include <iostream>
#include <cstdio>
using namespace std;

//Fcuntion to insert sort
int * insertSort(int *A ,int n){
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0; j--){
			if(A[j] < A[j-1]){
				swap(A[j],A[j-1]);
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
	insertSort(arr,n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

