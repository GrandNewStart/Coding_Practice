#include <iostream>

int dp[11];

int SumofOneTwoThree(int n) {
	if (n == 1) return dp[1] = 1;
	if (n == 2) return dp[2] = 2;
	if (n == 3) return dp[3] = 4;

	if (dp[n]) return dp[n];

	return dp[n] = SumofOneTwoThree(n-1) + SumofOneTwoThree(n-2) + SumofOneTwoThree(n-3);
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int testcase;
	std::cin >> testcase;

	while (testcase--) {
		int n;
		std::cin >> n;
		std::cout << SumofOneTwoThree(n) << "\n";
	}
}