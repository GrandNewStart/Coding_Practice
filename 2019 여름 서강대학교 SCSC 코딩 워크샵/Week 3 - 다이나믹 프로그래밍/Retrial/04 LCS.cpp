#include <iostream>
#include <algorithm>

std::string s1, s2;
int dp[1000][1000];

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	std::cin >> s1 >> s2;
	int len_s1 = (int)s1.size();
	int len_s2 = (int)s2.size();

	for (int i = 0; i < len_s1; i++) {
		for (int j = 0; j < len_s2; j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = std::max({dp[i + 1][j], dp[i][j + 1], dp[i][j] + 1});
			}
			else {
				dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	std::cout << dp[len_s1][len_s2];
}