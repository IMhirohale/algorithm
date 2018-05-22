#include <iostream>
#include <cstdio>
using namespace std;

//Fcuntion to select minIndex to swap
int * selectSort(int *A ,int n){
	for(int i = 0; i < n; i++){
		int minIndex = i;
		for(int j = i + 1; j < n; j++){
			if(A[j] < A[minIndex]){
				minIndex = j;
			}
		}
		swap(A[i],A[minIndex]);
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
	selectSort(arr,n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

