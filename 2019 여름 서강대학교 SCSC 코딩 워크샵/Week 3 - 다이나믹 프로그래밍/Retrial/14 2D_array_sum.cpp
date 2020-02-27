#include <iostream>

int arr[301][301];
int dp[301][301];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	std::fill(&dp[0][0], &dp[301][301], 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}

	int K;
	std::cin >> K;

	for (int n = 0; n < K; n++) {
		int i, j, x, y;
		std::cin >> i >> j >> x >> y;

		std::cout << dp[x][y] + dp[i - 1][j - 1] - dp[x][j - 1] - dp[i - 1][y] << "\n";
	}
}