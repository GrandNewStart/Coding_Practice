#include <iostream>

using pii = std::pair<int, int>;

int sequence[1001];
pii dp[1001];

pii SQ(int n) {
	if (dp[n].first == 0) {
		if (SQ(n - 1).second < sequence[n]) {
			dp[n] = pii(SQ(n - 1).first + 1, sequence[n]);
		}
		else {
			dp[n] = SQ(n - 1);
		}
	}

	return dp[n];
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, count = 1;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> sequence[i];
	}

	dp[1] = pii(1, sequence[1]);

	std::cout << SQ(n).first;
}