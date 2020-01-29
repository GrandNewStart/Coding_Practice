#include <iostream>
using namespace std;

int main() {
	int N, M, sum = 0, max = 0;
	cin >> N;
	cin >> M;
	int* card = new int[N];
	for (int i = 0; i < N; i++)
		cin >> card[i];

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum += card[i] + card[j] + card[k];
				if (sum > max && sum <= M) max = sum;
				sum = 0;
			}
		}
	}

	cout << max;

	return 0;
}