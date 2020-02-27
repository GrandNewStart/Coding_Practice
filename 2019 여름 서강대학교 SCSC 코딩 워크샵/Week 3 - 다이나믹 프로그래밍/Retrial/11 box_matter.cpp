#include <iostream>
#include <algorithm>

int box[1001];
int dp[1001];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, max;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> box[i];
		dp[i] = 1;
	}

	max = dp[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (box[i] > box[j]) {
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
		max = std::max(max, dp[i]);
	}

	std::cout << max;
}