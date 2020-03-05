#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using pii = std::pair<int, int>;
std::vector<pii> graph[1001];
int dist[1001];

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	std::fill(dist, dist + 1001, INT_MAX);

	int v;
	std::cin >> v;

	int e;
	std::cin >> e;

	for (int i = 0; i < e; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		graph[x].push_back(pii(y, z));
	}

	int start, end;
	std::cin >> start >> end;

	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	q.emplace(start);
	dist[start] = 0;

	while (!q.empty()) {
		int current = q.top();
		q.pop();

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first;
			int cost = graph[current][i].second;

			if (dist[next] > dist[current] + cost) {
				dist[next] = dist[current] + cost;
				q.emplace(next);
			}
		}
	}

	std::cout << dist[end];
}