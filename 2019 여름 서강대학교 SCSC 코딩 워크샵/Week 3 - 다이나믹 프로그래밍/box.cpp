#include <iostream>
#include <algorithm>
using namespace std;

int box[1000];
int dp[1000];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> box[i];
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[i] <= box[j]) continue;
			dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, dp[i]);
	}

	cout << mx;

	return 0;
}