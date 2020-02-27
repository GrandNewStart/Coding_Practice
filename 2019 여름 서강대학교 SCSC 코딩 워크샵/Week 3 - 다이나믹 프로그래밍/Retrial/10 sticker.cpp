#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int dp[3][100001];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int testcase, n;
	std::cin >> testcase;

	while (testcase--) {
		std::cin >> n;
		std::vector<int> sticker[2];

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				int input;
				std::cin >> input;
				sticker[i].push_back(input);
			}
		}

		dp[0][0] = 0;
		dp[1][0] = sticker[0][0];
		dp[2][0] = sticker[1][0];

		for (int i = 1; i < n; i++) {
			dp[0][i] = std::max({ dp[0][i - 1],dp[1][i - 1],dp[2][i - 1] });
			dp[1][i] = std::max(dp[0][i - 1], dp[2][i - 1]) + sticker[0][i];
			dp[2][i] = std::max(dp[0][i - 1], dp[1][i - 1]) + sticker[1][i];
		}

		std::cout << std::max({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] }) << "\n";

		memset(dp, 0, sizeof(dp));
	}
}