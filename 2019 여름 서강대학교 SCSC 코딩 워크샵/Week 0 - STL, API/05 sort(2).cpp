#include <iostream>
using namespace std;

void MergeSort(int[], int, int);
void Merge(int[], int, int, int);
int temp[100000];

int main() {
	int list[100000];
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];

	MergeSort(list, 0, N - 1);

	for (int i = 0; i < N; i++)
		cout << list[i] << "\n";
}

void MergeSort(int arr[], int start, int end) {
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid);
	MergeSort(arr, mid + 1, end);
	Merge(arr, start, mid, end);
}

void Merge(int arr[], int start, int mid, int end) {
	int i = start, j = mid + 1, k = end;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	for (int a = start; a <= end; a++)
		arr[a] = temp[a];
}