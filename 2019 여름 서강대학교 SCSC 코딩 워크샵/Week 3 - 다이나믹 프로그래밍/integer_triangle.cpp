#include <iostream>
using namespace std;

int t[500][500];
int T[500][500];

int max_sum(int x, int y) {
	if (T[x][y]) return T[x][y];
	if (x == 0 && y == 0) return T[0][0] = t[0][0];
	if (x == 1 && y == 0) return T[1][0] = max_sum(0, 0) + t[1][0];
	if (x == 1 && y == 1) return T[1][1] = max_sum(0, 0) + t[1][1];
	
	if (y == 0) return T[x][y] = max_sum(x - 1, 0) + t[x][0];
	if (x == y) return T[x][y] = max_sum(x - 1, y - 1) + t[x][y];
	
	int tmp1 = max_sum(x - 1, y - 1) + t[x][y];
	int tmp2 = max_sum(x - 1, y) + t[x][y];
	
	if (tmp1 > tmp2)
		T[x][y] = tmp1;
	else
		T[x][y] = tmp2;

	return T[x][y];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> t[i][j];
		}
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		if (max > max_sum(n - 1, i)) continue;
		max = max_sum(n - 1, i);
	}

	cout << max;

	return 0;
}