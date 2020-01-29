#include <iostream>
using namespace std;
using ll = long long;
ll tile[1001];

ll tiling(int x) {
	if (tile[x]) return tile[x];
	if (x == 1) return tile[x] = 1;
	if (x == 2) return tile[x] = 3;

	return tile[x] = (tiling(x - 1) + 2 * tiling(x - 2)) % 10007;
}

int main() {
	int n;
	cin >> n;
	cout << tiling(n);

	return 0;
}