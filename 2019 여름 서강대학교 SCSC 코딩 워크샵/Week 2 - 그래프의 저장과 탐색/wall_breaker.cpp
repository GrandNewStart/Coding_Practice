#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pii = pair<int, int>;
int N, M;
int map[1000][1000];
//r1(벽을 부수지 않은 거리), r2(벽을 부순 거리)
int r1[1000][1000];
int r2[1000][1000];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			map[i][j] = temp[j] - '0';
		}
	}
	
	memset(r1, -1, sizeof(r1));
	memset(r2, -1, sizeof(r2));

	queue<pii> q;
	r1[0][0] = 1;
	q.emplace(0, 0);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= M) continue;
			if (ny < 0 || ny >= N) continue;

			bool flag = false;

			// map[nx][ny]의 벽을 부수고 r1 -> r2
			if (map[nx][ny] && r1[x][y] != -1 && r2[nx][ny] == -1) {
				r2[nx][ny] = r1[x][y] + 1;
				flag = true;
			}

			// map[nx][ny]에 벽이 없고 r1 -> r1
			if (!map[nx][ny] && r1[x][y] != -1 && r1[nx][ny] == -1) {
				r1[nx][ny] = r1[x][y] + 1;
				flag = true;
			}

			// map[nx][ny]에 벽이 없고 r2 -> r2
			if (!map[nx][ny] && r2[x][y] != -1 && r2[nx][ny] == -1) {
				r2[nx][ny] = r2[x][y] + 1;
				flag = true;
			}

			if (flag) {
				q.emplace(pii(nx, ny));
			}
		}
	}

	if (r1[N - 1][M - 1] == -1) {
		if (r2[N - 1][M - 1] == -1) {
			cout << -1;
		}
		else {
			cout << r2[N - 1][M - 1];
		}
	}
	else {
		if (r2[N - 1][M - 1] == -1) {
			cout << r1[N - 1][M - 1];
		}
		else {
			cout << min(r1[N - 1][M - 1], r2[N - 1][M - 1]);
		}
	}

	return 0;
}