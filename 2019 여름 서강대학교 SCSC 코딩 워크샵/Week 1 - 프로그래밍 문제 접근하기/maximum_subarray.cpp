#include <iostream>
using namespace std;

int main() {
	int T, N, max, sum = 0;
	int arr[1000];
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> arr[j];

		max = arr[0];

		for (int l = 0; l < N; l++) {
			for (int m = 0; m < N - l; m++) {
				for (int n = m; n < m + l + 1; n++)
					sum += arr[n];
				if (sum > max) max = sum;
				sum = 0;
			}
		}
	
		cout << max << endl;
	}


	return 0;
}