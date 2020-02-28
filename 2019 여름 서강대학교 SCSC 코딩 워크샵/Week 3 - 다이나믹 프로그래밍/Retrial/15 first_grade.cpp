#include <iostream>

long long dp[21][100];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int x;
		std::cin >> x;

		if (i == 0) {
			dp[x][i] = 1;
			continue;
		}

		for (int j = 0; j <= 20; j++) {
			int u = j + x;
			int v = j - x;

			if (u >= 0 && u <= 20) {
				dp[u][i] += dp[j][i - 1];
			}
			if (v >= 0 && v <= 20) {
				dp[v][i] += dp[j][i - 1];
			}
		}
	}

	int s;
	std::cin >> s;
	std::cout << dp[s][N - 2];
}