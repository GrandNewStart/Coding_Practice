#include <iostream>
#include <cstring>

long long dp[101];

long long sequence(int input) {
	if (input == 1) return dp[1] = 1;
	if (input == 2) return dp[2] = 1;
	if (input == 3) return dp[3] = 1;
	if (input == 4) return dp[4] = 2;
	if (input == 5) return dp[5] = 2;

	if (dp[input]) return dp[input];

	return dp[input] = sequence(input - 5) + sequence(input - 1);
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int testcase;
	std::cin >> testcase;

	while (testcase--) {
		int input;
		std::cin >> input;
		std::cout << sequence(input) << "\n";
		memset(dp, 0, sizeof(dp));
	}

	return 0;
}