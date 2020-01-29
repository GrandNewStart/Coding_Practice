#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
queue<int> q;
bool visit[1000];

int main() {
	//n(정점의 개수), m(간선의 개수)
	int n, m;
	cin >> n >> m;

	graph.resize(n + 1);

	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;

		cnt++;
		q.emplace(i);
		
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int v : graph[x]) {
				if (visit[v]) continue;

				visit[v] = true;
				q.emplace(v);
			}
		}
	}

	cout << cnt;

	return 0;
}