#include <iostream>
#include <queue>
using namespace std;

int dist[100001];

int main() {
	int n, k;
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}

	queue<int> q;
	q.emplace(n);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		int next[3] = {x - 1, x + 1, 2 * x};
		for (int i = 0; i < 3; i++) {
			int nx = next[i];

			if (nx < 0 || nx > 100000) continue;
			if (dist[nx] > 0 || nx == n) continue;

			dist[nx] = dist[x] + 1;
			q.emplace(nx);
		}

		if (dist[k] > 0) {
			cout << dist[k];
			break;
		}
	}
	
	return 0;
}