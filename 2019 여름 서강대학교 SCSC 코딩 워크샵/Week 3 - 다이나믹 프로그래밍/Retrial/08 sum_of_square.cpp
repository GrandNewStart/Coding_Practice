#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 100000

int dp[100001];

int main() {
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::fill(dp, dp + MAX + 1, MAX);

	for (int i = 1; i <= n; i++) {
		long long t = (long long)i * i;

		if (t <= n) dp[t] = 1;

		for (int j = 1; j <= t; j++) {
			if (dp[i] == 1) break;

			if (j * j >= i) break;
			
			dp[i] = std::min(dp[i], dp[i - (j * j)] + 1);
		}
	}

	std::cout << dp[n];
}