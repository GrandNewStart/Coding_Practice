#include <iostream>
#include <queue>

int dist[100001] = { 0 };

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int subin, little, count = 1;
	std::cin >> subin >> little;

	if (subin == little) {
		std::cout << 0;
		return 0;
	}

	std::queue<int> q;
	q.emplace(subin);

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		int next[3] = { front - 1, front + 1, front * 2 };
		for (int i = 0; i < 3; i++) {
			int nx = next[i];

			if (nx >= 0 && nx < 100001 &&
				dist[nx] == 0 && dist[nx] != subin) {

				dist[nx] = dist[front] + 1;
				q.emplace(nx);
			}
		}

		if (dist[little] > 0) {
			std::cout << dist[little] << "\n";
			break;
		}
	}
}