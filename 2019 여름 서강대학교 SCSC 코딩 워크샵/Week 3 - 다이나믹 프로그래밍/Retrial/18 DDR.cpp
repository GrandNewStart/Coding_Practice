#include <iostream>

using pii = std::pair<int, int>;

pii step = pii(0, 0);
int dp[100000];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	int input;
	int i = 1;
	bool change = true;

	std::cin >> input;
	dp[i] = input;
	step.first = input;

	while (true) {
		i++;
		std::cin >> input;

		if (!input) break;

		if (input == step.first || input == step.second) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = dp[i - 1] + input;

			if (change) {
				step.first = input;
				change = false;
			}
			else {
				step.second = input;
				change = true;
			}
		}
	}

	std::cout << dp[i - 1];
}