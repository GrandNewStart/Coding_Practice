#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

string room[1000];
int dists[1000][1000];
int distf[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1 };

int main() {
	int T;
	cin >> T;

	while (T--) {
		memset(dists, -1, sizeof(dists));
		memset(distf, -1, sizeof(distf));
		int w, h;
		cin >> w >> h;

		queue<pii> qs, qf;

		for (int i = 0; i < h; i++) {
			cin >> room[i];
			for (int j = 0; j < w; j++) {
				if (room[i][j] == '@') {
					qs.emplace(i, j);
					dists[i][j] = 0;
				}
				if (room[i][j] == '*') {
					qf.emplace(i, j);
					distf[i][j] = 0;
				}
			}
		}

		while (!qf.empty()) {
			int x = qf.front().first;
			int y = qf.front().second;
			qf.pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || nx >= h) continue;
				if (ny < 0 || ny >= w) continue;
				if (room[nx][ny] == '#') continue;
				if (distf[nx][ny] != -1) continue;

				distf[nx][ny] = distf[x][y] + 1;
				qf.emplace(pii(nx, ny));
			}
		}

		while (!qs.empty()) {
			int x = qs.front().first;
			int y = qs.front().second;
			qs.pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || nx >= h) continue;
				if (ny < 0 || ny >= w) continue;
				if (room[nx][ny] == '#') continue;
				if (dists[nx][ny] != -1) continue;
				if (distf[nx][ny] != -1 && 
					dists[x][y] + 1 >= distf[nx][ny]) continue;

				dists[nx][ny] = dists[x][y] + 1;
				qs.emplace(pii(nx, ny));
			}
		}

		int mn = INT_MAX;
		for (int i = 0; i < h; i++) {
			if (dists[i][0] != -1) mn = min(mn, dists[i][0]);
			if (dists[i][w - 1] != -1) mn = min(mn, dists[i][w - 1]);
		}
		for (int j = 0; j < w; j++) {
			if (dists[0][j] != -1) mn = min(mn, dists[0][j]);
			if (dists[h - 1][j] != -1) mn = min(mn, dists[h - 1][j]);
		}

		if (mn == INT_MAX)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << mn + 1 << '\n';
	}

	return 0;
}