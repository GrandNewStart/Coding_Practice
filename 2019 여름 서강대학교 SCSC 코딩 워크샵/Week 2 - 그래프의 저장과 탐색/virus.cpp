#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> graph; // 인접리스트
bool visit[101]; // 방문시 TRUE

void dfs(int u) {
	for (int v : graph[u]) {
		if (visit[v]) continue;
		visit[v] = true;
		dfs(v);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v = 1, cnt = 0; // n(정점의 수), m(간선의 수), v(첫번째로 탐색할 정점), cnt(바이러스에 걸릴 컴퓨터의 수)
	cin >> n >> m;
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

	//탐색
	visit[v] = true;
	dfs(v);

	for (int i = 2; i <= n; i++) {
		if (visit[i]) cnt++;
	}

	cout << cnt;

	return 0;
}