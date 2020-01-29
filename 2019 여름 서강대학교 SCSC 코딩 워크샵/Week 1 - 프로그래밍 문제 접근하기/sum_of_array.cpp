#include <iostream>
using namespace std;

int main() {
	int N, L;
	cin >> N;
	cin >> L;

	bool flag = false;

	for (int i = L; i * (i - 1) / 2 <= N && i <= 100; i++) {
		int x = N - i * (i - 1) / 2;

		if (x % i != 0) continue;
		if (x < 0) continue;

		flag = true;

		int k = x / i;
		for (int j = k; j < k + i; j++)
			cout << j << ' ';

		break;
	}

	if (flag == false)
		cout << -1;

	return 0;
}