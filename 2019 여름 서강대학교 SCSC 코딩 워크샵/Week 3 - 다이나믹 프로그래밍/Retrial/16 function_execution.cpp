#include <iostream>

long long abc[21][21][21];

long long w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;

	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

	if (abc[a][b][c]) return abc[a][b][c];

	if (a < b && b < c) return abc[a][b][c] = w(a, b, c - 1) - w(a, b - 1, c) + w(a, b - 1, c - 1);

	return abc[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int a, b, c;

	while (true) {
		std::cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) break;

		std::cout << "w(" << a << ", " << b << ", " << c << ") = ";
		std::cout << w(a, b, c) << "\n";
	}
}