#include <iostream>
#include <queue>
using namespace std;

bool graph[1001][1001] = { false };
bool visited[1001] = { false };

void bfs(int start, int vertices) {
	queue<int> q;
	q.emplace(start);

	while (!q.empty()) {
		int front = q.front();
		visited[front] = true;
		q.pop();

		for (int i = 1; i <= vertices; i++) {
			if (!visited[i] && graph[front][i]) {
				q.emplace(i);
			}
		}
	}
}

void dfs(int start, int vertices) {
	for (int i = 1; i <= vertices; i++) {
		if (!visited[i] && graph[start][i]) {
			visited[i] = true;
			dfs(i, vertices);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// vertices: 1 ~ 1000, edges: 0 ~ N(N-1)/2
	int vertices, edges, count = 0;
	cin >> vertices >> edges;

	for (int i = 0; i < edges; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = true;
		graph[y][x] = true;
	}

	for (int i = 1; i <= vertices; i++) {
		if (!visited[i]) {
			dfs(i, vertices);
			count++;
		}
	}

	cout << count;
}