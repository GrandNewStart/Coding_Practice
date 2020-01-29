#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
bool visit[1000];

void dfs(int u) {
	for (int v : grpah[u]) {
		if (visit[u]) continue;

		visit[u] = true;
		dfs(v);
	}
}

int main() {
	//n(정점의 개수), m(간선의 개수)
	int n, m;
	cin >> n >> m;

	graph.resize(n + 1);

	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].emplace(y);
		graph[y].emplace(x);
	}

	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		cnt++;
		dfs(i);
	}

	cout << cnt;

	return 0;
}