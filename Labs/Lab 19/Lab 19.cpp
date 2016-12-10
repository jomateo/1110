#include <iostream>
using namespace std;

void selectionSort (int[], int);

int main () {
	int sort[] = {12, 56, 34, 78, 32, 13, 79, 90, 23, 43},
		numelts = 10;
	
	cout << "This is the unsorted array:\n";
	for (int i = 0; i < numelts; i++) {
		cout << sort[i] << ' ';
	}
	
	selectionSort(sort, numelts);
	
	cout << "\nThis is the sorted array:\n";
	for (int i = 0; i < numelts; i++) {
		cout << sort[i] << ' ';
	}
	
	cout << endl;
	return 0;
}

void selectionSort (int arr[], int n) {
	int temp;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}