#include <iostream>
using namespace std;

void MergeSort(int* arr, int start, int end) {

	if (end > start) {
		int mid, k = 0, m = 0, s = 0, size;
		mid = (end + start) / 2;
		size = end - start + 1;
		int* merge = new int[size];
		
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		
		while (start + s <= mid && mid + 1 + m <= end) {
			if (arr[start + s] < arr[mid + 1 + m])
				merge[k++] = arr[start + s++];
			else
				merge[k++] = arr[mid + 1 + m++];
		}

		while (start + s <= mid)
			merge[k++] = arr[start + s++];
		while (mid + 1 + m <= end)
			merge[k++] = arr[mid + 1 + m++];

		for (int i = start; i < end + 1; i++)
			arr[i] = merge[i];
	}
}

int main() {
	int N;

	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	MergeSort(arr, 0, N-1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}