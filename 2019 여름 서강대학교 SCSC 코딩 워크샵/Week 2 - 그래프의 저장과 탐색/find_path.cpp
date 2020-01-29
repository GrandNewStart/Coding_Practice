#include <iostream>
#include <cstring>
using namespace std;

int n;
int graph[101][101];
bool visit[101];

void dfs(int u, int start) {
	for (int v = 0; v < n; v++) {
		if (visit[v]) continue;
		if (!graph[u][v]) continue;

		visit[v] = true;

		dfs(v, start);
	}
}

int main() {
	//n(정점의 개수)
	cin >> n;

	//인접행렬 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	//경로 탐색 & 출력
	for (int i = 0; i < n; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i, i);

		for (int j = 0; j < n; j++) cout << visit[j] << ' ';
		cout << '\n';
	}

	return 0;
}