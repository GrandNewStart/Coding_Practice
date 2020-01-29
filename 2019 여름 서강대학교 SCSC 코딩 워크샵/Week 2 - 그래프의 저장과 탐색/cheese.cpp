#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

int m, n;
int graph[102][102];
bool visit[102][102];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

//한 시간에 녹은 치즈의 수 반환
int bfs() {
	memset(visit, 0, sizeof(visit));

	queue<pii> q;
	visit[0][0] = true;
	q.emplace(pii(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m + 2) continue;
			if (ny < 0 || ny >= n + 2) continue;
			if (visit[nx][ny]) continue;

			visit[nx][ny] = true;
			if (graph[nx][ny] == 0)
				q.emplace(pii(nx, ny));
		}
	}

	int melted = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] && graph[i][j] == 1) {
				graph[i][j] = 0;
				melted++;
			}
		}
	}

	return melted;
}

int main() {
	//m(세로길이), n(가로길이)
	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	
	int last = 0;
	int hour = 0;

	while (true) {
		int melted = bfs();
		if (!melted) break;
		last = melted;	
		hour++;
	}

	cout << hour << '\n';
	cout << last;

	return 0;
}