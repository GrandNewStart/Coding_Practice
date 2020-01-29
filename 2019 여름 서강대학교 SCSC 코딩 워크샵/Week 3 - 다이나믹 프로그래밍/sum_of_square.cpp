#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long square(int n) {
	return n * n;
}

long long dp[100001] = {0, 1};

int main() {
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		long long temp = LLONG_MAX;
		for (int j = 1; j < i; j++) {
			if (i < square(j)) break;
			
			temp = min(temp, dp[i - square(j)]);
		}
		dp[i] = temp + 1;
	}

	cout << dp[n];

	return 0;
}