#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int sticker[2][100000];
int dp[3][100000];

int main() {
	int T;
	cin >> T;

	while (T--) {
		memset(sticker, 0, sizeof(sticker));
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
			}
		}

		dp[0][0] = 0;
		dp[1][0] = sticker[0][0];
		dp[2][0] = sticker[1][0];

		for (int i = 0; i < n; i++) {
			dp[0][i] = max({ dp[0][i - 1], dp[1][i - 1], dp[2][i - 1] });
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + sticker[0][i];
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + sticker[1][i];
		}

		cout << max({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] }) << '\n';
	}

	return 0;
}