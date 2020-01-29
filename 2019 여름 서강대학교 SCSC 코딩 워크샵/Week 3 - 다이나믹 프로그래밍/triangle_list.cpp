#include <iostream>
#include <cstring>
using namespace std;
//D[i] = i번째 삼각형이 있을 때 가장 긴 변 길이
long long D[101];

long long P(int n) {
	if (n == 1) return D[1] = 1;
	if (n == 2) return D[2] = 1;
	if (n == 3) return D[3] = 1;
	if (n == 4) return D[4] = 2;
	if (n == 5) return D[5] = 2;

	if (D[n]) return D[n];

	D[n] = P(n - 1) + P(n - 5);
	return D[n];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		cout << P(N) << '\n';
		memset(D, 0, sizeof(D));
	}

	return 0;
}