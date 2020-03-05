#include <iostream>
#include <algorithm>

#define MAX 100000 * 101

long long dp[101][101];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	std::fill(&dp[0][0], &dp[100][100], MAX);

	int v, e;
	std::cin >> v >> e;

	for (int i = 1; i <= e; i++) {
		long long x, y, z;
		std::cin >> x >> y >> z;

		dp[x][y] = std::min(dp[x][y], z);
		if (i <= v) dp[i][i] = 0;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (dp[i][j] == MAX) dp[i][j] = 0;
			std::cout << dp[i][j] << " ";
		}
		std::cout << "\n";
	}
}