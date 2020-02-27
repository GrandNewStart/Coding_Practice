#include <iostream>

int dp[1001][1001];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	dp[0][0] = 1;
	dp[1][0] = dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0 || j == i) {
				dp[i][j] = 1;
			}
			else {
				//nCk = (n-1)Ck + (n-1)C(k-1)
				dp[i][j] = (dp[i - 1][j] % 10007 + dp[i - 1][j - 1] % 10007) % 10007;
			}
		}
	}

	std::cout << dp[n][k];
}