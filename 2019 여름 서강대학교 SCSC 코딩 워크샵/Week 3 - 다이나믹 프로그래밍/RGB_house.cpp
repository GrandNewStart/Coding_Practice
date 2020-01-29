#include <iostream>
using namespace std;

void mySwap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main() {
	int list[100000];
	int N; //1 ~ 1,000,000
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> list[i];
		int temp = list[i];

		for (int index = i - 1; index >= 0; index--) {
			if (list[index] > temp) {
				mySwap(list, index, index + 1);
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << list[i] << endl;
}
