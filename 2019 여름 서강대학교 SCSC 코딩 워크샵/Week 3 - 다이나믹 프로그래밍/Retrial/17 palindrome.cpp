#include <iostream>
#include <cstring>

int arr[2001];
short dp[2001][2001];

short palinedrome(int s, int e) {
	if (dp[s][e] != -1) return dp[s][e];
	if (s == e) return dp[s][e] = 1;

	for (int i = 0; i <= (e - s) / 2; i++) {
		if (arr[s + i] == arr[e - i]) continue;
		else return dp[s][e] = 0;
	}

	return dp[s][e] = 1;
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}

	int M;
	std::cin >> M;

	memset(dp, -1, sizeof(dp));

	while (M--) {
		int S, E;
		std::cin >> S >> E;
		std::cout << palinedrome(S, E) << "\n";
	}
}