#include <iostream>
using namespace std;

int main() {
	int N, x = 0, y = 0, min;
	bool possible = 0;
	cin >> N;
	min = N / 3 + 1;

	while (true) {
		if (3 * x + 5 * y == N) {
			possible = 1;
			if (x + y < min) min = x + y;
		}
		x++;
		if (3 * x + 5 * y > N) {
			x = 0;
			y++;
			if (3 * x + 5 * y > N) break;
		}
	}

	if (possible) cout << min;
	else cout << -1;

	return 0;
}