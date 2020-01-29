#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int box[1000][1000];
int days[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pii> q;


int main() {
	//m(가로, 행수), n(세로, 열수)
	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.emplace(pii(i, j));
		}
	}

	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= m) continue;
			if (box[nx][ny] != 0) continue;

			box[nx][ny] = 1;
			days[nx][ny] = days[x][y] + 1;
			q.emplace(pii(nx, ny));

			if (cnt < days[nx][ny]) cnt = days[nx][ny];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cnt = -1;
			}
		}	
	}

	cout << cnt;

	return 0;
}