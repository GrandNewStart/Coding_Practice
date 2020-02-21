#include <iostream>
#include <cstring>

int coin[101];
int dp[10001];

int main() {
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	int coins, target;
	std::cin >> coins >> target;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= coins; i++) {
		std::cin >> coin[i];
		dp[coin[i]] = 1;
	}

	for (int i = 1; i <= coins; i++) {
		int t = coin[i];
		for (int j = 1; j <= target; j++) {
			dp[j] += dp[j - t];
		}
	}

	std::cout << dp[target] << "\n";
}