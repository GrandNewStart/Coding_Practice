#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> graph;
bool visit[1001]; // 방문시 TRUE

void dfs(int u) {
	cout << u << ' ';
	for (int v : graph[u]) { // for (int v = graph[u].begin(); v < graph[u].end(); v++)
		if (visit[v]) continue;
		visit[v] = true;
		dfs(v);
	}
}

void bfs(int start) {
	queue<int> q;
	q.emplace(start);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << ' ';
		for (int v : graph[u]) {
			if (visit[v]) continue;
			visit[v] = true;
			q.emplace(v);
		}
	}
}

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v; // n(정점의 수), m(간선의 수), v(첫번째로 탐색할 정점)
	cin >> n >> m >> v;
	graph.resize(n + 1);

	//인접리스트 입력
	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}

	//입력된 쌍들 정렬
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	visit[v] = true;
	dfs(v);
	cout << '\n';

	memset(visit, 0, sizeof(visit));
	visit[v] = true;
	bfs(v);

	return 0;
}