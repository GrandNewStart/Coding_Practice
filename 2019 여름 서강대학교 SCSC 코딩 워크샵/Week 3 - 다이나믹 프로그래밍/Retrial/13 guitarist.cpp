#include <iostream>
#include <algorithm>

bool dp[101][1002];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int N, S, M;
	std::cin >> N >> S >> M;

	dp[0][S] = true;

	for (int i = 1; i <= N; i++) {
		int input;
		std::cin >> input;

		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {
				if (j + input <= M) {
					dp[i][j + input] = true;
				}
				if (j - input >= 0) {
					dp[i][j - input] = true;
				}
			}
		}
	}

	int max = -1;

	for (int i = 0; i <= M; i++) {
		if (dp[N][i]) {
			max = i;
		}
	}

	std::cout << max;
}