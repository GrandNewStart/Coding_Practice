#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];
int d[1000];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		d[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] >= A[i]) continue;
			d[i] = max(d[i], d[j] + 1);
		}
	}

	int mx = 0;
	for (int i = 0; i < N; i++) {
		mx = max(d[i], mx);
	}

	cout << mx;

	return 0;
}