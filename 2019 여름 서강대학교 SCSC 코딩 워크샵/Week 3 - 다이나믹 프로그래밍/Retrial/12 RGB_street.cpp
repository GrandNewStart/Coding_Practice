#include <iostream>
#include <algorithm>

int cost[1000][3];
int dp[1000][3];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int houses;
	std::cin >> houses;

	for (int i = 0; i < houses; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> cost[i][j];
		}
	}
	
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int i = 0; i < houses; i++) {
		dp[i][0] = std::min(dp[i - 1][1] + cost[i][0], dp[i - 1][2] + cost[i][0]);
		dp[i][1] = std::min(dp[i - 1][0] + cost[i][1], dp[i - 1][2] + cost[i][1]);
		dp[i][2] = std::min(dp[i - 1][0] + cost[i][2], dp[i - 1][1] + cost[i][2]);
	}

	std::cout << std::min({ dp[houses - 1][0],dp[houses - 1][1],dp[houses - 1][2] });
}