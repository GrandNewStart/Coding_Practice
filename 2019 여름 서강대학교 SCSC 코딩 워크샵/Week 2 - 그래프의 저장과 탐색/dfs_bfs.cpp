#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> graph;
bool visit[1001]; // �湮�� TRUE

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

	int n, m, v; // n(������ ��), m(������ ��), v(ù��°�� Ž���� ����)
	cin >> n >> m >> v;
	graph.resize(n + 1);

	//��������Ʈ �Է�
	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}

	//�Էµ� �ֵ� ����
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