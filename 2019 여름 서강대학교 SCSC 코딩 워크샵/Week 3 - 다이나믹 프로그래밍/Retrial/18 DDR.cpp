#include <iostream>
#include <algorithm>
#define MAX 98765432

int arr[100000], dp[100001][5][5];
int move[5][5] = {
	{0,2,2,2,2},
	{0,1,3,4,3},
	{0,3,1,3,4},
	{0,4,3,1,3},
	{0,3,4,3,1}
};

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	int n = 0;
		
	std::fill(&dp[0][0][0], &dp[100000][4][4], MAX);
	dp[0][0][0] = 0;

	while (true) {
		std::cin >> arr[n++];
		if (!arr[n - 1]) break;
	}

	for (int i = 0; i < n; i++) {
		int input = arr[i];

		for (int r = 0; r < 5; r++) {
			for (int l = 0; l < 5; l++) {
				if (input != r) dp[i + 1][r][input] = std::min(dp[i + 1][r][input], dp[i][r][l] + move[l][input]);
				if (input != l) dp[i + 1][input][l] = std::min(dp[i + 1][input][l], dp[i][r][l] + move[r][input]);
			}
		}
	}

	int min = MAX;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			min = std::min(min, dp[n][i][j]);
		}
	}

	std::cout << min;
}