#include <iostream>
#include <cstdio>
using namespace std;

//Function to swap two number value
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
int * bubbleSort (int *A, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(A[j] > A[j+1]){
				int temp;
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
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
	cout << n << endl;
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}



