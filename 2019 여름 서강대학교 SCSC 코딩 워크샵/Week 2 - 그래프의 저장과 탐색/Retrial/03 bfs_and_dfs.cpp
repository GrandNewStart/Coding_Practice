#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
bool visited[1001];

void dfs(int start) {
	if (!visited[start]) {
		cout << start << " ";
		visited[start] = true;
	}

	for (int i = 0; i < (int)graph[start].size(); i++) {
		int x = graph[start][i];
		if (!visited[x]) {
			dfs(x);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.emplace(start);

	while (!q.empty()) {
		int x = q.front();
		cout << x << " ";
		visited[x] = true;
		q.pop();

		for (int i = 0; i < (int)graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.emplace(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int vertices, edges, start;
	cin >> vertices >> edges >> start;

	graph.resize(vertices + 1);

	for (int i = 0; i < edges; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 0; i < vertices; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	memset(visited, false, sizeof(visited));
	dfs(start);

	cout << "\n";

	memset(visited, false, sizeof(visited));
	bfs(start);
}