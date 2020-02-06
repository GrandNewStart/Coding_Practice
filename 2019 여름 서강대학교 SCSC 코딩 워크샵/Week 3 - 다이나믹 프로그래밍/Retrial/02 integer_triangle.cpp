#include <iostream>

int triangle[500][500] = { 0 };
int dp[500][501] = { 0 };

int MaxSum(int n) {
	if (dp[n][n + 1] == 0) {
		dp[n][0] = dp[n - 1][0] + triangle[n][0];
		dp[n][n] = dp[n - 1][n - 1] + triangle[n][n];

		int max;
		(dp[n][0] > dp[n][n]) ? max = dp[n][0] : max = dp[n][n];

		for (int i = 1; i < n; i++) {
			int L = dp[n - 1][i - 1] + triangle[n][i];
			int R = dp[n - 1][i] + triangle[n][i];

			(L > R) ? dp[n][i] = L : dp[n][i] = R;

			if (dp[n][i] > max) {
				max = dp[n][i];
			}
		}

		dp[n][n + 1] = max;
	}

	return dp[n][n + 1];
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			std::cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];
	dp[0][1] = triangle[0][0];

	dp[1][0] = triangle[0][0] + triangle[1][0];
	dp[1][1] = triangle[0][0] + triangle[1][1];
	(dp[1][0] > dp[1][1]) ? dp[1][2] = dp[1][0] : dp[1][2] = dp[1][1];

	for (int i = 2; i < n; i++) {
		dp[i][i + 1] = MaxSum(i);
	}

	std::cout << dp[n - 1][n];
}