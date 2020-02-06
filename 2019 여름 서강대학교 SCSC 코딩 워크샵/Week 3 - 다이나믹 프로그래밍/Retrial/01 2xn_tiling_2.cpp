#include <iostream>

int dp[1001] = { 0 };

int tiling(int n) {
	if (dp[n] == 0) {
		dp[n] = (tiling(n - 1) + 2 * tiling(n - 2)) % 10007;
	}

	return dp[n];
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	dp[1] = 1;
	dp[2] = 3;

	int n, i = 2;
	std::cin >> n;

	if (n == 1 || n == 2) {
		std::cout << dp[n];
	}
	else {
		std::cout << tiling(n);
	}
}