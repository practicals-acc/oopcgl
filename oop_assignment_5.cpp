#include <iostream>
using namespace std;

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		T temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}

	// Output the sorted array
	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	// Integer array
	int intArr[] = {64, 25, 12, 22, 11};
	int intSize = sizeof(intArr) / sizeof(intArr[0]);
	cout << "Sorting integer array:" << endl;
	selectionSort(intArr, intSize);

	// Float array
	float floatArr[] = {64.5, 25.2, 12.7, 22.8, 11.1};
	int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
	cout << "Sorting float array:" << endl;
	selectionSort(floatArr, floatSize);

	return 0;
}
