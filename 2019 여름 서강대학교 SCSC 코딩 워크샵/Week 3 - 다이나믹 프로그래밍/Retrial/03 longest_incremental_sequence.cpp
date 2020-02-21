#include <iostream>
#include <algorithm>

int sequence[1001];
int dp[1001];

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, count = 1;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> sequence[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (sequence[i] > sequence[j]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}

	int max = 0;
	for (int i = 0; i <= n; i++) {
		if (dp[i] > max) {
			max = dp[i];
		}
	}

	std::cout << max;
}