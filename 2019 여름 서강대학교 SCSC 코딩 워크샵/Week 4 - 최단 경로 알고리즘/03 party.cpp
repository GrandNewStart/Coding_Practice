#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using pii = std::pair<int, int>;
std::vector<pii> graph[1001];
int dist[1001];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	int v, e, x;
	std::cin >> v >> e >> x;

	for (int i = 0; i < e; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		graph[x].push_back(pii(y, z));
	}

	int max = 0;

	for (int i = 1; i <= v; i++) {
		std::priority_queue<int, std::vector<int>, std::greater<int>> q;
		int result = 0;

		std::fill(dist, dist + 1001, INT_MAX);
		q.emplace(i);
		dist[i] = 0;

		while (!q.empty()) {
			int current = q.top();
			q.pop();

			for (int j = 0; j < graph[current].size(); j++) {
				int next = graph[current][j].first;
				int cost = graph[current][j].second;

				if (dist[next] > dist[current] + cost) {
					dist[next] = dist[current] + cost;
					q.emplace(next);
				}
			}
		}

		result += dist[x];

		std::fill(dist, dist + 1001, INT_MAX);
		q.emplace(x);
		dist[x] = 0;

		while (!q.empty()) {
			int current = q.top();
			q.pop();

			for (int j = 0; j < graph[current].size(); j++) {
				int next = graph[current][j].first;
				int cost = graph[current][j].second;

				if (dist[next] > dist[current] + cost) {
					dist[next] = dist[current] + cost;
					q.emplace(next);
				}
			}
		}

		result += dist[i];

		if (max < result) max = result;
	}
	
	std::cout << max;
}