#include <iostream>
using namespace std;

int c[101];
int D[10001];

int coins(int n, int k) {
	if (k == c[1]) return D[k] = 1;
	if (D[k]) return D[k];

	for (int i = 1; i <= n; i++) {
		if (k < c[k]) continue;
		
		D[k] += coins(n, k - c[i]);
	}

	if (k % 2 == 0) D[k] = (D[k] + 1) / 2; 
	else D[k] /= 2;

	return D[k];
}

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	cout << coins(n, k);

	return 0;
}