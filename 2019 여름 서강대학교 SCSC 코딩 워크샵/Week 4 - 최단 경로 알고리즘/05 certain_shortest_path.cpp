#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1000 * 801

using pii = std::pair<int, int>;
std::vector<pii> graph[801];
int dist[801];

int path(int start, int end) {
	std::fill(dist, dist + 801, MAX);
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

	return dist[end];
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);

	int v, e;
	std::cin >> v >> e;

	for (int i = 1; i <= e; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		graph[a].push_back(pii(b, c));
		graph[b].push_back(pii(a, c));
	}

	int x, y;
	std::cin >> x >> y;

	int op1;
	int op1_1 = path(1, x);
	int op1_2 = path(x, y);
	int op1_3 = path(y, v);
	if (op1_1 == MAX || op1_2 == MAX || op1_3 == MAX) {
		op1 = MAX;
	}
	else {
		op1 = op1_1 + op1_2 + op1_3;
	}

	int op2;
	int op2_1 = path(1, y);
	int op2_2 = path(y, x);
	int op2_3 = path(x, v);
	if (op2_1 == MAX || op2_2 == MAX || op2_3 == MAX) {
		op2 = MAX;
	}
	else {
		op2 = op2_1 + op2_2 + op2_3;
	}

	int result = std::min(op1, op2);
	
	if (result == MAX) {
		std::cout << -1;
	}
	else {
		std::cout << result;
	}
}