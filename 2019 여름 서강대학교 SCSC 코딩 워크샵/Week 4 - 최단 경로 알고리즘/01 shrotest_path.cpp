#include <iostream>
#include <queue>
#include <vector>

using pii = std::pair<int, int>;

std::vector<pii> graph[20001];
int dist[20001];
int inf = 987654;

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	std::fill(dist, dist + 20001, inf);

	int v, e;
	std::cin >> v >> e;

	int k;
	std::cin >> k;

	for (int i = 0; i < e; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		graph[x].emplace_back(pii(y, z));
	}

	std::priority_queue<pii, std::vector<pii>, std::greater<>> q;
	q.emplace(pii(0,k));
	dist[k] = 0;

	while (!q.empty()) {
		int d = q.top().first;
		int current = q.top().second;
		q.pop();

		if (dist[current] < d) continue;

		for (pii next : graph[current]) {
			if (dist[current] + next.second >= dist[next.first]) continue;
											
			dist[next.first] = dist[current] + next.second;
			q.emplace(pii(dist[next.first], next.first));
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == inf) std::cout << "INF" << "\n";
		else std::cout << dist[i] << "\n";
	}
}