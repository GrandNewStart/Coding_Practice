#include <iostream>
using namespace std;

int D[11];

int test(int n) {
	if (n == 1) return D[1] = 1;
	if (n == 2) return D[2] = 2;
	if (n == 3) return D[3] = 4;
	if (D[n]) return D[n];

	return D[n] = test(n - 3) + test(n - 2) + test(n - 1);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << test(n) << '\n';
	}

	return 0;
}