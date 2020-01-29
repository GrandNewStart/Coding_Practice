#include <iostream>
using namespace std;

//이항 계수의 성질 n C k + n C k+1 = n+1 C k+1
//% 연산의 성질 (a + b) % m = (a % m + b % m) % m

int dp[1001][1001];

int main() {
	int N, K;
	cin >> N >> K;

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		dp[i + 1][0] = 1;
		for (int j = 0; j < K; j++) {
			dp[i + 1][j + 1] = (dp[i][j] + dp[i][j + 1]) % 10007;
		}
	}

	cout << dp[N][K];

	return 0;
}