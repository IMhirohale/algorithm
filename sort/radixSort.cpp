#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int * radixSort(int *A, int n){
	
	//申请10个桶，每一个桶就是一个容器
	vector<int> bucket[10];

	for(int p = 1; p <= 100; p *= 10){
		
		//每进行一次运算前，清空桶
		for(int i = 0; i < 10; i++){
			bucket[i].clear();
		}

		//运行进行入桶
		for(int i = 0; i < n; i++){
			int num = (A[i] / p) % 10;
			bucket[num].push_back(A[i]);
		}

		int k = 0;
		for(int i = 0; i < 10; i++){

			for(int j = 0; j < bucket[i].size(); j++){
				A[k++] = bucket[i][j];	
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
	radixSort(arr,n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

